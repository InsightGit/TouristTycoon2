#include "BuildMenu.hpp"

imagine::sim::buildMenu::buildMenu(imagine::sim::player *mainPlayer,imagine::sim::helpBar *helpBarToUse,imagine::sim::actionArea *actionAreaToUse,sf::Font *fontToUse)
{
    //ctor
    defaultFont=*fontToUse;
    helpBar=helpBarToUse;
    player=mainPlayer;
    actionArea=actionAreaToUse;
}

imagine::sim::buildMenu::~buildMenu()
{
    //dtor
}

void imagine::sim::buildMenu::spawn(){
	leftRect.setFillColor(sf::Color::Color(83,125,252,230));
	leftRect.setPosition(sf::Vector2f(484,184));

	rightRect.setFillColor(sf::Color::Color(183,201,255,255));
	rightRect.setPosition(sf::Vector2f(584,184));

	attractions.setFont(defaultFont);
	roadText.setFont(defaultFont);
	services.setFont(defaultFont);

	attractions.setCharacterSize(20);
    roadText.setCharacterSize(20);
    services.setCharacterSize(20);

    float textPosX = leftRect.getPosition().x;

	attractions.setPosition(sf::Vector2f(textPosX,leftRect.getPosition().y+50));
	//roadText.setPosition(sf::Vector2f(textPosX,leftRect.getPosition().y+100));
	services.setPosition(sf::Vector2f(textPosX,leftRect.getPosition().y+100));

	attractions.setFillColor(sf::Color::Blue);
	//roadText.setFillColor(sf::Color::Color(163,163,163,230));
	services.setFillColor(sf::Color::Color(163,163,163,230));

	attractions.setString("Attractions");
	//roadText.setString("Roads");
	services.setString("Services");

	if(player->levelProgress.currentLevel>=0){
		imagine::sim::menuItem washMonu = imagine::sim::menuItem(&defaultFont,0);
		washMonu.optionalImage = new sf::Image;
		washMonu.optionalTexture = new sf::Texture;
		washMonu.optionalImage->create(washMonuIcon.width,washMonuIcon.height,washMonuIcon.pixel_data);
		washMonu.optionalTexture->loadFromImage(*washMonu.optionalImage);
		washMonu.sprite.setTexture(*washMonu.optionalTexture);
		//roadSprite.sprite.setPosition(sf::Vector2f(494,84));
		washMonu.sprite.setScale(0.85,0.85);
		washMonu.position = sf::Vector2f(594,184);
		washMonu.sprite.setPosition(washMonu.position);
		washMonu.category = "Attractions";
		washMonu.itemName.setString("Washington Monument");
		washMonu.itemName.setFillColor(sf::Color::Black);
		washMonu.itemName.setPosition(sf::Vector2f(washMonu.position.x,washMonu.position.y+54.4));
		washMonu.itemName.setFont(defaultFont);
		washMonu.itemName.setCharacterSize(7);
		attractionButtons.push_back(washMonu);
		attractionButtonSize++;

		//level 1 stuff
		imagine::sim::menuItem simpleHotel = imagine::sim::menuItem(&defaultFont,1);
		simpleHotel.optionalImage = new sf::Image;
		simpleHotel.optionalTexture = new sf::Texture;
		simpleHotel.optionalImage->create(hotelIconFile.width,hotelIconFile.height,hotelIconFile.pixel_data);
		simpleHotel.optionalTexture->loadFromImage(*simpleHotel.optionalImage);
		simpleHotel.sprite.setTexture(*simpleHotel.optionalTexture);
		//roadSprite.sprite.setPosition(sf::Vector2f(494,84));
		simpleHotel.sprite.setScale(0.85,0.85);
		simpleHotel.position = sf::Vector2f(594,184);
		simpleHotel.sprite.setPosition(simpleHotel.position);
		simpleHotel.category = "Services";
		simpleHotel.itemName.setString("Simple Hotel");
		simpleHotel.itemName.setFillColor(sf::Color::Black);
		simpleHotel.itemName.setPosition(sf::Vector2f(simpleHotel.position.x,simpleHotel.position.y+54.4));
		simpleHotel.itemName.setFont(defaultFont);
		simpleHotel.itemName.setCharacterSize(7);
		serviceButtons.push_back(simpleHotel);
		serviceButtonSize++;

		//level 2 stuff
		imagine::sim::menuItem tokyoTower = imagine::sim::menuItem(&defaultFont,2);
		tokyoTower.optionalImage = new sf::Image;
		tokyoTower.optionalTexture = new sf::Texture;
		tokyoTower.optionalImage->create(tokyoTowerIconImageFile.width,tokyoTowerIconImageFile.height,tokyoTowerIconImageFile.pixel_data);
		tokyoTower.optionalTexture->loadFromImage(*tokyoTower.optionalImage);
		tokyoTower.sprite.setTexture(*tokyoTower.optionalTexture);
		//roadSprite.sprite.setPosition(sf::Vector2f(494,84));
		tokyoTower.sprite.setScale(0.85,0.85);
		tokyoTower.position = sf::Vector2f(washMonu.position.x+70,184);
		tokyoTower.sprite.setPosition(tokyoTower.position);
		tokyoTower.category = "Attractions";
		tokyoTower.itemName.setString("Tokyo Tower");
		tokyoTower.itemName.setFillColor(sf::Color::Black);
		tokyoTower.itemName.setPosition(sf::Vector2f(tokyoTower.position.x,tokyoTower.position.y+54.4));
		tokyoTower.itemName.setFont(defaultFont);
		tokyoTower.itemName.setCharacterSize(7);
		attractionButtons.push_back(tokyoTower);
		attractionButtonSize++;

		imagine::sim::menuItem zipline = imagine::sim::menuItem(&defaultFont,2);
		zipline.optionalImage = new sf::Image;
		zipline.optionalTexture = new sf::Texture;
		zipline.optionalImage->create(ziplineIconImageFile.width,ziplineIconImageFile.height,ziplineIconImageFile.pixel_data);
		zipline.optionalTexture->loadFromImage(*zipline.optionalImage);
		zipline.sprite.setTexture(*zipline.optionalTexture);
		//roadSprite.sprite.setPosition(sf::Vector2f(494,84));
		zipline.sprite.setScale(0.85,0.85);
		zipline.position = sf::Vector2f(tokyoTower.position.x+70,tokyoTower.position.y);
		zipline.sprite.setPosition(zipline.position);
		zipline.category = "Attractions";
		zipline.itemName.setString("Zipline");
		zipline.itemName.setFillColor(sf::Color::Black);
		zipline.itemName.setPosition(sf::Vector2f(zipline.position.x,zipline.position.y+54.4));
		zipline.itemName.setFont(defaultFont);
		zipline.itemName.setCharacterSize(7);
		attractionButtons.push_back(zipline);
		attractionButtonSize++;

		imagine::sim::menuItem hikingTrail = imagine::sim::menuItem(&defaultFont,2);
		hikingTrail.optionalImage = new sf::Image;
		hikingTrail.optionalTexture = new sf::Texture;
		hikingTrail.optionalImage->create(hikingTrailIconImageFile.width,hikingTrailIconImageFile.height,hikingTrailIconImageFile.pixel_data);
		hikingTrail.optionalTexture->loadFromImage(*hikingTrail.optionalImage);
		hikingTrail.sprite.setTexture(*hikingTrail.optionalTexture);
		//roadSprite.sprite.setPosition(sf::Vector2f(494,84));
		hikingTrail.sprite.setScale(0.85,0.85);
		hikingTrail.position = sf::Vector2f(zipline.position.x+70,zipline.position.y);
		hikingTrail.sprite.setPosition(hikingTrail.position);
		hikingTrail.category = "Attractions";
		hikingTrail.itemName.setString("Hiking Trail");
		hikingTrail.itemName.setFillColor(sf::Color::Black);
		hikingTrail.itemName.setPosition(sf::Vector2f(hikingTrail.position.x,hikingTrail.position.y+54.4));
		hikingTrail.itemName.setFont(defaultFont);
		hikingTrail.itemName.setCharacterSize(7);
		attractionButtons.push_back(hikingTrail);
		attractionButtonSize++;
	}
	activeCategory="attractions";
	drawMenu=true;
}

