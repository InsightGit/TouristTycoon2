/*
 * Advertisements.cpp
 *
 *  Created on: Mar 11, 2017
 *      Author: newbobby
 */

#include "Advertisement.hpp"
#include "SimPlayer.hpp"

imagine::sim::types::date::date() : imagine::sim::types::date(1,1,2000){}

imagine::sim::types::date::date(int month,int day,int year){
	if(month > 12){
		throw imagine::sim::exceptions::invalidDateException();
	}else if(day > 31){
	    std::cout << "day\n";
		throw imagine::sim::exceptions::invalidDateException();
	}else if(year < 2000){
	    std::cout << "year\n";
		throw imagine::sim::exceptions::invalidDateException();
	}
	monthDate = month;
	dayDate = day;
	yearDate = year;
}

void imagine::sim::types::date::setMonth(int month){
	if(month > 12){
		throw imagine::sim::exceptions::invalidDateException();
	}
	monthDate = month;
}

void imagine::sim::types::date::setDay(int day){
	if(day > 31){
		throw imagine::sim::exceptions::invalidDateException();
	}
	dayDate = day;
}

void imagine::sim::types::date::setYear(int year){
	if(year < 2000){
		throw imagine::sim::exceptions::invalidDateException();
	};
	yearDate = year;
}

int imagine::sim::types::date::getMonth(){
	return monthDate;
}

int imagine::sim::types::date::getDay(){
	return dayDate;
}

int imagine::sim::types::date::getYear(){
	return yearDate;
}

imagine::sim::Advertisement::Advertisement(imagine::sim::types::date currentDate, const int idToUse) {
	// TODO Auto-generated constructor stub
	startDate=currentDate;
	id=idToUse;
	if(id==0){
		multiplier=3;
	}
}

imagine::sim::Advertisement::~Advertisement() {
	// TODO Auto-generated destructor stub
}

void imagine::sim::Advertisement::update(imagine::sim::types::date currentDate){
	if(currentDate.getMonth()>startDate.getMonth() && currentDate.getDay()>=startDate.getDay()){
		active=false;
	}
}
