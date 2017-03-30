/*
 * ActionArea.cpp
 *
 *  Created on: Feb 25, 2017
 *      Author: bobby
 */

#include "ActionArea.hpp"
#include "Resources/SmallGrass.h"
#include "../ImagineCore.hpp"
#include <string>

imagine::sim::actionArea::actionArea() {
	// TODO Auto-generated constructor stub
}
imagine::sim::actionArea::actionArea(Json::Value saveGameData){
	gameData=saveGameData;
	newGame=false;
}

imagine::sim::actionArea::~actionArea() {
	// TODO Auto-generated destructor stub
}

void imagine::sim::actionArea::spawn(){
	grassImage.create(smallGrass.width,smallGrass.height,smallGrass.pixel_data);
	repeatingGrassTexture.setRepeated(true);
	repeatingGrassTexture.loadFromImage(grassImage);
	repeatingGrassSprite.setTexture(repeatingGrassTexture);
	repeatingGrassSprite.setTextureRect({-1500,-1500,1500,1500});
	repeatingGrassSprite.setPosition(sf::Vector2f(200,100));
	if(!newGame){
		if(gameData.get("saveGameType","NONE").asString() == "TouristTycoon"){
			const Json::Value buildingList = gameData["buildings"];
			for(int i = 0; i < buildingList.size(); i++){
				const Json::Value id = buildingList[i]["id"];
				if(id.empty()){
					throw imagine::exceptions::invalidSaveFileException("id==NULL for Building #"+i);
				}else{
					const int idInt = id.asInt();
					switch(idInt){
						case 1:
							const Json::Value direction = buildingList[i]["direction"];
							const Json::Value x = buildingList[i]["xPos"];
							const Json::Value y = buildingList[i]["yPos"];
							if(direction.empty()){
								throw imagine::exceptions::invalidSaveFileException("direction==NULL for Building #"+i);
							}else if(x.empty()){
								throw imagine::exceptions::invalidSaveFileException("xPos==NULL for Building #"+i);
							}else if(y.empty()){
								throw imagine::exceptions::invalidSaveFileException("yPos==NULL for Building #"+i);
							}
							imagine::sim::road *newRoad;
							if(direction.asString()=="straight"){
								newRoad = new imagine::sim::road(imagine::sim::types::straight,sf::Vector2f(x.asFloat(),y.asFloat()));
								break;
							}else if(direction.asString()=="leftToDown"){
								newRoad = new imagine::sim::road(imagine::sim::types::leftToDown,sf::Vector2f(x.asFloat(),y.asFloat()));
								break;
							}else if(direction.asString()=="rightToDown"){
								newRoad = new imagine::sim::road(imagine::sim::types::rightToDown,sf::Vector2f(x.asFloat(),y.asFloat()));
								break;
							}else if(direction.asString()=="leftToUp"){
								newRoad = new imagine::sim::road(imagine::sim::types::leftToUp,sf::Vector2f(x.asFloat(),y.asFloat()));
								break;
							}else if(direction.asString()=="rightToUp"){
								newRoad = new imagine::sim::road(imagine::sim::types::rightToUp,sf::Vector2f(x.asFloat(),y.asFloat()));
								break;
							}
					}
				}
			}
		}else{
			throw imagine::exceptions::invalidSaveFileException("saveGameType != TouristTycoon");
		}
	}
}

void imagine::sim::actionArea::update(){
	if(!limitKeyboardPressesSet){
		limitKeyboardPresses.restart();
		limitKeyboardPressesSet = true;

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
			actionAreaView.move(sf::Vector2f(0,-100));
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
			actionAreaView.move(sf::Vector2f(0,100));
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
			actionAreaView.move(sf::Vector2f(-100,0));
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
			actionAreaView.move(sf::Vector2f(100,0));
		}
	}else if(limitKeyboardPresses.getElapsedTime().asSeconds() >= 0.1){
		limitKeyboardPressesSet = false;
	}
}

void imagine::sim::actionArea::draw(sf::RenderWindow *window){
	update();

	window->draw(repeatingGrassSprite);

}
