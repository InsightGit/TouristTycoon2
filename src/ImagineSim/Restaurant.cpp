/*
 * Restaurant.cpp
 *
 *  Created on: Mar 17, 2017
 *      Author: newbobby
 */

#include "Restaurant.hpp"

#include "SimPlayer.hpp"

imagine::sim::Restaurant::Restaurant(const int id,imagine::sim::player *mainPlayer, const sf::Vector2f position) {
	// TODO Auto-generated constructor stub
	if(id==6){
		buildingCost = 5000;
		cost = 80;
		maintainceCost=175;
		maintainceCostSet=true;
		cuisine=imagine::sim::types::Italian;
		quality=imagine::sim::types::Ok;
		maxOccupancy=45;
		tileImage.create(italianRestaurantImageFile.width,italianRestaurantImageFile.height,italianRestaurantImageFile.pixel_data);
	}else if(id==7){
		buildingCost = 5000;
		cost = 80;
		maintainceCost=175;
		maintainceCostSet=true;
		cuisine=imagine::sim::types::Mexican;
		quality=imagine::sim::types::Ok;
		maxOccupancy=45;
		tileImage.create(mexicanRestaurantImageFile.width,mexicanRestaurantImageFile.height,mexicanRestaurantImageFile.pixel_data);
	}else if(id==8){
		buildingCost = 5000;
		cost = 80;
		maintainceCost=175;
		maintainceCostSet=true;
		cuisine=imagine::sim::types::Diner;
		quality=imagine::sim::types::Ok;
		maxOccupancy=45;
		tileImage.create(dinerImageFile.width,dinerImageFile.height,dinerImageFile.pixel_data);
	}
	player=mainPlayer;
	tileSprite.setPosition(position);
}

imagine::sim::Restaurant::~Restaurant() {
	// TODO Auto-generated destructor stub
}

void imagine::sim::Restaurant::spawn(){
	tileTexture.loadFromImage(tileImage);
	tileSprite.setTexture(tileTexture);
	alive=true;
}

bool imagine::sim::Restaurant::create(imagine::sim::popUp *notEnoughMoneyPopUp,const sf::Font *fontToUse){
	spawn();
	if(player->money >= buildingCost){
		player->restaurantsCreated.push_back(*this);
		player->numberOfRestaurantsSpawned++;
		player->money-=buildingCost;
	}else{
		notEnoughMoneyPopUp = new imagine::sim::popUp("You don't have enough money.",fontToUse);
		return false;
	}
	return true;
}

bool imagine::sim::Restaurant::checkin(imagine::sim::tourist *tourist){
	if(tourist->money-cost > 0 && vacancy){
		tourist->money-=cost;
		player->money+=cost;
		currentOccupancy++;
		if(currentOccupancy>=maxOccupancy){
			vacancy=false;
		}
		return true;
	}else{
		return false;
	}
}

void imagine::sim::Restaurant::checkout(imagine::sim::tourist *tourist){
	currentOccupancy--;
	if(currentOccupancy < maxOccupancy){
		vacancy=true;
	}
}

void imagine::sim::Restaurant::draw(sf::RenderWindow *window){
	if(alive){
		tileTexture.loadFromImage(tileImage);
		tileSprite.setTexture(tileTexture);
		window->draw(tileSprite);
	}
}
