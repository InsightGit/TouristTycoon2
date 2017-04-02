//#include "../ImagineHUD.hpp"

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


#include "SimPlayer.hpp"
#include <SFML/Graphics.hpp>
#ifndef __SIMHUD_HPP__
#define __SIMHUD_HPP__
namespace imagine{
	namespace sim{
		class HUD{
		public:
			sf::Font defaultFont;
			sf::RectangleShape HUDRectangle;
			sf::Text moneyCounter;
			sf::Image moneyImage;
			sf::Texture moneyIcon;
			sf::Sprite moneySprite;
			sf::Text activeTouristCount;
			sf::Image touristSymbolImage;
			sf::Texture touristSymbolTexture;
			sf::Sprite touristSymbol;
			sf::Text dateText;
			sf::Image calSymbolImage;
			sf::Texture calSymbolTexture;
			sf::Sprite calSymbol;

			player *mainPlayer;

			HUD(sf::Font *fontToUse,player *currentPlayer);
			HUD(const std::string fontToUseLocation,player *currentPlayer);

			void display(sf::RenderWindow *window);
		protected:
			void update();
		};
	}
}
#endif // __SIMHUD_HPP__
