/*
 * CityService.hpp
 *
 *  Created on: Mar 20, 2017
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


#ifndef SRC_IMAGINESIM_CITYSERVICE_HPP_
#define SRC_IMAGINESIM_CITYSERVICE_HPP_

#include "service.hpp"

#include "../ClickableSprite.hpp"
#include "PopUp.hpp"

namespace imagine {
	namespace sim {
		class CityService: public service {
		public:
			bool created = false;

			imagine::clickableSprite cityServiceSprite;

			virtual void spawn() = 0;

			virtual void whenClicked() = 0;

			virtual void update(sf::RenderWindow *window) = 0;

			virtual void draw(sf::RenderWindow *window) = 0;

			virtual bool create(imagine::sim::popUp *notEnoughMoneyPopUp, const sf::Font *fontToUse) = 0;
		};

	} /* namespace sim */
} /* namespace imagine */

#endif /* SRC_IMAGINESIM_CITYSERVICE_HPP_ */
