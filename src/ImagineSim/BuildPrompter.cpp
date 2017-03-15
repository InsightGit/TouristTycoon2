/*
 * BuildPrompter.cpp
 *
 *  Created on: Feb 27, 2017
 *      Author: newbobby
 */

#include "BuildPrompter.hpp"
#include <iostream>


imagine::sim::buildPrompter::buildPrompter(imagine::sim::player *mainPlayer,sf::Image tileImageToUse,const signed int tileCost,const sf::Vector2i tileSize,imagine::sim::actionArea *actionAreaToUse,const signed int tileIdToUse, sf::Font *fontToUse) {
	// TODO Auto-generated constructor stub
	player=mainPlayer;
	tilePlacingImage=tileImageToUse;
	moneyNeeded=tileCost;
	defaultFont=*fontToUse;
	tilePlacingSize=tileSize;
	actionArea=actionAreaToUse;
	tileId=tileIdToUse;
}

imagine::sim::buildPrompter::buildPrompter(imagine::sim::player *mainPlayer,sf::Texture tileTextureToUse,const signed int tileCost,const sf::Vector2i tileSize,imagine::sim::actionArea *actionAreaToUse,const signed int tileIdToUse, sf::Font *fontToUse) {
	player=mainPlayer;
	tilePlacingTexture=tileTextureToUse;
	moneyNeeded=tileCost;
	defaultFont=*fontToUse;
	tilePlacingSize=tileSize;
	actionArea=actionAreaToUse;
	tileId=tileIdToUse;
}

imagine::sim::buildPrompter::~buildPrompter() {
	// TODO Auto-generated destructor stub
	delete notEnoughMoneyPopUp;
}

bool imagine::sim::buildPrompter::canBuild(){
	if(player->money>=moneyNeeded){
		return true;
	}else if(player->money<=moneyNeeded){
		return false;
	}else{
		return false;
	}
}

void imagine::sim::buildPrompter::spawn(sf::RenderWindow *window, std::vector<imagine::sim::attraction> *attractions, std::vector<imagine::sim::road> *roads,std::vector<imagine::sim::hotel> *hotels){
	if(!canBuild()){
		notEnoughMoneyPopUp = new imagine::sim::popUp("You don't have enough money.",&defaultFont);
		cannotBuild = true;
	}else{
		//
		float tempX = 128*tilePlacingSize.x;
		float tempY = 128*tilePlacingSize.y;
		buildArea = sf::RectangleShape(sf::Vector2f(tempX,tempY));
		mousePosition = sf::Vector2f(sf::Mouse::getPosition(*window));

		bool collides = false;
		for(int i = 0; i < attractions->size();i++){
			if(attractions->at(i).tileSprite.getGlobalBounds().contains(mousePosition)){
				collides=true;
			}
		}
		for(int i = 0; i < roads->size();i++){
			if(roads->at(i).tileSprite.getGlobalBounds().contains(mousePosition)){
				collides=true;
			}
		}
		if(collides){
			buildArea.setOutlineColor(sf::Color::Red);
		}else{
			buildArea.setOutlineColor(sf::Color(285,100,80,255));
		}
		buildArea.setOutlineThickness(4);
		buildArea.setPosition(mousePosition);
		if(tileId==0){
			drawingRoad=true;
		}
	}
	cost.setFont(defaultFont);
	cost.setFillColor(sf::Color::White);
	cost.setCharacterSize(30);
	cost.setPosition(sf::Vector2f(1068,650));
}

