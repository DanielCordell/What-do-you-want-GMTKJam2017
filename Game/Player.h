#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "Platform.h"
#include <optional>


class Player: public sf::Drawable {
private:
	sf::Texture playerTex;
	sf::Sprite sprite;

	int gravity = 2;
	const int maxSpeed = 300;
	sf::Vector2f velocity = {0,0};
	float yAcc = 0;
	bool hasTouchedPlatform = false;
	float platformY = 0;
	Platform::Position whichPlatformTouched;

public:
	Player();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	bool Update(std::tuple<std::optional<float>, std::optional<float>, std::optional<float>> collision);

	sf::FloatRect GetGlobalBounds() const { return sprite.getGlobalBounds(); }


};
