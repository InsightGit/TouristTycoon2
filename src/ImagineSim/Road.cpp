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

#include "Road.hpp"
#include <iostream>


imagine::sim::road::road(const imagine::sim::types::roadDirection roadDirectionToUse, sf::Vector2f tilePosition){
	roadDirection=roadDirectionToUse;
	position=tilePosition;
	maintainceCost=50;
	maintainceCostSet = true;
}

imagine::sim::road::~road(){

}

void imagine::sim::road::spawn(){
	if(roadDirection == imagine::sim::types::straight){
		std::cout << "roadSpawned\n";
		tileImage.create(roadIconSmall.width,roadIconSmall.height,roadIconSmall.pixel_data);
		roadTexture.loadFromImage(tileImage);
		tileSprite.setTexture(roadTexture);
		tileSprite.setPosition(position);
		tileSprite.setScale(sf::Vector2f(0.5,0.5));
	}
}
