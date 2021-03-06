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

bool imagine::sim::types::comparefoodquality::IsLess(imagine::sim::types::foodQuality leftSide, imagine::sim::types::foodQuality rightSide){
	switch(rightSide){
		case imagine::sim::types::Terrible:
			if(leftSide!=imagine::sim::types::Terrible){
				return true;
			}
			break;
		case imagine::sim::types::Poor:
			if(leftSide!=imagine::sim::types::Terrible && leftSide!=imagine::sim::types::Poor){
				return true;
			}
			break;
		case imagine::sim::types::Ok:
			if(leftSide == imagine::sim::types::Good && leftSide == imagine::sim::types::Great && leftSide == imagine::sim::types::Legendary){
				return true;
			}
			break;
		case imagine::sim::types::Good:
			if(leftSide == imagine::sim::types::Great && leftSide == imagine::sim::types::Legendary){
				return true;
			}
			break;
		case imagine::sim::types::Great:
			if(leftSide == imagine::sim::types::Legendary){
				return true;
			}
			break;
	}
	return false;
}

imagine::sim::NewTourist::NewTourist(imagine::sim::player *mainPlayer) {
	player = mainPlayer;

	std::random_device randomdevice;
	std::mt19937 randommt19937device(randomdevice());
	std::uniform_int_distribution<int> moneychanceuniformint(0,100);

	auto moneychance = moneychanceuniformint(randommt19937device);

	if(moneychance<=20){
		money_=1500;
		minimumquality_=imagine::sim::types::Good;
	}else if(moneychance>20 && moneychance<=80){
		money_=700;
		minimumquality_=imagine::sim::types::Ok;
	}else{
		money_=350;
		minimumquality_=imagine::sim::types::Ok;
	}
	std::uniform_int_distribution<int> energychanceuniformint(5,30);

	auto energychance = energychanceuniformint(randommt19937device);

	energy_=2*energychance;
	baseenergy_=energy_;

	std::uniform_int_distribution<int> preferredcuisineuniformint(1,4);
	auto preferredcuisineint = preferredcuisineuniformint(randommt19937device);
	switch(preferredcuisineint){
		case 1:
			preferredcuisine_=imagine::sim::types::Italian;
			break;
		case 2:
			preferredcuisine_=imagine::sim::types::Mexican;
			break;
		case 3:
			preferredcuisine_=imagine::sim::types::Diner;
			break;
		case 4:
			preferredcuisine_=imagine::sim::types::JapaneseTeppanyaki;
			break;
	}

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

void imagine::sim::NewTourist::DriveToDestination(){
	if(!GetDrivingToDestination()){
		drivingtimer.restart();
		SetDrivingToDestination(true);
	}else if(drivingtimer.getElapsedTime().asSeconds() >= 5){
		SetDrivingToDestination(false);
		SetArrivedAtDestination(true);
	}
}

void imagine::sim::NewTourist::DriveToHotel(){
	if(!GetDrivingToHotel()){
		drivingtohoteltimer.restart();
		SetDrivingToHotel(true);
		std::cout << "Reset\n";
	}else if(drivingtohoteltimer.getElapsedTime().asSeconds() >= 5 && GetDrivingToHotel()){
		SetDrivingToHotel(false);
		SetArrivedAtHotel(true);
		std::cout << "Reached\n";
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
		if(!GetHungry() && GetCheckedAttractionsSize() >= 2){
			 SetHungry(true);
		}
		SetVisitedAttractionNumber(GetVisitedAttractionNumber()+1);
		int happiness = GetHappiness();
		happiness-=int(5*GetVisitedAttractionNumber());
		if(player->townHallSpawned){
			happiness+=int(4*player->townHall->getCityPolicySize());
		}
	}
}

void imagine::sim::NewTourist::ChooseHotel(){
	for(int iterator = 0;player->numberOfHotelsSpawned > iterator;++iterator){
		if(GetMoney()-player->hotelsCreated[iterator].getCost() >= 0){
			if(iterator==0 || player->hotelsCreated[iterator].getPopularity() > GetCurrentHotel()->getPopularity()){
				bool passed = true;
				for(int iterator2 = 0; GetCheckedHotelsSize() > iterator2; ++iterator2){
					if(player->hotelsCreated[iterator].getId() == player->hotelsCreated[iterator2].getId()){
						if(player->hotelsCreated[iterator].hotelSprite.sprite.getPosition() == player->hotelsCreated[iterator2].hotelSprite.sprite.getPosition()){
							passed = false;
						}
					}
				}
				if(passed){
					SetChosenHotel(true);
					SetCurrentHotel(&player->hotelsCreated[iterator]);
				}
			}
		}
	}
}

void imagine::sim::NewTourist::ChooseRestaurant(){
	for(int iterator = 0; player->numberOfRestaurantsSpawned > iterator; ++iterator){
		if(GetMoney()-player->restaurantsCreated[iterator].getCost() >= 0){
			if(imagine::sim::types::comparefoodquality::IsLess(GetMinimumQuality(),player->restaurantsCreated[iterator].getQuality()) || GetMinimumQuality()==player->restaurantsCreated[iterator].getQuality()){
				if(iterator == 0){
					bool passed = true;
					for(int iterator2 = 0; GetCheckedRestaurantsSize() > iterator2; ++iterator2){
						if(player->restaurantsCreated[iterator2].getId() == player->restaurantsCreated[iterator].getId()){
							if(player->restaurantsCreated[iterator2].tileSprite.getPosition() == player->restaurantsCreated[iterator].tileSprite.getPosition()){
								passed = false;
							}
						}
					}
					if(passed){
						SetChosenRestaurant(true);
						SetCurrentRestaurant(&player->restaurantsCreated[iterator]);
						if(player->restaurantsCreated[iterator].getCuisine()==GetPreferredCuisine()){
							SetCuisineMatched(true);
						}
					}
				}else if(!GetCuisineMatched() && player->restaurantsCreated[iterator].getCuisine()==GetPreferredCuisine()){
					bool passed = true;
					for(int iterator2 = 0; GetCheckedRestaurantsSize() > iterator2; ++iterator2){
						if(player->restaurantsCreated[iterator2].getId() == player->restaurantsCreated[iterator].getId()){
							if(player->restaurantsCreated[iterator2].tileSprite.getPosition() == player->restaurantsCreated[iterator].tileSprite.getPosition()){
								passed = false;
							}
						}
					}
					if(passed){
						SetChosenRestaurant(true);
						SetCurrentRestaurant(&player->restaurantsCreated[iterator]);
						if(player->restaurantsCreated[iterator].getCuisine()==GetPreferredCuisine()){
							SetCuisineMatched(true);
						}
					}
				}else if(imagine::sim::types::comparefoodquality::IsLess(GetCurrentRestaurant()->getQuality(),player->restaurantsCreated[iterator].getQuality())){
					bool passed = true;
					for(int iterator2 = 0; GetCheckedRestaurantsSize() > iterator2; ++iterator2){
						if(player->restaurantsCreated[iterator2].getId() == player->restaurantsCreated[iterator].getId()){
							if(player->restaurantsCreated[iterator2].tileSprite.getPosition() == player->restaurantsCreated[iterator].tileSprite.getPosition()){
								passed = false;
							}
						}
					}
					if(passed){
						SetChosenRestaurant(true);
						SetCurrentRestaurant(&player->restaurantsCreated[iterator]);
						if(player->restaurantsCreated[iterator].getCuisine()==GetPreferredCuisine()){
							SetCuisineMatched(true);
						}
					}
				}
			}
		}
	}
	SetCuisineMatched(false);
}

void imagine::sim::NewTourist::Sleep(){
	if(GetSleeping() && sleepingtimer.getElapsedTime().asSeconds() >= 6){
		std::cout << "Checking Out\n";
		GetCurrentHotel()->checkout();
		SetSleeping(false);
		SetArrivedAtHotel(false);
		SetChosenHotel(false);
		SetInHotel(false);
	}else if(!GetSleeping()){
		SetSleeping(true);
		sleepingtimer.restart();
	}
	//std::cout << "Sleeping for:" << std::to_string(int(sleepingtimer.getElapsedTime().asSeconds())) << "\n";
}

void imagine::sim::NewTourist::Eat(){
	if(GetEating() && eatingtimer.getElapsedTime().asSeconds() >= 3){
		GetCurrentRestaurant()->checkout();
		SetEating(false);
		SetArrivedAtDestination(false);
		SetDrivingToDestination(false);
		SetChosenRestaurant(false);
		SetHungry(true);
	}
}

void imagine::sim::NewTourist::CalculateExtraHappiness(){
	player->touristExtraHappiness = 0;
	if(player->townHallSpawned){
		for(int i = 0;player->townHall->getCityPolicySize() > i;++i){
			if(player->townHall->cityPolicies[i].active){
				player->touristExtraHappiness+=player->townHall->cityPolicies[i].getHappinessGained();
			}
		}
	}
}

void imagine::sim::NewTourist::Update(){
	CalculateExtraHappiness();
	if(!GetLeaving()){
		if(GetHappiness() <= 0){
			SetLeaving(true);
	    }else if(GetHungry() && !GetChosenRestaurant()){
			ChooseRestaurant();
			if(!GetChosenRestaurant()){
				SetLeaving(true);
			}
		}else if(!GetChosenAttraction() && !GetHungry() && !GetChosenHotel()){
			ChooseAttraction();
			//std::cout << std::to_string(player->numberOfAttractionsSpawned-(GetCheckedAttractionsSize())-1) << "=#ofATTSPAW\n";
			if(!GetChosenAttraction() && player->numberOfAttractionsSpawned-GetCheckedAttractionsSize() > 0 && !GetJustSpawned()){
				ChooseHotel();
				//std::cout << "Choosing Hotel\n";
				if(!GetChosenHotel()){
					SetLeaving(true);
					std::cout << "Leaving2\n";
				}else{
					std::cout << "Chose Hotel1\n";
					SetArrivedAtDestination(false);
				}
			}else if(!GetChosenAttraction()){
				SetLeaving(true);
				std::cout << "Leaving1\n";
			}else if(GetJustSpawned()){
				SetJustSpawned(false);
			}
			if(GetChosenAttraction() && !GetChosenHotel()){
				std::cout << "Chosen Attraction but not hotel\n";
			}else if(GetChosenAttraction() && GetChosenHotel()){
				std::cout << "Chosen Both\n";
			}else if(GetChosenHotel()){
				std::cout << "Chose Hotel2\n";
			}
		}
		if(!GetArrivedAtDestination() && !GetChosenHotel()){
			DriveToDestination();
		}else if(GetChosenHotel() && !GetArrivedAtHotel()){
			DriveToHotel();
		}else if(GetArrivedAtDestination() && !GetVisitingAttraction() && GetChosenAttraction() && !GetChosenHotel()){
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
		}else if(GetArrivedAtHotel() && GetChosenHotel() && !GetInHotel()){
			if(GetCurrentHotel()->checkin(this)){
				std::cout << "Sleeping\n";
				SetArrivedAtHotel(true);
				SetInHotel(true);
				//sleepingtimer.restart();
			}else if(player->numberOfHotelsSpawned-(GetCheckedHotelsSize()+1) > 0){
				checkedhotels.push_back(GetCurrentHotel());
				SetCheckedHotelsSize(GetCheckedHotelsSize()+1);
				SetChosenHotel(false);
			}else{
				SetLeaving(true);
				//std::cout << "Leaving3\n";
			}
		}else if(GetArrivedAtDestination() && GetChosenRestaurant() && !GetEating()){
			if(GetCurrentRestaurant()->checkin(this)){
				std::cout << "Eating\n";
				SetEating(true);
				eatingtimer.restart();
			}else if(player->numberOfRestaurantsSpawned-(GetCheckedRestaurantsSize()+1) > 0){
				checkedrestaurants.push_back(GetCurrentRestaurant());
				SetCheckedHotelsSize(GetCheckedRestaurantsSize()+1);
				SetChosenRestaurant(false);
				SetArrivedAtDestination(false);
			}else{
				SetLeaving(true);
			}
		}else if(GetVisitingAttraction()){
			TourAttraction();
		}else if(GetInHotel()){
			Sleep();
		}else if(GetEating()){
			Eat();
		}
	}else{
		SetSafeToDelete(true);
	}
}

void imagine::sim::NewTourist::Draw(sf::RenderWindow *window){
	Update();

	//TODO(Bobby): Implement drawable Tourists
}
