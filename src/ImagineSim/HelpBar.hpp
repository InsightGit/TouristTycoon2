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
