#include "Player.h"
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>

Player::Player(){
	playerTex.loadFromFile("Resources/player.png");
	sprite.setTexture(playerTex);

}

void Player::draw(sf::RenderTarget & target, sf::RenderStates states) const{
	target.draw(sprite, states);
}

void Player::Update(){
	int xChange = 0;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))	xChange -= 12;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) xChange += 12;
	sprite.move(xChange,0);
	std::cout << sprite.getPosition().x << " " << sprite.getPosition().y << std::endl;

	bool onGround = false;
	sf::FloatRect playerBounds = sprite.getGlobalBounds();
	sf::Vector2f playerPos = sprite.getPosition();
	if (playerPos.y + playerBounds.height >= 720) { // HARDCODED SIZE BC I AM A BAD
		sprite.setPosition(playerPos.x, 720 - playerBounds.height);
		onGround = true;
	}

	if (!onGround) {
		fallSpeed += fallSpeed < maxSpeed ? gravity : 0;
		sprite.move(0, fallSpeed);
	}
	else {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			fallSpeed = -50;
			sprite.move(0, fallSpeed);
		}
	}
}
