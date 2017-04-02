/*
 * PublicTransport.hpp
 *
 *  Created on: Mar 26, 2017
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
