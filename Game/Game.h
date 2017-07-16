#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Audio/Music.hpp>
#include <memory>

#include "Player.h"
#include "Node.h"
#include "Platforms.h"
#include "Label.h"

class Game {
private:
	sf::Music music;
	bool shouldQuit;
	sf::RenderWindow window;
	Player player;
	std::shared_ptr<Node> nodes[68];
	std::shared_ptr<Node> current;
	Platforms platforms;
	std::tuple<std::optional<float>, std::optional<float>, std::optional<float>> previousCollision;
	Label label;
public:
	Game();
	void Events();
	void Update();
	void Draw();
	
	bool ShouldQuit() const { return shouldQuit; }
	Player& getPlayer() { return player; }
	
	void printTreeDebug() const;
};
