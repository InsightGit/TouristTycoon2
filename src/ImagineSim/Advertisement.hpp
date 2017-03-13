/*
 * Advertisements.hpp
 *
 *  Created on: Mar 11, 2017
 *      Author: newbobby
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
