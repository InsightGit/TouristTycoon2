/*
 * policeStation.hpp
 *
 *  Created on: Mar 24, 2017
 *      Author: newbobby
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
