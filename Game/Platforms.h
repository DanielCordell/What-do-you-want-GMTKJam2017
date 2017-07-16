#pragma once
#include <memory>
#include <optional>

#include "Node.h"
#include "Player.h"
#include "Platform.h"

class Platforms : public sf::Drawable {
private:
	Platform left;
	Platform centre;
	Platform right;
	
	bool isTransition = false;
public:
	void Change(std::shared_ptr<Node> left, std::shared_ptr<Node> centre, std::shared_ptr<Node> right);
	void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
	std::tuple<std::optional<float>, std::optional<float>, std::optional<float>> DetectCollision(Player& player) const;
	void Update();
	void Transition();
	bool TransitionDone() const;
};
