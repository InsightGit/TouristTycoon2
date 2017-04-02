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
