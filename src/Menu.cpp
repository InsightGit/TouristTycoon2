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
