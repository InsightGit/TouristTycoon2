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


#ifndef __SIMHUD_CPP__
#define __SIMHUD_CPP__
#include "SimHUD.hpp"
#include "Advertisement.hpp"
#include "Resources/MoneySign.h"
//#include "Resources/TouristSign.h"
//#include "Resources/personNew.h"
#include "Resources/cal.h"
#include <string>
#include <iostream>

imagine::sim::HUD::HUD(sf::Font *fontToUse,player *currentPlayer){
	defaultFont = *fontToUse;
	mainPlayer = currentPlayer;
	//int desktopModeWidth = sf::VideoMode::getDesktopMode().width;
	HUDRectangle = sf::RectangleShape(sf::Vector2f(1368,100));
	HUDRectangle.setFillColor(sf::Color::Color(187, 195, 189, 255));
	HUDRectangle.setPosition(sf::Vector2f(0,0));

	moneyImage.create(moneySign.width,moneySign.height,moneySign.pixel_data);
	moneyIcon.loadFromImage(moneyImage);

	moneySprite.setTexture(moneyIcon);
	moneySprite.setScale(0.5,0.5);
	moneySprite.setPosition(sf::Vector2f(200,25));

	moneyCounter.setFont(defaultFont);
	moneyCounter.setCharacterSize(30);
	moneyCounter.setString(std::to_string(mainPlayer->money));
	moneyCounter.setPosition(sf::Vector2f(350,25));

	moneyCounter.setCharacterSize(30);
	if(mainPlayer->money>1000){
		moneyCounter.setFillColor(sf::Color::Black);
	}else if(mainPlayer->money<0){
		moneyCounter.setFillColor(sf::Color::Red);
	}else{
		moneyCounter.setFillColor(sf::Color::Yellow);
	}
	touristSymbolImage.create(personNew.width,personNew.height,personNew.pixel_data);

	touristSymbolTexture.loadFromImage(touristSymbolImage);

	touristSymbol.setTexture(touristSymbolTexture);
	touristSymbol.setScale(0.5,0.5);
	touristSymbol.setPosition(sf::Vector2f(600,25));

	activeTouristCount.setFont(defaultFont);
	activeTouristCount.setCharacterSize(30);
	activeTouristCount.setString(std::to_string(mainPlayer->activeTourists));
	activeTouristCount.setPosition(sf::Vector2f(750,25));

	calSymbolImage.create(cal.width,cal.height,cal.pixel_data);

	calSymbolTexture.loadFromImage(calSymbolImage);

	calSymbol.setTexture(calSymbolTexture);
	calSymbol.setScale(0.5,0.5);
	calSymbol.setPosition(sf::Vector2f(850,25));

	dateText.setFont(defaultFont);
	dateText.setCharacterSize(30);
	dateText.setString(std::to_string(mainPlayer->playerDate->getMonth())+"/"+std::to_string(mainPlayer->playerDate->getDay())+"/"+std::to_string(mainPlayer->playerDate->getYear()));
	dateText.setPosition(sf::Vector2f(1000,25));

}

imagine::sim::HUD::HUD(const std::string fontToUseLocation,player *currentPlayer){
	if(!defaultFont.loadFromFile(fontToUseLocation)){
		//throw imagine::exceptions::couldNotOpenFontFileException(fontToUseLocation);
		throw std::runtime_error("could not open font for HUD");                         //CHANGE                                                                                                                                                                   !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	}

	mainPlayer = currentPlayer;
	HUDRectangle = sf::RectangleShape(sf::Vector2f(1368,100));
	HUDRectangle.setFillColor(sf::Color::Color(187, 195, 189, 1));
	HUDRectangle.setPosition(sf::Vector2f(0,0));

	moneyImage.create(moneySign.width,moneySign.height,moneySign.pixel_data);
	moneyIcon.loadFromImage(moneyImage);

	moneySprite.setTexture(moneyIcon);
	moneySprite.setScale(0.5,0.5);
	moneySprite.setPosition(sf::Vector2f(200,25));

	moneyCounter.setFont(defaultFont);
	moneyCounter.setCharacterSize(30);
	moneyCounter.setString(std::to_string(mainPlayer->money));
	moneyCounter.setPosition(sf::Vector2f(350,25));

	moneyCounter.setCharacterSize(30);
	if(mainPlayer->money>1000){
		moneyCounter.setFillColor(sf::Color::Black);
	}else if(mainPlayer->money<0){
		moneyCounter.setFillColor(sf::Color::Red);
	}else{
		moneyCounter.setFillColor(sf::Color::Yellow);
	}
	touristSymbolImage.create(personNew.width,personNew.height,personNew.pixel_data);

	touristSymbolTexture.loadFromImage(touristSymbolImage);

	touristSymbol.setTexture(touristSymbolTexture);
	touristSymbol.setScale(0.5,0.5);
	touristSymbol.setPosition(sf::Vector2f(400,25));

	activeTouristCount.setFont(defaultFont);
	activeTouristCount.setCharacterSize(30);
	activeTouristCount.setString(std::to_string(mainPlayer->activeTourists));
	activeTouristCount.setPosition(sf::Vector2f(550,25));

	calSymbolImage.create(cal.width,cal.height,cal.pixel_data);

	calSymbolTexture.loadFromImage(calSymbolImage);

	calSymbol.setTexture(calSymbolTexture);
	calSymbol.setScale(0.5,0.5);
	calSymbol.setPosition(sf::Vector2f(700,25));

	dateText.setFont(defaultFont);
	dateText.setCharacterSize(30);
	dateText.setString(std::to_string(mainPlayer->playerDate->getMonth())+"/"+std::to_string(mainPlayer->playerDate->getDay())+"/"+std::to_string(mainPlayer->playerDate->getYear()));
	dateText.setPosition(sf::Vector2f(850,25));

}

void imagine::sim::HUD::update(){
	moneyCounter.setString(std::to_string(mainPlayer->money));
	activeTouristCount.setString(std::to_string(mainPlayer->activeTourists));
	dateText.setString(std::to_string(mainPlayer->playerDate->getMonth())+"/"+std::to_string(mainPlayer->playerDate->getDay())+"/"+std::to_string(mainPlayer->playerDate->getYear()));
}

void imagine::sim::HUD::display(sf::RenderWindow *window){
	update();
    window->draw(HUDRectangle);

	window->draw(dateText);
	window->draw(activeTouristCount);
	window->draw(moneyCounter);

	window->draw(calSymbol);
	window->draw(touristSymbol);
	window->draw(moneySprite);
}
#endif
