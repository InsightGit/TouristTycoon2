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

#ifndef TILE_HPP
#define TILE_HPP
#include <SFML/Graphics.hpp>
#include "MenuItem.hpp"

namespace imagine{
    namespace sim{
    	namespace exceptions{
			class maintainceCostNotSetException : public std::runtime_error{
			public:
				maintainceCostNotSetException() : std::runtime_error("Maintaince Cost NOT SET in a tile"){}
			};
    	}
    	namespace types{
    		class SimTime;
    	}
    	class player;
        class tile{
        public:
            sf::Vector2f position;
            sf::Image tileImage;
            sf::Texture tileTexture;
            sf::Sprite tileSprite;
            signed int maintainceCost;
            bool maintainceCostSet = false;
            bool spawned = false;
            int previousHour = -1;

        //tile();
        //virtual ~tile();

            virtual void draw(sf::RenderWindow* window);

            void subtractMaintainceCost(imagine::sim::player *mainPlayer,imagine::sim::types::SimTime *time);
        };
    }
}


#endif // TILE_HPP
