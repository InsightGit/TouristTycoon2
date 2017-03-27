/*
 * CruiseTerminal.cpp
 *
 *  Created on: Mar 26, 2017
 *      Author: newbobby
 */

#include "CruiseTerminal.hpp"

#include "SimPlayer.hpp"

imagine::sim::CruiseTerminal::CruiseTerminal(imagine::sim::player *mainPlayer, const sf::Vector2f position) {
	// TODO Auto-generated constructor stub
	transportSprite.sprite.setPosition(position);
	player=mainPlayer;
	popularityBoost=1.25;
	cost=12000;
	maintainceCost=2500;
	maintainceCostSet=true;
	initlized=true;
}

imagine::sim::CruiseTerminal::CruiseTerminal(){
	maintainceCost=0;
	maintainceCostSet=true;
}

imagine::sim::CruiseTerminal::~CruiseTerminal() {
	// TODO Auto-generated destructor stub
}

void imagine::sim::CruiseTerminal::init(imagine::sim::player *mainPlayer, const sf::Vector2f position) {
	if(!initlized){
		transportSprite.sprite.setPosition(position);
		player=mainPlayer;
		popularityBoost=1.25;
		maintainceCost=5000;
		maintainceCostSet=true;
		initlized=true;
	}
}

void imagine::sim::CruiseTerminal::spawn(){
	if(!spawned){
		transportSprite.optionalTexture = new sf::Texture();
		transportSprite.optionalImage = new sf::Image();
		transportSprite.optionalImage->create(portImageFile.width,portImageFile.height,portImageFile.pixel_data);
		transportSprite.optionalTexture->loadFromImage(*transportSprite.optionalImage);
		transportSprite.sprite.setTexture(*transportSprite.optionalTexture);
		spawned=true;
	}
}

bool imagine::sim::CruiseTerminal::create(imagine::sim::popUp *notEnoughMoneyPopUp, const sf::Font *fontToUse){
	spawn();
	if(!created && initlized && spawned){
		if(player->money >= cost){
			player->publicTransport.currentCruiseTerminal = *this;
			player->publicTransport.cruiseTerminalSpawned = true;
			player->money-=cost;
		}else{
			notEnoughMoneyPopUp = new imagine::sim::popUp("You don't have enough money.",fontToUse);
			spawned=false;
			return false;
		}
		created=true;
		return true;
	}
	return false;
}

void imagine::sim::CruiseTerminal::draw(sf::RenderWindow *window){
	if(initlized && spawned){
		transportSprite.optionalTexture->loadFromImage(*transportSprite.optionalImage);
		transportSprite.sprite.setTexture(*transportSprite.optionalTexture);
		window->draw(transportSprite.sprite);
	}
}