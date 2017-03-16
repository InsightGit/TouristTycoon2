/*
 * MenuItem.cpp
 *
 *  Created on: Feb 27, 2017
 *      Author: newbobby
 */

#include "MenuItem.hpp"


imagine::sim::menuItem::menuItem(sf::Font *fontToUse, const signed int minimumRequiredLevel) {
	// TODO Auto-generated constructor stub
	defaultFont=*fontToUse;
	levelRequired=minimumRequiredLevel;
}

imagine::sim::menuItem::~menuItem() {
	// TODO Auto-generated destructor stub
}

/*void imagine::sim::menuItem::draw(sf::RenderWindow *window){
	window->draw(sprite);
	if(drawString){
		window->draw(itemName);
	}
}*/
