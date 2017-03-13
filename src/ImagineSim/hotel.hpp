/*
 * hotel.hpp
 *
 *  Created on: Mar 8, 2017
 *      Author: newbobby
 */

#ifndef SRC_IMAGINESIM_HOTEL_HPP_
#define SRC_IMAGINESIM_HOTEL_HPP_

#include "../ClickableSprite.hpp"

#include "service.hpp"
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

			hotel(sf::Vector2f position, imagine::sim::player *player);
			hotel();
			virtual ~hotel();

			bool getVacancy(){ return vacancy; }
			int getCost(){ return cost; }

			bool checkin(imagine::sim::tourist *tourist);
			void checkout(imagine::sim::tourist *tourist);

			void spawn()override;
			void update(sf::RenderWindow *window);
			void draw(sf::RenderWindow *window)override;
		protected:
			imagine::sim::player *player;
			bool vacancy = false;
			bool alive = false;
			int size = 0;
			int maxSize = 20;
			int cost;
		};

	} /* namespace sim */
} /* namespace imagine */

#endif /* SRC_IMAGINESIM_HOTEL_HPP_ */
