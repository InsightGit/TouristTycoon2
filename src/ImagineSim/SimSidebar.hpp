#ifndef SIMSIDEBAR_HPP
#define SIMSIDEBAR_HPP
#include <SFML/Graphics.hpp>
#include "../ClickableSprite.hpp"
#include "BuildMenu.hpp"
#include "SimPlayer.hpp"
#include "SimSaveGame.hpp"
#include "Resources/advertIcon.h"
#include "AdvertMenu.hpp"
#include "DeleteBuilding.hpp"

namespace imagine{
    namespace sim{
        namespace types{
            enum sidebarButton{
                none,
                saveButton,
                buildButton,
				advertButton,
				destroyButton
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
            sf::Image advertIconImage;
            sf::Texture advertIconTexture;
            imagine::clickableSprite advertIconSprite;
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
    		imagine::sim::advertMenu *sceneAdvertMenu;
            imagine::sim::DeleteBuilding *sceneDeleteBuilding;
    		imagine::sim::actionArea *actionArea;
    		imagine::sim::simSaveGame *simSaveGame;
    		bool sceneBuildMenuInit = false;
    		bool sceneAdvertMenuInit = false;
    		bool saveGameInit = false;
    		sf::Clock saveGameClickLimit;
    		bool saveClickLimitSet = false;
        };
    }
}


#endif // SIMSIDEBAR_HPP
