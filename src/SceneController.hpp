#ifndef _scenecontroller_h
#define _scenecontroller_h
#include "MainMenu.hpp"
#include "Scene.hpp"


namespace imagine{
	//class mainMenu;
	class sceneController{
	public:
		std::string fontLocation = "Resources/system/default.ttf";
		sf::RenderWindow displayWindow;
		mainMenu *currentmainMenu = new mainMenu();
		bool useMainMenu = true;
		imagine::types::event currentEvent;
		int eventTimes = 0;

		//sceneController();
		sceneController();

		bool switchScene(scene *scene);
		void update();
		bool draw();
		imagine::types::event getEvent();
		//bool init(sf::RenderWindow *displayWindow); you only have to call this if you did not pass in a window when you created the class
	protected:
		scene *currentScene;


		//bool fullyInit = false;
	};
}
#endif
