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
#include "ImagineSaveGame.hpp"

imagine::saveGame::saveGame(){

}

imagine::saveGame::saveGame(const std::string saveFileLocation){
	saveFileLoc=saveFileLocation;
	std::ifstream file(saveFileLoc);
	std::stringstream buffer;
	buffer << file.rdbuf();
	saveFileRoot = Json::Value(buffer.str());
	motd = saveFileRoot["motd"];
	/*if(int(motd)==nullptr){
		throw imagine::exceptions::saveFileMotdNotFoundException(saveFileLoc);
	}*/
}

bool imagine::saveGame::isOverwritingExistingSave(){
	return access(saveFileLoc.c_str(),0) == 0;
}

void imagine::saveGame::save(){
	if(imagine::core::getPlatform() == imagine::types::win32){
		//CreateDirectory(saveFileLoc,NULL);
	}else{
		mkdir(saveFileLoc.c_str(),S_IRWXU);
	}
	std::ofstream *tempSave = new std::ofstream(saveFileLoc+"saveFile.json");
	Json::StyledWriter *tempWriter = new Json::StyledWriter();
	if(!tempSave->is_open()){
		throw imagine::exceptions::couldNotOpenSaveFile(saveFileLoc+"saveFile.json");
	}
	*tempSave << std::string(tempWriter->write(saveFileRoot));

	tempSave->close();

	delete tempWriter,tempSave;
}

void imagine::saveGame::save(Json::Value newSaveFile){
	std::ofstream *tempSave = new std::ofstream(saveFileLoc+"saveFile.json");
	Json::StyledWriter *tempWriter = new Json::StyledWriter();
	if(!tempSave->is_open()){
		throw imagine::exceptions::couldNotOpenSaveFile(saveFileLoc+"saveFile.json");
	}
	*tempSave << std::string(tempWriter->write(newSaveFile));

	tempSave->close();

	delete tempWriter,tempSave;
}
