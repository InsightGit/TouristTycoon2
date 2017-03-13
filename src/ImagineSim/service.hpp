/*
 * service.hpp
 *
 *  Created on: Mar 8, 2017
 *      Author: newbobby
 */

#ifndef SRC_IMAGINESIM_SERVICE_HPP_
#define SRC_IMAGINESIM_SERVICE_HPP_

#include "Tile.hpp"

namespace imagine {
	namespace sim {
		class service : public tile {
			public:
				//service();
				//virtual ~service();
				virtual void spawn() = 0;

				virtual void draw(sf::RenderWindow *window) = 0;
			};

	} /* namespace sim */
} /* namespace imagine */

#endif /* SRC_IMAGINESIM_SERVICE_HPP_ */
