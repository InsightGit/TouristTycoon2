/*
 * Switch.hpp
 *
 *  Created on: Mar 21, 2017
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

#ifndef SRC_SWITCH_HPP_
#define SRC_SWITCH_HPP_
#include <iostream>

#include "ClickableSprite.hpp"

//Resource Files
#include "Resources/activebutton.h"
#include "Resources/activebuttonnotactive.h"
#include "Resources/nobutton.h"
#include "Resources/nobuttonnotactive.h"

namespace imagine {
	class Switch {
	public:
		Switch(const sf::Vector2f position);
		virtual ~Switch();

		bool getSwitchState() { return switchOn; }

		sf::Vector2f getPosition() { return yes.sprite.getPosition(); }

		void draw(sf::RenderWindow *window);
	protected:
		imagine::clickableSprite yes;
		imagine::clickableSprite no;

		bool switchOn = false;

		void update(sf::RenderWindow *window);
	};
} /* namespace imagine */

#endif /* SRC_SWITCH_HPP_ */
