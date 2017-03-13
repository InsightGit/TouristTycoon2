/*
 * GameTime.cpp
 *
 *  Created on: Mar 11, 2017
 *      Author: newbobby
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
	simTime = new imagine::sim::types::SimTime(0,0);
}

imagine::sim::GameTime::~GameTime() {
	// TODO Auto-generated destructor stub
	delete simTime;
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
		simTime->setHour(int(dayTime.getElapsedTime().asSeconds()/3));
	}else{
		simTime->setMinute(int(dayTime.getElapsedTime().asSeconds()*20));
	}
}
