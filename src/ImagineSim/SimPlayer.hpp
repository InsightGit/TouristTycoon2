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

//#include "Advertisement.hpp"
//#include <string>

#include "levelCompletePopUp.hpp"
//#include "Attraction.hpp"
//#include "Road.hpp"
//#include "hotel.hpp"
#include "Tourist.hpp"


namespace imagine{
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
			int money;
			imagine::sim::types::date *playerDate;
			imagine::sim::GameTime *time;
			std::vector<imagine::sim::attraction> attractionsCreated;
			std::vector<imagine::sim::road> roadsCreated;
			std::vector<imagine::sim::hotel> hotelsCreated;
			std::vector<imagine::sim::tourist> touristsSpawned;
			std::vector<imagine::sim::Advertisement> advertisementsCreated;
			imagine::sim::types::levelProgress levelProgress;
			imagine::sim::TouristSpawner *touristSpawner;
			signed int activeTourists = 0;
			signed int tourists = 0;
			signed int numberOfRoadsSpawned = 0;
			signed int numberOfAttractionsSpawned = 0;
			signed int numberOfAdvertisementsSpawned = 0;
			signed int numberOfHotelsSpawned = 0;
			sf::Font defaultFont;

			imagine::sim::levelCompletePopUp *levelCompletePopUp;

			player(sf::Font *fontToUse); //use when starting new game
			player(Json::Value loadGameData,sf::Font *fontToUse);

			Json::Value getReadySaveData();
			bool loadData();
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
