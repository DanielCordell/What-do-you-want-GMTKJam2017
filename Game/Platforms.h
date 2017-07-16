#pragma once
#include <memory>

#include "Node.h"
#include "Player.h"
#include "Platform.h"

class Platforms : public sf::Drawable {
private:
	Platform left;
	Platform centre;
	Platform right;
public:
	void Update(std::shared_ptr<Node> left, std::shared_ptr<Node> centre, std::shared_ptr<Node> right);
	void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
	Player::Col DetectCollision(Player& player);
};
