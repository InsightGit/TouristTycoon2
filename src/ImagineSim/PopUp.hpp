/*
 * PopUp.hpp
 *
 *  Created on: Feb 28, 2017
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


#ifndef SRC_IMAGINESIM_POPUP_HPP_
#define SRC_IMAGINESIM_POPUP_HPP_
#include "../ClickableSprite.hpp"

namespace imagine {
	namespace sim {

		class popUp {
		public:
			sf::RectangleShape messageBox = sf::RectangleShape(sf::Vector2f(300,150));
			sf::Font defaultFont;
			sf::Text message;
			imagine::clickableSprite okButton;

			popUp(const std::string messageToDisplay, const sf::Font *fontToUse, sf::Vector2f position = sf::Vector2f(584,234)); //center of display
			virtual ~popUp();

			void draw(sf::RenderWindow *window);
		protected:
			std::string messageDisplayed;
			bool popUpDraw = false;
			void update(sf::RenderWindow *window);
		};

	} /* namespace sim */
} /* namespace imagine */

#endif /* SRC_IMAGINESIM_POPUP_HPP_ */
