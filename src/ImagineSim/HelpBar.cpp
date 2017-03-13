#include "HelpBar.hpp"

imagine::sim::helpBar::helpBar(sf::Font *fontToUse)
{
    //ctor
    defaultFont = *fontToUse;

    helpBarRect.setFillColor(sf::Color::Color(187, 195, 189, 255));
    helpBarRect.setPosition(sf::Vector2f(0,718));

    helpText.setFont(defaultFont);
    helpText.setCharacterSize(30);
    helpText.setPosition(sf::Vector2f(20,728));
    helpText.setString(message);
}

imagine::sim::helpBar::helpBar(sf::Font *fontToUse, const std::string customMessage){
    message = customMessage;
    defaultFont = *fontToUse;

    helpBarRect.setFillColor(sf::Color::Color(187, 195, 189, 255));
    helpBarRect.setPosition(sf::Vector2f(0,718));

    helpText.setFont(defaultFont);
    helpText.setCharacterSize(30);
    helpText.setPosition(sf::Vector2f(20,728));
    helpText.setString(message);
}

imagine::sim::helpBar::~helpBar()
{
    //dtor
}

void imagine::sim::helpBar::switchMessage(std::string helpMessage){
	previousMessage=message;
    message=helpMessage;
    helpText.setString(message);
}

void imagine::sim::helpBar::switchToPreviousMessage(){
	if(previousMessageCallLimit.getElapsedTime().asSeconds() >= 1){
		previousMessageLimitSet=false;
	}
	if(!previousMessageLimitSet){
		previousMessageCallLimit.restart();
		previousMessageLimitSet = true;
		message=previousMessage;
		helpText.setString(message);
	}
}

std::string imagine::sim::helpBar::getMessage(){
    return message;
}

std::string imagine::sim::helpBar::getPreviousMessage(){
    return previousMessage;
}

void imagine::sim::helpBar::draw(sf::RenderWindow *window){
    window->draw(helpBarRect);
    window->draw(helpText);
}