void imagine::sim::buildMenu::update(sf::RenderWindow *window){
	if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		if(attractions.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*window)))){
			attractions.setFillColor(sf::Color::Blue);
			roadText.setFillColor(sf::Color::Color(163,163,163,230));
			services.setFillColor(sf::Color::Color(163,163,163,230));
			activeCategory="attractions";
		}else if(roadText.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*window)))){
			roadText.setFillColor(sf::Color::Blue);
			attractions.setFillColor(sf::Color::Color(163,163,163,230));
			services.setFillColor(sf::Color::Color(163,163,163,230));
			activeCategory="roads";
		}else if(services.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*window)))){
			services.setFillColor(sf::Color::Blue);
			attractions.setFillColor(sf::Color::Color(163,163,163,230));
			roadText.setFillColor(sf::Color::Color(163,163,163,230));
			activeCategory="services";
		}else if(leftRect.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*window))) || rightRect.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*window)))){
			//inside
			/*switch(previousTextName){
				case "attractions":
					attractions.setFillColor(sf::Color::Blue);
					break;
				case "roads":
					roadText.setFillColor(sf::Color::Blue);
					break;
				case "services":
					services.setFillColor(sf::Color::Blue);
					break;
			}*/
		}else if(limitClicks.getElapsedTime().asSeconds() >= 0.5){
			drawMenu=false;
		}
	}
	//std::cout << activeCategory << "\n";
	if(activeCategory=="services"){
		for(int i = 0; serviceButtonSize > i; i++){
			if(serviceButtons[i].isClicked(window)){
				switch(i){
					case 0:
						imageForPrompter.create(hotelImageFile.width,hotelImageFile.height,hotelImageFile.pixel_data);
						buildingPrompter = new imagine::sim::buildPrompter(player,imageForPrompter,5000,sf::Vector2i(1,2),actionArea,2,&defaultFont);
						buildingPrompter->spawn(window,&player->attractionsCreated,&player->roadsCreated,&player->hotelsCreated);
						prompterCreated = true;
						drawMenu = false;

						if(prompterTimerNotYetSet){
							limitPrompterClicks.restart();
						}
						helpBar->switchMessage("Press Escape to Cancel");
				}
			}
		}
	}else if(activeCategory=="roads"){
		for(int i = 0; 1 > i;i++){
			if(prompterTimerNotYetSet || limitPrompterClicks.getElapsedTime().asSeconds() >= 1){
				if(roadButtons[i].isClicked(window)){
					switch(i){
						case 0:
							largeRoad.create(roadBigSize.width,roadBigSize.height,roadBigSize.pixel_data);
							buildingPrompter = new imagine::sim::buildPrompter(player,largeRoad,imagine::sim::road::cost,sf::Vector2i(imagine::sim::road::xSize,imagine::sim::road::ySize),actionArea,0,&defaultFont);
							buildingPrompter->spawn(window,&player->attractionsCreated,&player->roadsCreated,&player->hotelsCreated);
							prompterCreated = true;
							drawMenu = false;
							//drawPrompter = true;
							//inPrompter = new imagine::types::arrayLocation("roadButtons",0);
							if(prompterTimerNotYetSet){
								limitPrompterClicks.restart();
							}
							helpBar->switchMessage("Press Escape to Cancel");
					}
				}
			}
		}
	}else if(activeCategory=="attractions"){
		for(int i = 0; attractionButtonSize > i; i++){
			if(attractionButtons[i].isClicked(window)){
				if(attractionButtons[i].itemName.getString() == "Washington Monument"){
					buildingPrompter = new imagine::sim::buildPrompter(player,*attractionButtons[i].optionalImage,1500,sf::Vector2i(1,1),actionArea,1,&defaultFont);
					buildingPrompter->spawn(window,&player->attractionsCreated,&player->roadsCreated,&player->hotelsCreated);
					prompterCreated = true;
					drawMenu = false;
					//drawPrompter = true;
					//inPrompter = new imagine::types::arrayLocation("roadButtons",0);
					if(prompterTimerNotYetSet){
						limitPrompterClicks.restart();
					}
					helpBar->switchMessage("Press Escape to Cancel");

				}else if(attractionButtons[i].itemName.getString() == "Tokyo Tower"){
					buildingPrompter = new imagine::sim::buildPrompter(player,*attractionButtons[i].optionalImage,5000,sf::Vector2i(1,2),actionArea,3,&defaultFont);
					buildingPrompter->spawn(window,&player->attractionsCreated,&player->roadsCreated,&player->hotelsCreated);
					prompterCreated = true;
					drawMenu = false;
					//drawPrompter = true;
					//inPrompter = new imagine::types::arrayLocation("roadButtons",0);
					if(prompterTimerNotYetSet){
						limitPrompterClicks.restart();
					}
					helpBar->switchMessage("Press Escape to Cancel");
				}else if(attractionButtons[i].itemName.getString() == "Zipline"){
					buildingPrompter = new imagine::sim::buildPrompter(player,*attractionButtons[i].optionalImage,7000,sf::Vector2i(2,1),actionArea,4,&defaultFont);
					buildingPrompter->spawn(window,&player->attractionsCreated,&player->roadsCreated,&player->hotelsCreated);
					prompterCreated = true;
					drawMenu = false;
					//drawPrompter = true;
					//inPrompter = new imagine::types::arrayLocation("roadButtons",0);
					if(prompterTimerNotYetSet){
						limitPrompterClicks.restart();
					}
					helpBar->switchMessage("Press Escape to Cancel");
				}else if(attractionButtons[i].itemName.getString() == "Hiking Trail"){
					buildingPrompter = new imagine::sim::buildPrompter(player,*attractionButtons[i].optionalImage,7500,sf::Vector2i(2,1),actionArea,5,&defaultFont);
					buildingPrompter->spawn(window,&player->attractionsCreated,&player->roadsCreated,&player->hotelsCreated);
					prompterCreated = true;
					drawMenu = false;
					//drawPrompter = true;
					//inPrompter = new imagine::types::arrayLocation("roadButtons",0);
					if(prompterTimerNotYetSet){
						limitPrompterClicks.restart();
					}
					helpBar->switchMessage("Press Escape to Cancel");
				}
			}
		}
	}
	if(!drawMenu){
		prompterTimerNotYetSet = true;
	}
	if(drawPrompter){
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
			drawPrompter=false;
			drawMenu=true;
			helpBar->switchMessage(helpBar->getPreviousMessage());
		}
	}
	/*if(prompterCreated){
		/*if(buildingPrompter->playerRequestingBuild){
			if(inPrompter->arrayName == "roadButtons"){
				if(inPrompter->location == 0){
					//TODO: MAKE THIS WORK WITH MULTIPLE DIRECTIONS
				}
			}
		}else if(buildingPrompter->drawingRoad){
			if(buildingPrompter->playerRequestingBuild){

			}
		}
	}*/
}

