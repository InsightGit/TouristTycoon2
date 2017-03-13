#include "SimSidebar.hpp"
#include "Resources/saveicon.h"
#include "Resources/buildIcon.h"
#include "../ImagineCore.hpp"
#include <iostream>

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
    }
}

void imagine::sim::sidebar::update(sf::RenderWindow *window){
    if(saveIconSprite.isClicked(window)){
        whenClicked(imagine::sim::types::saveButton);
    }else if(buildIconSprite.isClicked(window)){
        whenClicked(imagine::sim::types::buildButton);
    }

}

bool imagine::sim::sidebar::display(sf::RenderWindow *window){
    window->draw(sideBarRect);
    window->draw(saveIconSprite.sprite);
    window->draw(buildIconSprite.sprite);
    if(sceneBuildMenuInit){
    	sceneBuildMenu->draw(window);
    }
    if(saveGameInit){
        simSaveGame->draw(window);
    }
    return true;
}
