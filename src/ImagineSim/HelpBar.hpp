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


#ifndef HELPBAR_HPP
#define HELPBAR_HPP
#include <string>
#include <SFML/Graphics.hpp>

namespace imagine{
    namespace sim{
        class helpBar{
        public:
            helpBar(sf::Font *fontToUse);
            helpBar(sf::Font *fontToUse, const std::string customMessage);
            virtual ~helpBar();

            void switchMessage(std::string helpMessage);
            void switchToPreviousMessage();
            std::string getMessage();
            std::string getPreviousMessage();
            void draw(sf::RenderWindow *window);
        protected:
            sf::RectangleShape helpBarRect = sf::RectangleShape(sf::Vector2f(1368,50));
            sf::Font defaultFont;
            sf::Text helpText;
            sf::Clock previousMessageCallLimit;
            bool previousMessageLimitSet = false;
            std::string previousMessage;
            std::string message = "You do not have any roads connecting your city! Go to the City Items in the build menu to build some."; //default for new game
        };
    }

}


#endif // HELPBAR_HPP
