#include "Attraction.hpp"

#include "Resources/WashMonu.h"

#include "Tourist.hpp"
#include "SimPlayer.hpp"

imagine::sim::attraction::attraction(int idToUse, imagine::sim::player *mainPlayer,sf::Vector2f positionToUse)
{
    //ctor
	id=idToUse;
	player=mainPlayer;
	position=positionToUse;
}

imagine::sim::attraction::attraction(){}

imagine::sim::attraction::~attraction()
{
    //dtor
}

void imagine::sim::attraction::spawn(){
	//tileImage.create(Car.width,Car.height,Car.pixel_data);
	if(id == 1){
		cost=50;
		attractionLevel=0;
		popularity = 10;
		maxOccupancy = 25;
		tileImage.create(washMonu.width,washMonu.height,washMonu.pixel_data);
	}
	tileTexture.loadFromImage(tileImage);

	tileSprite.setTexture(tileTexture);
	tileSprite.setPosition(position);

	alive=true;
	//tileSprite.set
}

bool imagine::sim::attraction::admit(imagine::sim::tourist *tourist){
	if(maxOccupancy>currentTouristNum++ && tourist->money-cost > 0 && tourist->energy-activityLevel > 0){
		currentTouristNum++;
		tourist->money-=cost;
		player->money+=cost;
		tourist->energy-=activityLevel;
		return true;
	}else{
		return false;
	}
}

void imagine::sim::attraction::demit(){
	currentTouristNum--;
}

void imagine::sim::attraction::draw(sf::RenderWindow *window){
	if(alive){
		window->draw(tileSprite);
	}
}
