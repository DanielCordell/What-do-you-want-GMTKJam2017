#pragma once
#include <optional>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include "Platform.h"


class Player: public sf::Drawable {
private:
	sf::Texture playerTex;
	sf::Sprite sprite;

	int gravity = 2;
	const int maxSpeed = 300;
	sf::Vector2f velocity = {0,0};
	float yAcc = 0;
	bool hasTouchedPlatform = false;
	bool onGround = true;
	float platformY = 0;
	Platform::Position whichPlatformTouched;
	sf::SoundBuffer jumpBuffer;
	sf::Sound jumpSound;

	sf::SoundBuffer landBuffer;
	sf::Sound landSound;
public:
	Player();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	bool Update(std::tuple<std::optional<float>, std::optional<float>, std::optional<float>> collision);

	sf::FloatRect GetGlobalBounds() const { return sprite.getGlobalBounds(); }

	static void playSound(sf::Sound& sound);
};
