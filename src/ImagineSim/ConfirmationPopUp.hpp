/*
 * confirmationPopUp.hpp
 *
 *  Created on: Mar 5, 2017
 *      Author: newbobby
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
			confirmationPopUp(const std::string messageToUse,sf::Font *fontToUse, sf::Vector2f position = sf::Vector2f(584,234)); //center of display
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
