/*
 * PublicTransport.hpp
 *
 *  Created on: Mar 26, 2017
 *      Author: newbobby
 */

#ifndef SRC_IMAGINESIM_PUBLICTRANSPORT_HPP_
#define SRC_IMAGINESIM_PUBLICTRANSPORT_HPP_

#include "../ClickableSprite.hpp"

#include "service.hpp"
#include "PopUp.hpp"

namespace imagine {
	namespace sim {
		class PublicTransport: public service {
		public:
			imagine::clickableSprite transportSprite;
			virtual float getPopularityBoost() { return popularityBoost; }
			virtual int getCost() { return cost; }

			virtual void spawn() = 0;
			virtual bool create(imagine::sim::popUp *notEnoughMoneyPopUp, const sf::Font *fontToUse) = 0;
			virtual void draw(sf::RenderWindow *window)override = 0;
		protected:
			float popularityBoost = 0;
			int cost = 0;
			bool created = false;
			bool initlized = false;
			bool spawned = false;
		};
	} /* namespace sim */
} /* namespace imagine */

#endif /* SRC_IMAGINESIM_PUBLICTRANSPORT_HPP_ */
