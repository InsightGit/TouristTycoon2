/*
 * TouristSpawner.cpp
 *
 *  Created on: Mar 11, 2017
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

#include "TouristSpawner.hpp"

#include "Advertisement.hpp"

#include "SimPlayer.hpp"

imagine::sim::TouristSpawner::TouristSpawner(imagine::sim::player *mainPlayer,std::vector<imagine::sim::Advertisement> *advertisements,std::vector<imagine::sim::attraction> *attractions) {
	// TODO Auto-generated constructor stub
	player=mainPlayer;
	allAdvertisements=advertisements;
	allAttractions=attractions;
}

imagine::sim::TouristSpawner::~TouristSpawner() {
	// TODO Auto-generated destructor stub
}

void imagine::sim::TouristSpawner::update(const signed int numberOfAttractionsSpawned, const signed int numberOfAdvertisementsSpawned) {
	if(numberOfAttractionsSpawned!=pastNumberOfAttractionsSpawned){ //possible SIGSEV?
		basePopularity=0;
		for(int i = 0; i < numberOfAttractionsSpawned; ++i){
			if(i==0){
				basePopularity=allAttractions->at(i).getPopularity();
			}else if(basePopularity < allAttractions->at(i).getPopularity()){
				basePopularity=allAttractions->at(i).getPopularity();
			}
			//basePopularity+=allAttractions->at(i).getPopularity();
		}
		for(int i = 0; i < numberOfAttractionsSpawned; ++i){
			crime+=allAttractions->at(i).getCrimeAttention();
		}
		for(int i = 0; i < player->numberOfPoliceStationsSpawned > i;++i){
			crimeFighting+=player->policeStationsCreated[i].getCrimeFightingAbility();
		}
		if(crimeFighting-crime < 0){
			basePopularity-=(crimeFighting-crime);
		}
		pastNumberOfAttractionsSpawned=numberOfAttractionsSpawned;
		if(player->publicTransport.cruiseTerminalSpawned){
			basePopularity=basePopularity*player->publicTransport.currentCruiseTerminal.getPopularityBoost();
		}
		int buildingNumber = 0;
		buildingNumber = player->numberOfAttractionsSpawned+player->numberOfHotelsSpawned+player->numberOfPoliceStationsSpawned+player->numberOfRestaurantsSpawned;
		if(player->townHallSpawned){
			//if() TODO:(Bobby)Add City Policy removing limits
		}else if(int(buildingNumber / 3) > 0){
			activeTourists = activeTourists / int(buildingNumber / 3);
		}
	}

	if(player->time->getSimTime().getHour() >= 5 && player->time->getSimTime().getHour() <= 17){
		if(pastHour==NULL){
			spawnNumber = basePopularity;
			for(int i = 0; i < numberOfAdvertisementsSpawned;++i){
				if(allAdvertisements->at(i).id==0 && allAdvertisements->at(i).active){
					spawnNumber = spawnNumber*allAdvertisements->at(i).multiplier; //online advert multiplier
				}
			}
			pastHour=player->time->getSimTime().getHour();
		}else if(pastHour+3!=player->time->getSimTime().getHour()){
				spawnNumber = basePopularity;
				for(int i = 0; i < numberOfAdvertisementsSpawned;++i){
					if(allAdvertisements->at(i).id==0 && allAdvertisements->at(i).active){
						spawnNumber = spawnNumber*allAdvertisements->at(i).multiplier; //online advert multiplier
					}
				}
		}
	}else{
		if(pastHour==NULL){
			spawnNumber = basePopularity/2;
			for(int i = 0; i < numberOfAdvertisementsSpawned;++i){
				if(allAdvertisements->at(i).id==0 && allAdvertisements->at(i).active){
					spawnNumber = spawnNumber*allAdvertisements->at(i).multiplier; //online advert multiplier
				}
			}
			//pastHour=player->time->getSimTime().getHour();
		}else if(pastHour+3!=player->time->getSimTime().getHour()){
			spawnNumber = basePopularity/2;
			for(int i = 0; i < numberOfAdvertisementsSpawned;++i){
				if(allAdvertisements->at(i).id==0){
					spawnNumber = spawnNumber*allAdvertisements->at(i).multiplier; //online advert multiplier
				}
			}
		}
	}
	activeTourists=0; //NOT thread safe 																															NTS
	for(int i = 0; player->numberOfAttractionsSpawned > i;++i){
		activeTourists+=player->attractionsCreated[i].getCurrentOccupancy();
	}
	for(int i = 0; player->numberOfRestaurantsSpawned > i;++i){
		activeTourists+=player->restaurantsCreated[i].getCurrentOccupancy();
	}
}

void imagine::sim::TouristSpawner::spawnTourists(const signed int numberOfAttractionsSpawned, const signed int numberOfAdvertisementsSpawned) {
	update(numberOfAttractionsSpawned,numberOfAdvertisementsSpawned);
	/*if(pastHour!=NULL && activeTourists < limitActiveTourists){
		if(pastHour!=player->time->getSimTime().getHour()){
			for(int i = 0; player->tourists > i;++i){
				if(player->touristsSpawned[i].leaving && !player->touristsSpawned[i].pastLeaving){
					//delete player->touristsSpawned[i];
					player->activeTourists--;
					player->tourists--;
				}else if(!player->touristsSpawned[i].added && player->touristsSpawned[i].status!=imagine::sim::types::sleeping){
					player->activeTourists++;
					player->touristsSpawned[i].added=true;
				}else if(player->touristsSpawned[i].status!=imagine::sim::types::sleeping){
					player->activeTourists--;
					player->touristsSpawned[i].added=false;
				}
			}*/
			//std::cout << "SPAWN:" << spawnNumber << "\n";
	if(pastHour!=NULL){
		if(pastHour!=player->time->getSimTime().getHour()){
			for(int i = 0; spawnNumber > i;++i){
				imagine::sim::NewTourist newTourist = imagine::sim::NewTourist(player);
				player->touristsSpawned.push_back(newTourist);
				player->tourists++;
				std::cout << "Tourist spawned\n";
			}
		}
		for(int i = 0; player->tourists > i;++i){
			if(player->touristsSpawned[i].GetSafeToDelete()){
				player->touristsSpawned.erase(player->touristsSpawned.begin()+i);
				player->tourists--;
			}
		}
	}
	pastHour=player->time->getSimTime().getHour();
}
