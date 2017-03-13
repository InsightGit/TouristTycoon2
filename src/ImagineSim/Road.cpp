#include "Road.hpp"
#include <iostream>


imagine::sim::road::road(const imagine::sim::types::roadDirection roadDirectionToUse, sf::Vector2f tilePosition){
	roadDirection=roadDirectionToUse;
	position=tilePosition;
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
