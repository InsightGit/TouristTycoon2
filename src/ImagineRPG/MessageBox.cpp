#include "MessageBox.hpp"

imagine::RPG::messageBox::messageBox(sf::Font defaultFont,std::vector<std::string> messagesToDisplay){
	messageFont = defaultFont;
	messages = messagesToDisplay;
	messageSize = messages.size();
	if(!messageBoxTexture.loadFromFile(imagine::core::getExecutablePath()+"/Resources/images/messageBox.png")){
		throw std::runtime_error("Could not load messageBox.png");
	}
	if(messages[currentMessage] != std::string(NULL)){
		message.setFont(defaultFont);
		message.setFillColor(sf::Color::Green);
		message.setCharacterSize(16);
		message.setStyle(sf::Text::Regular);
		message.setString(sf::String(messages[currentMessage]));
	}else{
		//
	}
	messageBoxSprite.setPosition(sf::Vector2f(384,500));
	message.setPosition(sf::Vector2f(messageBoxSprite.getPosition().x+50,messageBoxSprite.getPosition().y+134));
}

void imagine::RPG::messageBox::onNext(){
	currentMessage++;
	if(messages[currentMessage] != std::string(NULL)){
		message.setFont(messageFont);
		message.setFillColor(sf::Color::Green);
		message.setCharacterSize(16);
		message.setStyle(sf::Text::Regular);
		message.setString(sf::String(messages[currentMessage]));
	}else{
		messageBoxSprite.setPosition(sf::Vector2f(-1000000,-1000000));
	}
}
