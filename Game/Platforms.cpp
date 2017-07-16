#include "Platforms.h"
#include <SFML/Graphics/RenderTarget.hpp>
#include <optional>

void Platforms::Change(std::shared_ptr<Node> left, std::shared_ptr<Node> centre, std::shared_ptr<Node> right)
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
	if (left.ShouldDraw()) target.draw(left, states);
	if (centre.ShouldDraw()) target.draw(centre, states);
	if (right.ShouldDraw()) target.draw(right, states);
}


std::tuple<std::optional<float>, std::optional<float>, std::optional<float>> Platforms::DetectCollision(Player& player) const {
	std::tuple<std::optional<float>, std::optional<float>, std::optional<float>> collision = std::make_tuple(std::optional<float>(), std::optional<float>(), std::optional<float>());
	auto playerBounds = player.GetGlobalBounds();

	if (left.ShouldDraw()) {
		std::get<0>(collision) = left.GetCollision(playerBounds);
	}
	if (centre.ShouldDraw()) {
		std::get<1>(collision) = centre.GetCollision(playerBounds);
	}
	if (right.ShouldDraw()) {
		std::get<2>(collision) = right.GetCollision(playerBounds);
	}
	return collision;
}

void Platforms::Update()
{
	if (!isTransition) return;
	left.Transition();
	right.Transition();
	centre.Transition();

	if (left.DoneTransition() && right.DoneTransition() && centre.DoneTransition()) {
		isTransition = false;
	}
}

void Platforms::Transition()
{
	if (isTransition) return;
	isTransition = true;
}

bool Platforms::TransitionDone() const {
	return left.DoneTransition() && right.DoneTransition() 	&& centre.DoneTransition();
}
