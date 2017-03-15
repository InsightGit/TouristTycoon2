#include "Attraction.hpp"

#include "Resources/WashMonu.h"

#include "Tourist.hpp"
#include "SimPlayer.hpp"
#include <iostream>

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
		cost=1500;
		costForTourists=50;
		attractionLevel=0;
		popularity = 10;
		maxOccupancy = 50;
		activityLevel = 7;
		attractionImage.create(washMonu.width,washMonu.height,washMonu.pixel_data);
		std::cout << "id==0\n";
	}
	attractionTexture.loadFromImage(attractionImage);

	attractionSprite.setTexture(attractionTexture);
	attractionSprite.setPosition(position);

	alive=true;
	//tileSprite.set
}

bool imagine::sim::attraction::create(imagine::sim::popUp *notEnoughMoneyPopUp, const sf::Font *fontToUse){
	spawn();
	if(id==1){
		if(player->money >= cost){
			player->attractionsCreated.push_back(*this);
			player->numberOfAttractionsSpawned++;
			std::cout << "Attraction created\n";
			player->money-=cost;
		}else{
			notEnoughMoneyPopUp = new imagine::sim::popUp("You don't have enough money.",fontToUse);
			return false;
		}
	}
	return true;
}

bool imagine::sim::attraction::admit(imagine::sim::tourist *tourist){
	if(maxOccupancy>currentTouristNum+1){
		if(tourist->money-costForTourists > 0){
			 if(tourist->energy-activityLevel > 0){
					currentTouristNum++;
					tourist->money-=costForTourists;
					player->money+=costForTourists;
					tourist->energy-=activityLevel;
			 }else{
				std::cout << "No activity\n";
				return false;
			 }
		}else{
			std::cout << "No money\n";
			return false;
		}
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
		attractionTexture.loadFromImage(attractionImage);

		attractionSprite.setTexture(attractionTexture);
		window->draw(attractionSprite);
	}
}
