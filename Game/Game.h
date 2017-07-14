#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include "Resources/Player.h"

class Game {
public:
	Game();

private:
	bool shouldQuit;
	sf::RenderWindow window;
	Player player;

public:
	void Events();
	void Update();
	void Draw();
	
	bool ShouldQuit() const { return shouldQuit; }
	Player& getPlayer() { return player; }
	
};
