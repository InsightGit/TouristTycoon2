/*
 * touristCar.cpp
 *
 *  Created on: Mar 7, 2017
 *      Author: newbobby
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
