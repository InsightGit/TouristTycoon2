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
