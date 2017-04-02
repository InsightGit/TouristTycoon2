/*
 * AdvertIcon.cpp
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


#include "AdvertMenu.hpp"


imagine::sim::advertMenu::advertMenu(imagine::sim::player *mainPlayer,sf::Font *fontToUse) {
	// TODO Auto-generated constructor stub
	player=mainPlayer;
	defaultFont=*fontToUse;
}

imagine::sim::advertMenu::~advertMenu() {
	// TODO Auto-generated destructor stub
	delete popUp;
}

void imagine::sim::advertMenu::spawn(){
	menuBox.setFillColor(sf::Color(183,201,255,255));
	menuBox.setPosition(sf::Vector2f(484,184));

	if(player->levelProgress.currentLevel >= 1){
		imagine::sim::menuItem newMenuItem = imagine::sim::menuItem(&defaultFont,1);
		newMenuItem.optionalImage = new sf::Image();
		newMenuItem.optionalTexture = new sf::Texture();
		newMenuItem.optionalImage->create(laptop.width,laptop.height,laptop.pixel_data);
		newMenuItem.optionalTexture->loadFromImage(*newMenuItem.optionalImage);
		newMenuItem.sprite.setTexture(*newMenuItem.optionalTexture);
		newMenuItem.position = sf::Vector2f(494,184);
		newMenuItem.sprite.setPosition(newMenuItem.position);
		newMenuItem.itemName.setFont(defaultFont);
		newMenuItem.itemName.setFillColor(sf::Color::Black);
		newMenuItem.itemName.setString("Online Advertising $1500");
		newMenuItem.itemName.setCharacterSize(9);
		newMenuItem.itemName.setPosition(sf::Vector2f(newMenuItem.position.x,newMenuItem.position.y+64));
		newMenuItem.cost=1500;
		menuItems.push_back(newMenuItem);
		menuItemsLength++;
	}
	drawMenu=true;
	if(!limitClicksTimerSet){
		limitClicks.restart();
	}
}

void imagine::sim::advertMenu::update(sf::RenderWindow *window){
	if(drawMenu){
		if(!menuBox.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*window))) && limitClicks.getElapsedTime().asSeconds() >= 0.5 && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
			drawMenu=false;
		}else{
			for(int i = 0; menuItemsLength > i; i++){
				if(menuItems[i].isClicked(window)){
					if(player->money-menuItems[i].cost > 0 && !limitBuysSet){
						switch(i){
							case 0:
								imagine::sim::Advertisement newAdvert = imagine::sim::Advertisement(*player->playerDate,0);
								bool match = false;
								for(int i = 0;player->numberOfAdvertisementsSpawned > i;++i){
									if(player->advertisementsCreated[i].active && player->advertisementsCreated[i].id==0){
										match=true;
									}
								}
								if(!match){
									player->money-=menuItems[i].cost;
									player->advertisementsCreated.push_back(newAdvert);
									player->numberOfAdvertisementsSpawned++;
									std::cout << "Ad is active\n";
									drawMenu=false;
								}else if(match && !limitBuysSet){
									popUp = new imagine::sim::popUp("You can't make 2 of the same active advertisements",&defaultFont);
									popUpSpawned = true;
									drawMenu=false;
								}
							limitBuysSet=true;
							limitBuys.restart();
						}
					}else if(limitBuysSet && limitBuys.getElapsedTime().asSeconds() > 0.1 && player->money-menuItems[i].cost > 0){
						limitBuysSet=false;
					}else if(player->money-menuItems[i].cost < 0){
						popUp = new imagine::sim::popUp("You don't have enough money",&defaultFont);
						popUpSpawned = true;
						drawMenu=false;
					}
					for(int i = 0; player->numberOfAdvertisementsSpawned > i;++i){
						if(!player->advertisementsCreated[i].active){
							player->advertisementsCreated.erase(player->advertisementsCreated.begin()+i);
							player->numberOfAdvertisementsSpawned--;
							for(int i = 0;activeSpritesLength > i;++i){
								int placement = std::stoi(activeSprites[i].category);
								if(!player->advertisementsCreated[placement].active){
									activeSprites.erase(activeSprites.begin()+i);
									activeSpritesLength--;
								}
							}
						}
						if(player->advertisementsCreated[i].active){
							if(player->advertisementsCreated[i].id == 0){
								bool passed = true;
								for(int i = 0;activeSpritesLength > i;++i){
									if(std::stoi(activeSprites[i].category)==player->advertisementsCreated[i].id){
										passed = false;
									}
								}
								if(passed){
									imagine::clickableSprite tempSprite;
									tempSprite.category = std::to_string(i);
									tempSprite.optionalImage = menuItems[0].optionalImage;
									tempSprite.optionalTexture = new sf::Texture();
									tempSprite.optionalTexture->loadFromImage(*tempSprite.optionalImage);
									tempSprite.sprite.setTexture(*tempSprite.optionalTexture);
									tempSprite.sprite.setPosition(sf::Vector2f(1240,100));
									activeSprites.push_back(tempSprite);
									activeSpritesLength++;
								}
							}
						}
					}
				}
			}
		}
	}
}

void imagine::sim::advertMenu::draw(sf::RenderWindow *window){
	update(window);
	if(drawMenu){
		window->draw(menuBox);
		for(int i = 0;menuItemsLength > i;i++){
			if(menuItems[i].levelRequired <= player->levelProgress.currentLevel){
				window->draw(menuItems[i].sprite);
				window->draw(menuItems[i].itemName);
			}
		}
	}else if(popUpSpawned){
		popUp->draw(window);
	}
	for(int i = 0; activeSpritesLength > i;++i){
		window->draw(activeSprites[i].sprite);
	}
}
