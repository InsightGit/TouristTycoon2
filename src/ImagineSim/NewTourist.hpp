/*
 * NewTourist.hpp
 *
 *  Created on: Apr 1, 2017
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


#ifndef SRC_IMAGINESIM_NEWTOURIST_HPP_
#define SRC_IMAGINESIM_NEWTOURIST_HPP_
#include <random>
#include <vector>

#include <SFML/Graphics.hpp>

#include "Attraction.hpp"

namespace imagine {
	namespace sim {
		class player;
		class NewTourist {
		public:
			NewTourist(imagine::sim::player *mainPlayer);
			virtual ~NewTourist();

			int GetMoney() { return money; }
			void SetMoney(int moneyamounttouse) { money=moneyamounttouse; }
			int GetEnergy() { return energy; }
			void SetEnergy(int energyamounttouse) { energy=energyamounttouse; }

			bool GetSafeToDelete() { return safetodelete; }

			void Draw(sf::RenderWindow *window);

		protected:
			imagine::sim::player *player;

			std::vector<imagine::sim::attraction*> checkedattractions;
			std::vector<int> popularitylist;
			sf::Clock drivingtimer;
			sf::Clock visitingtimer;

			void ChooseAttraction();
			void DriveToAttraction();
			void TourAttraction();
			void Update();

			bool GetJustSpawned() { return justspawned; }
			void SetJustSpawned(const bool justspawnedtouse) { justspawned=justspawnedtouse; }

			bool GetChosenAttraction() { return chosenattraction; }
			void SetChosenAttraction(const bool chosenattractiontouse) { chosenattraction=chosenattractiontouse; }

			bool GetLeaving() { return leaving; }
			void SetLeaving(const bool leavingstatetouse) { leaving=leavingstatetouse; }

			void SetSafeToDelete(bool deletionstatustouse) { safetodelete=deletionstatustouse; }

			bool GetArrivedAtDestination() { return arrivedatdestination; }
			void SetArrivedAtDestination(bool arrivalstatus) { arrivedatdestination=arrivalstatus; }

			bool GetDrivingToDestination() const {
				return drivingtodestination;
			}

			void SetDrivingToDestination(bool drivingtodestination = false) {
				this->drivingtodestination  = drivingtodestination;
			}

			bool GetVisitingAttraction() const {
				return visitingattraction;
			}

			void SetVisitingAttraction(bool visitingattraction = false) {
				this->visitingattraction = visitingattraction;
			}

			int GetCheckedAttractionsSize() const {
				return checkedattractionssize;
			}

			void SetCheckedAttractionsSize(int checkedattractionssize) {
				this->checkedattractionssize = checkedattractionssize;
			}

			imagine::sim::attraction* GetCurrentAttraction() { return currentattraction; }
			void SetCurrentAttraction(const imagine::sim::attraction *attractiontouse) { currentattraction=attractiontouse; }
		private:
			int money;
			int energy;
			int checkedattractionssize = 0;
			bool justspawned = true;
			bool chosenattraction = false;
			bool leaving = false;
			bool safetodelete = false;
			bool arrivedatdestination = false;
			bool drivingtodestination = false;
			bool visitingattraction = false;
			imagine::sim::attraction *currentattraction;
		};
	} /* namespace sim */
} /* namespace imagine */

#endif /* SRC_IMAGINESIM_NEWTOURIST_HPP_ */
