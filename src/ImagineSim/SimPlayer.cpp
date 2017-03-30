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
    currentLevel = 5;
}

imagine::sim::types::levelProgress::levelProgress(const int finishValue, const int currentValue, const int currentLevelNum){
	finishPoint=finishValue;
	currentProgress=currentValue;
	currentLevel=currentLevelNum;
}

imagine::sim::player::player(sf::Font *fontToUse){
    //For now
    money=15000;
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
					 if(money >= 13000){
						 progressAdded.push_back(true);
						 levelProgress.currentProgress++;
						 progressAddedSize++;
					 }else{
						 progressAdded.push_back(false);
					 }
				 }
			 }
		 }
	 }else if(levelProgress.currentLevel==2){
		 if(levelProgress.currentProgress < levelProgress.finishPoint){
			 for(int i = 0; levelProgress.finishPoint > i;++i){
					 if(progressAddedSize >= 2){
						 if(!progressAdded[i]){
							 if(money >= 20000 && i==0){
								 progressAdded[i]= true;
								 progressAddedSize++;
								 levelProgress.currentProgress++;
							 }else if(activeTourists >= 500 && i==1){
								 progressAdded[i] = true;
								 progressAddedSize++;
								 levelProgress.currentProgress++;
							 }
						 }
					 }else if(std::find(progressAdded.begin(), progressAdded.end(),i)==progressAdded.end()){
						 progressAdded.push_back(false);
						 progressAddedSize++;
					 }
			 }
		 }else if(levelProgress.currentLevel==3){
			 if(levelProgress.currentProgress < levelProgress.finishPoint){
				 for(int i = 0; levelProgress.finishPoint > i;++i){
						 if(progressAddedSize >= 2){
							 if(!progressAdded[i]){
								 if(money >= 40000 && i==0){
									 progressAdded[i]= true;
									 progressAddedSize++;
									 levelProgress.currentProgress++;
								 }else if(activeTourists >= 1500 && i==1){
									 progressAdded[i] = true;
									 progressAddedSize++;
									 levelProgress.currentProgress++;
								 }
							 }
						 }else if(std::find(progressAdded.begin(), progressAdded.end(),i)==progressAdded.end()){
							 progressAdded.push_back(false);
							 progressAddedSize++;
						 }
				 }
			 }
		 }else if(levelProgress.currentLevel==4){
			 for(int i = 0; levelProgress.finishPoint > i; ++i){
				 if(progressAddedSize >= 3){
					 if(!progressAdded[i]){
						 if(money >= 300000 && i==0){
							 progressAdded[i]= true;
							 progressAddedSize++;
							 levelProgress.currentProgress++;
						 }else if(activeTourists >= 10000 && i==1){
							 progressAdded[i] = true;
							 progressAddedSize++;
							 levelProgress.currentProgress++;
						 }else if(touristExtraHappiness >= 35 && i==2){
							 progressAdded[i] = true;
							 progressAddedSize++;
							 levelProgress.currentProgress++;
						 }
					 }
				 }else if(std::find(progressAdded.begin(), progressAdded.end(),i)==progressAdded.end()){
					 progressAdded.push_back(false);
					 progressAddedSize++;
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
			levelProgress.finishPoint = 1;
			levelCompletePopUp = new imagine::sim::levelCompletePopUp(sf::Vector3i(0,1,1),"Level Up! 1",&defaultFont);
			levelUp=true;
		}else if(levelProgress.currentLevel==1 && levelProgress.currentProgress >= levelProgress.finishPoint){
			levelProgress.currentLevel = 2;
			levelProgress.currentProgress = 0;
			levelProgress.finishPoint = 2;
			levelCompletePopUp = new imagine::sim::levelCompletePopUp(sf::Vector3i(0,2,3),"Level Up! 2",&defaultFont);
			levelUp=true;
		}else if(levelProgress.currentLevel==2 && levelProgress.currentProgress >= levelProgress.finishPoint){
			levelProgress.currentLevel = 3;
			levelProgress.currentProgress = 0;
			levelProgress.finishPoint = 2;
			levelCompletePopUp = new imagine::sim::levelCompletePopUp(sf::Vector3i(0,2,3),"Level Up! 3",&defaultFont);
			levelUp=true;
			progressAdded.clear();
			progressAddedSize = 0;
		}else if(levelProgress.currentLevel==3 && levelProgress.currentProgress >= levelProgress.finishPoint){
			levelProgress.currentLevel = 4;
			levelProgress.currentProgress = 0;
			levelProgress.finishPoint = 3;
			levelCompletePopUp = new imagine::sim::levelCompletePopUp(sf::Vector3i(0,2,3),"Level Up! 4",&defaultFont);
			levelUp=true;
			progressAdded.clear();
			progressAddedSize = 0;
		}else if(levelProgress.currentLevel==4 && levelProgress.currentProgress >= levelProgress.finishPoint){
			levelProgress.currentLevel = 5;
			levelProgress.currentProgress = 0;
			levelProgress.finishPoint = 99;
			levelCompletePopUp = new imagine::sim::levelCompletePopUp(sf::Vector3i(0,2,3),"Level Up! 5",&defaultFont);
			levelUp=true;
			progressAdded.clear();
			progressAddedSize = 0;
		}
	}else{
		progressAdded.clear();
		progressAddedSize = 0;
		if(!levelCompletePopUp->getDrawingStatus()){
			levelUp=false;
		}
	}
	publicTransport.update();
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
	//std::cout << JSONReader.parse(buffer.str(),playerData) << "\n";
	char *jsonAsCString = new char[buffer.str().length()+1];
	std::strcpy(jsonAsCString,buffer.str().c_str());
	std::cout << jsonAsCString << "\n";
	rapidjson::Document saveFileJSON;
	saveFileJSON.Parse(jsonAsCString);
	numberOfRoadsSpawned = saveFileJSON[0]["player"]["buildings"]["roads"]["number"].GetInt();
	numberOfAttractionsSpawned = saveFileJSON[0]["player"]["buildings"]["attractions"]["number"].GetInt();
	numberOfHotelsSpawned = saveFileJSON[0]["player"]["buildings"]["hotels"]["number"].GetInt();
	numberOfRestaurantsSpawned = saveFileJSON[0]["player"]["buildings"]["restaurants"]["number"].GetInt();
	numberOfPoliceStationsSpawned = saveFileJSON[0]["player"]["buildings"]["policeStations"]["number"].GetInt();
	townHallSpawned = saveFileJSON[0]["player"]["buildings"]["townHallSpawned"].GetBool();
	std::cout << townHallSpawned << "=TownHallSpawned\n";
	publicTransport.cruiseTerminalSpawned = saveFileJSON[0]["player"]["buildings"]["cruiseTerminalSpawned"].GetBool();
	int policyCount;
	if(townHallSpawned){
		policyCount = saveFileJSON[0]["player"]["buildings"]["townHall"]["policyNumber"].GetInt();
	}
	for(unsigned int i = 0; i < numberOfRoadsSpawned;++i){
		imagine::sim::types::roadDirection direction;
		std::string originalString = std::to_string(i);
		sf::Vector2f position;
		if(saveFileJSON[0]["player"]["buildings"]["roads"][originalString.c_str()]["direction"].GetString() == "straight"){
			direction=imagine::sim::types::straight;
		}
		position.x = saveFileJSON[0]["player"]["buildings"]["roads"][originalString.c_str()]["xPos"].GetInt();
		position.y = saveFileJSON[0]["player"]["buildings"]["roads"][originalString.c_str()]["yPos"].GetInt();

		imagine::sim::road newRoad = imagine::sim::road(direction,position);
		roadsCreated.push_back(newRoad);
	}

	for(unsigned int i = 0; i < numberOfAttractionsSpawned;++i){
		std::string originalString = std::to_string(i);
		//char *placement = new char[originalString.length()+1];
		//std::strcpy()
		int id = saveFileJSON[0]["player"]["buildings"]["attractions"][originalString.c_str()]["id"].GetInt();
		sf::Vector2f position = sf::Vector2f(saveFileJSON[0]["player"]["buildings"]["attractions"][originalString.c_str()]["xPos"].GetFloat(),saveFileJSON[0]["player"]["buildings"]["attractions"][originalString.c_str()]["yPos"].GetFloat());
		imagine::sim::attraction *tempAttraction = new imagine::sim::attraction(id,this,position);
		tempAttraction->spawn();
		//tempAttraction->alive = true;
		//tempAttraction->createdVarOverride = imagine::sim::types::Overridetrue;
		attractionsCreated.push_back(*tempAttraction);
		delete tempAttraction;
	}
	for(unsigned int i = 0; i < numberOfHotelsSpawned;++i){
		std::string originalString = std::to_string(i);
		int id = saveFileJSON[0]["player"]["buildings"]["hotels"][originalString.c_str()]["id"].GetInt();
		sf::Vector2f position = sf::Vector2f(saveFileJSON[0]["player"]["buildings"]["hotels"][originalString.c_str()]["xPos"].GetFloat(),saveFileJSON[0]["player"]["buildings"]["hotels"][originalString.c_str()]["yPos"].GetFloat());
		imagine::sim::hotel *tempHotel = new imagine::sim::hotel(id,position,this);
		tempHotel->spawn();
		hotelsCreated.push_back(*tempHotel);
		delete tempHotel;
	}
	for(unsigned int i = 0; i < numberOfRestaurantsSpawned;++i){
		std::string originalString = std::to_string(i);
		int id = saveFileJSON[0]["player"]["buildings"]["restaurants"][originalString.c_str()]["id"].GetInt();
		sf::Vector2f position = sf::Vector2f(saveFileJSON[0]["player"]["buildings"]["restaurants"][originalString.c_str()]["xPos"].GetFloat(),saveFileJSON[0]["player"]["buildings"]["restaurants"][originalString.c_str()]["yPos"].GetFloat());
		imagine::sim::Restaurant *tempRestaurant = new imagine::sim::Restaurant(id,this,position);
		tempRestaurant->spawn();
		restaurantsCreated.push_back(*tempRestaurant);
		delete tempRestaurant;
	}
	for(unsigned int i = 0; i < numberOfPoliceStationsSpawned;++i){
		std::string originalString = std::to_string(i);
		int id = saveFileJSON[0]["player"]["buildings"]["policeStations"][originalString.c_str()]["id"].GetInt();
		sf::Vector2f position = sf::Vector2f(saveFileJSON[0]["player"]["buildings"]["policeStations"][originalString.c_str()]["xPos"].GetFloat(),saveFileJSON[0]["player"]["buildings"]["policeStations"][originalString.c_str()]["yPos"].GetFloat());
		imagine::sim::policeStation *tempPoliceStation = new imagine::sim::policeStation(id,this,position);
		tempPoliceStation->spawn();
		policeStationsCreated.push_back(*tempPoliceStation);
		delete tempPoliceStation;
	}
	if(townHallSpawned){
		std::vector<imagine::sim::CityPolicy> tempPolicies;
		sf::Vector2f position = sf::Vector2f(saveFileJSON[0]["player"]["buildings"]["townHall"]["xPos"].GetFloat(),saveFileJSON[0]["player"]["buildings"]["townHall"]["yPos"].GetFloat());
		for(unsigned int i = 0; policyCount > i;++i){
			std::string originalString = std::to_string(i);
			int id = saveFileJSON[0]["player"]["buildings"]["townHall"]["policies"][originalString.c_str()]["id"].GetInt();
			bool policyState = saveFileJSON[0]["player"]["buildings"]["townHall"]["policies"][originalString.c_str()]["state"].GetBool();
			int minLevel = saveFileJSON[0]["player"]["buildings"]["townHall"]["policies"][originalString.c_str()]["minLevel"].GetInt();
			imagine::sim::types::conditions condition = imagine::sim::types::noConditions;
			if(saveFileJSON[0]["player"]["buildings"]["townHall"]["policies"][originalString.c_str()]["conditions"].GetString() == "buildPolice"){
				condition=imagine::sim::types::buildPolice;
			}
			imagine::sim::CityPolicy tempPolicy = imagine::sim::CityPolicy(id,this,minLevel,condition);
			tempPolicy.active = policyState;
			tempPolicies.push_back(tempPolicy);
		}
		std::cout << "(" << position.x << "," << position.y << ")\n";
		townHall = new imagine::sim::TownHall(this,position,&defaultFont,&tempPolicies);
	}
	if(publicTransport.cruiseTerminalSpawned){
		sf::Vector2f position = sf::Vector2f(saveFileJSON[0]["player"]["buildings"]["cruiseTerminal"]["xPos"].GetFloat(),saveFileJSON[0]["player"]["buildings"]["cruiseTerminal"]["yPos"].GetFloat());
		publicTransport.currentCruiseTerminal = imagine::sim::CruiseTerminal(this,position);
		publicTransport.currentCruiseTerminal.spawn();
	}

	money = saveFileJSON[0]["player"]["money"].GetInt();

	int day = saveFileJSON[0]["player"]["date"]["day"].GetInt();
	int month = saveFileJSON[0]["player"]["date"]["month"].GetInt();
	int year = saveFileJSON[0]["player"]["date"]["year"].GetInt();
	playerDate = new imagine::sim::types::date(day,month,year);

	int hour = saveFileJSON[0]["player"]["time"]["hour"].GetInt();
	int minute = saveFileJSON[0]["player"]["time"]["minute"].GetInt();
	time = new imagine::sim::GameTime(this,imagine::sim::types::SimTime(hour,minute));

	activeTourists = saveFileJSON[0]["player"]["activeTourists"].GetInt();

	levelProgress.finishPoint = saveFileJSON[0]["player"]["levelProgress"]["finishPoint"].GetInt();
	levelProgress.currentProgress = saveFileJSON[0]["player"]["levelProgress"]["currentProgress"].GetInt();
	levelProgress.currentLevel = saveFileJSON[0]["player"]["levelProgress"]["currentLevel"].GetInt();

	return true;
}

Json::Value imagine::sim::player::getReadySaveData(){
	playerData["player"]["buildings"]["roads"]["number"] = numberOfRoadsSpawned;
	playerData["player"]["buildings"]["attractions"]["number"] = numberOfAttractionsSpawned;
	playerData["player"]["buildings"]["hotels"]["number"] = numberOfHotelsSpawned;
	playerData["player"]["buildings"]["restaurants"]["number"] = numberOfRestaurantsSpawned;
	playerData["player"]["buildings"]["policeStations"]["number"] = numberOfPoliceStationsSpawned;
	playerData["player"]["buildings"]["townHallSpawned"] = townHallSpawned;
	playerData["player"]["buildings"]["cruiseTerminalSpawned"] = publicTransport.cruiseTerminalSpawned;
	std::string directionString;
	for(unsigned int i = 0; i < numberOfRoadsSpawned;i++){
		if(roadsCreated[i].getRoadDirection() == imagine::sim::types::straight){
			directionString="straight";
		}
		playerData["player"]["buildings"]["roads"][std::to_string(i)]["direction"] = directionString;
		playerData["player"]["buildings"]["roads"][std::to_string(i)]["xPos"] = roadsCreated[i].tileSprite.getPosition().x;
		playerData["player"]["buildings"]["roads"][std::to_string(i)]["yPos"] = roadsCreated[i].tileSprite.getPosition().y;
	}
	for(unsigned int i = 0; i < numberOfAttractionsSpawned;++i){
		std::cout << "passed I=" << i << "\n";
		playerData["player"]["buildings"]["attractions"][std::to_string(i)]["id"] = attractionsCreated[i].getId(); //!
		std::cout << "passed2\n";
		playerData["player"]["buildings"]["attractions"][std::to_string(i)]["xPos"] = attractionsCreated[i].attractionSprite.getPosition().x;
		playerData["player"]["buildings"]["attractions"][std::to_string(i)]["yPos"] = attractionsCreated[i].attractionSprite.getPosition().y;
	}
	for(unsigned int i = 0; i < numberOfHotelsSpawned; ++i){
		playerData["player"]["buildings"]["hotels"][std::to_string(i)]["id"] = hotelsCreated[i].getId();
		playerData["player"]["buildings"]["hotels"][std::to_string(i)]["xPos"] = hotelsCreated[i].hotelSprite.sprite.getPosition().x;
		playerData["player"]["buildings"]["hotels"][std::to_string(i)]["yPos"] = hotelsCreated[i].hotelSprite.sprite.getPosition().y;
	}
	/*for(int i = 0; i < numberOfAdvertisementsSpawned; ++i){
		playerData["player"]["buildings"]["hotels"][i]["id"] = hotelsCreated[i].getId();
		playerData["player"]["buildings"]["hotels"][i]["xPos"] = hotelsCreated[i].tileSprite.getPosition().x;
		playerData["player"]["buildings"]["hotels"][i]["yPos"] = hotelsCreated[i].tileSprite.getPosition().y;
	}*/
	for(unsigned int i = 0; i < numberOfRestaurantsSpawned; ++i){
		playerData["player"]["buildings"]["restaurants"][std::to_string(i)]["id"] = restaurantsCreated[i].getId();
		playerData["player"]["buildings"]["restaurants"][std::to_string(i)]["xPos"] = restaurantsCreated[i].tileSprite.getPosition().x;
		playerData["player"]["buildings"]["restaurants"][std::to_string(i)]["yPos"] = restaurantsCreated[i].tileSprite.getPosition().y;
	}
	for(unsigned int i = 0; i < numberOfPoliceStationsSpawned; ++i){
		playerData["player"]["buildings"]["policeStations"][std::to_string(i)]["id"] = policeStationsCreated[i].getId();
		playerData["player"]["buildings"]["policeStations"][std::to_string(i)]["xPos"] = policeStationsCreated[i].policeSprite.sprite.getPosition().x;
		playerData["player"]["buildings"]["policeStations"][std::to_string(i)]["yPos"] = policeStationsCreated[i].policeSprite.sprite.getPosition().y;
	}
	if(townHallSpawned){
		playerData["player"]["buildings"]["townHall"]["xPos"] = townHall->cityServiceSprite.sprite.getPosition().x;
		playerData["player"]["buildings"]["townHall"]["yPos"] = townHall->cityServiceSprite.sprite.getPosition().y;
		playerData["player"]["buildings"]["townHall"]["policyNumber"] = townHall->getCityPolicySize();
		for(unsigned int i = 0;townHall->cityPolicies.size() > i;++i){
			playerData["player"]["buildings"]["townHall"]["policies"][std::to_string(i)]["id"] = townHall->cityPolicies[i].getId();
			playerData["player"]["buildings"]["townHall"]["policies"][std::to_string(i)]["state"] = townHall->cityPolicies[i].active;
			playerData["player"]["buildings"]["townHall"]["policies"][std::to_string(i)]["minLevel"] = townHall->cityPolicies[i].getMinimumlevel();
			if(townHall->cityPolicies[i].getConditions()==imagine::sim::types::noConditions){
				playerData["player"]["buildings"]["townHall"]["policies"][std::to_string(i)]["conditions"] = "None";
			}else if(townHall->cityPolicies[i].getConditions()==imagine::sim::types::buildPolice){
				playerData["player"]["buildings"]["townHall"]["policies"][std::to_string(i)]["conditions"] = "buildPolice";
			}
		}
	}
	if(publicTransport.cruiseTerminalSpawned){
		playerData["player"]["buildings"]["cruiseTerminal"]["xPos"] = publicTransport.currentCruiseTerminal.transportSprite.sprite.getPosition().x;
		playerData["player"]["buildings"]["cruiseTerminal"]["yPos"] = publicTransport.currentCruiseTerminal.transportSprite.sprite.getPosition().y;
	}
	playerData["player"]["money"] = money;

	playerData["player"]["date"]["day"] = playerDate->getDay();
	playerData["player"]["date"]["month"] = playerDate->getMonth();
	playerData["player"]["date"]["year"] = playerDate->getYear();

	playerData["player"]["time"]["hour"] = time->getSimTime().getHour();
	playerData["player"]["time"]["minute"] = time->getSimTime().getMinute();

	playerData["player"]["activeTourists"] = activeTourists;

	playerData["player"]["levelProgress"]["finishPoint"] = levelProgress.finishPoint;
	playerData["player"]["levelProgress"]["currentProgress"] = levelProgress.currentProgress;
	playerData["player"]["levelProgress"]["currentLevel"] = levelProgress.currentLevel;

	return playerData;
}

