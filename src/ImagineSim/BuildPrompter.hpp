/*
 * BuildPrompter.hpp
 *
 *  Created on: Feb 27, 2017
 *      Author: newbobby
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
					std::vector<imagine::sim::road> drawingRoads;
					imagine::sim::road *previousRoad;
					sf::Text cost;
					unsigned drawingRoadLength = 0;

					bool cannotBuild = false;
					bool playerRequestingBuild = false;
			    	bool drawingRoad = false;
			    	bool done = false;

					buildPrompter(imagine::sim::player *mainPlayer,sf::Image tileImageToUse,const signed int tileCost,const sf::Vector2i tileSize,imagine::sim::actionArea *actionAreaToUse,const signed int tileIdToUse, sf::Font *fontToUse);
					buildPrompter(imagine::sim::player *mainPlayer, sf::Texture tileTextureToUse,const signed int tileCost,const sf::Vector2i tileSize,imagine::sim::actionArea *actionAreaToUse,const signed int tileIdToUse,sf::Font *fontToUse);
					virtual ~buildPrompter();

					bool canBuild();
					void spawn(sf::RenderWindow *window, std::vector<imagine::sim::attraction> *attractions, std::vector<imagine::sim::road> *roads,std::vector<imagine::sim::hotel> *hotels, std::vector<imagine::sim::Restaurant> *restaurants);
					void draw(sf::RenderWindow *window, std::vector<imagine::sim::attraction> *attractions, std::vector<imagine::sim::road> *roads,std::vector<imagine::sim::hotel> *hotels, std::vector<imagine::sim::Restaurant> *restaurants);
					sf::Vector2f getMousePos();
				protected:
					bool drawTimerSet=false;
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
