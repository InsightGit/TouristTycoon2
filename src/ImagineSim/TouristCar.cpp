/*
 * touristCar.cpp
 *
 *  Created on: Mar 7, 2017
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

#include "touristCar.hpp"


imagine::sim::touristCar::touristCar(const sf::Vector2f position) {
	// TODO Auto-generated constructor stub
	carSprite.setPosition(position);
}

imagine::sim::touristCar::~touristCar() {
	// TODO Auto-generated destructor stub
}

void imagine::sim::touristCar::spawn(){
	carImage.create(car.width,car.height,car.pixel_data);
	carTexture.loadFromImage(carImage);
	carSprite.setTexture(carTexture);

	display=true;
}

void imagine::sim::touristCar::draw(sf::RenderWindow *window){
	if(display){
		window->draw(carSprite);
	}
}
