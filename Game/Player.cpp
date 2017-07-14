#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>

#include "Player.h"

Player::Player(){
	playerTex.loadFromFile("Resources/player.png");
	sprite.setTexture(playerTex);

}

void Player::draw(sf::RenderTarget & target, sf::RenderStates states) const{
	target.draw(sprite, states);
}

void Player::Update(){
	sf::FloatRect playerBounds = sprite.getGlobalBounds();
	sf::Vector2f playerPos = sprite.getPosition();
	
	//HORIZONTAL MOVEMENT
	int xChange = 0;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))	
		xChange -= 12;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) 
		xChange += 12;
	playerPos.x += xChange;

	//Wall collision
	if (playerPos.x < 0)
		playerPos.x = 0;
	else if (playerPos.x + playerBounds.width >= 1280) 
		playerPos.x = 1280 - playerBounds.width;

	//VERTICAL MOVEMENT
	//Floor collision 
	bool onGround = false;
	if (playerPos.y + playerBounds.height >= 720) { // HARDCODED SIZE BC I AM A BAD
		playerPos.y = 720 - playerBounds.height;
		onGround = true;
	}

	if (!onGround) { 
		fallSpeed += fallSpeed < maxSpeed ? gravity : 0;
		playerPos.y += fallSpeed;
	}
	else {
		//Jumping
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			fallSpeed = -50;
			playerPos.y += fallSpeed;
		}
	}
	sprite.setPosition(playerPos);
	std::cout << sprite.getPosition().x << " " << sprite.getPosition().y << std::endl;
}
