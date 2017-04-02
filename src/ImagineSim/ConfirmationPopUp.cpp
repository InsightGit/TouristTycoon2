/*
 * confirmationPopUp.cpp
 *
 *  Created on: Mar 5, 2017
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


#include "ConfirmationPopUp.hpp"

imagine::sim::confirmationPopUp::confirmationPopUp(const std::string messageToUse,sf::Font *fontToUse, const int charSize, const sf::Vector2f position) {
	// TODO Auto-generated constructor stub
	defaultFont=*fontToUse;

	//spawn code
	messageBox.setPosition(position);
	messageBox.setFillColor(sf::Color(233,100,54,230));

	message.setFont(defaultFont);
	message.setPosition(sf::Vector2f(position.x+10,position.y+10));
	message.setString(messageToUse);
	message.setFillColor(sf::Color::Blue);
	message.setCharacterSize(charSize);

	yesButton.optionalImage = new sf::Image();
	yesButton.optionalImage->create(yesButtonImageFile.width,yesButtonImageFile.height,yesButtonImageFile.pixel_data);
	yesButton.optionalTexture = new sf::Texture();
	yesButton.optionalTexture->loadFromImage(*yesButton.optionalImage);
	yesButton.sprite.setPosition(sf::Vector2f(position.x+20,position.y+76));
	yesButton.sprite.setTexture(*yesButton.optionalTexture);

	noButton.optionalImage = new sf::Image();
	noButton.optionalImage->create(noImageFile.width,noImageFile.height,noImageFile.pixel_data);
	noButton.optionalTexture = new sf::Texture();
	noButton.optionalTexture->loadFromImage(*noButton.optionalImage);
	noButton.sprite.setPosition(sf::Vector2f(position.x+100,position.y+76));
	noButton.sprite.setTexture(*noButton.optionalTexture);
	popUpDraw=true;
}

imagine::sim::confirmationPopUp::~confirmationPopUp() {
	// TODO Auto-generated destructor stub
}

void imagine::sim::confirmationPopUp::update(sf::RenderWindow *window){
	if(yesButton.isClicked(window)){
		response=imagine::sim::types::yes;
		popUpDraw=false;
	}else if(noButton.isClicked(window)){
		response=imagine::sim::types::no;
		popUpDraw=false;
	}
}

void imagine::sim::confirmationPopUp::draw(sf::RenderWindow *window){
	update(window);
	if(popUpDraw){
		window->draw(messageBox);
		window->draw(message);
		window->draw(noButton.sprite);
		window->draw(yesButton.sprite); //LOVE TRUMPS HATE!
	}
}
