/*
 * levelCompletePopUp.hpp
 *
 *  Created on: Mar 6, 2017
 *      Author: newbobby
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
