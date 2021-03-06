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


#ifndef ATTRACTION_HPP
#define ATTRACTION_HPP

#include <string>

#include "Tile.hpp"
#include "PopUp.hpp"

#include "Resources/WashMonu.h"
#include "Resources/Tokyotower.h"
#include "Resources/Zipline.h"
#include "Resources/HikingTrail.h"
#include "Resources/empireState.h"
#include "Resources/amusementpark.h"
#include "Resources/bigBen.h"
#include "Resources/casino.h"
#include "Resources/centralpark.h"
#include "Resources/movieSet.h"
#include "Resources/spaceNeedle.h"


namespace imagine{
	namespace sim{

		class player;
		class NewTourist;
		class tourist;
		class attraction : public tile
		{
		    public:
			std::string name = "Unknown";
			bool alive = false;
			bool exists = false;
			sf::Image attractionImage;
			sf::Texture attractionTexture;
			sf::Sprite attractionSprite;
			//imagine::sim::types::boolOverride createdVarOverride; //used when loading object

			attraction(int idToUse, imagine::sim::player *mainPlayer,sf::Vector2f positionToUse);
			attraction();
			virtual ~attraction();

			signed int getId() { return id; }
			signed int getCostForTourists() { return costForTourists; }
			signed int getAttractionLevel() { return attractionLevel; }
			signed int getTouristsThisYear() { return touristsThisYear; }
			signed int getPopularity() { return popularity; }
			signed int getMaxOccupancy() { return maxOccupancy; }
			signed int getCurrentOccupancy() { return currentTouristNum; }
			signed int getActivityLevel() { return activityLevel; }
			signed int getCrimeAttention() { return crimeAttention; }
			bool getCreated() { return created; }
			bool getAlive() { return alive; }

			void spawn();
			bool create(imagine::sim::popUp *notEnoughMoneyPopUp, const sf::Font *fontToUse);
			bool admit(imagine::sim::NewTourist *tourist);
			bool admit(imagine::sim::tourist *tourist);
			void demit();
			void draw(sf::RenderWindow *window)override;

		    protected:
			bool created = false;
			imagine::sim::player *player;
			bool playerAssign = false;

			signed int id;
			signed int crimeAttention = 0;
			signed int pastTouristNum = 0;
			signed int allTouristNum = 0;
			signed int baseMaintainceCost;
			signed int currentTouristNum = 0;
			signed int costForTourists = 0;
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
