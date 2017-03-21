//#include ""
#ifndef _menu_h
#define _menu_h
#include <SFML/Graphics.hpp>
#include "ImagineCore.hpp"
//#include "SceneController.hpp"


namespace imagine{
	class sceneController;
	class menu{
	public:
		int optionSize;
		int activeCirclePosition = 0;

		sf::RectangleShape activeCircle = sf::RectangleShape(sf::Vector2f(100,50));

		//virtual menu() = 0;

		void updateMenu();
		void move(imagine::types::menuDirection direction);
		//virtual void onEnter(sceneController *sceneController) = 0;
	};
}
#endif
