/*
 * SimSaveGame.hpp
 *
 *  Created on: Mar 2, 2017
 *      Author: newbobby
 */

#ifndef SRC_IMAGINESIM_SIMSAVEGAME_HPP_
#define SRC_IMAGINESIM_SIMSAVEGAME_HPP_
#include <thread>

#include "../ImagineCore.hpp"
#include "../ImagineSaveGame.hpp"
#include "PopUp.hpp"
#include "SimPlayer.hpp"


namespace imagine {
	namespace sim {
		class simSaveGame: public imagine::saveGame{
		public:
			sf::Font defaultFont;
			imagine::sim::popUp *savePopUp;
			int saveResult = -1;

			simSaveGame(imagine::sim::player *playerToUse,const sf::Font *fontToUse, const std::string saveLocation = imagine::core::getApplicationDataDir()+"touristtycoon");
			virtual ~simSaveGame();

			void save()override;
			void launchSaveGameThread();
			void draw(sf::RenderWindow *window);
		protected:
			bool saveGameStarted = false;
			bool drawSavePopUp = false;
			imagine::sim::player *player;
			std::thread saveGameThread;
			std::string saveFileLocation;

			void update();
			//void saveGameThreadFunction();
		};

	} /* namespace sim */
} /* namespace imagine */

#endif /* SRC_IMAGINESIM_SIMSAVEGAME_HPP_ */
