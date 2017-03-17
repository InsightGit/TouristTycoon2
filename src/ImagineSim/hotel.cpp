/*
 * hotel.cpp
 *
 *  Created on: Mar 8, 2017
 *      Author: newbobby
 */

#include "hotel.hpp"
#include "Tourist.hpp"
#include "SimPlayer.hpp"

imagine::sim::hotel::hotel(const signed int idToUse, const sf::Vector2f position, imagine::sim::player *mainPlayer) {
	// TODO Auto-generated constructor stub
	id=idToUse;
	if(id==3){
		cost=150;
		maintainceCost=750;
		maintainceCostSet=true;
		buildingCost=3000;
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
			std::cout << "Hotel created\n";
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
		return true;
	}else{
		return false;
	}
}

void imagine::sim::hotel::checkout(imagine::sim::tourist *tourist){
	size--;
	if(size<=maxSize){
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
