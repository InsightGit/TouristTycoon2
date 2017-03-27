/*
 * DeleteBuilding.h
 *
 *  Created on: Mar 26, 2017
 *      Author: newbobby
 */

#ifndef SRC_IMAGINESIM_DELETEBUILDING_HPP_
#define SRC_IMAGINESIM_DELETEBUILDING_HPP_

#include <SFML/Graphics.hpp>
#include "../ClickableSprite.hpp"

#include "Resources/deleteBuilding.h"
#include "SimPlayer.hpp"

namespace imagine {
	namespace sim {
		class DeleteBuilding {
		public:
			imagine::clickableSprite button;
			sf::RectangleShape selection = sf::RectangleShape(sf::Vector2f(64,64));
			bool active = false;

			DeleteBuilding(imagine::sim::player *mainPlayer, const sf::Vector2f position = sf::Vector2f(50,400));
			virtual ~DeleteBuilding();

			void whenClicked();

			void update(sf::RenderWindow *window);
			void draw(sf::RenderWindow *window);
		protected:
			imagine::sim::player *player;
		};
	} /* namespace sim */
} /* namespace imagine */

#endif /* SRC_IMAGINESIM_DELETEBUILDING_HPP_ */
