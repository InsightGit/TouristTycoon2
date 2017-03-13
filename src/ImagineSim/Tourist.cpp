#include "Tourist.hpp"

#include <iostream>

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

imagine::sim::tourist::tourist(std::vector<imagine::sim::attraction> *attractionList, std::vector<imagine::sim::road> *roadList, std::vector<imagine::sim::hotel> *hotelList, const int attractionsSpawned, const int roadsSpawned, const int hotelsSpawned){
	allAttractions=attractionList;
	allRoads=roadList;
	allHotels=hotelList;
	attractionLength=attractionsSpawned;
	roadLength=roadsSpawned;
	hotelLength=roadsSpawned;
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> uni(0,100);

	auto randomInt = uni(rng);

	if(randomInt<=20){
		money=1500;
	}else if(randomInt>20 && randomInt<=80){
		money=700;
	}else{
		money=350;
	}
}

std::vector<int> imagine::sim::tourist::findNextRoadPlace(const imagine::sim::road *road){
	std::vector<int> result;
	for(int i = 0; roadLength > i; i++){
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
	if(touringTimeSet && chosenAttraction && touringTime.getElapsedTime().asSeconds() >= 5 && status==imagine::sim::types::touring){
		chosenAttraction=false;
		currentAttraction.demit();
		visitedAttractions->push_back(currentAttraction);
		status=imagine::sim::types::driving;
	}
	if(sleepingTimeSet && chosenHotel && sleepingTime.getElapsedTime().asSeconds() >= 7 && status==imagine::sim::types::sleeping){
		chosenAttraction=false;
		currentAttraction.demit();
		visitedAttractions->push_back(currentAttraction);
		status=imagine::sim::types::driving;
	}

	if(!chosenAttraction && justSpawned){
		/*car = new imagine::sim::touristCar(sf::Vector2f(allRoads->at(0).tileSprite.getPosition().x+64,allRoads->at(0).tileSprite.getPosition().y));
		car->carSprite.setRotation(allRoads->at(0).tileSprite.getRotation());
		currentRoad=allRoads->at(0);
		aRoad=allRoads->at(0);*/

		//decide which is most popular attraction and go to that attraction
		for(int i = 0;attractionLength > i;++i){
			std::cout << std::to_string(i) << "\n";
			if(money-allAttractions->at(i).getCost() > 0){
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
		if(mostPopularPlace==NULL){
			leaving=true;
		}else{
			currentAttraction = allAttractions->at(mostPopularPlace);
			chosenAttraction=true;
		}
		justSpawned=false;
	}else if(chosenAttraction && status==imagine::sim::types::driving){
		if(!drivingTimeSet){
			drivingTime.restart();
			drivingTimeSet = true;
		}else if(drivingTime.getElapsedTime().asSeconds() >= 5){
			drivingTimeSet=false;
			if(currentAttraction.admit(this)){
				touringTime.restart();
				touringTimeSet=true;
				status=imagine::sim::types::touring;
			}else{
				chosenAttraction=false;
				tempBlackList->push_back(currentAttraction);
			}
		}
	}else if(!chosenAttraction && !leaving && !chosenHotel){
		for(int i = 0; attractionLength > i; i++){
			if(i==0){
				bool passed = true;
				if(!tempBlackList->empty()){
					for(int i = 0; tempBlackList->size() > i; i++){
						if(allAttractions->at(0).getId()==tempBlackList->at(i).getId() && allAttractions->at(0).tileSprite.getPosition()==tempBlackList->at(i).tileSprite.getPosition()){
							passed=false;
						}
					}
				}
				if(!visitedAttractions->empty()){
					for(int i = 0; tempBlackList->size() > i; i++){
						if(allAttractions->at(0).getId()==visitedAttractions->at(i).getId() && allAttractions->at(0).tileSprite.getPosition()==visitedAttractions->at(i).tileSprite.getPosition()){
							passed=false;
						}
					}
				}
				if(passed && money-allAttractions->at(i).getCost() > 0){
					mostPopular=allAttractions->at(0).getPopularity();
					mostPopularPlace = i;
				}

			}else if(mostPopular >= allAttractions->at(i).getPopularity()){
				bool passed = true;
				if(!tempBlackList->empty()){
					for(int i = 0; tempBlackList->size() > i; i++){
						if(allAttractions->at(0).getId()==tempBlackList->at(i).getId() && allAttractions->at(0).tileSprite.getPosition()==tempBlackList->at(i).tileSprite.getPosition()){
							passed=false;
						}
					}
					tempBlackList->clear();
				}
				if(!visitedAttractions->empty()){
					for(int i = 0; tempBlackList->size() > i; i++){
						if(allAttractions->at(0).getId()==visitedAttractions->at(i).getId() && allAttractions->at(0).tileSprite.getPosition()==visitedAttractions->at(i).tileSprite.getPosition()){
							passed=false;
						}
					}
				}
				if(passed && money-allAttractions->at(i).getCost() > 0){
					mostPopular=allAttractions->at(i).getPopularity();
					mostPopularPlace = i;
				}

				mostPopular = allAttractions->at(i).getPopularity();
				mostPopularPlace = i;


			}
			if(mostPopularPlace==NULL){
				leaving=true;
			}else{
				currentAttraction = allAttractions->at(mostPopularPlace);
				if(energy<=0){
					//if()
					if(hotelLength!=0){
						if(money-allHotels->at(i).getCost() > 0){
							if(hotelLength==1){
								currentHotel=allHotels->at(0);
							}else{
								std::random_device rd;
								std::mt19937 rng(rd());
								std::uniform_int_distribution<int> uni(0,hotelLength-1);
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
			tempBlackList->clear();
		}
	}else if(chosenHotel && !leaving && status==imagine::sim::types::driving){
		if(currentHotel.checkin(this)){
				sleepingTime.restart();
				sleepingTimeSet=true;
				status=imagine::sim::types::sleeping;
		}else{
			leaving=true;
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
