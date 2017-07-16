#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

class Player: public sf::Drawable {
private:
	sf::Texture playerTex;
	sf::Sprite sprite;

	int gravity = 2;
	const int maxSpeed = 300;
	sf::Vector2f velocity = {0,0};
	float yAcc = 0;

public:
	Player();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void Update();

	sf::FloatRect GetGlobalBounds() const { return sprite.getGlobalBounds(); }

	enum Col {
		noCollision = 0,
		topCollision = 1 << 0,
		leftCollision = 1 << 1,
		bottomCollision = 1 << 2,
		rightCollision = 1 << 3
	};
};
