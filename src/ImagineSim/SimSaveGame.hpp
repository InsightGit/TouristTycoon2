/*
 * SimSaveGame.hpp
 *
 *  Created on: Mar 2, 2017
 *      Author: newbobby
 */

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
