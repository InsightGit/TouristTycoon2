/*
 * Restaurant.hpp
 *
 *  Created on: Mar 17, 2017
 *      Author: newbobby
 */

#ifndef SRC_IMAGINESIM_RESTAURANT_HPP_
#define SRC_IMAGINESIM_RESTAURANT_HPP_
#include <SFML/Graphics.hpp>

#include "Tile.hpp"
#include "Tourist.hpp"
#include "PopUp.hpp"

//#include "Resources/"

namespace imagine {
	namespace sim {
		class player;
		namespace types{
			enum foodCuisine{
				Italian,
				Mexican,
				Diner
			};
			enum foodQuality{
				Terrible,
				Poor,
				Ok,
				Good,
				Great,
				Legendary
			};
		}
		class Restaurant : public tile{
		public:
			Restaurant(const int id,imagine::sim::player *mainPlayer, const sf::Vector2f position);
			virtual ~Restauran,sft();
			void spawn();

			imagine::sim::types::foodCuisine getCuisine() { return cuisine; }
			imagine::sim::types::foodQuality getQuality() { return quality; }
			int getCost() { return cost; }
			bool getVacancy() { return vacancy; }

			bool create(imagine::sim::popUp *notEnoughMoneyPopUp, const sf::Font *fontToUse);
			bool checkin(imagine::sim::tourist *tourist);
			void checkout(imagine::sim::tourist *tourist);

			void draw(sf::RenderWindow *window)override;
		protected:
			imagine::sim::player *player;
			imagine::sim::types::foodCuisine cuisine;
			imagine::sim::types::foodQuality quality;
			signed int maxOccupancy;
			signed int currentOccupancy = 0;
			signed int cost;
			signed int buildingCost;
			bool alive = false;
			bool vacancy = true;

			//void update();
		};
	} /* namespace sim */
} /* namespace imagine */

#endif /* SRC_IMAGINESIM_RESTAURANT_HPP_ */
