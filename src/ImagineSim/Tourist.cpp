#include "Tourist.hpp"

#include <iostream>

#include "SimPlayer.hpp"
#include "Restaurant.hpp"

bool imagine::sim::types::compareFoodQuality::isLess(imagine::sim::types::foodQuality leftSide, imagine::sim::types::foodQuality rightSide){
	switch(rightSide){
		case imagine::sim::types::Terrible:
			if(leftSide!=imagine::sim::types::Terrible){
				return true;
			}
			break;
		case imagine::sim::types::Poor:
			if(leftSide!=imagine::sim::types::Terrible && leftSide!=imagine::sim::types::Poor){
				return true;
			}
			break;
		case imagine::sim::types::Ok:
			if(leftSide == imagine::sim::types::Good && leftSide == imagine::sim::types::Great && leftSide == imagine::sim::types::Legendary){
				return true;
			}
			break;
		case imagine::sim::types::Good:
			if(leftSide == imagine::sim::types::Great && leftSide == imagine::sim::types::Legendary){
				return true;
			}
			break;
		case imagine::sim::types::Great:
			if(leftSide == imagine::sim::types::Legendary){
				return true;
			}
			break;
	}
	return false;
}

imagine::sim::types::aStarRoad::aStarRoad(imagine::sim::road *aRoadToUse, imagine::sim::road *currentRoadToUse, imagine::sim::road *futureRoadToUse){
	aRoad=aRoadToUse;
	currentRoad=currentRoadToUse;
	futureRoad=futureRoadToUse;

	sf::Vector2f distanceVector;
	if(aRoad->tileSprite.getPosition().x >= futureRoad->tileSprite.getPosition().x){
		distanceVector.x = (aRoad->tileSprite.getPosition().x-futureRoad->tileSprite.getPosition().x)/-64;
	}else{
		distanceVector.x = (aRoad->tileSprite.getPosition().x+futureRoad->tileSprite.getPosition().x)/64;
	}

	if(aRoad->tileSprite.getPosition().y >= futureRoad->tileSprite.getPosition().y){
		distanceVector.y = (aRoad->tileSprite.getPosition().y-futureRoad->tileSprite.getPosition().y)/-64;
	}else{
		distanceVector.y = (aRoad->tileSprite.getPosition().x+futureRoad->tileSprite.getPosition().y)/64;
	}

	gScore=distanceVector.x+distanceVector.y;

	if(aRoad->tileSprite.getPosition().x >= currentRoad->tileSprite.getPosition().x){
		distanceVector.x = (aRoad->tileSprite.getPosition().x-currentRoad->tileSprite.getPosition().x)/-64;
	}else{
		distanceVector.x = (aRoad->tileSprite.getPosition().x+currentRoad->tileSprite.getPosition().x)/64;
	}

	if(aRoad->tileSprite.getPosition().y >= currentRoad->tileSprite.getPosition().y){
		distanceVector.y = (aRoad->tileSprite.getPosition().y-currentRoad->tileSprite.getPosition().y)/-64;
	}else{
		distanceVector.y = (aRoad->tileSprite.getPosition().x+currentRoad->tileSprite.getPosition().y)/64;
	}

	hScore=distanceVector.x+distanceVector.y;

	fScore=gScore+hScore;
}

