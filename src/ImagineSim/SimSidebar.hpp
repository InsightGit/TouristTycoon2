#ifndef SIMSIDEBAR_HPP
#define SIMSIDEBAR_HPP
#include <SFML/Graphics.hpp>
#include "../ClickableSprite.hpp"
#include "BuildMenu.hpp"
#include "SimPlayer.hpp"
#include "SimSaveGame.hpp"

namespace imagine{
    namespace sim{
        namespace types{
            enum sidebarButton{
                none,
                saveButton,
                buildButton
            };
        }
        class sidebar
        {
        public:
            sf::RectangleShape sideBarRect = sf::RectangleShape(sf::Vector2f(200,768));
            sf::Image saveIconImage;
            sf::Texture saveIconTexture;
            imagine::clickableSprite saveIconSprite;
            imagine::sim::helpBar *helpBar;
            sf::Image buildIconImage;
            sf::Texture buildIconTexture;
            imagine::clickableSprite buildIconSprite;
    		//imagine::sim::types::levelProgress progress;
            sf::Font defaultFont;

            sidebar(sf::Font *fontToUse, imagine::sim::player *mainPlayer, imagine::sim::helpBar *helpBarToUse,imagine::sim::actionArea *actionAreaToUse);
            virtual ~sidebar();

            void spawn();
            void whenClicked(imagine::sim::types::sidebarButton buttonPressed);
            void update(sf::RenderWindow *window);
            bool display(sf::RenderWindow *window);
        protected:
            imagine::sim::player *player;
    		imagine::sim::buildMenu *sceneBuildMenu;
    		imagine::sim::actionArea *actionArea;
    		imagine::sim::simSaveGame *simSaveGame;
    		bool sceneBuildMenuInit = false;
    		bool saveGameInit = false;
    		sf::Clock saveGameClickLimit;
    		bool saveClickLimitSet = false;
        };
    }
}


#endif // SIMSIDEBAR_HPP
