/*
 * NewTourist.cpp
 *
 *  Created on: Apr 1, 2017
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


#include "NewTourist.hpp"

#include "SimPlayer.hpp"

imagine::sim::NewTourist::NewTourist(imagine::sim::player *mainPlayer) {
	player = mainPlayer;

	std::random_device randomdevice;
	std::mt19937 randommt19937device(randomdevice());
	std::uniform_int_distribution<int> moneychanceuniformint(0,100);

	auto moneychance = moneychanceuniformint(randommt19937device);

	if(moneychance<=20){
		money=1500;
		//minimumQuality=imagine::sim::types::Good;
	}else if(moneychance>20 && moneychance<=80){
		money=700;
		//minimumQuality=imagine::sim::types::Ok;
	}else{
		money=350;
		//minimumQuality=imagine::sim::types::Ok;
	}
	std::uniform_int_distribution<int> energychanceuniformint(5,30);

	auto energychance = energychanceuniformint(randommt19937device);

	energy=2*energychance;
}

imagine::sim::NewTourist::~NewTourist() {
	// TODO(Bobby): Auto-generated destructor stub
}

void imagine::sim::NewTourist::ChooseAttraction(){ //TODO(Bobby): change return type to return statuses
	for(int iterator = 0;player->numberOfAttractionsSpawned > iterator; ++iterator){
		if(GetMoney()-player->attractionsCreated[iterator].getCostForTourists() >= 0){
			if(GetEnergy()-player->attractionsCreated[iterator].getActivityLevel() >= 0){
				if(iterator==0){
					bool passed = true;
					for(int iterator2 = 0;GetCheckedAttractionsSize() > iterator2; ++iterator2){
						if(player->attractionsCreated[iterator].getId() == checkedattractions.at(iterator2)->getId()){
							if(player->attractionsCreated[iterator].attractionSprite.getPosition() == checkedattractions.at(iterator2)->attractionSprite.getPosition()){
								passed = false;
							}
						}
					}
					if(passed){
						SetChosenAttraction(true);
						SetCurrentAttraction(&player->attractionsCreated[iterator]);
					}
				}else{
					if(GetCurrentAttraction()->getPopularity() < player->attractionsCreated[iterator].getPopularity()){
						bool passed = true;
						for(int iterator2 = 0;GetCheckedAttractionsSize() > iterator2; ++iterator2){
							if(player->attractionsCreated[iterator].getId() == checkedattractions.at(iterator2)->getId()){
								if(player->attractionsCreated[iterator].attractionSprite.getPosition() == checkedattractions.at(iterator2)->attractionSprite.getPosition()){
									passed = false;
								}
							}
						}
						if(passed){
							SetChosenAttraction(true);
							SetCurrentAttraction(&player->attractionsCreated[iterator]);
						}
					}
				}
			}
		}
	}
}

void imagine::sim::NewTourist::DriveToAttraction(){
	if(!GetDrivingToDestination()){
		drivingtimer.restart();
		SetDrivingToDestination(true);
	}else if(drivingtimer.getElapsedTime().asSeconds() >= 5){
		SetDrivingToDestination(false);
		SetArrivedAtDestination(true);
	}
}

void imagine::sim::NewTourist::TourAttraction(){
	if(GetVisitingAttraction() && visitingtimer.getElapsedTime().asSeconds() >= 5){
		GetCurrentAttraction()->demit();
		checkedattractions.push_back(GetCurrentAttraction());
		SetCheckedAttractionsSize(GetCheckedAttractionsSize()+1);
		SetChosenAttraction(false);
		SetArrivedAtDestination(false);
		SetVisitingAttraction(false);
	}
}

void imagine::sim::NewTourist::Update(){
	if(!GetLeaving()){
		if(!GetChosenAttraction()){
			ChooseAttraction();
			if(!GetChosenAttraction()){
				SetLeaving(true);
			}
		}else if(!GetArrivedAtDestination()){
			DriveToAttraction();
		}else if(GetArrivedAtDestination() && !GetVisitingAttraction()){
			if(GetCurrentAttraction()->admit(this)){
				visitingtimer.restart();
				player->activeTourists++;
				SetVisitingAttraction(true);
			}else if(player->numberOfAttractionsSpawned-(GetCheckedAttractionsSize()+1) > 0){
				checkedattractions.push_back(GetCurrentAttraction());
				SetCheckedAttractionsSize(GetCheckedAttractionsSize()+1);
				SetChosenAttraction(false);
				SetArrivedAtDestination(false);
			}else{
				SetLeaving(true);
			}
		}else if(GetVisitingAttraction()){
			TourAttraction();
		}
	}else{
		SetSafeToDelete(true);
	}
}

void imagine::sim::NewTourist::Draw(sf::RenderWindow *window){
	Update();

	//TODO(Bobby): Implement drawable Tourists
}
