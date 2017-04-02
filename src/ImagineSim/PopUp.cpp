/*
 * PopUp.cpp
 *
 *  Created on: Feb 28, 2017
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


#include "PopUp.hpp"
#include "../Resources/okButton.h"


imagine::sim::popUp::popUp(const std::string messageToDisplay, const sf::Font *fontToUse,sf::Vector2f position) {
	// TODO Auto-generated constructor stub
	defaultFont=*fontToUse;
	messageDisplayed=messageToDisplay;

	//spawn code
	messageBox.setPosition(position);
	messageBox.setFillColor(sf::Color(233,100,54,230));

	message.setFont(defaultFont);
	message.setPosition(sf::Vector2f(position.x+10,position.y+10));
	message.setString(messageDisplayed);
	message.setFillColor(sf::Color::Green);
	message.setCharacterSize(12);

	okButton.optionalImage = new sf::Image();
	okButton.optionalImage->create(okButtonImage.width,okButtonImage.height,okButtonImage.pixel_data);
	okButton.optionalTexture = new sf::Texture();
	okButton.optionalTexture->loadFromImage(*okButton.optionalImage);

	okButton.sprite.setPosition(sf::Vector2f(position.x+50,position.y+76));
	okButton.sprite.setTexture(*okButton.optionalTexture);
	popUpDraw=true;
}

imagine::sim::popUp::~popUp() {
	// TODO Auto-generated destructor stub
	delete okButton.optionalImage,okButton.optionalTexture;
}

void imagine::sim::popUp::update(sf::RenderWindow *window){
	if(okButton.isClicked(window)){
		popUpDraw=false;
	}
}

void imagine::sim::popUp::draw(sf::RenderWindow *window){
	update(window);
	if(popUpDraw){
		window->draw(messageBox);
		window->draw(message);
		window->draw(okButton.sprite);
	}
}