imagine::sim::types::aStarRoad::aStarRoad(imagine::sim::road *aRoadToUse, imagine::sim::road *currentRoadToUse, sf::Vector2f dest){
	aRoad=aRoadToUse;

	sf::Vector2f distanceVector;
	if(aRoad->tileSprite.getPosition().x >= dest.x){
		distanceVector.x = (aRoad->tileSprite.getPosition().x-dest.x)/-64;
	}else{
		distanceVector.x = (aRoad->tileSprite.getPosition().x+dest.x)/64;
	}

	if(aRoad->tileSprite.getPosition().y >= dest.y){
		distanceVector.y = (aRoad->tileSprite.getPosition().y-dest.y)/-64;
	}else{
		distanceVector.y = (aRoad->tileSprite.getPosition().x+dest.y)/64;
	}

	gScore=distanceVector.x+distanceVector.y;

	if(aRoad->tileSprite.getPosition().x >= currentRoad->tileSprite.getPosition().x){
		distanceVector.x = (aRoad->tileSprite.getPosition().x-dest.x)/-64;
	}else{
		distanceVector.x = (aRoad->tileSprite.getPosition().x+dest.x)/64;
	}

	if(aRoad->tileSprite.getPosition().y >= currentRoad->tileSprite.getPosition().y){
		distanceVector.y = (aRoad->tileSprite.getPosition().y-dest.y)/-64;
	}else{
		distanceVector.y = (aRoad->tileSprite.getPosition().x+currentRoad->tileSprite.getPosition().y)/64;
	}

	hScore=distanceVector.x+distanceVector.y;

	fScore=gScore+hScore;
}

imagine::sim::tourist::tourist(std::vector<imagine::sim::attraction> *attractionList, std::vector<imagine::sim::road> *roadList, std::vector<imagine::sim::hotel> *hotelList, imagine::sim::player *mainPlayer){
	allAttractions=attractionList;
	allRoads=roadList;
	allHotels=hotelList;
	player = mainPlayer;
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> uni(0,100);

	auto randomInt = uni(rng);

	if(randomInt<=20){
		money=1500;
		minimumQuality=imagine::sim::types::Good;
	}else if(randomInt>20 && randomInt<=80){
		money=700;
		minimumQuality=imagine::sim::types::Ok;
	}else{
		money=350;
		minimumQuality=imagine::sim::types::Ok;
	}
	std::uniform_int_distribution<int> uni2(5,30);

	auto randomInt2 = uni2(rng);

	energy=2*randomInt2;

	std::uniform_int_distribution<int> uni3(1,3);
	auto randomInt3 = uni3(rng);
	switch(randomInt3){
		case 1:
			preferredCuisine=imagine::sim::types::Italian;
			break;
		case 2:
			preferredCuisine=imagine::sim::types::Mexican;
			break;
		case 3:
			preferredCuisine=imagine::sim::types::Diner;
			break;
	}

}

std::vector<int> imagine::sim::tourist::findNextRoadPlace(const imagine::sim::road *road){
	std::vector<int> result;
	for(int i = 0; player->numberOfRoadsSpawned > i; i++){
		if(road->tileSprite.getGlobalBounds().intersects(allRoads->at(i).tileSprite.getGlobalBounds())){
			result.push_back(i);
		}
	}
	return result;
}

void imagine::sim::tourist::spawn(){
	//drivingForm.create(car.width,car.height,car.pixel_data);
	walkingForm.create(personNew.width,personNew.height,personNew.pixel_data);
	touristTexture.loadFromImage(walkingForm);
	touristSprite.setTexture(touristTexture);
}

