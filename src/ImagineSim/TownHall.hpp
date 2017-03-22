/*
 * TownHall.hpp
 *
 *  Created on: Mar 20, 2017
 *      Author: newbobby
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
				virtual ~TownHall();

				int getCost(){ return cost; }
				int getCityPolicySize(){ return cityPoliciesCount; }

				void spawn()override;
				bool create(imagine::sim::popUp *notEnoughMoneyPopUp, const sf::Font *fontToUse);

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
