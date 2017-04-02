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
