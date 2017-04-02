/*
 * DeleteBuilding.cpp
 *
 *  Created on: Mar 26, 2017
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


#include "DeleteBuilding.hpp"


imagine::sim::DeleteBuilding::DeleteBuilding(imagine::sim::player *mainPlayer, const sf::Vector2f position) {
	// TODO Auto-generated constructor stub
	player=mainPlayer;
	button.optionalImage = new sf::Image();
	button.optionalTexture = new sf::Texture();
	button.optionalImage->create(deleteBuildingImageFile.width,deleteBuildingImageFile.height,deleteBuildingImageFile.pixel_data);
	button.optionalTexture->loadFromImage(*button.optionalImage);
	button.sprite.setTexture(*button.optionalTexture);
	button.sprite.setPosition(position);
	selection.setOutlineThickness(4);
	selection.setFillColor(sf::Color::Transparent);
	//selection.setOutlineColor()
}

imagine::sim::DeleteBuilding::~DeleteBuilding() {
	// TODO Auto-generated destructor stub
	delete button.optionalImage;
	delete button.optionalTexture;
}

void imagine::sim::DeleteBuilding::whenClicked(){
	active=true;
}

void imagine::sim::DeleteBuilding::update(sf::RenderWindow *window){
	selection.setPosition(sf::Vector2f(sf::Mouse::getPosition(*window)));
	if(active){
		bool passed = false;
		//goes through and sees if intersecting with anything
		sf::Vector2i placement;
		for(int i = 0; player->numberOfAttractionsSpawned > i;++i){
			if(player->attractionsCreated[i].attractionSprite.getGlobalBounds().intersects(selection.getGlobalBounds())){
				passed=true;
				placement.x=1;
				placement.y=i;
			}
		}
		for(int i = 0;player->numberOfHotelsSpawned > i;++i){
			if(player->hotelsCreated[i].hotelSprite.sprite.getGlobalBounds().intersects(selection.getGlobalBounds())){
				passed=true;
				placement.x=2;
				placement.y=i;
			}
		}
		for(int i = 0;player->numberOfPoliceStationsSpawned > i;++i){
			if(player->policeStationsCreated[i].cityServiceSprite.sprite.getGlobalBounds().intersects(selection.getGlobalBounds())){
				passed=true;
				placement.x=3;
				placement.y=i;
			}
		}
		for(int i = 0;player->numberOfRestaurantsSpawned > i;++i){
			if(player->restaurantsCreated[i].tileSprite.getGlobalBounds().intersects(selection.getGlobalBounds())){
				passed=true;
				placement.x=4;
				placement.y=i;
			}
		}
		if(player->townHallSpawned){
			if(player->townHall->cityServiceSprite.sprite.getGlobalBounds().intersects(selection.getGlobalBounds())){
				passed=true;
				placement.x=5;
				placement.y=0;
			}
		}
		if(player->publicTransport.cruiseTerminalSpawned){
			if(player->publicTransport.currentCruiseTerminal.transportSprite.sprite.getGlobalBounds().intersects(selection.getGlobalBounds())){
				passed=true;
				placement.x=6;
				placement.y=0;
			}
		}
		if(passed){
			selection.setOutlineColor(sf::Color::Green);
		}else{
			selection.setOutlineColor(sf::Color::Red);
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
			active=false;
		}
		if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && passed){
			switch(placement.x){
				case 1:
					/*auto it = std::find(player->attractionsCreated.begin(), player->attractionsCreated.end(), player->attractionsCreated[placement.y]);
					player->attractionsCreated.erase(it);*/
					player->attractionsCreated.erase(player->attractionsCreated.begin()+placement.y);
					player->numberOfAttractionsSpawned--;
					active=false;
					break;
				case 2:
					player->hotelsCreated.erase(player->hotelsCreated.begin()+placement.y);
					player->numberOfHotelsSpawned--;
					active=false;
					break;
				case 3:
					player->policeStationsCreated.erase(player->policeStationsCreated.begin()+placement.y);
					player->numberOfPoliceStationsSpawned--;
					active=false;
					break;
				case 4:
					player->restaurantsCreated.erase(player->restaurantsCreated.begin()+placement.y);
					player->numberOfRestaurantsSpawned--;
					active=false;
					break;
				case 5:
					delete player->townHall;
					player->townHallSpawned=false;
					active=false;
					break;
				case 6:
					player->publicTransport.currentCruiseTerminal = imagine::sim::CruiseTerminal();
					player->publicTransport.cruiseTerminalSpawned=false;
					active=false;
					break;
			}
		}
	}
}

void imagine::sim::DeleteBuilding::draw(sf::RenderWindow *window){
	update(window);
	window->draw(button.sprite);
	if(active){
		window->draw(selection);
	}
}
