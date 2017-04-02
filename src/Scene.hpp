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

#ifndef _scene_h
#define _scene_h
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <jsoncpp/json/reader.h>

#include "SceneMusicPlayer.hpp"
#include "ImagineSim/SimHUD.hpp"
#include "ImagineSim/SimSidebar.hpp"
#include "ImagineSim/SimPlayer.hpp"
#include "ImagineSim/HelpBar.hpp"
#include "ImagineSim/SimPlayer.hpp"
#include "ImagineSim/ActionArea.hpp"
#include "ImagineSim/GameTime.hpp"
#include "ImagineSim/TouristSpawner.hpp"

namespace imagine{
    class mainMenu;
	class scene : sf::NonCopyable{
	public:
		int sceneNum = 0;
		sf::Font defaultFont;
		imagine::sceneMusicPlayer *musicPlayer;
		imagine::sim::HUD *sceneHUD;
		imagine::sim::player *playerInScene;
		imagine::sim::sidebar *sceneSidebar;
		imagine::mainMenu *currentmainMenu;
		imagine::sim::helpBar *sceneHelpBar;
		imagine::sim::actionArea *sceneActionArea;
		std::string sceneName = "MainMenu";
		bool useJSONData = false; //using JSON data is HIGHLY ENCOURAGED for everything but the main menu
		//std::vector<tile> sceneTiles uncomment when tile class is created
		scene();
		scene(const int windowSceneNum,sf::Font *fontToUse, imagine::sim::player *mainPlayer);
		scene(const int windowSceneNum,const Json::Value *JSONSceneData,const sf::Font *fontToUse, imagine::sim::player *mainPlayer);

		bool spawn();
		void update(sf::RenderWindow *window);
		void draw(sf::RenderWindow *window);
	protected:
		Json::Value sceneData;
		sf::Music music;
	};
}
#endif
