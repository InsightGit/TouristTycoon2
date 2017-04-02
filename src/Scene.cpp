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
			/*std::vector<std::string> musicTracks = {"1.ogg"};
			musicPlayer = new imagine::sceneMusicPlayer(musicTracks,1);
			musicPlayer->play();*/
			if(!music.openFromFile("1.ogg")){
				throw imagine::exceptions::couldNotOpenMusicFile("1.ogg");
			}
			music.play();
			music.setLoop(true);
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
        	playerInScene->touristsSpawned[i].Draw(window);
        }

    	for(int i = 0;playerInScene->numberOfRoadsSpawned > i;++i){
    		playerInScene->roadsCreated[i].subtractMaintainceCost(playerInScene,&playerInScene->time->getSimTime());
    	}
    	for(int i = 0;playerInScene->numberOfAttractionsSpawned > i;++i){
    		playerInScene->attractionsCreated[i].subtractMaintainceCost(playerInScene,&playerInScene->time->getSimTime());
    	}
    	for(int i = 0;playerInScene->numberOfHotelsSpawned > i;++i){
    		playerInScene->hotelsCreated[i].subtractMaintainceCost(playerInScene,&playerInScene->time->getSimTime());
    	}
    	for(int i = 0;playerInScene->numberOfRestaurantsSpawned > i;++i){
    		playerInScene->restaurantsCreated[i].subtractMaintainceCost(playerInScene,&playerInScene->time->getSimTime());
    	}
    	for(int i = 0;playerInScene->numberOfPoliceStationsSpawned > i;++i){
    		playerInScene->policeStationsCreated[i].subtractMaintainceCost(playerInScene,&playerInScene->time->getSimTime());
    	}
    	if(playerInScene->townHallSpawned){
        	playerInScene->townHall->subtractMaintainceCost(playerInScene,&playerInScene->time->getSimTime());
    	}
    	if(playerInScene->publicTransport.cruiseTerminalSpawned){
    		playerInScene->publicTransport.currentCruiseTerminal.subtractMaintainceCost(playerInScene,&playerInScene->time->getSimTime());
    	}
    	/*if(music.getStatus() != sf::Music::Playing){
    		music.
    	}*/
    	//if()
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
    	for(int i = 0;playerInScene->numberOfHotelsSpawned > i;i++){
    		playerInScene->hotelsCreated[i].draw(window);
    	}
    	for(int i = 0;playerInScene->numberOfRestaurantsSpawned > i;i++){
    		playerInScene->restaurantsCreated[i].draw(window);
    	}
    	for(int i = 0;playerInScene->numberOfPoliceStationsSpawned > i;++i){
    		playerInScene->policeStationsCreated[i].draw(window);
    	}
    	if(playerInScene->townHallSpawned){
    		playerInScene->townHall->draw(window);
    	}
    	if(playerInScene->publicTransport.cruiseTerminalSpawned){
    		playerInScene->publicTransport.currentCruiseTerminal.draw(window);
    	}
    	window->setView(window->getDefaultView());
        sceneHUD->display(window);
        sceneSidebar->display(window);
        sceneHelpBar->draw(window);
        playerInScene->display(window);
    }
}
