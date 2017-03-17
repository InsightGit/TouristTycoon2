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
