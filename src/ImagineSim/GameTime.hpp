/*
 * GameTime.hpp
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


#ifndef SRC_IMAGINESIM_GAMETIME_HPP_
#define SRC_IMAGINESIM_GAMETIME_HPP_

#include <SFML/Graphics.hpp>
#include "Advertisement.hpp"

namespace imagine {
	namespace sim {
		class player;
		namespace exceptions{
			class invalidSimTimeException : public std::runtime_error {
			public:
				invalidSimTimeException() : std::runtime_error("Invalid Time") {}
			};
		}
		namespace types{
			class SimTime{
			public:
				SimTime(const signed int hourToUse, const signed int minuteToUse);

				signed int getHour() { return hour; }
				signed int getMinute() { return minute; }
				void setHour(const signed int hourToUse);
				void setMinute(const signed int minuteToUse);
			protected:
				signed int hour;
				signed int minute;
			};
		}
		class GameTime {
		public:
			GameTime(imagine::sim::player *mainPlayer);
			GameTime(imagine::sim::player *mainPlayer, imagine::sim::types::SimTime time);
			virtual ~GameTime();

			imagine::sim::types::SimTime getSimTime() { return simTime; }
			void update();
		protected:
			imagine::sim::player *player;
			imagine::sim::types::SimTime simTime = imagine::sim::types::SimTime(0,0);
			sf::Clock dayTime;
		};

	} /* namespace sim */
} /* namespace imagine */

#endif /* SRC_IMAGINESIM_GAMETIME_HPP_ */
