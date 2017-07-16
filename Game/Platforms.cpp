#include "Platforms.h"
#include <SFML/Graphics/RenderTarget.hpp>

void Platforms::Update(std::shared_ptr<Node> left, std::shared_ptr<Node> centre, std::shared_ptr<Node> right)
{
	if (left != nullptr) this->left.Reset(left->answerText, Platform::Position::left);
	else this->left.Reset();

	if (right != nullptr) this->right.Reset(right->answerText, Platform::Position::right);
	else this->right.Reset();

	if (centre != nullptr) this->centre.Reset(centre->answerText, Platform::Position::centre);
	else this->centre.Reset();
	
}

void Platforms::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	if (left.shouldDraw()) target.draw(left, states);
	if (centre.shouldDraw()) target.draw(centre, states);
	if (right.shouldDraw()) target.draw(right, states);
}

Player::Col Platforms::DetectCollision(Player& player) {
	return Player::noCollision;
}
