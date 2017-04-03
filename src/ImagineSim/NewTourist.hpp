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
#include "hotel.hpp"
#include "Restaurant.hpp"

namespace imagine {
	namespace sim {
		namespace types{
			namespace comparefoodquality{
				bool IsLess(imagine::sim::types::foodQuality leftSide, imagine::sim::types::foodQuality rightSide);
			}
		}
		class player;
		class NewTourist {
		public:
			NewTourist(imagine::sim::player *mainPlayer);
			virtual ~NewTourist();

			int GetMoney() { return money_; }
			void SetMoney(int moneyamounttouse) { money_=moneyamounttouse; }
			int GetEnergy() { return energy_; }
			void SetEnergy(int energyamounttouse) { energy_=energyamounttouse; }

			bool GetSafeToDelete() { return safetodelete_; }

			int GetBaseEnergy() const {
				return baseenergy_;
			}

			void Draw(sf::RenderWindow *window);
		protected:
			imagine::sim::player *player;

			std::vector<imagine::sim::Restaurant*> checkedrestaurants;
			std::vector<imagine::sim::attraction*> checkedattractions;
			std::vector<imagine::sim::hotel*> checkedhotels;
			sf::Clock drivingtimer;
			sf::Clock visitingtimer;
			sf::Clock sleepingtimer;
			sf::Clock eatingtimer;

			void DriveToDestination();

			void ChooseAttraction();
			void TourAttraction();

			void ChooseHotel();
			void Sleep();

			void ChooseRestaurant();
			void Eat();

			void Update();

			bool GetJustSpawned() { return justspawned_; }
			void SetJustSpawned(const bool justspawnedtouse) { justspawned_=justspawnedtouse; }

			bool GetChosenAttraction() { return chosenattraction_; }
			void SetChosenAttraction(const bool chosenattractiontouse) { chosenattraction_=chosenattractiontouse; }

			bool GetLeaving() { return leaving_; }
			void SetLeaving(const bool leavingstatetouse) { leaving_=leavingstatetouse; }

			void SetSafeToDelete(bool deletionstatustouse) { safetodelete_=deletionstatustouse; }

			bool GetArrivedAtDestination() { return arrivedatdestination_; }
			void SetArrivedAtDestination(bool arrivalstatus) { arrivedatdestination_=arrivalstatus; }

			bool GetDrivingToDestination() const {
				return drivingtodestination_;
			}

			void SetDrivingToDestination(bool drivingtodestination = false) {
				this->drivingtodestination_ = drivingtodestination;
			}

			bool GetVisitingAttraction() const {
				return visitingattraction_;
			}

			void SetVisitingAttraction(bool visitingattraction = false) {
				this->visitingattraction_ = visitingattraction;
			}

			int GetCheckedAttractionsSize() const {
				return checkedattractionssize_;
			}

			void SetCheckedAttractionsSize(int checkedattractionssize) {
				this->checkedattractionssize_ = checkedattractionssize;
			}

			bool GetChosenHotel() const {
				return chosenhotel_;
			}

			void SetChosenHotel(bool chosenhotel = false) {
				this->chosenhotel_ = chosenhotel;
			}

			imagine::sim::hotel* GetCurrentHotel(){
				return currenthotel_;
			}

			void SetCurrentHotel(const imagine::sim::hotel* currenthotel) {
				this->currenthotel_ = currenthotel;
			}

			int GetCheckedHotelsSize() const {
				return checkedhotelssize_;
			}

			void SetCheckedHotelsSize(int checkedhotelssize = 0) {
				this->checkedhotelssize_ = checkedhotelssize;
			}

			bool GetSleeping() const {
				return sleeping_;
			}

			void SetSleeping(bool sleeping = false) {
				this->sleeping_ = sleeping;
			}

			bool GetHungry() const {
				return hungry_;
			}

			void SetHungry(bool hungry = false) {
				hungry_ = hungry;
			}

			imagine::sim::types::foodCuisine GetPreferredCuisine() const {
				return preferredcuisine_;
			}

			void SetPreferredCuisine(imagine::sim::types::foodCuisine preferredcuisine) {
				preferredcuisine_ = preferredcuisine;
			}

			imagine::sim::Restaurant* GetCurrentRestaurant() {
				return currentrestaurant_;
			}

			void SetCurrentRestaurant(const imagine::sim::Restaurant* currentrestaurant) {
				currentrestaurant_ = currentrestaurant;
			}

			imagine::sim::types::foodQuality GetMinimumQuality() const {
				return minimumquality_;
			}

			void SetMinimumQuality(imagine::sim::types::foodQuality minimumquality) {
				minimumquality_ = minimumquality;
			}

			int GetCheckedRestaurantsSize() const {
				return checkedrestaurantssize_;
			}

			void SetCheckedRestaurantsSize(int checkedrestaurantssize = 0) {
				checkedrestaurantssize_ = checkedrestaurantssize;
			}

			bool GetChosenRestaurant() const {
				return chosenrestaurant_;
			}

			void SetChosenRestaurant(bool chosenrestaurant = false) {
				chosenrestaurant_ = chosenrestaurant;
			}

			bool GetCuisineMatched() const {
				return cuisinematched_;
			}

			void SetCuisineMatched(bool cuisineMatched = true) {
				cuisinematched_ = cuisineMatched;
			}

			bool GetEating() const {
				return eating_;
			}

			void SetEating(bool eating = false) {
				eating_ = eating;
			}

			int GetHappiness() const {
				return happiness_;
			}

			void SetHappiness(int happiness = 20) {
				happiness_ = happiness;
			}

			int GetVisitedAttractionNumber() const {
				return visitedattractionnumber_;
			}

			void SetVisitedAttractionNumber(int visitedattractionnumber = 0) {
				visitedattractionnumber_ = visitedattractionnumber;
			}

			imagine::sim::attraction* GetCurrentAttraction() { return currentattraction_; }
			void SetCurrentAttraction(const imagine::sim::attraction *attractiontouse) { currentattraction_=attractiontouse; }
		private:
			int money_;
			int energy_;
			int baseenergy_;
			int checkedattractionssize_ = 0;
			int checkedhotelssize_ = 0;
			int checkedrestaurantssize_ = 0;
			int happiness_ = 20; //TODO(Bobby): Make happiness a random value based on a psuedorandom number
			int visitedattractionnumber_ = 0;
			bool justspawned_ = true;
			bool chosenattraction_ = false;
			bool leaving_ = false;
			bool safetodelete_ = false;
			bool arrivedatdestination_ = false;
			bool drivingtodestination_ = false;
			bool visitingattraction_ = false;
			bool chosenhotel_ = false;
			bool sleeping_ = false;
			bool hungry_ = false;
			bool chosenrestaurant_ = false;
			bool cuisinematched_ = false;
			bool eating_ = false;
			imagine::sim::Restaurant *currentrestaurant_;
			imagine::sim::hotel *currenthotel_;
			imagine::sim::attraction *currentattraction_;
			imagine::sim::types::foodCuisine preferredcuisine_;
			imagine::sim::types::foodQuality minimumquality_;
		};
	} /* namespace sim */
} /* namespace imagine */

#endif /* SRC_IMAGINESIM_NEWTOURIST_HPP_ */