void imagine::sim::tourist::update(){
	pastLeaving=leaving;

	if(happiness==0){
		leaving=true;
	}
	/*if(status==imagine::sim::types::driving){
		std::cout << chosenAttraction << " driving\n";
	}else if(status==imagine::sim::types::touring){
		std::cout << chosenAttraction << " touring\n";
	}*/
	if(touringTimeSet && chosenAttraction && touringTime.getElapsedTime().asSeconds() >= 5 && status==imagine::sim::types::touring){
		chosenAttraction=false;
		touringTimeSet=false;
		currentAttraction->demit();
		visitedAttractions.push_back(currentAttraction);
		visitedAttractionsSize++;
		numberOfAttractionsSinceLastEat++;
		if(numberOfAttractionsSinceLastEat>=2){
			hungry=true;
		}
		happiness+=0.1*currentAttraction->getPopularity();
		happiness-=1.5*visitedAttractionsSize;
		if(player->townHallSpawned){
			for(int i = 0;player->townHall->getCityPolicySize() > i;++i){
				if(player->townHall->cityPolicies[i].active){
					happiness+=player->townHall->cityPolicies[i].getHappinessGained();
				}
			}
		}
		//if(niceParks)
		mostPopularPlace=-1;
		status=imagine::sim::types::driving;
		std::cout << "Visited\n";
	}else if(touringTimeSet && chosenRestaurant && touringTime.getElapsedTime().asSeconds() >= 4 && status==imagine::sim::types::eating){
		chosenRestaurant=false;
		touringTimeSet=false;
		currentRestaurant->checkout(this);
		numberOfAttractionsSinceLastEat = 0;
		hungry=false;
		mostPopularPlace=-1;
		status=imagine::sim::types::driving;
		std::cout << "Visited\n";
	}
	if(sleepingTimeSet && chosenHotel && sleepingTime.getElapsedTime().asSeconds() >= 7 && status==imagine::sim::types::sleeping){
		chosenAttraction=false;
		currentHotel.checkout(this);
		//visitedAttractions.push_back(currentAttraction);
		status=imagine::sim::types::driving;
	}

	if(!chosenAttraction && justSpawned){
		/*car = new imagine::sim::touristCar(sf::Vector2f(allRoads->at(0).tileSprite.getPosition().x+64,allRoads->at(0).tileSprite.getPosition().y));
		car->carSprite.setRotation(allRoads->at(0).tileSprite.getRotation());
		currentRoad=allRoads->at(0);
		aRoad=allRoads->at(0);*/

		//decide which is most popular attraction and go to that attraction
		for(int i = 0;player->numberOfAttractionsSpawned > i;++i){
			if(money-allAttractions->at(i).getCostForTourists() > 0){
				if(i==0){
					mostPopular=allAttractions->at(0).getPopularity();
					mostPopularPlace = i;
				}else if(mostPopular >= allAttractions->at(i).getPopularity()){
					mostPopular = allAttractions->at(i).getPopularity();
					mostPopularPlace = i;
				}
			}
			popularityList.push_back(allAttractions->at(i).getPopularity());
		}
		if(mostPopularPlace==-1){
			leaving=true;
			std::cout << "LeavingNOW Attractions:" << player->numberOfAttractionsSpawned <<"\n";
		}else{
			currentAttraction = &allAttractions->at(mostPopularPlace);
			chosenAttraction=true;
			status=imagine::sim::types::driving;
			std::cout << "MPP\n";
		}
		justSpawned=false;
	}else if(chosenAttraction && status==imagine::sim::types::driving){
		if(!drivingTimeSet){
			drivingTime.restart();
			drivingTimeSet = true;
			std::cout << "here\n";
		}else if(drivingTime.getElapsedTime().asSeconds() >= 5){
			if(currentAttraction->admit(this)){
				std::cout << "Admitted\n";
				touringTime.restart();
				touringTimeSet=true;
				status=imagine::sim::types::touring;
			}else{
				std::cout << "NOPE\n";
				chosenAttraction=false;
				tempBlackList.push_back(currentAttraction);
				tempBlackListSize++;
			}
			drivingTimeSet=false;
		}
	}else if(!chosenAttraction && !leaving && !chosenHotel && !hungry){
		for(int i = 0; player->numberOfAttractionsSpawned > i; i++){
			if(i==0){
				bool passed = true;
				if(!tempBlackList.empty()){
					for(int i = 0; tempBlackListSize > i; i++){
						if(allAttractions->at(0).getId()==tempBlackList.at(i)->getId() && allAttractions->at(0).tileSprite.getPosition()==tempBlackList.at(i)->tileSprite.getPosition()){
							passed=false;
						}
					}
				}
				if(visitedAttractionsSize!=0){
					for(int i = 0; visitedAttractionsSize > i; i++){
						if(allAttractions->at(0).getId()==visitedAttractions.at(i)->getId() && allAttractions->at(0).tileSprite.getPosition()==visitedAttractions.at(i)->tileSprite.getPosition()){
							passed=false;
						}
					}
				}
				if(passed && money-allAttractions->at(i).getCostForTourists() > 0){
					mostPopular=allAttractions->at(0).getPopularity();
					mostPopularPlace = i;
				}

			}else if(mostPopular < allAttractions->at(i).getPopularity()){
				bool passed = true;
				if(!tempBlackList.empty()){
					for(int i = 0; tempBlackListSize > i; i++){
						if(allAttractions->at(i).getId()==tempBlackList.at(i)->getId() && allAttractions->at(i).tileSprite.getPosition()==tempBlackList.at(i)->tileSprite.getPosition()){
							passed=false;
						}
					}
					tempBlackList.clear();
				}
				if(visitedAttractionsSize!=0){
					for(int i = 0; visitedAttractionsSize > i; i++){
						if(allAttractions->at(i).getId()==visitedAttractions.at(i)->getId() && allAttractions->at(i).tileSprite.getPosition()==visitedAttractions.at(i)->tileSprite.getPosition()){
							passed=false;
						}
					}
				}
				if(passed && money-allAttractions->at(i).getCostForTourists() > 0){
					mostPopular=allAttractions->at(i).getPopularity();
					mostPopularPlace = i;
				}
			}
			if(mostPopularPlace==-1){
				leaving=true;
			}else{
				//std::cout << allAttractions->at(mostPopularPlace).name << "\n";
				currentAttraction = &allAttractions->at(mostPopularPlace);
				if(energy<=0 || energy-currentAttraction->getActivityLevel() < 0){
					//if();
					if(player->numberOfHotelsSpawned!=0){
						if(money-allHotels->at(0).getCost() > 0){
							if(player->numberOfHotelsSpawned==1){
								currentHotel=allHotels->at(0);
							}else{
								std::random_device rd;
								std::mt19937 rng(rd());
								std::uniform_int_distribution<int> uni(0,player->numberOfHotelsSpawned-1);
								auto randomInt = uni(rng);
								currentHotel=allHotels->at(randomInt);
							}
							chosenHotel=true;
						}else{
							leaving=true;
						}
					}else{
						leaving=true;
					}
				}
			}
			tempBlackList.clear();
			tempBlackListSize=0;
		}
	}else if(chosenHotel && !leaving && status==imagine::sim::types::driving){
		std::cout << "Hotel\n";
		if(currentHotel.checkin(this)){
				sleepingTime.restart();
				sleepingTimeSet=true;
				status=imagine::sim::types::sleeping;
		}else{
			leaving=true;
		}
	}else if(hungry && !chosenRestaurant && !leaving){
		//choose a restaurant
		for(int i = 0; player->numberOfRestaurantsSpawned > i;i++){
			if(money-player->restaurantsCreated[i].getCost() >= 0){
				imagine::sim::types::foodQuality foodQuality = player->restaurantsCreated[i].getQuality();
				if(minimumQuality==imagine::sim::types::Good){
					if(foodQuality == imagine::sim::types::Good && foodQuality == imagine::sim::types::Great && foodQuality == imagine::sim::types::Legendary){
						if(i==0){
							mostPopularRestaurant=i;
							if(player->restaurantsCreated[i].getCuisine() == preferredCuisine){
								previousCuisineMatched=true;
							}else{
								previousCuisineMatched=false;
							}
						}else if(imagine::sim::types::compareFoodQuality::isLess(player->restaurantsCreated[mostPopularPlace].getQuality(),player->restaurantsCreated[i].getQuality()) || player->restaurantsCreated[mostPopularPlace].getQuality() == player->restaurantsCreated[i].getQuality()){
							if(player->restaurantsCreated[mostPopularPlace].getQuality() == player->restaurantsCreated[i].getQuality() && !previousCuisineMatched && player->restaurantsCreated[i].getCuisine() == preferredCuisine){
								mostPopularRestaurant=i;
								previousCuisineMatched=true;
							}else if(imagine::sim::types::compareFoodQuality::isLess(player->restaurantsCreated[mostPopularPlace].getQuality(),player->restaurantsCreated[i].getQuality())){
								mostPopularRestaurant=i;
								if(player->restaurantsCreated[i].getCuisine() == preferredCuisine){
									previousCuisineMatched=true;
								}else{
									previousCuisineMatched=false;
								}
							}
						}
					}
				}else if(minimumQuality==imagine::sim::types::Ok){
					if(foodQuality == imagine::sim::types::Ok && foodQuality == imagine::sim::types::Good && foodQuality == imagine::sim::types::Great && foodQuality == imagine::sim::types::Legendary){
						if(i==0){
							mostPopularRestaurant=i;
							if(player->restaurantsCreated[i].getCuisine() == preferredCuisine){
								previousCuisineMatched=true;
							}else{
								previousCuisineMatched=false;
							}
						}else if(imagine::sim::types::compareFoodQuality::isLess(player->restaurantsCreated[mostPopularPlace].getQuality(),player->restaurantsCreated[i].getQuality()) || player->restaurantsCreated[mostPopularPlace].getQuality() == player->restaurantsCreated[i].getQuality()){
							if(player->restaurantsCreated[mostPopularPlace].getQuality() == player->restaurantsCreated[i].getQuality() && !previousCuisineMatched && player->restaurantsCreated[i].getCuisine() == preferredCuisine){
								mostPopularRestaurant=i;
								previousCuisineMatched=true;
							}else if(imagine::sim::types::compareFoodQuality::isLess(player->restaurantsCreated[mostPopularPlace].getQuality(),player->restaurantsCreated[i].getQuality())){
								mostPopularRestaurant=i;
								if(player->restaurantsCreated[i].getCuisine() == preferredCuisine){
									previousCuisineMatched=true;
								}else{
									previousCuisineMatched=false;
								}
							}
						}
					}
				}
				if(mostPopularPlace!=-1){
					currentRestaurant=&player->restaurantsCreated[i];
					chosenRestaurant=true;
				}else{
					leaving=true;
				}
			}
		}
	}else if(hungry && chosenRestaurant && !leaving){
		if(!drivingTimeSet){
			drivingTime.restart();
			drivingTimeSet = true;
			std::cout << "hereRestaurant\n";
		}else if(drivingTime.getElapsedTime().asSeconds() >= 5){
			if(currentRestaurant->checkin(this)){
				std::cout << "CheckedIn\n";
				touringTime.restart();
				touringTimeSet=true;
				status=imagine::sim::types::eating;
			}else{
				//std::cout << "NOPE\n";
				leaving=true;
			}
			drivingTimeSet=false;
		}
	}else{
	/*}else if(chosenAttraction && display && status==imagine::sim::types::driving){
		//A*
		openList.push_back(currentRoad);
		float lowestFScore;
		while(!openList.empty()){
			std::vector<int> possibleRoads = findNextRoadPlace(currentRoad);
			for(int i = 0; i < possibleRoads.size();i++){
				//if(i==0){
					//lowestFScore = ;
				//}
				aStarResults.push_back(imagine::sim::types::aStarRoad(aRoad,currentRoad,&allRoads->at(possibleRoads[i])));
			}
			sf::Vector2i lowestFScore;
			for(int i = 0; aStarResults.size() > i; i++){
				if(i==0){
					lowestFScore.x=i;
					lowestFScore.y=aStarResults[i].fScore;
				}else{
					if(lowestFScore.y > aStarResults[i].fScore){
						lowestFScore.x=i;
						lowestFScore.y=aStarResults[i].fScore;
					}
				}
			}
			closeList.push_back(&allRoads->at(lowestFScore.x));
		}*/
	}
}

void imagine::sim::tourist::draw(sf::RenderWindow *window){
	update();
	/*if(display){
		if(status==imagine::sim::types::driving){
			car->draw(window);
		}else if(status==imagine::sim::types::walking){
			window->draw(touristSprite);
		}
	}*/
}
