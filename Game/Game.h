#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>

#include "Player.h"
#include "Node.h"
#include "Platforms.h"
#include "Label.h"

class Game {
public:
	Game();

private:
	bool shouldQuit;
	sf::RenderWindow window;
	Player player;
	std::shared_ptr<Node> nodes[68];
	std::shared_ptr<Node> current;
	Platforms platforms;
	std::tuple<std::optional<float>, std::optional<float>, std::optional<float>> previousCollision;
	Label label;
public:
	void Events();
	void Update();
	void Draw();
	
	bool ShouldQuit() const { return shouldQuit; }
	Player& getPlayer() { return player; }
	
	void printTreeDebug() const;
};
