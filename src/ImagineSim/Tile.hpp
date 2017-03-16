#ifndef TILE_HPP
#define TILE_HPP
#include <SFML/Graphics.hpp>
#include "MenuItem.hpp"

namespace imagine{
    namespace sim{
        class tile{
        public:
            sf::Vector2f position;
            sf::Image tileImage;
            sf::Texture tileTexture;
            sf::Sprite tileSprite;
            bool spawned = false;

        //tile();
        //virtual ~tile();

            virtual void draw(sf::RenderWindow* window);
        };
    }
}


#endif // TILE_HPP
