#include "ClickableSprite.hpp"
#include <iostream>

imagine::clickableSprite::clickableSprite()
{
    //ctor
}

bool imagine::clickableSprite::isClicked(sf::RenderWindow *window){
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            //std::cout << sf::Mouse::getPosition().x << " Y:" << sf::Mouse::getPosition().y << "\n";
            if(sprite.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*window)))){
                return true;
            }
    }

    return false;
}
