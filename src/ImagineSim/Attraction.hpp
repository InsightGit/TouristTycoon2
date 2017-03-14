#ifndef ATTRACTION_HPP
#define ATTRACTION_HPP

#include <string>

#include "Tile.hpp"


namespace imagine{
	namespace sim{
		class player;
		class tourist;
		class attraction : public tile
		{
		    public:
			std::string name;
			attraction(int idToUse, imagine::sim::player *mainPlayer,sf::Vector2f positionToUse);
			attraction();
			virtual ~attraction();

			signed int getId() { return id; }
			signed int getCost() { return cost; }
			signed int getAttractionLevel() { return attractionLevel; }
			signed int getTouristsThisYear() { return touristsThisYear; }
			signed int getPopularity() { return popularity; }
			signed int getMaxOccupancy() { return maxOccupancy; }
			signed int getActivityLevel() { return activityLevel; }

			void spawn();
			bool admit(imagine::sim::tourist *tourist);
			void demit();
			void draw(sf::RenderWindow *window)override;
		    protected:
			bool alive = false;
			imagine::sim::player *player;

			signed int id;
			signed int currentTouristNum = 0;
			signed int cost;
			signed int attractionLevel;
			signed int touristsThisYear;
			signed int popularity;
			signed int maxOccupancy;
			signed int activityLevel;

			void update();

		};
	}
}


#endif // ATTRACTION_HPP
