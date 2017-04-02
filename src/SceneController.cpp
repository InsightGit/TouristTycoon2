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

#include "SceneController.hpp"
#include <iostream>

imagine::mainMenu::mainMenu(){}

imagine::sceneController::sceneController() : displayWindow(sf::VideoMode(1368,768),"TouristTycoon"){
	//window=displayWindow;
	currentmainMenu = new mainMenu(fontLocation);
	currentmainMenu->spawn();
	//fullyInit = true;
}


/*bool imagine::sceneController::init(sf::RenderWindow *displayWindow): window(displayWindow){
	if(fullyInit){
		return false;
	}
	//window=displayWindow;
	fullyInit=true;
	currentmainMenu = new mainMenu(fontLocation);
	currentmainMenu->spawn();
	return true;
}*/

void imagine::sceneController::update(){
    currentScene->update(&displayWindow);
}

bool imagine::sceneController::draw(){
	//std::cout << fullyInit << ":" << useMainMenu <<  "\n";
	if(useMainMenu){
		displayWindow.clear(sf::Color::White);
        currentmainMenu->updateMenu();
		displayWindow.draw(currentmainMenu->startText);
		displayWindow.draw(currentmainMenu->loadGameText);
		displayWindow.draw(currentmainMenu->optionsText);
		displayWindow.draw(currentmainMenu->quitText);
		displayWindow.draw(currentmainMenu->activeCircle);
	}else{
	    displayWindow.clear(sf::Color::White);
		currentScene->draw(&displayWindow);
	}
    displayWindow.display();
	return true;
}

imagine::types::event imagine::sceneController::getEvent(){
	if(currentEvent!=imagine::types::none){
		if(eventTimes==0){
			eventTimes++;
		}else{
			eventTimes=0;
			currentEvent=imagine::types::none;
		}
		return currentEvent;
	}else{
		return imagine::types::none;
	}
}

bool imagine::sceneController::switchScene(scene *scene){
	currentScene=scene;
	if(currentScene->sceneNum!=0){
		useMainMenu=false;
	}
}
