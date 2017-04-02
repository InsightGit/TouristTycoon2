/*
 * TownHall.hpp
 *
 *  Created on: Mar 20, 2017
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

#ifndef SRC_IMAGINESIM_TOWNHALL_HPP_
#define SRC_IMAGINESIM_TOWNHALL_HPP_

#include <iostream>

#include "../Switch.hpp"

#include "CityService.hpp"
#include "PopUp.hpp"
#include "SimMenu.hpp"
#include "CityPolicy.hpp"

#include "Resources/TownHall.h"

namespace imagine {
	namespace sim {
		class player;
		class TownHall: public CityService {
			public:
				imagine::sim::SimMenu *cityManagmentMenu;
				std::vector<imagine::Switch> cityPoliciesSwitches;
				std::vector<sf::Text> cityPolicyDescriptions;
				std::vector<int> cityPolicyMinumumLevels;
				std::vector<imagine::sim::CityPolicy> cityPolicies;
				bool cityManagmentMenuSpawned = false;
				bool drawManagmentMenu = false;

				TownHall(imagine::sim::player *mainPlayer, const sf::Vector2f position, const sf::Font *fontToUse);
				TownHall(imagine::sim::player *mainPlayer, const sf::Vector2f position, const sf::Font *fontToUse, const std::vector<imagine::sim::CityPolicy> *cityPoliciesToUse);
				virtual ~TownHall();

				int getCost(){ return cost; }
				int getCityPolicySize(){ return cityPoliciesCount; }

				void spawn()override;
				bool create(imagine::sim::popUp *notEnoughMoneyPopUp, const sf::Font *fontToUse)override;

				void draw(sf::RenderWindow *window)override;
			protected:
				std::vector<bool> pastClickStates;
				imagine::sim::player *player;
				sf::Font defaultFont;
				int cost = 4000;
				signed int cityPoliciesCount = 0;
				bool created = false;
				bool pastMouseState = false;
				sf::Clock mouseTimer;

				void whenClicked()override;
				void update(sf::RenderWindow *window)override;
		};
	} /* namespace sim */
} /* namespace imagine */

#endif /* SRC_IMAGINESIM_TOWNHALL_HPP_ */
