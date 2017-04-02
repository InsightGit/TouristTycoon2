/*
 * SimMenu.hpp
 *
 *  Created on: Mar 20, 2017
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
