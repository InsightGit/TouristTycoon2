/*
 * SimSaveGame.cpp
 *
 *  Created on: Mar 2, 2017
 *      Author: newbobby
 */

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


#include "SimSaveGame.hpp"
#include <iostream>


imagine::sim::simSaveGame::simSaveGame(imagine::sim::player *playerToUse,const sf::Font *fontToUse, const std::string saveLocation) {
	// TODO Auto-generated constructor stub
	player=playerToUse;
	saveFileLocation=saveLocation;
	defaultFont=*fontToUse;
	saveGameStarted=false;
}

imagine::sim::simSaveGame::~simSaveGame() {
	// TODO Auto-generated destructor stub
}

void imagine::sim::simSaveGame::save(){
	saveFileRoot.append(player->getReadySaveData());
	saveGameStarted=true;
	if(imagine::core::getPlatform() == imagine::types::win32){
		//CreateDirectory(saveFileLoc,NULL);
	}else{
		std::cout << std::to_string(mkdir(saveFileLocation.c_str(),0777)) << "\n";
	}
	std::ofstream *tempSave = new std::ofstream(saveFileLocation+"/saveFile.json");
	Json::StyledWriter *tempWriter = new Json::StyledWriter();
	if(!tempSave->is_open()){
		throw imagine::exceptions::couldNotOpenSaveFile(saveFileLocation+"/saveFile.json");
	}
	*tempSave << std::string(tempWriter->write(saveFileRoot));

	tempSave->close();

	delete tempWriter,tempSave;
	saveResult=0;
}

void imagine::sim::simSaveGame::launchSaveGameThread(){
	saveGameThread = std::thread(&imagine::sim::simSaveGame::save,this);
}

void imagine::sim::simSaveGame::update(){
	/*if(!saveGameThreadStarted){
		launchSaveGameThread();
	}*/
	//std::cout << saveGameThreadStarted << "\n";
	if(saveGameStarted && !drawSavePopUp){
		if(saveResult==0){
			savePopUp = new imagine::sim::popUp("Saved game",&defaultFont);
			drawSavePopUp = true;
		}
	}
}

void imagine::sim::simSaveGame::draw(sf::RenderWindow *window){
	//
	update();
	if(drawSavePopUp){
		savePopUp->draw(window);
	}
}
/*void imagine::sim::simSaveGame::saveGameThreadFunction(){

}*/
