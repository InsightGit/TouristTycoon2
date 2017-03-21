/*
 * TownHall.hpp
 *
 *  Created on: Mar 20, 2017
 *      Author: newbobby
 */

#ifndef SRC_IMAGINESIM_TOWNHALL_HPP_
#define SRC_IMAGINESIM_TOWNHALL_HPP_

#include "Resources/TownHall.h"

#include "CityService.hpp"
#include "PopUp.hpp"

namespace imagine {
	namespace sim {
		class player;
		class TownHall: public CityService {
			public:
				imagine::sim::SimMenu *cityManagmentMenu;

				TownHall(imagine::sim::player *mainPlayer, const sf::Vector2f position, const sf::Font *fontToUse);
				virtual ~TownHall();

				int getCost(){ return cost; }

				void spawn()override;
				bool create(imagine::sim::popUp *notEnoughMoneyPopUp, const sf::Font *fontToUse);

				void draw(sf::RenderWindow *window)override;
			protected:
				imagine::sim::player *player;
				sf::Font defaultFont;
				int cost = 4000;
				bool created = false;

				void whenClicked()override;
				void update(sf::RenderWindow *window)override;
		};
	} /* namespace sim */
} /* namespace imagine */

#endif /* SRC_IMAGINESIM_TOWNHALL_HPP_ */
