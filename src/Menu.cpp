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

#include "Menu.hpp"
#include <random>

void imagine::menu::updateMenu(){
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> uni(0, 5);

	auto randomInt = uni(rng);
	activeCircle.setFillColor(sf::Color(activeCircle.getFillColor().r+randomInt, activeCircle.getFillColor().g, activeCircle.getFillColor().b));
	randomInt = uni(rng);
	activeCircle.setFillColor(sf::Color(activeCircle.getFillColor().r, activeCircle.getFillColor().g + randomInt, activeCircle.getFillColor().b));
	randomInt = uni(rng);
	activeCircle.setFillColor(sf::Color(activeCircle.getFillColor().r, activeCircle.getFillColor().g, activeCircle.getFillColor().b + randomInt));
}

void imagine::menu::move(imagine::types::menuDirection direction){
	if (direction == imagine::types::Up) {
		if (activeCirclePosition != 0) {
			activeCircle.move(sf::Vector2f(0, -100));
			activeCirclePosition--;
		}
	}
	else if (direction == imagine::types::Down) {
		if (activeCirclePosition < optionSize) {
			activeCircle.move(sf::Vector2f(0, 100));
			activeCirclePosition++;
		}
	}
}
