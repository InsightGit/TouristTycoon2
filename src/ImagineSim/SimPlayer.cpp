#include <iostream>

#include "SimPlayer.hpp"

#include "Advertisement.hpp"
#include "GameTime.hpp"
#include "TouristSpawner.hpp"

static imagine::sim::types::platform imagine::sim::player::getPlatform(){
#if _WIN32
#if _WIN64
	return imagine::sim::types::platform::win64;
#else
	return imagine::sim::types::platform::win32;
#endif
#endif
#if __linux
#if __GNUC__
#if __x86_64__
	return imagine::sim::types::platform::lin64;
#else
	return imagine::sim::types::platform::lin32;
#endif
#endif
#endif
#if __APPLE__ || __MACH__
	return imagine::sim::types::platform::macos;
#endif
	return imagine::sim::types::platform::unknown;
}

static std::string imagine::sim::player::getApplicationDataDir(){
	if(getPlatform()==imagine::sim::types::lin32 || getPlatform()==imagine::sim::types::lin64){
		char *USER = getenv("USER");
		std::string USERSTRING = USER;
		return "/home/"+USERSTRING+"/.";
	}else if(getPlatform()==imagine::sim::types::win32 || getPlatform()==imagine::sim::types::win64){
		return "%APPDATA%/"; //use forward slashes because they cause no difference in Windows and cause less internal errors
	}else if(getPlatform()==imagine::sim::types::macos){
		char *USER = getenv("USER");
		std::string USERSTRING = USER;
		return "/Users/"+USERSTRING+"/Library/Application Support/";
	}
}

imagine::sim::types::levelProgress::levelProgress(){
    finishPoint = 0;
    currentProgress = 0;
    currentLevel = 0;
}

imagine::sim::types::levelProgress::levelProgress(const int finishValue, const int currentValue, const int currentLevelNum){
	finishPoint=finishValue;
	currentProgress=currentValue;
	currentLevel=currentLevelNum;
}

imagine::sim::player::player(sf::Font *fontToUse){
    //For now
    money=10000;
    defaultFont=*fontToUse;
	playerDate = new imagine::sim::types::date();
	time = new imagine::sim::GameTime(this);
	touristSpawner = new imagine::sim::TouristSpawner(this,&advertisementsCreated,&attractionsCreated);
}

imagine::sim::player::player(Json::Value loadGameData,sf::Font *fontToUse){
    //for now
	playerData=loadGameData;
	loadDataExists=true;
	defaultFont=*fontToUse;
}

void imagine::sim::player::updatePlayerLevel(){
	//update the player level based on in-game events
	 if(levelProgress.currentLevel==1){
		 if(levelProgress.currentProgress < levelProgress.finishPoint){
			 for(int i = 0;levelProgress.finishPoint > i;i++){
				 if(i==0 && progressAddedSize-1 >= 0){
					 if(!progressAdded[i]){
						 if(money >= 13000){
							 progressAdded.push_back(true);
							 progressAddedSize++;
							 levelProgress.currentProgress++;
						 }
					 }
				 }else if(i==0){
					 if(money >= 15000){
						 progressAdded.push_back(true);
						 levelProgress.currentProgress++;
						 progressAddedSize++;
					 }else{
						 progressAdded.push_back(false);
					 }
				 }
			 }
		 }
	 }
}

void imagine::sim::player::update(){
	updatePlayerLevel();
	//check level-up conditions
	if(!levelUp){
		if(numberOfAttractionsSpawned>=1 && levelProgress.currentLevel==0){
			levelProgress.currentLevel = 1;
			levelProgress.currentProgress = 0;
			levelProgress.finishPoint=1;
			levelCompletePopUp = new imagine::sim::levelCompletePopUp(sf::Vector3i(0,1,1),"Level Up! 1",&defaultFont);
			levelUp=true;
		}else if(levelProgress.currentLevel==1 && levelProgress.currentProgress >= levelProgress.finishPoint){
			levelProgress.currentLevel = 2;
			levelProgress.currentProgress = 0;
			levelProgress.finishPoint = 2;
			levelCompletePopUp = new imagine::sim::levelCompletePopUp(sf::Vector3i(0,2,3),"Level Up! 2",&defaultFont);
			levelUp=true;
		}
	}else{
		progressAdded.clear();
		progressAddedSize = 0;
		if(!levelCompletePopUp->getDrawingStatus()){
			levelUp=false;
		}
	}
}

