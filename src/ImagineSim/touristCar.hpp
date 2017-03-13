/*
 * touristCar.hpp
 *
 *  Created on: Mar 7, 2017
 *      Author: newbobby
 */

#ifndef SRC_IMAGINESIM_TOURISTCAR_HPP_
#define SRC_IMAGINESIM_TOURISTCAR_HPP_

#include <SFML/Graphics.hpp>

#include "Resources/Car.h"

namespace imagine {
	namespace sim {
		class touristCar {
		public:
			bool display = false;
			sf::Image carImage;
			sf::Texture carTexture;
			sf::Sprite carSprite;

			touristCar(const sf::Vector2f position);
			virtual ~touristCar();

			void spawn();
			void draw(sf::RenderWindow *window);
		};

	} /* namespace sim */
} /* namespace imagine */

#endif /* SRC_IMAGINESIM_TOURISTCAR_HPP_ */
