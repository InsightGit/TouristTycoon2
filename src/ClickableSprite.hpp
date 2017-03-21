#ifndef CLICKABLESPRITE_HPP
#define CLICKABLESPRITE_HPP
#include <SFML/Graphics.hpp>

namespace imagine{
   class clickableSprite
   {
      public:
        sf::Sprite sprite;
        sf::Texture *optionalTexture;
        sf::Image *optionalImage;
        std::string category = "N/A";
        sf::Vector2f position;

        clickableSprite();

        bool isClicked(sf::RenderWindow *window);
    };
}


#endif // CLICKABLESPRITE_HPP
