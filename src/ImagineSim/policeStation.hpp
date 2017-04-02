/*
 * policeStation.hpp
 *
 *  Created on: Mar 24, 2017
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


#ifndef SRC_IMAGINESIM_POLICESTATION_HPP_
#define SRC_IMAGINESIM_POLICESTATION_HPP_

#include "CityService.hpp"

#include "Resources/policeStation.h"

namespace imagine {
	namespace sim {
		class player;
		class policeStation: public CityService {
		public:
			imagine::clickableSprite policeSprite;
			policeStation(const int idToUse,imagine::sim::player *mainPlayer,const sf::Vector2f position);
			virtual ~policeStation();

			int getCost() { return cost; }
			int getCrimeFightingAbility() { return crimeFightingAbility; }
			int getId() { return id; }

			void spawn()override;
			void whenClicked()override;
			void update(sf::RenderWindow *window)override;
			void draw(sf::RenderWindow *window)override;
			bool create(imagine::sim::popUp *notEnoughMoneyPopUp, const sf::Font *fontToUse)override;
		protected:
			bool spawned = false;
			int cost;
			int crimeFightingAbility;
			int id;
			imagine::sim::player *player;

		};
	} /* namespace sim */
} /* namespace imagine */

#endif /* SRC_IMAGINESIM_POLICESTATION_HPP_ */
