/*
 * TouristSpawner.cpp
 *
 *  Created on: Mar 11, 2017
 *      Author: newbobby
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
		for(int i = 0; i < numberOfAttractionsSpawned; i++){
			if(i==0){
				basePopularity=allAttractions->at(i).getPopularity();
			}else if(basePopularity < allAttractions->at(i).getPopularity()){
				basePopularity=allAttractions->at(i).getPopularity();
			}
			//basePopularity+=allAttractions->at(i).getPopularity();
		}
		pastNumberOfAttractionsSpawned=numberOfAttractionsSpawned;
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
	if(pastHour!=NULL && activeTourists < limitActiveTourists){
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
			}
			std::cout << spawnNumber << "\n";
			for(int i = 0; spawnNumber > i;++i){
				imagine::sim::tourist newTourist = imagine::sim::tourist(&player->attractionsCreated,&player->roadsCreated,&player->hotelsCreated,player);
				player->touristsSpawned.push_back(newTourist);
				player->tourists++;
				std::cout << "Tourist spawned\n";
			}
		}
	}
	pastHour=player->time->getSimTime().getHour();
}
