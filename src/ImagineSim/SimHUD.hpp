//#include "../ImagineHUD.hpp"
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
