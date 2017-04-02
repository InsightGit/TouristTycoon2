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


#ifndef BUILDMENU_HPP
#define BUILDMENU_HPP

#include "../ImagineCore.hpp"
#include "SimPlayer.hpp"
#include "../Menu.hpp"
#include "MenuItem.hpp"
#include "BuildPrompter.hpp"
#include <iostream>
#include "HelpBar.hpp"
#include "ActionArea.hpp"

#include "Resources/roadIcon.h"
#include "Resources/roadRemastered.h"
#include "Resources/WashMonuIcon.h"
#include "Resources/hotelIcon.h"
#include "Resources/TokyotowerIcon.h"
#include "Resources/ZiplineIcon.h"
#include "Resources/HikingTrailIcon.h"
#include "Resources/ItalianRestaurantIcon.h"
#include "Resources/MexicanRestaurantIcon.h"
#include "Resources/dinerIcon.h"
#include "Resources/TownHallIcon.h"
#include "Resources/empireStateIcon.h"
#include "Resources/teppanyakiIcon.h"
#include "Resources/bigBenIcon.h"
#include "Resources/amusementparkIcon.h"
#include "Resources/policeStationIcon.h"
#include "Resources/casinoIcon.h"
#include "Resources/portIcon.h"
#include "Resources/centralparkIcon.h"
#include "Resources/movieSetIcon.h"
#include "Resources/spaceNeedleIcon.h"

namespace imagine {
    namespace sim{
        class buildMenu : public imagine::menu
        {
        public:
        	bool drawMenu = false;
            sf::RectangleShape leftRect = sf::RectangleShape(sf::Vector2f(100,300));
            sf::RectangleShape rightRect = sf::RectangleShape(sf::Vector2f(300,300));

            buildMenu(imagine::sim::player *mainPlayer,imagine::sim::helpBar *helpBarToUse,imagine::sim::actionArea *actionAreaToUse,sf::Font *fontToUse);
            virtual ~buildMenu();

            void spawn();
	    	void draw(sf::RenderWindow *window);
        protected:
	    	sf::Font defaultFont;
	    	sf::Text attractions;
	    	sf::Text roadText;
	    	sf::Text services;
	    	sf::Text restaurants;
	    	std::string activeCategory;
	    	std::string previousTextName = "attractions";
	    	std::vector<imagine::sim::menuItem> attractionButtons;
	    	std::vector<imagine::sim::menuItem> roadButtons;
	    	std::vector<imagine::sim::menuItem> serviceButtons;
	    	std::vector<imagine::sim::menuItem> restaurantButtons;
	    	imagine::sim::player *player;
	    	imagine::sim::buildPrompter *buildingPrompter;
	    	imagine::sim::helpBar *helpBar;
	    	imagine::sim::actionArea *actionArea;
	    	imagine::types::arrayLocation *inPrompter;
	    	sf::Image largeRoad;
	    	sf::Image imageForPrompter;
	    	bool pastDrawMenu = false;
	    	bool drawPrompter = false;
	    	bool prompterTimerNotYetSet = true;
	    	bool prompterCreated = false;
	    	bool placeTimerNotSet = true;
	    	signed int attractionButtonSize = 0;
	    	signed int serviceButtonSize = 0;
	    	signed int restaurantButtonSize = 0;

	    	sf::Clock limitPrompterClicks;
	    	sf::Clock limitClicks;
	    	sf::Clock limitPlaceClicks;

	    	void update(sf::RenderWindow *window);
        };
    }
}


#endif // BUILDMENU_HPP
