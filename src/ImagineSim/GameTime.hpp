/*
 * GameTime.hpp
 *
 *  Created on: Mar 11, 2017
 *      Author: newbobby
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
