/*
 * PopUp.cpp
 *
 *  Created on: Feb 28, 2017
 *      Author: newbobby
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
