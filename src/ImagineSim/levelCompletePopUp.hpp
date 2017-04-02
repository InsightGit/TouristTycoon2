/*
 * levelCompletePopUp.hpp
 *
 *  Created on: Mar 6, 2017
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


#ifndef SRC_IMAGINESIM_LEVELCOMPLETEPOPUP_HPP_
#define SRC_IMAGINESIM_LEVELCOMPLETEPOPUP_HPP_
#include <SFML/Graphics.hpp>
#include "../ClickableSprite.hpp"

namespace imagine {
	namespace sim {
		class levelCompletePopUp {
			public:
				sf::Font defaultFont;
				sf::Text message;
				sf::Image templateImage;
				sf::Texture templateTexture;
				sf::Sprite templateSprite;
				std::string unlockText;
				sf::Text unlockMessage;
				imagine::clickableSprite okButton;
				int newRoads = -1;
				int newAttractions = -1;
				int newServices = -1;
				bool unlockedAnything = false;

				levelCompletePopUp(const sf::Vector3i howManyNewItems, const std::string messageToDisplay,sf::Font *fontToUse,const sf::Vector2f position = sf::Vector2f(584,234));
				virtual ~levelCompletePopUp();

				bool getDrawingStatus();
				void draw(sf::RenderWindow *window);
			protected:
				bool drawPopUp = false;

				void update(sf::RenderWindow *window);
			};

	} /* namespace sim */
} /* namespace imagine */

#endif /* SRC_IMAGINESIM_LEVELCOMPLETEPOPUP_HPP_ */
