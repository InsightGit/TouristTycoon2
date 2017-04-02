/*
 * TownHall.cpp
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

#include "TownHall.hpp"

#include "SimPlayer.hpp"


imagine::sim::TownHall::TownHall(imagine::sim::player *mainPlayer, const sf::Vector2f position, const sf::Font *fontToUse) {
	// TODO Auto-generated constructor stub
	player=mainPlayer;
	cityServiceSprite.sprite.setPosition(position);
	defaultFont=*fontToUse;
	maintainceCost=200;
	maintainceCostSet=true;
}

void imagine::sim::TownHall::spawn(){
	cityServiceSprite.optionalImage = new sf::Image();
	cityServiceSprite.optionalTexture = new sf::Texture();
	cityServiceSprite.optionalImage->create(townHallImageFile.width,townHallImageFile.height,townHallImageFile.pixel_data);
	cityServiceSprite.optionalTexture->loadFromImage(*cityServiceSprite.optionalImage);
	cityServiceSprite.sprite.setTexture(*cityServiceSprite.optionalTexture);
}

imagine::sim::TownHall::TownHall(imagine::sim::player *mainPlayer, const sf::Vector2f position, const sf::Font *fontToUse, const std::vector<imagine::sim::CityPolicy> *cityPoliciesToUse){
	player=mainPlayer;
	cityServiceSprite.sprite.setPosition(position);
	defaultFont=*fontToUse;
	maintainceCost=200;
	maintainceCostSet=true;
	cityPolicies=*cityPoliciesToUse;
	spawn();
	created=true;
}

imagine::sim::TownHall::~TownHall() {
	// TODO Auto-generated destructor stub
	delete cityServiceSprite.optionalImage;
	delete cityServiceSprite.optionalTexture;
	delete cityManagmentMenu;
}

bool imagine::sim::TownHall::create(imagine::sim::popUp *notEnoughMoneyPopUp, const sf::Font *fontToUse){
	spawn();
	if(!created){
		if(player->money >= cost){
			player->townHallSpawned = true;
			player->money-=cost;
		}else{
			notEnoughMoneyPopUp = new imagine::sim::popUp("You don't have enough money.",fontToUse);
			return false;
		}
		created=true;
		return true;
	}
	return false;
}

void imagine::sim::TownHall::whenClicked(){
	if(!cityManagmentMenuSpawned){
		cityManagmentMenu = new imagine::sim::SimMenu(sf::Vector2f(300,300),sf::Vector2f(584,184),"City Policies",&defaultFont);
		cityManagmentMenuSpawned=true;
		imagine::Switch nicerTrees = imagine::Switch(sf::Vector2f(594,200));
		imagine::sim::CityPolicy nicerTreesPolicy = imagine::sim::CityPolicy(0,player);
		sf::Text nicerTreesTitle;
		nicerTreesTitle.setFont(defaultFont);
		nicerTreesTitle.setCharacterSize(15);
		nicerTreesTitle.setFillColor(sf::Color::Black);
		nicerTreesTitle.setPosition(sf::Vector2f(594,270));
		nicerTreesTitle.setString("Nicer trees");
		cityPoliciesSwitches.push_back(nicerTrees);
		//cityPolicyMinumumLevels.push_back(3);
		pastClickStates.push_back(false);
		cityPolicies.push_back(nicerTreesPolicy);
		cityPolicyDescriptions.push_back(nicerTreesTitle);
		cityPoliciesCount++;

		imagine::Switch doublePoliceSpending = imagine::Switch(sf::Vector2f(nicerTrees.getPosition().x,nicerTrees.getPosition().y+70));
		imagine::sim::CityPolicy doublePoliceSpendingPolicy = imagine::sim::CityPolicy(1,player,5,imagine::sim::types::buildPolice);
		sf::Text policeSpendingTitle;
		policeSpendingTitle.setFont(defaultFont);
		policeSpendingTitle.setCharacterSize(15);
		policeSpendingTitle.setFillColor(sf::Color::Black);
		policeSpendingTitle.setPosition(sf::Vector2f(doublePoliceSpending.getPosition().x,doublePoliceSpending.getPosition().y+70));
		policeSpendingTitle.setString("Double police spending");
		cityPoliciesSwitches.push_back(doublePoliceSpending);
		//cityPolicyMinumumLevels.push_back(3);
		pastClickStates.push_back(false);
		cityPolicies.push_back(doublePoliceSpendingPolicy);
		cityPolicyDescriptions.push_back(policeSpendingTitle);
		cityPoliciesCount++;
	}
	drawManagmentMenu=true;
}

void imagine::sim::TownHall::update(sf::RenderWindow *window){
	if(sf::Mouse::isButtonPressed(sf::Mouse::Left)!=pastMouseState && pastMouseState==false){
		mouseTimer.restart();
	}
	if(cityServiceSprite.isClicked(window)){
		whenClicked();
	}
	if(drawManagmentMenu){
		for(int i = 0; cityPoliciesCount > i;++i){
			if(pastClickStates[i]!=cityPoliciesSwitches[i].getSwitchState()){
				if(cityPoliciesSwitches[i].getSwitchState()){
					cityPolicies[i].active = true;
					maintainceCost+=cityPolicies[i].getMaintainceCost();
				}else{
					cityPolicies[i].active = false;
					maintainceCost-=cityPolicies[i].getMaintainceCost();
				}
			}
		}
		/*if(!cityManagmentMenu->menuBox.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*window))) && sf::Mouse::isButtonPressed(sf::Mouse::Left) && mouseTimer.getElapsedTime().asSeconds() >= 0.01){
			drawManagmentMenu = false;
		}*/
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
			drawManagmentMenu = false;
		}
	}
	for(int i = 0; cityPoliciesCount > i;++i){
		pastClickStates[i] = cityPoliciesSwitches[i].getSwitchState();
		cityPolicies[i].update();
	}
}

void imagine::sim::TownHall::draw(sf::RenderWindow *window){
	update(window);
	if(created){
		cityServiceSprite.optionalTexture->loadFromImage(*cityServiceSprite.optionalImage);
		cityServiceSprite.sprite.setTexture(*cityServiceSprite.optionalTexture);
		window->draw(cityServiceSprite.sprite);
		if(drawManagmentMenu){
			window->draw(cityManagmentMenu->menuBox);
			window->draw(cityManagmentMenu->title);
			for(int i = 0;cityPoliciesCount > i;++i){
				if(cityPolicies[i].getMinimumlevel() <= player->levelProgress.currentLevel && cityPolicies[i].getConditions() == imagine::sim::types::noConditions){
					cityPoliciesSwitches[i].draw(window);
					window->draw(cityPolicyDescriptions[i]);
				}else if(cityPolicies[i].getMinimumlevel() <= player->levelProgress.currentLevel && cityPolicies[i].getConditions() == imagine::sim::types::buildPolice){
					std::cout << player->numberOfPoliceStationsSpawned << "\n";
					if(player->numberOfPoliceStationsSpawned > 0){
						cityPoliciesSwitches[i].draw(window);
						window->draw(cityPolicyDescriptions[i]);
					}
				}
			}
		}
	}
}
