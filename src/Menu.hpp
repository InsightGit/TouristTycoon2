//#include ""

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
