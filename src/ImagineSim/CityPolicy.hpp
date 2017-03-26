/*
 * CityPolicy.hpp
 *
 *  Created on: Mar 21, 2017
 *      Author: newbobby
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
