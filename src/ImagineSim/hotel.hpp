/*
 * hotel.hpp
 *
 *  Created on: Mar 8, 2017
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


#ifndef SRC_IMAGINESIM_HOTEL_HPP_
#define SRC_IMAGINESIM_HOTEL_HPP_

#include <iostream>

#include "../ClickableSprite.hpp"

#include "service.hpp"
#include "PopUp.hpp"

//#include "Tourist.hpp"
//#include "SimPlayer.hpp"

#include "Resources/hotel.h"

namespace imagine {
	namespace sim {
		class player;
		class tourist;
		class NewTourist;
		class hotel : public service {
		public:
			sf::Vector2f tilePosition;
			imagine::clickableSprite hotelSprite;

			hotel(const signed int idToUse, const sf::Vector2f position, imagine::sim::player *mainPlayer);
			hotel();
			virtual ~hotel();

			bool getVacancy(){ return vacancy; }
			signed int getCost(){ return cost; }
			signed int getId() { return id; }
			signed int getCurrentOccupancy() { return size; }
			signed int getPopularity() const {
				return popularity;
			}

			bool checkin(imagine::sim::tourist *tourist);
			void checkout(imagine::sim::tourist *tourist);

			bool checkin(imagine::sim::NewTourist *tourist);
			void checkout();

			bool create(imagine::sim::popUp *notEnoughMoneyPopUp, const sf::Font *fontToUse);

			void spawn()override;
			void update(sf::RenderWindow *window);
			void draw(sf::RenderWindow *window)override;
		protected:
			imagine::sim::player *player;
			bool vacancy = true;
			bool alive = false;
			int size = 0;
			int maxSize = 300;
			signed int cost;
			signed int buildingCost;
			signed int id;

			void setPopularity(signed int popularity) {
				this->popularity = popularity;
			}
		private:
			signed int popularity = 0;
		};

	} /* namespace sim */
} /* namespace imagine */

#endif /* SRC_IMAGINESIM_HOTEL_HPP_ */
