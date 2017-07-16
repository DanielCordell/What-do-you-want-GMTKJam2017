#pragma once
#include <SFML/Graphics/RectangleShape.hpp>
#include "Node.h"
#include <optional>


class Platform : public sf::Drawable {
private:
	bool doesExist;
	sf::RectangleShape platform;
	sf::Text text;
	static sf::Color colors[8];
	static sf::Font font;
	float transitionSpeed = 0;
public:
	enum Position {
		left = 0,
		centre = 1,
		right = 2
	};

	Platform();

	void Reset(std::string string, Position pos);
	void Reset();
	bool ShouldDraw() const { return doesExist; }
	void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
	std::optional<float> GetCollision(sf::FloatRect player) const;
	void Transition();
	bool DoneTransition() const { return platform.getPosition().y + platform.getSize().y > 1280; }
};
