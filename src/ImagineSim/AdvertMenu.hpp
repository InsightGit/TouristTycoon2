/*
 * AdvertIcon.hpp
 *
 *  Created on: Mar 11, 2017
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


#ifndef SRC_IMAGINESIM_ADVERTMENU_HPP_
#define SRC_IMAGINESIM_ADVERTMENU_HPP_
#include "../Menu.hpp"
#include "Advertisement.hpp"
#include "MenuItem.hpp"
#include "SimPlayer.hpp"
#include "PopUp.hpp"
#include "Resources/laptop.h"

namespace imagine {
	namespace sim {
		class advertMenu: public menu {
		public:
			std::vector<imagine::clickableSprite> activeSprites;
			signed int activeSpritesLength = 0;
			sf::RectangleShape menuBox = sf::RectangleShape(sf::Vector2f(400,300));

			bool drawMenu = false;

			advertMenu(imagine::sim::player *mainPlayer,sf::Font *fontToUse);
			virtual ~advertMenu();

			void spawn();

			void draw(sf::RenderWindow *window);
		protected:
			sf::Font defaultFont;
			std::vector<imagine::sim::menuItem> menuItems;
			sf::Clock limitClicks;
			sf::Clock limitBuys;
			bool limitBuysSet = false;
			bool limitClicksTimerSet = false;
			bool popUpSpawned = false;
			signed int menuItemsLength = 0;
			imagine::sim::player *player;
			imagine::sim::popUp *popUp;

			void update(sf::RenderWindow *window);
		};

	} /* namespace sim */
} /* namespace imagine */

#endif /* SRC_IMAGINESIM_ADVERTMENU_HPP_ */
