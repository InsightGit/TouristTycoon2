/*
 * SimMenu.hpp
 *
 *  Created on: Mar 20, 2017
 *      Author: newbobby
 */

#ifndef SRC_IMAGINESIM_SIMMENU_HPP_
#define SRC_IMAGINESIM_SIMMENU_HPP_
#include <SFML/Graphics.hpp>
#include "../Menu.hpp"

namespace imagine {
	namespace sim {
		class SimMenu: public menu {
		public:
			sf::RectangleShape menuBox;
			sf::Text title;
			sf::Font defaultFont;

			SimMenu(const sf::Vector2f size,const sf::Vector2f position, const sf::Color fillColor = sf::Color(183,201,255,255));
			SimMenu(const sf::Vector2f size,const sf::Vector2f position,std::string titleText, sf::Font *fontToUse, const sf::Color fillColor = sf::Color(183,201,255,255));
			virtual ~SimMenu();
		};

	} /* namespace sim */
} /* namespace imagine */

#endif /* SRC_IMAGINESIM_SIMMENU_HPP_ */
