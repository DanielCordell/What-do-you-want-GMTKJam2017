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
	bool moveLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
	bool moveRight = sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
	if (moveLeft || moveRight) {
		int xAcc = 0;
		if (!moveRight)
			xAcc -= 12;
		if (!moveLeft)
			xAcc += 12;
		velocity.x = xAcc;
	} else {
		velocity.x *= 0.8f;
	}
	//Initial movement
	playerPos.x += velocity.x;

	//Wall collision
	if (playerPos.x < 0)
		playerPos.x = 0;
	else if (playerPos.x + playerBounds.width >= 1280) 
		playerPos.x = 1280 - playerBounds.width;

	//VERTICAL MOVEMENT
	//Floor collision 
	bool onGround = false;

	//Detect if on ground
	if (playerPos.y + playerBounds.height >= 720) { // HARDCODED SIZE BC I AM A BAD
		onGround = true;
	}

	if (!onGround) { 
		//Mid Jump
		if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && velocity.y <= 0) gravity = 6;
		else gravity = 2;
		velocity.y += velocity.y < maxSpeed ? gravity : 0;
	}
	else {
		playerPos.y = 720 - playerBounds.height;
		//Jumping
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			velocity.y = -50;
		}
		//Not Jumping
		else {
			velocity.y = 0;
		}
	}
	playerPos.y += velocity.y;
	sprite.setPosition(playerPos);
	std::cout << sprite.getPosition().x << " " << sprite.getPosition().y << std::endl;
}
