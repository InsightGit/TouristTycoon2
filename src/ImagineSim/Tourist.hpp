#ifndef _TOURIST_HPP
#define _TOURIST_HPP

#include <string>
#include <vector>
#include <random>

#include <SFML/Graphics.hpp>


#include "Road.hpp"
#include "touristCar.hpp"
#include "hotel.hpp"
#include "Attraction.hpp"

//#include "Resources/Car.h"
#include "Resources/personNew.h"

namespace imagine{
	namespace sim{
		namespace types{
			enum touristStatus{
				driving,
				walking,
				touring,
				sleeping,
				eating
			};
			enum foodCuisine : unsigned int;
			enum foodQuality : unsigned int;
			class aStarRoad{
			public:
				float gScore;
				float hScore;
				float fScore;

				imagine::sim::road *aRoad;
				imagine::sim::road *currentRoad;
				imagine::sim::road *futureRoad;

				aStarRoad(imagine::sim::road *aRoadToUse, imagine::sim::road *currentRoadToUse, imagine::sim::road *futureRoadToUse);
				aStarRoad(imagine::sim::road *aRoadToUse, imagine::sim::road *currentRoadToUse, sf::Vector2f dest);
			};
			class compareFoodQuality{
			public:
				static bool isLess(imagine::sim::types::foodQuality leftSide, imagine::sim::types::foodQuality rightSide);
			};
		}
		class player;
		class Restaurant;

		class tourist{
		public:
			//std::string name;
			//signed int visitedAttractionsNumber = 0;
			signed int numberOfAttractionsSinceLastEat = 0;
			signed int happiness = 20;
			sf::Vector2f position;
			bool display = false;
			bool chosenAttraction = false;
			bool justSpawned = true;
			bool chosenHotel = false;
			bool chosenRestaurant = false;
			bool leaving = false;
			bool added = false;
			bool pastLeaving = false;
			bool hungry = false;
			//int attractionLength;
			//int roadLength;
			//int hotelLength;
			signed int money;
			signed int energy;
			//std::vector<imagine::sim::attraction> *allAttractions;
			//std::vector<imagine::sim::road> *allRoads;
			//std::vector<imagine::sim::hotel> *allHotels;
			imagine::sim::hotel currentHotel;
 			imagine::sim::attraction *currentAttraction;
 			imagine::sim::Restaurant *currentRestaurant;
			imagine::sim::types::touristStatus status = imagine::sim::types::driving;
			imagine::sim::touristCar *car;
			imagine::sim::types::foodCuisine preferredCuisine;
			imagine::sim::types::foodQuality minimumQuality;


			//sf::Image drivingForm;
			sf::Image walkingForm;
			sf::Texture touristTexture;
			sf::Sprite touristSprite;

			tourist(imagine::sim::player *mainPlayer);
			//TODO: add tourist(saveData)


			void spawn();
			void draw(sf::RenderWindow *window);
		protected:
			bool previousCuisineMatched = false;
			std::vector<int> popularityList;
			std::vector<imagine::sim::attraction*> tempBlackList;
			std::vector<imagine::sim::attraction*> visitedAttractions;
			int mostPopular;
			int mostPopularPlace = -1;
			int mostPopularRestaurant = -1;
			signed int tempBlackListSize = 0;
			signed int visitedAttractionsSize = 0;

			sf::Clock drivingTime;
			sf::Clock touringTime;
			sf::Clock sleepingTime;
			bool touringTimeSet = false;
			bool drivingTimeSet = false;
			bool sleepingTimeSet = false;


			//used for A*
			std::vector<imagine::sim::road*> openList;
			std::vector<imagine::sim::road*> closeList;
			std::vector<imagine::sim::types::aStarRoad> aStarResults;
			imagine::sim::road *currentRoad;
			imagine::sim::road *aRoad;
			imagine::sim::player *player;

			std::vector<int> findNextRoadPlace(const imagine::sim::road *road);
			std::vector<int> findNextAttractionPlace(const imagine::sim::attraction *attraction);

			void switchForm(imagine::sim::types::touristStatus form);

			void update();
		};
	}
}

#endif
