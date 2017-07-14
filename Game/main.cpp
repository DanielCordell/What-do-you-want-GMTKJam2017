#include <SFML/Graphics.hpp>
#include "Game.h"

int main()
{
	Game game;
	float frameTime = 1.f / 60.f;
	sf::Clock clock;
	sf::Time elapsedTime;
	while (!game.ShouldQuit()) {
		elapsedTime += clock.restart();
		game.Events();
		if (elapsedTime.asSeconds() >= frameTime) {
			game.Update();
			game.Draw();
			elapsedTime = sf::Time::Zero;
		}
	}
	return 0;
}
