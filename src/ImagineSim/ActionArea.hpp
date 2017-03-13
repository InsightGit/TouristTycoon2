/*
 * ActionArea.hpp
 *
 *  Created on: Feb 25, 2017
 *      Author: bobby
 */
#include <SFML/Graphics.hpp>
#include <jsoncpp/json/value.h>
#include <vector>
#include "Attraction.hpp"
#include "Road.hpp"

#ifndef SRC_IMAGINESIM_ACTIONAREA_HPP_
#define SRC_IMAGINESIM_ACTIONAREA_HPP_

namespace imagine {
	namespace sim {
		class actionArea {
			public:
			sf::View actionAreaView = sf::View(sf::FloatRect(200,100,1168,668));
			sf::Image grassImage;
			sf::Texture repeatingGrassTexture;
			sf::Sprite repeatingGrassSprite;
			Json::Value gameData;
			std::vector<imagine::sim::attraction> attractions;
			std::vector<imagine::sim::road> roads;

			actionArea();
			actionArea(Json::Value saveGameData);
			virtual ~actionArea();

			void spawn();
			void draw(sf::RenderWindow *window);
			protected:
			bool newGame = true;
		};

	} /* namespace sim */
} /* namespace imagine */

#endif /* SRC_IMAGINESIM_ACTIONAREA_HPP_ */
