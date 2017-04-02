/*
 * Advertisements.cpp
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
