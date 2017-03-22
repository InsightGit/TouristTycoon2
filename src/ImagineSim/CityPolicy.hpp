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
		class CityPolicy {
		public:
			bool active = false;

			CityPolicy(const signed int idToUse);
			virtual ~CityPolicy();

			std::string getName() { return name; }
			int getHappinessGained() { return happinessGained; }
			int getId() { return id; }
			int getMaintainceCost() { return maintainceCost; }
		protected:
			std::string name;
			signed int happinessGained;
			signed int id;
			signed int maintainceCost;
		};
	} /* namespace sim */
} /* namespace imagine */

#endif /* SRC_IMAGINESIM_CITYPOLICY_HPP_ */
