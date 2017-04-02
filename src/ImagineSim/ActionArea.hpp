/*
 * ActionArea.hpp
 *
 *  Created on: Feb 25, 2017
 *      Author: bobby
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
			sf::Clock limitKeyboardPresses;
			bool limitKeyboardPressesSet = false;
			void update();
		};

	} /* namespace sim */
} /* namespace imagine */

#endif /* SRC_IMAGINESIM_ACTIONAREA_HPP_ */
