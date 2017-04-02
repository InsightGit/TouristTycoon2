/*
 * levelCompletePopUp.cpp
 *
 *  Created on: Mar 6, 2017
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


#include "levelCompletePopUp.hpp"
#include "Resources/levelUpTemplate.h"
#include "../Resources/okButton.h"


imagine::sim::levelCompletePopUp::levelCompletePopUp(const sf::Vector3i howManyNewItems, const std::string messageToDisplay,sf::Font *fontToUse,const sf::Vector2f position) {
	// TODO Auto-generated constructor stub

	defaultFont=*fontToUse;
	message.setFont(defaultFont);
	unlockMessage.setFont(defaultFont);

	unlockText = "You have unlocked";

	if(howManyNewItems.x!=-1){
		newAttractions=howManyNewItems.x;
		unlockedAnything=true;
		unlockText.append(" "+std::to_string(newAttractions)+" Attractions");
	}
	if(howManyNewItems.y!=-1){
		newRoads=howManyNewItems.y;
		unlockedAnything=true;
		unlockText.append(" "+std::to_string(newRoads)+" Roads");
	}
	if(howManyNewItems.z!=-1){
		newServices=howManyNewItems.z;
		unlockedAnything=true;
		unlockText.append(" "+std::to_string(newServices)+" Services");
	}
	if(unlockedAnything){
		unlockText.append(".");
	}

	templateImage.create(levelUpTemplate.width,levelUpTemplate.height,levelUpTemplate.pixel_data);
	templateTexture.loadFromImage(templateImage);

	templateSprite.setTexture(templateTexture);
	templateSprite.setPosition(position);

	message.setCharacterSize(20);
	unlockMessage.setCharacterSize(13);

	message.setFillColor(sf::Color(255,193,77,255));
	unlockMessage.setFillColor(sf::Color(43,107,255,255));

	message.setString(messageToDisplay);
	if(unlockedAnything){
		unlockMessage.setString(unlockText);
	}

	message.setPosition(sf::Vector2f(position.x+75,position.y+80));
	unlockMessage.setPosition(sf::Vector2f(position.x+120,position.y+30));

	okButton.optionalImage = new sf::Image();
	okButton.optionalTexture = new sf::Texture();
	okButton.optionalImage->create(okButtonImage.width,okButtonImage.height,okButtonImage.pixel_data);
	okButton.optionalTexture->loadFromImage(*okButton.optionalImage);

	okButton.sprite.setTexture(*okButton.optionalTexture);
	okButton.sprite.setPosition(sf::Vector2f(position.x+128,position.y+128));

	drawPopUp=true;
}

imagine::sim::levelCompletePopUp::~levelCompletePopUp() {
	// TODO Auto-generated destructor stub
}

bool imagine::sim::levelCompletePopUp::getDrawingStatus(){
	return drawPopUp;
}

void imagine::sim::levelCompletePopUp::update(sf::RenderWindow *window){
	if(okButton.isClicked(window)){
		drawPopUp=false;
	}
}

void imagine::sim::levelCompletePopUp::draw(sf::RenderWindow *window){\
	update(window);
	if(drawPopUp){
		window->draw(templateSprite);
		window->draw(message);
		//window->draw(unlockMessage);
		window->draw(okButton.sprite);
	}
}
