/*
 * PublicTransportManager.hpp
 *
 *  Created on: Mar 26, 2017
 *      Author: newbobby
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
