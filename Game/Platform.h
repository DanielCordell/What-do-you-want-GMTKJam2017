#pragma once
#include <SFML/Graphics/RectangleShape.hpp>
#include "Node.h"



class Platform : public sf::Drawable {
private:
	bool doesExist;
	sf::RectangleShape platform;
	sf::Text text;
	static sf::Color colors[8];
	static sf::Font font;
public:
	enum Position {
		left = 0,
		centre = 1,
		right = 2
	};

	Platform();

	void Reset(std::string string, Position pos);
	void Reset();
	bool shouldDraw() const { return doesExist; }
	void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
	
};
