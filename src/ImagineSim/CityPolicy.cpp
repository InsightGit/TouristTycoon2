/*
 * CityPolicy.cpp
 *
 *  Created on: Mar 21, 2017
 *      Author: newbobby
 */

#include "CityPolicy.hpp"

#include "SimPlayer.hpp"

imagine::sim::CityPolicy::CityPolicy(const signed int idToUse, imagine::sim::player *mainPlayer, const signed int minimumLevelNeeded, const imagine::sim::types::conditions conditionsNeeded) {
	// TODO Auto-generated constructor stub
	id=idToUse;
	player=mainPlayer;
	if(id==0){
		name="Nice Trees";
		happinessGained=3;
		maintainceCost=200;
	}else if(id==1){
		name="Double Police Spending";
		happinessGained=0.5*player->numberOfPoliceStationsSpawned;
		maintainceCost = 0;
		for(int i = 0; player->numberOfPoliceStationsSpawned > i; ++i){
			maintainceCost+=player->policeStationsCreated[i].maintainceCost;
		}
	}
	minimumLevel=minimumLevelNeeded;
	conditions=conditionsNeeded;

}

imagine::sim::CityPolicy::~CityPolicy() {
	// TODO Auto-generated destructor stub
}

void imagine::sim::CityPolicy::update(){
	if(id==1){
		happinessGained=0.5*player->numberOfPoliceStationsSpawned;
		maintainceCost = 0;
		for(int i = 0; player->numberOfPoliceStationsSpawned > i; ++i){
			maintainceCost+=player->policeStationsCreated[i].maintainceCost;
		}
	}
}
