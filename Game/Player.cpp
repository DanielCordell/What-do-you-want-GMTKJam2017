#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Window/Keyboard.hpp>

#include <tuple>

#include "Player.h"
#include <iostream>

Player::Player(){
	playerTex.loadFromFile("Resources/player.png");
	sprite.setTexture(playerTex);
	sprite.setPosition(500, 500);
}

void Player::draw(sf::RenderTarget & target, sf::RenderStates states) const{
	target.draw(sprite, states);
}

bool Player::Update(std::tuple<std::optional<float>, std::optional<float>, std::optional<float>> collision){
	bool isTouchingPlatform = std::get<0>(collision).has_value() || std::get<1>(collision).has_value() || std::get<2>(collision).has_value();
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
		hasTouchedPlatform = false;
	}
	
	if (!isTouchingPlatform) {
		if (!onGround) {

			//Mid Jump
			if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && velocity.y <= 0) gravity = 6;
			else gravity = 1;
			velocity.y += velocity.y < maxSpeed ? gravity : 0;
		}
		else {
			playerPos.y = 720 - playerBounds.height;
			//Jumping
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
				velocity.y = -35;
			}
			//Not Jumping
			else {
				velocity.y = 0;
			}
		}
	}
	else if (velocity.y >= 0){
		if (!hasTouchedPlatform) {
			velocity.y = 1;
			gravity = 0;
			platformY = 0;
			if (std::get<0>(collision).has_value()) platformY = std::get<0>(collision).value();
			else if (std::get<1>(collision).has_value()) platformY = std::get<1>(collision).value();
			else if (std::get<2>(collision).has_value()) platformY = std::get<2>(collision).value();
			hasTouchedPlatform = true;
			playerPos.y = platformY - playerBounds.height + 1;
		}
	}
	playerPos.y += velocity.y;
	sprite.setPosition(playerPos);
	return isTouchingPlatform && velocity.y >= 0;
}