void imagine::sim::buildMenu::draw(sf::RenderWindow *window){
	if(pastDrawMenu==false && drawMenu == true){
		limitClicks.restart();
	}
	pastDrawMenu=drawMenu;
	update(window);
	if(drawMenu){
		//std::cout << "Menu Drawn\n";
		window->draw(leftRect);
		window->draw(rightRect);
		window->draw(attractions);
		//window->draw(roadText);
		window->draw(services);
		if(activeCategory=="roads"){
			/*for(int i = 0; roadButtons.size() > i; i++){
				window->draw(roadButtons[i].sprite);
				window->draw(roadButtons[i].itemName);
			}*/
		}else if(activeCategory=="attractions"){
			for(int i = 0; attractionButtons.size() > i; i++){
				if(attractionButtons[i].levelRequired <= player->levelProgress.currentLevel){
					window->draw(attractionButtons[i].sprite);
					window->draw(attractionButtons[i].itemName);
				}
			}
		}else if(activeCategory=="services"){
			for(int i = 0; serviceButtons.size() > i; i++){
				if(serviceButtons[i].levelRequired <= player->levelProgress.currentLevel){
					window->draw(serviceButtons[i].sprite);
					window->draw(serviceButtons[i].itemName);
				}
			}
			std::cout << "serviceButtons drawn\n";
		}
	}else if(prompterCreated){
		//if(buildingPrompter->done){
			buildingPrompter->draw(window,&player->attractionsCreated,&player->roadsCreated,&player->hotelsCreated);
		//}
	}
}


