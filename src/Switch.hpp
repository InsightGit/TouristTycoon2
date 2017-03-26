/*
 * Switch.hpp
 *
 *  Created on: Mar 21, 2017
 *      Author: newbobby
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
