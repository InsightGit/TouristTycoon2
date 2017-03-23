/*
 * TouristSpawner.hpp
 *
 *  Created on: Mar 11, 2017
 *      Author: newbobby
 */

#ifndef SRC_IMAGINESIM_TOURISTSPAWNER_HPP_
#define SRC_IMAGINESIM_TOURISTSPAWNER_HPP_

#include "Attraction.hpp"
#include "Tourist.hpp"
#include "GameTime.hpp"

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
			imagine::sim::player *player;
			std::vector<imagine::sim::Advertisement> *allAdvertisements;
			std::vector<imagine::sim::attraction> *allAttractions;

			void update(const signed int numberOfAttractionsSpawned, const signed int numberOfAdvertisementsSpawned);
		};

	} /* namespace sim */
} /* namespace imagine */

#endif /* SRC_IMAGINESIM_TOURISTSPAWNER_HPP_ */
