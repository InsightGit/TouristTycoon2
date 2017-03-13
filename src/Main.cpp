//============================================================================
// Name        : Main.cpp
// Author      : InfernoStudios
// Version     :
// Copyright   : Licensed under  the Apache License 2.0
// Description :
//============================================================================

#include <iostream>
#include <fstream>

#include "SceneController.hpp"
#include "ImagineCore.hpp"
#include "MainMenu.hpp"


int main() {
	if(imagine::core::isDebugBuild()){
		std::clog << "[DEBUG]Running Imagine Engine Game compiled for " << imagine::core::getPlatformString() << "\n";
		std::clog << "[DEBUG]Imagine Engine executable file found at " << imagine::core::getExecutablePath() << "\n";
	}
	imagine::sceneController sceneController;
	imagine::scene *currentScene;
	imagine::sim::player *player;
	//Json::Reader *JSONReader;
	//Json::Value *JSONDataValue;
	while(sceneController.displayWindow.isOpen()){
		sf::Event event;
		imagine::types::event imagineEvent;
		while(sceneController.displayWindow.pollEvent(event)){
			imagineEvent = sceneController.getEvent();
			if(event.type == sf::Event::Closed){
				sceneController.displayWindow.close();
			}
			if(sceneController.useMainMenu){
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
					sceneController.currentmainMenu->move(imagine::types::Up);
				}
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
					sceneController.currentmainMenu->move(imagine::types::Down);
				}
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
					sceneController.currentmainMenu->onEnter(&sceneController);
				}
			}

			if(imagineEvent != imagine::types::none){
				if(imagineEvent == imagine::types::newGame){
                    std::cout << "newGame\n";
					//const std::string path = imagine::core::getExecutablePath()+"/Resources/leveldata/scene1.json";
					/*if(JSONReader->parse(path,*JSONDataValue)){
						currentScene = new imagine::scene(1,JSONDataValue);
					}else{
						throw std::runtime_error("Could not parse JSON file scene1.json");
					}*/
					sf::Font fontToUse;
					if(!fontToUse.loadFromFile(sceneController.fontLocation)){
						throw imagine::exceptions::couldNotOpenFontFileException(sceneController.fontLocation);
					}
					player = new imagine::sim::player(&fontToUse);
					currentScene = new imagine::scene(1,&fontToUse,player);
					//currentScene->sceneHUD(currentScene->fontToUse,player);
					if(!currentScene->spawn()){
                        return 1;
					}
					sceneController.switchScene(currentScene);
				}else if(imagineEvent == imagine::types::loadGame){
					sf::Font fontToUse;
					//JSONReader = new Json::Reader();
					//JSONDataValue = new Json::Value();
					if(!fontToUse.loadFromFile(sceneController.fontLocation)){
						throw imagine::exceptions::couldNotOpenFontFileException(sceneController.fontLocation);
					}
					//std::cout << buffer.str() << "\n";
					player = new imagine::sim::player(&fontToUse);
					player->loadData();
					currentScene = new imagine::scene(1,&fontToUse,player);
					if(!currentScene->spawn()){
                        return 1;
					}
					sceneController.switchScene(currentScene);
				}
			}
		}
		sceneController.update();
		sceneController.draw();
	}
	return 0;
}
