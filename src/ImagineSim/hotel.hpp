/*
 * hotel.hpp
 *
 *  Created on: Mar 8, 2017
 *      Author: newbobby
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

			bool checkin(imagine::sim::tourist *tourist);
			void checkout(imagine::sim::tourist *tourist);

			bool create(imagine::sim::popUp *notEnoughMoneyPopUp, const sf::Font *fontToUse);

			void spawn()override;
			void update(sf::RenderWindow *window);
			void draw(sf::RenderWindow *window)override;
		protected:
			imagine::sim::player *player;
			bool vacancy = false;
			bool alive = false;
			int size = 0;
			int maxSize = 20;
			signed int cost;
			signed int buildingCost;
			signed int id;
		};

	} /* namespace sim */
} /* namespace imagine */

#endif /* SRC_IMAGINESIM_HOTEL_HPP_ */
