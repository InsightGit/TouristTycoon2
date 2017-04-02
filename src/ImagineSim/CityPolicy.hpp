/*
 * CityPolicy.hpp
 *
 *  Created on: Mar 21, 2017
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


#ifndef SRC_IMAGINESIM_CITYPOLICY_HPP_
#define SRC_IMAGINESIM_CITYPOLICY_HPP_
#include <iostream>

namespace imagine {
	namespace sim {
		namespace types {
			enum conditions{
				noConditions,
				buildPolice
			};
		}
		class player;
		class CityPolicy {
		public:
			bool active = false;

			CityPolicy(const signed int idToUse, imagine::sim::player *mainPlayer, const signed int minimumLevelNeeded = 4, const imagine::sim::types::conditions conditionsNeeded = imagine::sim::types::noConditions);
			virtual ~CityPolicy();

			std::string getName() { return name; }
			int getHappinessGained() { return happinessGained; }
			int getId() { return id; }
			int getMaintainceCost() { return maintainceCost; }
			int getMinimumlevel() { return minimumLevel; }
			imagine::sim::types::conditions getConditions() { return conditions; }

			void update();
		protected:
			imagine::sim::player *player;
			std::string name;
			signed int happinessGained;
			signed int id;
			signed int maintainceCost;
			signed int minimumLevel;
			imagine::sim::types::conditions conditions;
		};
	} /* namespace sim */
} /* namespace imagine */

#endif /* SRC_IMAGINESIM_CITYPOLICY_HPP_ */
