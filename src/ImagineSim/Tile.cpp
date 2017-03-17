#include "Tile.hpp"

#include "SimPlayer.hpp"
#include "GameTime.hpp"

void imagine::sim::tile::draw(sf::RenderWindow *window){
    window->draw(tileSprite);
}

void imagine::sim::tile::subtractMaintainceCost(imagine::sim::player *mainPlayer,imagine::sim::types::SimTime *time){
	if(!maintainceCostSet){
		throw imagine::sim::exceptions::maintainceCostNotSetException();
	}
	if(time->getHour()!=previousHour){
		mainPlayer->money-=maintainceCost;
		previousHour=time->getHour();
	}
}