void imagine::sim::player::display(sf::RenderWindow *window){
	update();
	if(levelUp){
		levelCompletePopUp->draw(window);
	}
}

bool imagine::sim::player::loadData(){
	std::ifstream saveFile(imagine::sim::player::getApplicationDataDir()+"touristtycoon/saveFile.json");
	std::stringstream buffer;
	buffer << saveFile.rdbuf();
	std::cout << JSONReader.parse(buffer.str(),playerData) << "\n";
	numberOfRoadsSpawned = playerData["player"]["buildings"]["number"].asInt();
	for(int i = 0; i < numberOfRoadsSpawned;++i){
		imagine::sim::types::roadDirection direction;
		sf::Vector2f position;
		if(playerData["player"]["buildings"]["roads"][i]["direction"].asString() == "straight"){
			direction=imagine::sim::types::straight;
		}
		position.x = playerData["player"]["buildings"]["roads"][i]["xPos"].asInt();
		position.y = Json::Value(playerData["player"]["buildings"]["roads"][i]["yPos"]).asInt();

		imagine::sim::road newRoad = imagine::sim::road(direction,position);
		roadsCreated.push_back(newRoad);
	}
	//TODO: Implement attraction loading with similar looking code to roadSpawning
	money = Json::Value(playerData["player"]["money"]).asInt();

	int day = Json::Value(playerData["player"]["date"]["day"]).asInt();
	int month = Json::Value(playerData["player"]["date"]["month"]).asInt();
	int year = Json::Value(playerData["player"]["date"]["year"]).asInt();
	playerDate = new imagine::sim::types::date(day,month,year);

	activeTourists = Json::Value(playerData["player"]["activeTourists"]).asInt();

	levelProgress.finishPoint = Json::Value(playerData["player"]["levelProgress"]["finishPoint"]).asInt();
	levelProgress.currentProgress = Json::Value(playerData["player"]["levelProgress"]["currentProgress"]).asInt();
	levelProgress.currentLevel = Json::Value(playerData["player"]["levelProgress"]["currentLevel"]).asInt();

	return true;
}

Json::Value imagine::sim::player::getReadySaveData(){
	playerData["player"]["buildings"]["number"] = numberOfRoadsSpawned;
	std::string directionString;
	for(int i = 0; i < numberOfRoadsSpawned;i++){
		if(roadsCreated[i].getRoadDirection() == imagine::sim::types::straight){
			directionString="straight";
		}
		playerData["player"]["buildings"]["roads"][i]["direction"] = directionString;
		playerData["player"]["buildings"]["roads"][i]["xPos"] = roadsCreated[i].tileSprite.getPosition().x;
		playerData["player"]["buildings"]["roads"][i]["yPos"] = roadsCreated[i].tileSprite.getPosition().y;
	}
	//TODO: Implement attraction saving with similar looking code to roadSpawning
	playerData["player"]["money"] = money;

	playerData["player"]["date"]["day"] = playerDate->getDay();
	playerData["player"]["date"]["month"] = playerDate->getMonth();
	playerData["player"]["date"]["year"] = playerDate->getYear();

	playerData["player"]["activeTourists"] = activeTourists;

	playerData["player"]["levelProgress"]["finishPoint"] = levelProgress.finishPoint;
	playerData["player"]["levelProgress"]["currentProgress"] = levelProgress.currentProgress;
	playerData["player"]["levelProgress"]["currentLevel"] = levelProgress.currentLevel;

	return playerData;
}

