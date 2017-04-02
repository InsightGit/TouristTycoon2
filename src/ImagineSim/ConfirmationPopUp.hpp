/*
 * confirmationPopUp.hpp
 *
 *  Created on: Mar 5, 2017
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


#ifndef SRC_IMAGINESIM_CONFIRMATIONPOPUP_HPP_
#define SRC_IMAGINESIM_CONFIRMATIONPOPUP_HPP_

#include "../ClickableSprite.hpp"

#include "../Resources/yes.h"
#include "../Resources/no.h"

namespace imagine {
	namespace sim {
		namespace types{
			enum confirmationResponse{
				notYetResponded,
				yes,
				no
			};
		}

		class confirmationPopUp {
		public:
			confirmationPopUp(const std::string messageToUse,sf::Font *fontToUse, const int charSize = 16, const sf::Vector2f position = sf::Vector2f(584,234)); //center of display
			virtual ~confirmationPopUp();

			imagine::sim::types::confirmationResponse getResponse(){ return response; }

			void draw(sf::RenderWindow *window);
		protected:
			imagine::sim::types::confirmationResponse response = imagine::sim::types::notYetResponded;
			sf::RectangleShape messageBox = sf::RectangleShape(sf::Vector2f(300,150));
			sf::Text message;
			sf::Font defaultFont;
			bool popUpDraw = true;
			imagine::clickableSprite yesButton;
			imagine::clickableSprite noButton;

			void update(sf::RenderWindow *window);
		};

	} /* namespace sim */
} /* namespace imagine */

#endif /* SRC_IMAGINESIM_CONFIRMATIONPOPUP_HPP_ */
