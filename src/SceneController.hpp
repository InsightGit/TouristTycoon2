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
