/*
 * BuildPrompter.hpp
 *
 *  Created on: Feb 27, 2017
 *      Author: newbobby
 */

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


#ifndef SRC_IMAGINESIM_BUILDPROMPTER_HPP_
#define SRC_IMAGINESIM_BUILDPROMPTER_HPP_
#include <vector>
#include "SimPlayer.hpp"
#include "PopUp.hpp"
#include "Attraction.hpp"
#include "Road.hpp"
#include "hotel.hpp"
#include "ActionArea.hpp"
#include "Restaurant.hpp"
//#include "Services.hpp"
#include "TownHall.hpp"
#include "policeStation.hpp"
#include "ConfirmationPopUp.hpp"

namespace imagine {
		namespace sim {
			class buildPrompter {
				public:
					sf::Image tilePlacingImage;
					sf::Texture tilePlacingTexture;
					sf::Sprite tilePlacingSprite;
					sf::Vector2i tilePlacingSize;
					signed int moneyNeeded;
					sf::Font defaultFont;
					sf::RectangleShape buildArea;
					imagine::sim::popUp *notEnoughMoneyPopUp;
					imagine::sim::confirmationPopUp *confirmationPopUp;
					std::vector<imagine::sim::road> drawingRoads;
					imagine::sim::road *previousRoad;
					sf::Text cost;
					unsigned drawingRoadLength = 0;

					bool cannotBuild = false;
					bool playerRequestingBuild = false;
			    	bool drawingRoad = false;
			    	bool done = false;
			    	bool attentionNeeded = false;
			    	bool bypassed = false;

					buildPrompter(imagine::sim::player *mainPlayer,sf::Image tileImageToUse,const signed int tileCost,const sf::Vector2i tileSize,imagine::sim::actionArea *actionAreaToUse,const signed int tileIdToUse, sf::Font *fontToUse);
					buildPrompter(imagine::sim::player *mainPlayer, sf::Texture tileTextureToUse,const signed int tileCost,const sf::Vector2i tileSize,imagine::sim::actionArea *actionAreaToUse,const signed int tileIdToUse,sf::Font *fontToUse);
					virtual ~buildPrompter();

					bool canBuild();
					void spawn(sf::RenderWindow *window, std::vector<imagine::sim::attraction> *attractions, std::vector<imagine::sim::road> *roads,std::vector<imagine::sim::hotel> *hotels, std::vector<imagine::sim::Restaurant> *restaurants);
					void draw(sf::RenderWindow *window, std::vector<imagine::sim::attraction> *attractions, std::vector<imagine::sim::road> *roads,std::vector<imagine::sim::hotel> *hotels, std::vector<imagine::sim::Restaurant> *restaurants);
					sf::Vector2f getMousePos();
				protected:
					bool drawTimerSet = false;
					bool mouseWasPressed = false;
					bool limitClickTimerNotSet = true;
					sf::Clock limitClicks;
					imagine::sim::player *player;
					imagine::sim::actionArea *actionArea;
					sf::Vector2f mousePosition;
					sf::Clock mousePressed;
					sf::Clock drawTimer;
					signed int tileId;

					void update(sf::RenderWindow *window, std::vector<imagine::sim::attraction> *attractions, std::vector<imagine::sim::road> *roads, std::vector<imagine::sim::hotel> *hotels, std::vector<imagine::sim::Restaurant> *restaurants);
				};

		} /* namespace sim */
} /* namespace imagine */

#endif /* SRC_IMAGINESIM_BUILDPROMPTER_HPP_ */
