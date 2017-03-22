/*
 * CityPolicy.cpp
 *
 *  Created on: Mar 21, 2017
 *      Author: newbobby
 */

#include "CityPolicy.hpp"

imagine::sim::CityPolicy::CityPolicy(const signed int idToUse) {
	// TODO Auto-generated constructor stub
	id=idToUse;
	if(id==0){
		name="Nice Trees";
		happinessGained=3;
		maintainceCost=200;
	}
}

imagine::sim::CityPolicy::~CityPolicy() {
	// TODO Auto-generated destructor stub
}
