#include "Scene.hpp"
#include "MainMenu.hpp"
#include <iostream>



imagine::scene::scene(const int windowSceneNum,sf::Font *fontToUse, imagine::sim::player *mainPlayer){
	sceneNum = windowSceneNum;
	defaultFont=*fontToUse;
	playerInScene=mainPlayer;
}

imagine::scene::scene(const int windowSceneNum,const Json::Value *JSONSceneData,const sf::Font *fontToUse, imagine::sim::player *mainPlayer){
	sceneData = *JSONSceneData;
	sceneNum = windowSceneNum;
	defaultFont=*fontToUse;
	playerInScene=mainPlayer;
}

bool imagine::scene::spawn(){
	if(useJSONData){
		//JSONloop here
	}else if(!useJSONData){
		if(sceneNum==0){
			return true;
		}
		else if(sceneNum==1){
			sceneHUD = new imagine::sim::HUD(&defaultFont,playerInScene);
			sceneHelpBar = new imagine::sim::helpBar(&defaultFont);
			sceneActionArea = new imagine::sim::actionArea();
			sceneActionArea->spawn();
			sceneSidebar = new imagine::sim::sidebar(&defaultFont,playerInScene,sceneHelpBar,sceneActionArea);
			sceneSidebar->spawn();
			std::vector<std::string> musicTracks = {"1.ogg"};
			musicPlayer = new imagine::sceneMusicPlayer(musicTracks,1);
			musicPlayer->play();
			return true;
		}
	}
}

void imagine::scene::update(sf::RenderWindow *window){
    //std::cout << sceneNum << "\n";
    if(sceneNum==1){
        sceneSidebar->update(window);
        playerInScene->time->update();
        playerInScene->touristSpawner->spawnTourists(playerInScene->numberOfAttractionsSpawned,playerInScene->numberOfAdvertisementsSpawned);
        for(int i = 0;playerInScene->tourists > i; ++i){
        	playerInScene->touristsSpawned[i].draw(window);
        }
    }
}

void imagine::scene::draw(sf::RenderWindow *window){
    if(sceneNum==1){
    	window->setView(sceneActionArea->actionAreaView);
    	sceneActionArea->draw(window); //TODO: When porting to windows in Visual Studio disable SDL checks
    	for(int i = 0;playerInScene->numberOfRoadsSpawned > i;i++){
    		window->draw(playerInScene->roadsCreated[i].tileSprite);                 //NOT THIS WAY
    	}
    	for(int i = 0;playerInScene->numberOfAttractionsSpawned > i;i++){
    		playerInScene->attractionsCreated[i].draw(window);                         //THIS WAY
    	}
    	window->setView(window->getDefaultView());
        sceneHUD->display(window);
        sceneSidebar->display(window);
        sceneHelpBar->draw(window);
        playerInScene->display(window);
    }
}
