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

#ifndef ROAD_HPP
#define ROAD_HPP
#include "Tile.hpp"
//Including road image resource files
#include "Resources/roadIcon.h"
#include "Resources/roadturn.h"

namespace imagine{
	namespace sim{
		namespace types{
			enum roadDirection{
				straight,
				leftToDown,
				rightToDown,
				leftToUp,
				rightToUp
			};
		}
		class road : public tile{
		public:
			static const int cost = 100;
			static const int xSize = 1;
			static const int ySize = 1;
			sf::Texture roadTexture;

			road(const imagine::sim::types::roadDirection roadDirectionToUse,sf::Vector2f tilePosition);
			virtual ~road();

			imagine::sim::types::roadDirection getRoadDirection() { return roadDirection; }
			void spawn();
		protected:
			imagine::sim::types::roadDirection roadDirection;
		};
	}
}

#endif // ROAD_HPP
