/*
 * OptionsMenu.hpp
 *
 *  Created on: Mar 29, 2017
 *      Author: newbobby
 */

#ifndef SRC_OPTIONSMENU_HPP_
#define SRC_OPTIONSMENU_HPP_
#include <SFML/Graphics.hpp>

namespace imagine {
	namespace sim {
		class OptionsMenu {
		public:
			sf::RectangleShape menuBox = sf::RectangleShape(sf::Vector2f(300,200));

			OptionsMenu();
			virtual ~OptionsMenu();
		};
	} /* namespace sim */
} /* namespace imagine */

#endif /* SRC_OPTIONSMENU_HPP_ */
