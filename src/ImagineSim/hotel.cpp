/*
 * hotel.cpp
 *
 *  Created on: Mar 8, 2017
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


#include "hotel.hpp"
#include "Tourist.hpp"
#include "NewTourist.hpp"
#include "SimPlayer.hpp"

imagine::sim::hotel::hotel(const signed int idToUse, const sf::Vector2f position, imagine::sim::player *mainPlayer) {
	// TODO Auto-generated constructor stub
	id=idToUse;
	if(id==2){
		cost=150;
		maintainceCost=750;
		maintainceCostSet=true;
		buildingCost=3000;
		setPopularity(1);
		std::cout << "Hotel created\n";
	}
	tilePosition=position;

	player = mainPlayer;
}

imagine::sim::hotel::hotel(){}

imagine::sim::hotel::~hotel() {
	// TODO Auto-generated destructor stub
}

void imagine::sim::hotel::spawn(){
	if(id==2){
		tileImage.create(hotelImageFile.width,hotelImageFile.height,hotelImageFile.pixel_data);
		tileTexture.loadFromImage(tileImage);

		hotelSprite.sprite.setTexture(tileTexture);
		hotelSprite.sprite.setPosition(tilePosition);
		alive=true;
		spawned=true;
	}

}

bool imagine::sim::hotel::create(imagine::sim::popUp *notEnoughMoneyPopUp, const sf::Font *fontToUse){
	spawn();
	if(id==2){
		if(player->money >= buildingCost){
			player->hotelsCreated.push_back(*this);
			player->numberOfHotelsSpawned++;
			player->money-=buildingCost;
		}else{
			notEnoughMoneyPopUp = new imagine::sim::popUp("You don't have enough money.",fontToUse);
			return false;
		}
	}
	return true;
}

bool imagine::sim::hotel::checkin(imagine::sim::tourist *tourist){
	if(tourist->money-cost > 0 && vacancy){
		tourist->money-=cost;
		player->money+=cost;
		size++;
		if(size>=maxSize){
			vacancy=false;
		}
		std::cout << "Accepted\n";
		return true;
	}else{
		std::cout << "Rejected\n";
		return false;
	}
}

void imagine::sim::hotel::checkout(imagine::sim::tourist *tourist){
	size--;
	if(size < maxSize){
		vacancy=true;
	}
}

bool imagine::sim::hotel::checkin(imagine::sim::NewTourist *tourist){
	if(tourist->GetMoney()-cost > 0 && vacancy){
		tourist->SetMoney(tourist->GetMoney()-cost);
		player->money+=cost;
		size++;
		if(size>=maxSize){
			vacancy=false;
		}
		tourist->SetEnergy(tourist->GetBaseEnergy());
		return true;
	}else{
		return false;
	}
}

void imagine::sim::hotel::checkout(){
	size--;
	if(size < maxSize){
		vacancy=true;
	}
}

void imagine::sim::hotel::draw(sf::RenderWindow *window){
	if(spawned && alive){
		tileTexture.loadFromImage(tileImage);
		hotelSprite.sprite.setTexture(tileTexture);
		window->draw(hotelSprite.sprite);
	}
}
