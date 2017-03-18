#ifndef ATTRACTION_HPP
#define ATTRACTION_HPP

#include <string>

#include "Tile.hpp"
#include "PopUp.hpp"

#include "Resources/WashMonu.h"
#include "Resources/Tokyotower.h"
#include "Resources/Zipline.h"
#include "Resources/HikingTrail.h"


namespace imagine{
	namespace sim{
		class player;
		class tourist;
		class attraction : public tile
		{
		    public:
			std::string name;
			sf::Image attractionImage;
			sf::Texture attractionTexture;
			sf::Sprite attractionSprite;

			attraction(int idToUse, imagine::sim::player *mainPlayer,sf::Vector2f positionToUse);
			attraction();
			virtual ~attraction();

			signed int getId() { return id; }
			signed int getCostForTourists() { return costForTourists; }
			signed int getAttractionLevel() { return attractionLevel; }
			signed int getTouristsThisYear() { return touristsThisYear; }
			signed int getPopularity() { return popularity; }
			signed int getMaxOccupancy() { return maxOccupancy; }
			signed int getActivityLevel() { return activityLevel; }

			void spawn();
			bool create(imagine::sim::popUp *notEnoughMoneyPopUp, const sf::Font *fontToUse);
			bool admit(imagine::sim::tourist *tourist);
			void demit();
			void draw(sf::RenderWindow *window)override;
		    protected:
			bool alive = false;
			bool created = false;
			imagine::sim::player *player;

			signed int id;
			signed int currentTouristNum = 0;
			signed int costForTourists;
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
