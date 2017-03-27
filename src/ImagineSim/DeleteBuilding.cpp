/*
 * DeleteBuilding.cpp
 *
 *  Created on: Mar 26, 2017
 *      Author: newbobby
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
					player->attractionsCreated.erase(it);
					active=false;*/
					break;
				case 2:
					break;
				case 3:
					break;
				case 4:
					break;
				case 5:
					break;
				case 6:
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
