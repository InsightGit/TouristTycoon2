/*
 * Advertisements.hpp
 *
 *  Created on: Mar 11, 2017
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


#ifndef SRC_IMAGINESIM_ADVERTISEMENT_HPP_
#define SRC_IMAGINESIM_ADVERTISEMENT_HPP_

#include "SimPlayer.hpp"
#include <iostream>

namespace imagine {
	namespace sim {
		namespace types{
			class date{
				public:
					date(const int month, const int day, const int year);
					date();
					void setMonth(const int month);
					void setDay(const int day);
					void setYear(const int year);

					int getMonth();
					int getDay();
					int getYear();
				protected:
					int monthDate;
					int dayDate;
					int yearDate;
			};
		}
		class Advertisement {
		public:
			signed int id;
			bool active = true;
			int multiplier;

			Advertisement(imagine::sim::types::date currentDate, const int idToUse);
			virtual ~Advertisement();

			void update(imagine::sim::types::date currentDate);
		protected:
			imagine::sim::types::date startDate;
		};
	} /* namespace sim */
} /* namespace imagine */

#endif /* SRC_IMAGINESIM_ADVERTISEMENT_HPP_ */
