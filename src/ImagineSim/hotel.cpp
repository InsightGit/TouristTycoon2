/*
 * hotel.cpp
 *
 *  Created on: Mar 8, 2017
 *      Author: newbobby
 */

#include "hotel.hpp"
#include "Tourist.hpp"
#include "SimPlayer.hpp"

imagine::sim::hotel::hotel(sf::Vector2f position, imagine::sim::player *mainPlayer) {
	// TODO Auto-generated constructor stub
	tilePosition=position;
	cost=150;
	player = mainPlayer;
}

imagine::sim::hotel::hotel(){}

imagine::sim::hotel::~hotel() {
	// TODO Auto-generated destructor stub
}

void imagine::sim::hotel::spawn(){
	tileImage.create(hotelImageFile.width,hotelImageFile.height,hotelImageFile.pixel_data);
	tileTexture.loadFromImage(tileImage);

	hotelSprite.sprite.setTexture(tileTexture);
	hotelSprite.sprite.setPosition(tilePosition);

	alive=true;
	spawned=true;
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
		window->draw(hotelSprite.sprite);
	}
}
