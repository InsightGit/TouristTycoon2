/*
 * GameTime.cpp
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


#include "GameTime.hpp"

#include "SimPlayer.hpp"

imagine::sim::types::SimTime::SimTime(const signed int hourToUse, const signed int minuteToUse){
	if(hourToUse > 15){
		throw imagine::sim::exceptions::invalidSimTimeException();
	}else if(minuteToUse > 60){
		throw imagine::sim::exceptions::invalidSimTimeException();
	}
	hour=hourToUse;
	minute=minuteToUse;
}

void imagine::sim::types::SimTime::setHour(const signed int hourToUse){
	if(hourToUse > 15){
		throw imagine::sim::exceptions::invalidSimTimeException();
	}
	hour=hourToUse;
}

void imagine::sim::types::SimTime::setMinute(const signed int minuteToUse){
	if(minuteToUse > 60){
		throw imagine::sim::exceptions::invalidSimTimeException();
	}
	minute=minuteToUse;
}

imagine::sim::GameTime::GameTime(imagine::sim::player *mainPlayer) {
	// TODO Auto-generated constructor stub
	player = mainPlayer;
}

imagine::sim::GameTime::GameTime(imagine::sim::player *mainPlayer, imagine::sim::types::SimTime time){
	player = mainPlayer;
	simTime = time;
}

imagine::sim::GameTime::~GameTime() {
	// TODO Auto-generated destructor stub
}

void imagine::sim::GameTime::update(){
	if(dayTime.getElapsedTime().asSeconds()/3 > 15){
		//update player date
		if(player->playerDate->getDay() >= 3){
			if(player->playerDate->getMonth() >= 12){
				player->playerDate->setYear(player->playerDate->getYear()+1);
				player->playerDate->setMonth(1);
				player->playerDate->setDay(1);
			}else{
				player->playerDate->setMonth(player->playerDate->getMonth()+1);
				player->playerDate->setDay(1);
			}
		}else{
			player->playerDate->setDay(player->playerDate->getDay()+1);
		}
		dayTime.restart();
	}
	if(dayTime.getElapsedTime().asSeconds() >= 3){
		simTime.setHour(int(dayTime.getElapsedTime().asSeconds()/3));
	}else{
		simTime.setMinute(int(dayTime.getElapsedTime().asSeconds()*20));
	}
}
