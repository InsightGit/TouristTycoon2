/*
 * CityPolicy.cpp
 *
 *  Created on: Mar 21, 2017
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
