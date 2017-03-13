/*
 * MessageBox.hpp
 *
 *  Created on: Feb 3, 2017
 *      Author: newbobby
 */
#include "../ImagineCore.hpp"
#include <list>
#include <SFML/Graphics.hpp>

#ifndef IMAGINERPG_MESSAGEBOX_HPP_
#define IMAGINERPG_MESSAGEBOX_HPP_
namespace imagine{
	namespace RPG{
		class messageBox{
		public:
			//imagine::types::rgbColor boxColor;
			sf::Font messageFont;
			sf::Text message;
			sf::Sprite messageBoxSprite;
			std::vector<std::string> messages;

			messageBox(sf::Font defaultFont,std::vector<std::string> messagesToDisplay);

			void onNext();
		protected:
			sf::Texture messageBoxTexture;
			int messageSize;
			int currentMessage = 0;
		};
	}
}




#endif /* IMAGINERPG_MESSAGEBOX_HPP_ */
