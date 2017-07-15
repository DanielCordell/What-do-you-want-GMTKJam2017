#pragma once
#include <SFML/Graphics/Text.hpp>
#include <memory>

class Node {

public:
	Node(int left, int centre, int right);
	static std::shared_ptr<Node> create(int left, int centre, int right);


	int leftID;
	int centreID;
	int rightID;

	sf::String questionText;
	sf::String answerText;
};