void imagine::sim::buildPrompter::update(sf::RenderWindow *window, std::vector<imagine::sim::attraction> *attractions, std::vector<imagine::sim::road> *roads,std::vector<imagine::sim::hotel> *hotels){
	if(!drawTimerSet){
		drawTimer.restart();
		drawTimerSet=true;
	}
	buildArea = sf::RectangleShape(sf::Vector2f(64*tilePlacingSize.x,64*tilePlacingSize.y));
	sf::Vector2i mouse = sf::Mouse::getPosition(*window);
	mousePosition = (sf::Vector2f)(mouse);
	//std::cout << mousePosition.x << " Y:" << mousePosition.y << "\n";

	bool collides = false;
	for(int i = 0; i < attractions->size();i++){
		if(attractions->at(i).tileSprite.getGlobalBounds().contains(mousePosition)){
			collides=true;
		}
	}
	for(int i = 0; i < roads->size();i++){
		if(roads->at(i).tileSprite.getGlobalBounds().contains(mousePosition)){
			collides=true;
		}
	}
	if(collides || !actionArea->actionAreaView.getViewport().intersects(buildArea.getGlobalBounds())){
		buildArea.setOutlineColor(sf::Color::Red);
	}else{
		buildArea.setOutlineColor(sf::Color(285,100,80,255));
	}
	buildArea.setFillColor(sf::Color::Transparent);
	buildArea.setOutlineThickness(4);
	buildArea.setPosition(mousePosition);

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
		done=true;
	}
	if(drawTimer.getElapsedTime().asSeconds() >= 1 && drawTimerSet){
		if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
			mouseWasPressed=true;
			mousePressed.restart();
			//std::cout << "Mouse Pressed\n";
		}
		if(!collides && !done){
			if(tileId==0){
				if(drawingRoad && !done){
					if(drawingRoadLength==0){
						sf::Vector2f mouseTemp = mousePosition;
						imagine::sim::road newRoad(imagine::sim::types::straight,mouseTemp);
						//std::cout << std::to_string(mousePosition.x) << "Y:"<< std::to_string(mousePosition.y) << "\n";
						newRoad.spawn();
						drawingRoads.push_back(newRoad);
						previousRoad=&drawingRoads[drawingRoadLength];
						drawingRoadLength++;
						std::clog << newRoad.tileSprite.getPosition().x << "Y:" << newRoad.tileSprite.getPosition().y << "\n";
					}else{
						sf::Vector2f mouseTemp = mousePosition;
						imagine::sim::road newRoad(imagine::sim::types::straight,mouseTemp);
						std::cout << std::to_string(mousePosition.x) << "Y:"<< std::to_string(mousePosition.y) << "\n";
						newRoad.spawn();
						if(!newRoad.tileSprite.getGlobalBounds().intersects(previousRoad->tileSprite.getGlobalBounds())){
							drawingRoads.push_back(newRoad);
							previousRoad=&drawingRoads[drawingRoadLength];
							drawingRoadLength++;
						}
						std::clog << newRoad.tileSprite.getPosition().x << "Y:" << newRoad.tileSprite.getPosition().y << "\n";
					}
				}else if(drawingRoadLength>=0 && mouseWasPressed && mousePressed.getElapsedTime().asSeconds() >= 0.5){
					if(drawingRoadLength*50 <= player->money){
						for(int i = 0; drawingRoadLength > i;++i){
							player->roadsCreated.push_back(drawingRoads[i]);
							std::clog << player->roadsCreated[i].tileSprite.getPosition().x << "Y:" << player->roadsCreated[i].tileSprite.getPosition().y << "\n";
						}
						player->numberOfRoadsSpawned = drawingRoadLength+player->numberOfRoadsSpawned;
						player->money=player->money-drawingRoadLength*50;
					}else{
						notEnoughMoneyPopUp = new imagine::sim::popUp("You don't have enough money.",&defaultFont);
						cannotBuild=true;
					}
					done=true;
				}


				/*}else{
					imagine::sim::road *newRoad = new imagine::sim::road(imagine::sim::types::straight,mousePosition);
					newRoad->spawn();
					//if(previousRoad->tileSprite.getPosition().y == newRoad->tileSprite.getPosition().y && previousRoad->tileSprite.getPosition().x+64 == previousRoad->tileSprite.getPosition().x){
						drawingRoads.push_back(*newRoad);
						previousRoad=&drawingRoads[drawingRoadLength];
						drawingRoadLength++;
					//}else{
						delete newRoad;
					//}
				}*/
			}else if(tileId==1){
				if(mouseWasPressed && mousePressed.getElapsedTime().asSeconds() >= 0.1){
					std::cout << "TILEID=1\n";
					imagine::sim::attraction attraction = imagine::sim::attraction(1,player,mousePosition);
					limitClicks.restart();
					limitClickTimerNotSet = false;
					if(attraction.create(notEnoughMoneyPopUp,&defaultFont)){
						done=true;
					}else{
						cannotBuild=true;
					}
				}else if(!limitClickTimerNotSet && limitClicks.getElapsedTime().asSeconds() >= 0.5){
					limitClickTimerNotSet=true;
				}
			}
		}
	}
	if(drawingRoadLength*50 > player->money){
		cost.setFillColor(sf::Color::Red);
	}else{
		cost.setFillColor(sf::Color::White);
	}
	cost.setString("Cost:"+std::to_string(drawingRoadLength*50));
	/*if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		if(!collides){
			playerRequestingBuild=true;
		}
	}*/

}

sf::Vector2f imagine::sim::buildPrompter::getMousePos(){
	return mousePosition;
}

void imagine::sim::buildPrompter::draw(sf::RenderWindow *window, std::vector<imagine::sim::attraction> *attractions, std::vector<imagine::sim::road> *roads,std::vector<imagine::sim::hotel> *hotels){
	update(window,attractions,roads,hotels);
	if(!done){
		if(cannotBuild){
			notEnoughMoneyPopUp->draw(window);
		}else{
			if(drawingRoad && drawingRoadLength!=0){
				for(int i = 0;drawingRoadLength > i;++i){
					window->draw(drawingRoads[i].tileSprite);
				}
			}
			window->draw(buildArea);
			window->draw(cost);
		}
	}
}
/*				for(int i = 0; buildingPrompter->drawingRoadLength > i;++i){
					if(placeTimerNotSet){
						limitPlaceClicks.restart();
						placeTimerNotSet=false;

						imagine::sim::road newRoad(imagine::sim::types::straight,buildingPrompter->getMousePos());
						newRoad.spawn();
						player->roadsCreated.push_back(newRoad);
						player->numberOfRoadsSpawned++;
						drawPrompter=false;
					}else if(limitPlaceClicks.getElapsedTime().asSeconds() >= 1){
						placeTimerNotSet=true;
					}
				}*/
