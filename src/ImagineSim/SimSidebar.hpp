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
