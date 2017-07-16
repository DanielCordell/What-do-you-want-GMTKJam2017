#pragma once
#include <SFML/Graphics/Text.hpp>

class Label : public sf::Drawable {
private:
	sf::Font font;
	sf::Text text;
public:
	Label();
	void Label::Change(sf::String newText);
	void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
};
