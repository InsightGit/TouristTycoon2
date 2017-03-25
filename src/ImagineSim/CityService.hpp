/*
 * CityService.hpp
 *
 *  Created on: Mar 20, 2017
 *      Author: newbobby
 */

#ifndef SRC_IMAGINESIM_CITYSERVICE_HPP_
#define SRC_IMAGINESIM_CITYSERVICE_HPP_

#include "service.hpp"

#include "../ClickableSprite.hpp"
#include "PopUp.hpp"

namespace imagine {
	namespace sim {
		class CityService: public service {
		public:
			bool created = false;

			imagine::clickableSprite cityServiceSprite;

			virtual void spawn() = 0;

			virtual void whenClicked() = 0;

			virtual void update(sf::RenderWindow *window) = 0;

			virtual void draw(sf::RenderWindow *window) = 0;

			virtual bool create(imagine::sim::popUp *notEnoughMoneyPopUp, const sf::Font *fontToUse) = 0;
		};

	} /* namespace sim */
} /* namespace imagine */

#endif /* SRC_IMAGINESIM_CITYSERVICE_HPP_ */
