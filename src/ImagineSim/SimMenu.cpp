/*
 * SimMenu.cpp
 *
 *  Created on: Mar 20, 2017
 *      Author: newbobby
 */

#include "SimMenu.hpp"

imagine::sim::SimMenu::SimMenu(const sf::Vector2f size,const sf::Vector2f position,const sf::Color fillColor) {
	// TODO Auto-generated constructor stub
	menuBox.setSize(size);
	menuBox.setPosition(position);
	menuBox.setFillColor(fillColor);
}

imagine::sim::SimMenu::SimMenu(const sf::Vector2f size,const sf::Vector2f position,std::string titleText, sf::Font *fontToUse, const sf::Color fillColor){
	menuBox.setSize(size);
	menuBox.setPosition(position);
	menuBox.setFillColor(fillColor);

	defaultFont = *fontToUse;
	title.setFont(defaultFont);
	title.setCharacterSize(20);
	title.setFillColor(sf::Color::Black);
	title.setPosition(sf::Vector2f(position.x+size.x/2,position.y/10));
}

imagine::sim::SimMenu::~SimMenu() {
	// TODO Auto-generated destructor stub
}
