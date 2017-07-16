#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Font.hpp>
#include <sstream>

#include "Platform.h"
#include <iostream>

sf::Font Platform::font;

sf::Color Platform::colors[] = { 
	sf::Color(255,168,168), 
	sf::Color(166,202,169), 
	sf::Color(160,149,238), 
	sf::Color(123,167,255), 
	sf::Color(163,254,186), 
	sf::Color(255,213,134), 
	sf::Color(200,200,149), 
	sf::Color(200,200,200) };

void Platform::Reset(std::string string, Position pos)
{
	text.setString("");
	this->doesExist = true;
	int randColor = rand() % 8;
	platform.setFillColor(colors[randColor]);

	sf::Vector2f platPos;
	platPos.y = rand() % 400 + 100;
	platPos.x = rand() % 226 + 426 * pos;
	platform.setPosition(platPos);

	//Adding newlines to string
	std::string buf; // Have a buffer string
	std::stringstream ss(string); // Insert the string into a stream
	std::vector<std::string> tokens; // Create vector to hold our words
	float spaceWidth = sf::Text(" ", font, 20).getGlobalBounds().width;
	while (ss >> buf)
		tokens.push_back(buf);
	float currentWidth = 0;
	for (auto word : tokens) {
		auto wordWidth = sf::Text(word, font, 20).getGlobalBounds().width;
		if (currentWidth + wordWidth + spaceWidth >= 200) {
			text.setString(text.getString().toAnsiString() += "\n" + word + " ");
			std::cout << currentWidth << std::endl;
			currentWidth = wordWidth + spaceWidth;
		}
		else {
			text.setString(text.getString().toAnsiString() += word + " ");
			currentWidth += wordWidth + spaceWidth;
		}
	}
	text.setString(text.getString().substring(0, text.getString().getSize() - 1)); // Remove trailing space
	text.setPosition(platform.getPosition().x + (200 - text.getGlobalBounds().width) / 2.f, platform.getPosition().y - text.getLocalBounds().height - 20);
}

void Platform::Reset() {
	this->doesExist = false;
}

void Platform::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(text, states);
	target.draw(platform, states);
}

Platform::Platform() {
	font.loadFromFile("Resources/font.ttf");
	doesExist = false;
	platform.setOutlineColor(sf::Color::Transparent);
	platform.setSize({ 200, 10 });
	text.setFillColor(sf::Color(0, 0, 0));
	text.setCharacterSize(20);
	text.setFont(font);
}