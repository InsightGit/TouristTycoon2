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


#ifndef _simplayer_h
#define _simplayer_h

//#include "SimHUD.hpp"
#include <stdexcept>
#include <vector>
#include <sstream>
#include <fstream>

#include <SFML/System.hpp>
#include <jsoncpp/json/value.h>
#include <jsoncpp/json/reader.h>
#include <rapidjson/document.h>


//#include "Advertisement.hpp"
//#include <string>

#include "levelCompletePopUp.hpp"
//#include "Attraction.hpp"
//#include "Road.hpp"
//#include "hotel.hpp"
#include "Tourist.hpp"
#include "NewTourist.hpp"
#include "Restaurant.hpp"
#include "TownHall.hpp"
#include "policeStation.hpp"
#include "PublicTransportManager.hpp"

namespace imagine{
	class scene;
	namespace sim{
	    namespace exceptions{
            class invalidDateException : public std::runtime_error {
                public:
                invalidDateException() : std::runtime_error("Invalid date entered"){}
            };
	    }
	    class GameTime;
	    class TouristSpawner;
	    class Advertisement;

	    namespace types{
	    	class date;
            class levelProgress{
                public:
                int finishPoint;
                int currentProgress;
                int currentLevel;

                levelProgress();
                levelProgress(const int finishValue, const int currentValue, const int currentLevelNum);
            };
            enum boolOverride{
				Overridetrue,
				Overridefalse,
				UseInternalValue
			};
    		enum platform{
    			win32,
    			win64,
    			macos,
    			lin32,
    			lin64,
    			unknown
    		};
	    }
		class player : sf::NonCopyable{
		    public:
			int money = 15000;
			imagine::sim::types::date *playerDate;
			imagine::sim::GameTime *time;
			std::vector<imagine::sim::attraction> attractionsCreated;
			std::vector<imagine::sim::road> roadsCreated;
			std::vector<imagine::sim::hotel> hotelsCreated;
			std::vector<imagine::sim::NewTourist> touristsSpawned;
			std::vector<imagine::sim::Advertisement> advertisementsCreated;
			std::vector<imagine::sim::Restaurant> restaurantsCreated;
			std::vector<imagine::sim::policeStation> policeStationsCreated;
			imagine::sim::types::levelProgress levelProgress;
			imagine::sim::TouristSpawner *touristSpawner;
			imagine::sim::TownHall *townHall;
			imagine::sim::PublicTransportManager publicTransport;
			bool townHallSpawned = false;
			signed int activeTourists = 0;
			signed int tourists = 0;
			signed int numberOfRoadsSpawned = 0;
			signed int numberOfAttractionsSpawned = 0;
			signed int numberOfAdvertisementsSpawned = 0;
			signed int numberOfHotelsSpawned = 0;
			signed int numberOfRestaurantsSpawned = 0;
			signed int numberOfPoliceStationsSpawned = 0;
			signed int touristExtraHappiness = 0;
			sf::Font defaultFont;
			imagine::scene *currentScene;

			imagine::sim::levelCompletePopUp *levelCompletePopUp;

			player(sf::Font *fontToUse); //use when starting new game
			player(Json::Value loadGameData,sf::Font *fontToUse);

			Json::Value getReadySaveData();
			bool loadData();
			void setScene(imagine::scene *scene) { currentScene=scene; }
			void display(sf::RenderWindow *window);
		    protected:
				std::vector<bool> progressAdded;
				signed int progressAddedSize = 0;
				bool levelUp = false;
				Json::Reader JSONReader;
				Json::Value playerData;
				bool loadDataExists = false;

				void updatePlayerLevel();
				void update();
				static std::string getApplicationDataDir();
				static imagine::sim::types::platform getPlatform();

		};
	}
}
#endif
