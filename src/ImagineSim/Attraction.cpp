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


#include "Attraction.hpp"

#include <iostream>

#include "NewTourist.hpp"
#include "Tourist.hpp"
#include "SimPlayer.hpp"


imagine::sim::attraction::attraction(int idToUse, imagine::sim::player *mainPlayer,sf::Vector2f positionToUse)
{
    //ctor
	id=idToUse;
	player=mainPlayer;
	position=positionToUse;
	exists=true;
	playerAssign=true;
	//createdVarOverride=imagine::sim::types::UseInternalValue;
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
		costForTourists=70;
		attractionLevel=0;
		popularity = 10;
		maxOccupancy = 50;
		activityLevel = 7;
		attractionImage.create(washMonu.width,washMonu.height,washMonu.pixel_data);
	}else if(id == 3){ //We skip 2 because it is a hotel
		name="Tokyo Tower";
		cost=2500;
		baseMaintainceCost=950;
		costForTourists=80;
		popularity = 20;
		maxOccupancy = 100;
		activityLevel = 9;
		attractionImage.create(tokyoTowerImageFile.width,tokyoTowerImageFile.height,tokyoTowerImageFile.pixel_data);
	}else if(id == 4){
		name="Zipline";
		cost=7000;
		baseMaintainceCost=400;
		costForTourists=110;
		popularity = 40;
		maxOccupancy = 80;
		activityLevel = 15;
		attractionImage.create(ziplineImageFile.width,ziplineImageFile.height,ziplineImageFile.pixel_data);
	}else if(id == 5){
		name="Hiking Trail";
		cost=7500;
		baseMaintainceCost=375;
		costForTourists=160;
		popularity = 40;
		maxOccupancy = 100;
		activityLevel = 25;
		attractionImage.create(hikingTrailImageFile.width,hikingTrailImageFile.height,hikingTrailImageFile.pixel_data);
	}else if(id == 10){ //we skip 6-9 because they are restaurants, or a townHall
		name="Empire State Building";
		cost=8500;
		baseMaintainceCost=2000;
		costForTourists=180;
		popularity = 50;
		maxOccupancy = 150;
		activityLevel = 10;
		attractionImage.create(empireStateImageFile.width,empireStateImageFile.height,empireStateImageFile.pixel_data);
	}else if(id==12){ //we skip 11 because it is a restaurant
		name = "Big Ben";
		cost = 6000;
		baseMaintainceCost=2500;
		costForTourists=170;
		popularity = 45;
		maxOccupancy = 100;
		activityLevel = 10;
		attractionImage.create(bigBenImageFile.width,bigBenImageFile.height,bigBenImageFile.pixel_data);
	}else if(id==13){
		name = "Amusement Park";
		cost = 9000;
		baseMaintainceCost=4000;
		costForTourists=230;
		popularity = 65;
		maxOccupancy = 300;
		activityLevel = 20;
		attractionImage.create(amusementParkImageFile.width,amusementParkImageFile.height,amusementParkImageFile.pixel_data);
	}else if(id==15){ //we skip id #14 because it is a police station
		name = "Casino";
		cost = 10000;
		baseMaintainceCost=5000;
		costForTourists=350;
		popularity = 75;
		maxOccupancy = 350;
		activityLevel = 9;
		crimeAttention = 10;
		attractionImage.create(casinoImageFile.width,casinoImageFile.height,casinoImageFile.pixel_data);
	}else if(id==17){ //we skip id #16 because it is a cruise terminal
		name = "Central Park";
		cost = 7500;
		baseMaintainceCost=1500;
		costForTourists=250;
		popularity = 75;
		maxOccupancy = 600;
		activityLevel = 27;
		attractionImage.create(centralParkImageFile.width,centralParkImageFile.height,centralParkImageFile.pixel_data);
	}else if(id==18){
		name = "Movie Set";
		cost = 8000;
		baseMaintainceCost=700;
		costForTourists=130;
		popularity = 25;
		maxOccupancy = 50;
		activityLevel = 15;
		attractionImage.create(movieSetImageFile.width,movieSetImageFile.height,movieSetImageFile.pixel_data);
	}else if(id==19){
		name = "Space Needle";
		cost = 4000;
		baseMaintainceCost=750;
		costForTourists=95;
		popularity = 30;
		maxOccupancy = 100;
		activityLevel = 9;
		attractionImage.create(spaceNeedleImageFile.width,spaceNeedleImageFile.height,spaceNeedleImageFile.pixel_data);
	}else{
		name = "Unknown";
		costForTourists=0;
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
			created=true;
		}else{
			notEnoughMoneyPopUp = new imagine::sim::popUp("You don't have enough money.",fontToUse);
			return false;
		}
		return true;
	}
	return false;
}

bool imagine::sim::attraction::admit(imagine::sim::NewTourist *tourist){
	//if(maxOccupancy>currentTouristNum+1){
		if(tourist->GetMoney()-costForTourists > 0 && alive ){
			 if(tourist->GetEnergy()-activityLevel > 0){
				 	//tourist->currentAttraction = this;
					currentTouristNum++;
					allTouristNum++;
					tourist->SetMoney(tourist->GetMoney()-costForTourists);
					player->money+=costForTourists;
					tourist->SetEnergy(tourist->GetMoney()-activityLevel);
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

bool imagine::sim::attraction::admit(imagine::sim::tourist *tourist){
	//if(maxOccupancy>currentTouristNum+1){
		if(tourist->money-costForTourists > 0 && exists){
			 if(tourist->energy-activityLevel > 0){
				 	tourist->currentAttraction = this;
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
	/*if(int(allTouristNum/100)!=0 && pastTouristNum!=int(allTouristNum/100)){
		maintainceCost=baseMaintainceCost*(int(allTouristNum/100));
	}
	pastTouristNum=int(allTouristNum/100);
	/*switch(createdVarOverride){
		case imagine::sim::types::Overridetrue:

	}*/
}

void imagine::sim::attraction::draw(sf::RenderWindow *window){
	update();
	if(alive){
		//std::cout << "ALIVE\n";
		attractionTexture.loadFromImage(attractionImage);

		attractionSprite.setTexture(attractionTexture);
		window->draw(attractionSprite);
	}
}
