/*
 * Switch.cpp
 *
 *  Created on: Mar 21, 2017
 *      Author: newbobby
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
