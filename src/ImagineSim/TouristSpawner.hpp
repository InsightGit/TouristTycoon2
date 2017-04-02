/*
 * TouristSpawner.hpp
 *
 *  Created on: Mar 11, 2017
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

#ifndef SRC_IMAGINESIM_TOURISTSPAWNER_HPP_
#define SRC_IMAGINESIM_TOURISTSPAWNER_HPP_

#include "Attraction.hpp"
#include "Tourist.hpp"
#include "GameTime.hpp"
#include "NewTourist.hpp"

namespace imagine {
	namespace sim {
		class player;
		class Advertisement;
		class TouristSpawner {
		public:
			signed int limitActiveTourists = 50;

			TouristSpawner(imagine::sim::player *mainPlayer,std::vector<imagine::sim::Advertisement> *advertisements,std::vector<imagine::sim::attraction> *attractions);
			virtual ~TouristSpawner();

			void spawnTourists(const signed int numberOfAttractionsSpawned, const signed int numberOfAdvertisementsSpawned);
		protected:
			signed int pastNumberOfAttractionsSpawned = 0;
			signed int basePopularity = 0;
			signed int pastHour;
			signed int spawnNumber = 0;
			signed int pastTouristNumber = 0;
			signed int activeTourists = 0;
			signed int crime = 0;
			signed int crimeFighting = 0;
			imagine::sim::player *player;
			std::vector<imagine::sim::Advertisement> *allAdvertisements;
			std::vector<imagine::sim::attraction> *allAttractions;

			void update(const signed int numberOfAttractionsSpawned, const signed int numberOfAdvertisementsSpawned);
		};

	} /* namespace sim */
} /* namespace imagine */

#endif /* SRC_IMAGINESIM_TOURISTSPAWNER_HPP_ */
