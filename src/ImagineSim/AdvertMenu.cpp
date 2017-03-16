/*
 * AdvertIcon.cpp
 *
 *  Created on: Mar 11, 2017
 *      Author: newbobby
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
		newMenuItem.defaultFont = defaultFont;
		newMenuItem.itemName.setString("Online Advertising");
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
					if(player->money-menuItems[i].cost > 0){
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
									player->advertisementsCreated.push_back(newAdvert);
									player->numberOfAdvertisementsSpawned++;
								}else if(match){
									popUp = new imagine::sim::popUp("You can't make 2 of the same advertisements active at the same time",&defaultFont);
									popUpSpawned = true;
									drawMenu=false;
								}
						}
					}else{
						popUp = new imagine::sim::popUp("You don't have enough money",&defaultFont);
						popUpSpawned = true;
						drawMenu=false;
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
}
