/*
 * TownHall.cpp
 *
 *  Created on: Mar 20, 2017
 *      Author: newbobby
 */

#include "TownHall.hpp"

#include "SimPlayer.hpp"

imagine::sim::TownHall::TownHall(imagine::sim::player *mainPlayer, const sf::Vector2f position, const sf::Font *fontToUse) {
	// TODO Auto-generated constructor stub
	player=mainPlayer;
	cityServiceSprite.sprite.setPosition(position);
	defaultFont=fontToUse;
}

imagine::sim::TownHall::~TownHall() {
	// TODO Auto-generated destructor stub
	delete cityServiceSprite.optionalImage;
	delete cityServiceSprite.optionalTexture;
}

void imagine::sim::TownHall::spawn(){
	cityServiceSprite.optionalImage = new sf::Image();
	cityServiceSprite.optionalTexture = new sf::Texture();
	cityServiceSprite.optionalImage->create(townHallImageFile.width,townHallImageFile.height,townHallImageFile.pixel_data);
	cityServiceSprite.optionalTexture->loadFromImage(*cityServiceSprite.optionalImage);
	cityServiceSprite.sprite.setTexture(*cityServiceSprite.optionalTexture);
}

bool imagine::sim::TownHall::create(imagine::sim::popUp *notEnoughMoneyPopUp, const sf::Font *fontToUse){
	spawn();
	if(!created){
		if(player->money >= cost){
			player->townHallSpawned = true;
			player->money-=cost;
		}else{
			notEnoughMoneyPopUp = new imagine::sim::popUp("You don't have enough money.",fontToUse);
			return false;
		}
		created=true;
		return true;
	}
	return false;
}

void imagine::sim::TownHall::whenClicked(){

	return;
}

void imagine::sim::TownHall::update(sf::RenderWindow *window){
	if(cityServiceSprite.isClicked(window)){
		whenClicked();
	}
}

void imagine::sim::TownHall::draw(sf::RenderWindow *window){
	update(window);
	if(created){
		cityServiceSprite.optionalTexture->loadFromImage(*cityServiceSprite.optionalImage);
		cityServiceSprite.sprite.setTexture(*cityServiceSprite.optionalTexture);
		window->draw(cityServiceSprite.sprite);
	}
}
