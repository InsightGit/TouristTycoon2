#include "MainMenu.hpp"
#include "SceneController.hpp"
#include <stdexcept>
#include <iostream>


imagine::scene::scene(){}


imagine::mainMenu::mainMenu(const std::string fontLocation){
	if(!defaultFont.loadFromFile(fontLocation)){
		throw std::runtime_error("Could not load font for mainMenu.");
	}
	if(imagine::core::doesFileExist(imagine::core::getApplicationDataDir()+"touristtycoon/saveFile.json")){
		optionSize=3;
	}else{
		optionSize=2;
	}
}

bool imagine::mainMenu::spawn(){
	startText.setPosition(300,300);
	if(imagine::core::doesFileExist(imagine::core::getApplicationDataDir()+"touristtycoon/saveFile.json")){
		loadGameText.setFont(defaultFont);
		loadGameText.setFillColor(sf::Color::Black);
		loadGameText.setCharacterSize(30);
		loadGameText.setStyle(sf::Text::Regular);
		loadGameText.setString("Load Game");
		loadGameText.setPosition(startText.getPosition().x,startText.getPosition().y+100);

		optionsText.setPosition(startText.getPosition().x,loadGameText.getPosition().y+100);
	}else{
		optionsText.setPosition(startText.getPosition().x,startText.getPosition().y+100);
	}
	startText.setFont(defaultFont);
	optionsText.setFont(defaultFont);
	quitText.setFont(defaultFont);

	startText.setFillColor(sf::Color::Green);

	optionsText.setFillColor(sf::Color::Cyan);
	quitText.setFillColor(sf::Color::Red);

	quitText.setPosition(startText.getPosition().x,optionsText.getPosition().y+100);

	startText.setCharacterSize(30);
	optionsText.setCharacterSize(30);
	quitText.setCharacterSize(30);

	startText.setStyle(sf::Text::Regular);
	optionsText.setStyle(sf::Text::Regular);
	quitText.setStyle(sf::Text::Regular);

	startText.setString("Start New Game");
	optionsText.setString("Options");
	quitText.setString("Quit");


	activeCircle.setPosition(200,300);

	return 0;
}

void imagine::mainMenu::onEnter(sceneController *sceneController){
	if(optionSize==3){
		if(activeCirclePosition==0){
			sceneController->currentEvent = imagine::types::newGame;
		}else if(activeCirclePosition==1){
			sceneController->currentEvent = imagine::types::loadGame;
		}
		else if(activeCirclePosition==3){
			sceneController->displayWindow.close();
		}
	}else{
		if(activeCirclePosition==0){
			sceneController->currentEvent = imagine::types::newGame;
		}else if(activeCirclePosition==2){
			sceneController->displayWindow.close();
		}
	}
	std::cout << optionSize << "\n";
	std::cout << activeCirclePosition << "\n";
}
