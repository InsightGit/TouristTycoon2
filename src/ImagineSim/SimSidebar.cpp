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
#include "SimSidebar.hpp"

#include <iostream>

#include "../ImagineCore.hpp"

#include "AdvertMenu.hpp"
#include "BuildMenu.hpp"
#include "DeleteBuilding.hpp"
#include "SimSaveGame.hpp"

#include "Resources/saveicon.h"
#include "Resources/buildIcon.h"


imagine::sim::sidebar::sidebar(sf::Font *fontToUse, imagine::sim::player *mainPlayer, imagine::sim::helpBar *helpBarToUse,imagine::sim::actionArea *actionAreaToUse)
{
    //ctor
	defaultFont=*fontToUse;
	//progress=playerProgress;
	player=mainPlayer;
	helpBar=helpBarToUse;
	actionArea=actionAreaToUse;
};

imagine::sim::sidebar::~sidebar()
{
    //dtor
	delete simSaveGame;
	delete sceneBuildMenu;
	delete sceneAdvertMenu;
	delete sceneDeleteBuilding;
}

void imagine::sim::sidebar::spawn(){
    sideBarRect.setFillColor(sf::Color::Color(sf::Color::Color(187, 195, 189, 255)));
    sideBarRect.setPosition(sf::Vector2f(0,0));

    saveIconImage.create(saveIcon.width,saveIcon.height,saveIcon.pixel_data);
    saveIconTexture.loadFromImage(saveIconImage);
    saveIconSprite.sprite.setTexture(saveIconTexture);
    saveIconSprite.sprite.setPosition(sf::Vector2f(50,550));

    buildIconImage.create(buildIcon.width,buildIcon.height,buildIcon.pixel_data);
    buildIconTexture.loadFromImage(buildIconImage);
    buildIconSprite.sprite.setTexture(buildIconTexture);
    buildIconSprite.sprite.setPosition(sf::Vector2f(50,100));

    advertIconImage.create(advertIcon.width,advertIcon.height,advertIcon.pixel_data);
    advertIconTexture.loadFromImage(advertIconImage);
    advertIconSprite.sprite.setTexture(advertIconTexture);
    advertIconSprite.sprite.setPosition(sf::Vector2f(50,250));

    sceneDeleteBuilding = new imagine::sim::DeleteBuilding(player);
}

void imagine::sim::sidebar::whenClicked(imagine::sim::types::sidebarButton buttonPressed){
    if(buttonPressed==imagine::sim::types::saveButton){
        //start save Procedure.
        //if(imagine::core::isDebugBuild()){
    		if(!saveClickLimitSet){
    			saveGameClickLimit.restart();
    			saveClickLimitSet=true;

                std::cout << "Save button clicked.\n";
                simSaveGame = new imagine::sim::simSaveGame(player,&defaultFont);
                simSaveGame->launchSaveGameThread();
                saveGameInit=true;
    		}else if(saveGameClickLimit.getElapsedTime().asSeconds() >= 1){
    			saveClickLimitSet=false;
    		}

        //}
    }else if(buttonPressed==imagine::sim::types::buildButton){
        std::cout << "Build button clicked.\n";
		sceneBuildMenu = new imagine::sim::buildMenu(player,helpBar,actionArea,&defaultFont);
		sceneBuildMenu->spawn();
		sceneBuildMenuInit = true;
    }else if(buttonPressed==imagine::sim::types::advertButton && player->levelProgress.currentLevel >= 1){
    	std::cout << "Advert button clicked\n";
    	sceneAdvertMenu = new imagine::sim::advertMenu(player,&defaultFont);
    	sceneAdvertMenu->spawn();
    	sceneAdvertMenuInit = true;
    }else if(buttonPressed==imagine::sim::types::destroyButton){
    	std::cout << "Destroy button clicked\n";
    	sceneDeleteBuilding->whenClicked();
    }
}

void imagine::sim::sidebar::update(sf::RenderWindow *window){
    if(saveIconSprite.isClicked(window)){
        whenClicked(imagine::sim::types::saveButton);
    }else if(buildIconSprite.isClicked(window)){
        whenClicked(imagine::sim::types::buildButton);
    }else if(advertIconSprite.isClicked(window)){
    	whenClicked(imagine::sim::types::advertButton);
    }else if(sceneDeleteBuilding->button.isClicked(window)){
    	whenClicked(imagine::sim::types::destroyButton);
    }
}

bool imagine::sim::sidebar::display(sf::RenderWindow *window){
    window->draw(sideBarRect);
    window->draw(saveIconSprite.sprite);
    window->draw(buildIconSprite.sprite);
    if(player->levelProgress.currentLevel >= 1){
    	window->draw(advertIconSprite.sprite);
    }
    sceneDeleteBuilding->draw(window);
    if(sceneBuildMenuInit){
    	sceneBuildMenu->draw(window);
    }
    if(saveGameInit){
        simSaveGame->draw(window);
    }
    if(sceneAdvertMenuInit){
    	sceneAdvertMenu->draw(window);
    }
    return true;
}
