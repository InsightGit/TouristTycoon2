#include "BuildMenu.hpp"


#include "Resources/roadIcon.h"
#include "Resources/roadRemastered.h"
#include "Resources/WashMonuIcon.h"

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

	/*switch(player->levelProgress.currentLevel){
		case 0:
			/*imagine::sim::menuItem roadSprite = imagine::sim::menuItem(&defaultFont);
			roadSprite.optionalImage = new sf::Image;
			roadSprite.optionalTexture = new sf::Texture;
			roadSprite.optionalImage->create(roadIconSmall.width,roadIconSmall.height,roadIconSmall.pixel_data);
			roadSprite.optionalTexture->loadFromImage(*roadSprite.optionalImage);
			roadSprite.sprite.setTexture(*roadSprite.optionalTexture);
			//roadSprite.sprite.setPosition(sf::Vector2f(494,84));
			roadSprite.sprite.setScale(0.25,0.25);
			roadSprite.position = sf::Vector2f(594,184);
			roadSprite.sprite.setPosition(roadSprite.position);
			roadSprite.category = "Roads";
			roadSprite.itemName.setString("Small Road");
			roadSprite.itemName.setFillColor(sf::Color::Black);
			roadSprite.itemName.setPosition(sf::Vector2f(roadSprite.position.x,roadSprite.position.y+28));
			roadSprite.itemName.setFont(defaultFont);
			roadSprite.itemName.setCharacterSize(10);
			roadSprite.drawString = true;

		case 1:
			/*imagine::sim::menuItem roadSprite = imagine::sim::menuItem(&defaultFont);
			roadSprite.optionalImage = new sf::Image;
			roadSprite.optionalTexture = new sf::Texture;
			roadSprite.optionalImage->create(roadIconSmall.width,roadIconSmall.height,roadIconSmall.pixel_data);
			roadSprite.optionalTexture->loadFromImage(*roadSprite.optionalImage);
			roadSprite.sprite.setTexture(*roadSprite.optionalTexture);
			//roadSprite.sprite.setPosition(sf::Vector2f(494,84));
			roadSprite.sprite.setScale(0.25,0.25);
			roadSprite.position = sf::Vector2f(594,184);
			roadSprite.sprite.setPosition(roadSprite.position);
			roadSprite.category = "Roads";
			roadSprite.itemName.setString("Small Road");
			roadSprite.itemName.setFillColor(sf::Color::Black);
			roadSprite.itemName.setPosition(sf::Vector2f(roadSprite.position.x,roadSprite.position.y+28));
			roadSprite.itemName.setFont(defaultFont);
			roadSprite.itemName.setCharacterSize(10);
			roadSprite.drawString = true;
			roadButtons.push_back(roadSprite);

			//imagine::sim::menuItem attraction
	}*/
	if(player->levelProgress.currentLevel>=0){
		imagine::sim::menuItem washMonu = imagine::sim::menuItem(&defaultFont);
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
		for(int i = 0; attractionButtons.size() > i; i++){
			if(attractionButtons[i].isClicked(window)){
				switch(i){
					case 0:
						//TODO: Add attractions
						NULL;

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
				switch(i){
					case 0:
						//TODO: Add services
						buildingPrompter = new imagine::sim::buildPrompter(player,*attractionButtons[0].optionalImage,1500,sf::Vector2i(1,1),actionArea,1,&defaultFont);
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
				window->draw(attractionButtons[i].sprite);
				window->draw(attractionButtons[i].itemName);
			}
		}
	}else if(prompterCreated){
		//if(buildingPrompter->done){
			buildingPrompter->draw(window,&player->attractionsCreated,&player->roadsCreated,&player->hotelsCreated);
		//}
	}
}


