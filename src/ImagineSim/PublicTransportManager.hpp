/*
 * PublicTransportManager.hpp
 *
 *  Created on: Mar 26, 2017
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


#ifndef SRC_IMAGINESIM_PUBLICTRANSPORTMANAGER_HPP_
#define SRC_IMAGINESIM_PUBLICTRANSPORTMANAGER_HPP_

#include "CruiseTerminal.hpp"

namespace imagine {
	namespace sim {
		class PublicTransportManager {
		public:
			imagine::sim::CruiseTerminal currentCruiseTerminal;
			bool cruiseTerminalSpawned = false;

			PublicTransportManager();
			virtual ~PublicTransportManager();

			void update();
		protected:
			//imagine::sim::CruiseTerminal NULLCruiseTerminal;
		};
	} /* namespace sim */
} /* namespace imagine */

#endif /* SRC_IMAGINESIM_PUBLICTRANSPORTMANAGER_HPP_ */
