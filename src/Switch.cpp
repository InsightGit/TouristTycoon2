/*
 * Switch.cpp
 *
 *  Created on: Mar 21, 2017
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

#include "Switch.hpp"

imagine::Switch::Switch(const sf::Vector2f position) {
	// TODO Auto-generated constructor stub
	yes.sprite.setPosition(position);
	no.sprite.setPosition(sf::Vector2f(position.x+64,position.y));

	yes.optionalImage = new sf::Image();
	yes.optionalTexture = new sf::Texture();
	no.optionalImage = new sf::Image();
	no.optionalTexture = new sf::Texture();

	yes.optionalImage->create(activeButtonNotImageFile.width,activeButtonNotImageFile.height,activeButtonNotImageFile.pixel_data);
	no.optionalImage->create(noButtonImageFile.width,noButtonImageFile.height,noButtonImageFile.pixel_data);

	yes.optionalTexture->loadFromImage(*yes.optionalImage);
	no.optionalTexture->loadFromImage(*no.optionalImage);

	yes.sprite.setTexture(*yes.optionalTexture);
	no.sprite.setTexture(*no.optionalTexture);
}

imagine::Switch::~Switch() {
	// TODO Auto-generated destructor stub
}

void imagine::Switch::update(sf::RenderWindow *window){
	if(yes.isClicked(window) && !switchOn){
		yes.optionalImage->create(activeButtonImageFile.width,activeButtonImageFile.height,activeButtonImageFile.pixel_data);
		no.optionalImage->create(noButtonNotImageFile.width,noButtonNotImageFile.height,noButtonNotImageFile.pixel_data);
		switchOn=true;
		std::cout << "Switch is on\n";
	}else if(no.isClicked(window) && switchOn){
		yes.optionalImage->create(activeButtonNotImageFile.width,activeButtonNotImageFile.height,activeButtonNotImageFile.pixel_data);
		no.optionalImage->create(noButtonImageFile.width,noButtonImageFile.height,noButtonImageFile.pixel_data);
		switchOn=false;
		std::cout << "Switch is off\n";
	}
}

void imagine::Switch::draw(sf::RenderWindow *window){
	update(window);

	yes.optionalTexture->loadFromImage(*yes.optionalImage);
	no.optionalTexture->loadFromImage(*no.optionalImage);

	yes.sprite.setTexture(*yes.optionalTexture);
	no.sprite.setTexture(*no.optionalTexture);

	window->draw(yes.sprite);
	window->draw(no.sprite);
}
