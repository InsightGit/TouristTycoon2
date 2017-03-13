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
