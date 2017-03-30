/*
 * AdvertIcon.hpp
 *
 *  Created on: Mar 11, 2017
 *      Author: newbobby
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
