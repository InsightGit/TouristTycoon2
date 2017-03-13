#ifndef _mainmenu_h
#define _mainmenu_h
#include "Menu.hpp"
#include "Scene.hpp"
#include <list>


namespace imagine{
	class sceneController;
	class mainMenu : public menu, public scene{
	public:
		sf::Font defaultFont;
		sf::Text startText;
		sf::Text loadGameText;
		sf::Text optionsText;
		sf::Text quitText;

		mainMenu();
		mainMenu(const std::string fontLocation);

		bool spawn();
		void onEnter(sceneController *sceneController);
		scene getScene();
	};
}
#endif
