/*
 * confirmationPopUp.cpp
 *
 *  Created on: Mar 5, 2017
 *      Author: newbobby
 */

#include "ConfirmationPopUp.hpp"

imagine::sim::confirmationPopUp::confirmationPopUp(const std::string messageToUse,sf::Font *fontToUse, sf::Vector2f position) {
	// TODO Auto-generated constructor stub
	defaultFont=*fontToUse;

	//spawn code
	messageBox.setPosition(position);
	messageBox.setFillColor(sf::Color(233,100,54,230));

	message.setFont(defaultFont);
	message.setPosition(sf::Vector2f(position.x+50,position.y+10));
	message.setString(messageToUse);
	message.setFillColor(sf::Color::Red);
	message.setCharacterSize(16);

	yesButton.optionalImage = new sf::Image();
	yesButton.optionalImage->create(yesButtonImageFile.width,yesButtonImageFile.height,yesButtonImageFile.pixel_data);
	yesButton.optionalTexture = new sf::Texture();
	yesButton.optionalTexture->loadFromImage(*yesButton.optionalImage);
	yesButton.sprite.setPosition(sf::Vector2f(position.x+20,position.y+76));
	yesButton.sprite.setTexture(*yesButton.optionalTexture);

	noButton.optionalImage = new sf::Image();
	noButton.optionalImage->create(noButtonImageFile.width,noButtonImageFile.height,noButtonImageFile.pixel_data);
	noButton.optionalTexture = new sf::Texture();
	noButton.optionalTexture->loadFromImage(*yesButton.optionalImage);
	noButton.sprite.setPosition(sf::Vector2f(position.x+100,position.y+76));
	noButton.sprite.setTexture(*yesButton.optionalTexture);
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
