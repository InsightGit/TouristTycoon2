/*
 * PopUp.hpp
 *
 *  Created on: Feb 28, 2017
 *      Author: newbobby
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
