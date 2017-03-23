#include "Attraction.hpp"

#include <iostream>

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
	if(id == 1){ //We skip id #0 because it is a road
		name="Washington Monument";
		cost=1500;
		baseMaintainceCost=600;
		costForTourists=50;
		attractionLevel=0;
		popularity = 10;
		maxOccupancy = 50;
		activityLevel = 7;
		attractionImage.create(washMonu.width,washMonu.height,washMonu.pixel_data);
		std::cout << "id==0\n";
	}else if(id == 3){ //We skip 2 because it is a hotel
		name="Tokyo Tower";
		cost=2500;
		baseMaintainceCost=950;
		costForTourists=100;
		popularity = 20;
		maxOccupancy = 100;
		activityLevel = 9;
		attractionImage.create(tokyoTowerImageFile.width,tokyoTowerImageFile.height,tokyoTowerImageFile.pixel_data);
	}else if(id == 4){
		name="Zipline";
		cost=7000;
		baseMaintainceCost=400;
		costForTourists=150;
		popularity = 40;
		maxOccupancy = 80;
		activityLevel = 15;
		attractionImage.create(ziplineImageFile.width,ziplineImageFile.height,ziplineImageFile.pixel_data);
	}else if(id == 5){
		name="Hiking Trail";
		cost=7500;
		baseMaintainceCost=375;
		costForTourists=175;
		popularity = 40;
		maxOccupancy = 100;
		activityLevel = 25;
		attractionImage.create(hikingTrailImageFile.width,hikingTrailImageFile.height,hikingTrailImageFile.pixel_data);
	}else if(id == 10){ //we skip 6-9 because they are restaurants, or a townHall
		name="Empire State Building";
		cost=8500;
		baseMaintainceCost=2000;
		costForTourists=200;
		popularity = 65;
		maxOccupancy = 150;
		activityLevel = 10;
		attractionImage.create(empireStateImageFile.width,empireStateImageFile.height,empireStateImageFile.pixel_data);
	}
	maintainceCost=baseMaintainceCost;
	maintainceCostSet=true;

	std::cout << id << "\n";
	attractionTexture.loadFromImage(attractionImage);

	attractionSprite.setTexture(attractionTexture);
	attractionSprite.setPosition(position);

	alive=true;
	//tileSprite.set
}

bool imagine::sim::attraction::create(imagine::sim::popUp *notEnoughMoneyPopUp, const sf::Font *fontToUse){
	spawn();
	if(!created){
		if(player->money >= cost){
			player->attractionsCreated.push_back(*this);
			player->numberOfAttractionsSpawned++;
			std::cout << "Attraction created\n";
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

bool imagine::sim::attraction::admit(imagine::sim::tourist *tourist){
	//if(maxOccupancy>currentTouristNum+1){
		if(tourist->money-costForTourists > 0){
			 if(tourist->energy-activityLevel > 0){
					currentTouristNum++;
					allTouristNum++;
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
	//}else{
		//return false;
	//}
}

void imagine::sim::attraction::demit(){
	currentTouristNum--;
}

void imagine::sim::attraction::update(){
	if(int(allTouristNum/100)!=0 && pastTouristNum!=int(allTouristNum/100)){
		maintainceCost=baseMaintainceCost*(int(allTouristNum/100));
	}
	pastTouristNum=int(allTouristNum/100);
}

void imagine::sim::attraction::draw(sf::RenderWindow *window){
	//std::cout << currentTouristNum << "\n";
	update();
	if(alive){
		attractionTexture.loadFromImage(attractionImage);

		attractionSprite.setTexture(attractionTexture);
		window->draw(attractionSprite);
	}
}
