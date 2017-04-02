/*
 * policeStation.cpp
 *
 *  Created on: Mar 24, 2017
 *      Author: newbobby
 */

/*Copyright (C) 2017 Bobby Youstra

This file is part of TouristTycoon2.

TouristTycoon2 is free software: you can redistribute it and/or modify
it under the terms of the GNU Affero General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

TouristTycoon2 is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Affero General Public License for more details.

You should have received a copy of the GNU Affero General Public License
along with TouristTycoon2.  If not, see <http://www.gnu.org/licenses/>.
*/


#include "policeStation.hpp"

#include "SimPlayer.hpp"

imagine::sim::policeStation::policeStation(const int idToUse,imagine::sim::player *mainPlayer,const sf::Vector2f position) {
	// TODO Auto-generated constructor stub
	player=mainPlayer;
	policeSprite.optionalImage = new sf::Image();
	id=idToUse;
	//if(id==14){
		cost = 6500;
		maintainceCost=400;
		maintainceCostSet=true;
		crimeFightingAbility=20;
		//std::cout << "cost set\n";
		policeSprite.optionalImage->create(policeStationImageFile.width,policeStationImageFile.height,policeStationImageFile.pixel_data);
	//}
	policeSprite.sprite.setPosition(position);
}

imagine::sim::policeStation::~policeStation() {
	// TODO Auto-generated destructor stub
	if(spawned){
		delete policeSprite.optionalImage;
		delete policeSprite.optionalTexture;
	}

}

void imagine::sim::policeStation::spawn(){
	policeSprite.optionalTexture = new sf::Texture();
	policeSprite.optionalTexture->loadFromImage(*policeSprite.optionalImage);
	policeSprite.sprite.setTexture(*policeSprite.optionalTexture);
	spawned=true;
	//created=true;
}

bool imagine::sim::policeStation::create(imagine::sim::popUp *notEnoughMoneyPopUp,const sf::Font *fontToUse){
	//spawn();
	if(!created){
		policeSprite.optionalTexture = new sf::Texture();
		policeSprite.optionalTexture->loadFromImage(*policeSprite.optionalImage);
		policeSprite.sprite.setTexture(*policeSprite.optionalTexture);
		spawned=true;
		//std::cout << player->money << " vs " << cost << "\n";
		if(player->money >= cost){
			player->policeStationsCreated.push_back(*this);
			player->numberOfPoliceStationsSpawned++;
			player->money-=cost;
		}else{
			notEnoughMoneyPopUp = new imagine::sim::popUp("You don't have enough money.",fontToUse);
			//notEnoughMoneyPopUp->popUpdraw=true
			return false;
		}
		created=true;
		return true;
	}
	return false;
}

void imagine::sim::policeStation::whenClicked(){
	return;
}

void imagine::sim::policeStation::update(sf::RenderWindow *window){
	if(policeSprite.isClicked(window)){
		whenClicked();
	}
}

void imagine::sim::policeStation::draw(sf::RenderWindow *window){
	update(window);
	if(spawned){
		policeSprite.optionalTexture->loadFromImage(*policeSprite.optionalImage);
		policeSprite.sprite.setTexture(*policeSprite.optionalTexture);
		window->draw(policeSprite.sprite);
	}else{
		std::cout << "notcreated\n";
	}
}
