#include "Label.h"
#include <SFML/Graphics/RenderTarget.hpp>

Label::Label() {
	font.loadFromFile("Resources/font.ttf");
	text.setFillColor(sf::Color(0, 0, 0));
	text.setCharacterSize(20);
	text.setFont(font);
	text.setPosition(0, 5);
}

void Label::Change(sf::String newText) {
	text.setString(newText);
	text.setPosition(640 - text.getGlobalBounds().width / 2.f,text.getPosition().y);
}

void Label::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(text, states);
}
