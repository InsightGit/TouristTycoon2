/*
 * MenuItem.hpp
 *
 *  Created on: Feb 27, 2017
 *      Author: newbobby
 */

#ifndef SRC_IMAGINESIM_MENUITEM_HPP_
#define SRC_IMAGINESIM_MENUITEM_HPP_

#include <SFML/Graphics.hpp>

#include "../ClickableSprite.hpp"

namespace imagine {
	namespace sim {
		class menuItem: public clickableSprite {
		public:
			sf::Font defaultFont;
			sf::Text itemName;

			bool drawString = false;

			menuItem(sf::Font *fontToUse);
			virtual ~menuItem();

			//void draw(sf::RenderWindow *window); //not required, just a shortHand
		};

	} /* namespace sim */
} /* namespace imagine */

#endif /* SRC_IMAGINESIM_MENUITEM_HPP_ */
