/*
 * CruiseTerminal.hpp
 *
 *  Created on: Mar 26, 2017
 *      Author: newbobby
 */

#ifndef SRC_IMAGINESIM_CRUISETERMINAL_HPP_
#define SRC_IMAGINESIM_CRUISETERMINAL_HPP_

#include "PublicTransport.hpp"

#include "Resources/port.h"

namespace imagine {
	namespace sim {
		class player;
		class CruiseTerminal: public PublicTransport {
		public:
			CruiseTerminal(imagine::sim::player *mainPlayer, const sf::Vector2f position);
			CruiseTerminal();
			virtual ~CruiseTerminal();

			void init(imagine::sim::player *mainPlayer, const sf::Vector2f position);
			void spawn()override;
			bool create(imagine::sim::popUp *notEnoughMoneyPopUp, const sf::Font *fontToUse)override;
			void draw(sf::RenderWindow *window)override;
		protected:
			imagine::sim::player *player;
		};

	} /* namespace sim */
} /* namespace imagine */

#endif /* SRC_IMAGINESIM_CRUISETERMINAL_HPP_ */
