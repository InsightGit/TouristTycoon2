/*
 * SimMenu.hpp
 *
 *  Created on: Mar 20, 2017
 *      Author: newbobby
 */

#ifndef SRC_IMAGINESIM_SIMMENU_HPP_
#define SRC_IMAGINESIM_SIMMENU_HPP_
#include <SFML/Graphics.hpp>


namespace imagine {
	namespace sim {
		class SimMenu: public menu {
		public:
			sf::RectangleShape menuBox;
			sf::Text title;
			sf::Font defaultFont;

			SimMenu(const sf::Vector2f size,const sf::Vector2f position, const sf::Color fillColor = sf::Color(183,201,255,255));
			SimMenu(const sf::Vector2f size,const sf::Vector2f position, const sf::Color fillColor = sf::Color(183,201,255,255),std::string titleText, sf::Font *fontToUse);
			virtual ~SimMenu();
		};

	} /* namespace sim */
} /* namespace imagine */

#endif /* SRC_IMAGINESIM_SIMMENU_HPP_ */
