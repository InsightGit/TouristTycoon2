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
