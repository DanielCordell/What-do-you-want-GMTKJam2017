#include <SFML/Window/Event.hpp>
#include "Game.h"

Game::Game(): shouldQuit(false), window(sf::VideoMode(1280, 720), "Hello", sf::Style::Close) {
}

void Game::Events()
{
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			shouldQuit = true;
	}
}

void Game::Update()
{
	player.Update();
}

void Game::Draw()
{
	window.clear(sf::Color::White);
	window.draw(player);
	window.display();
}
