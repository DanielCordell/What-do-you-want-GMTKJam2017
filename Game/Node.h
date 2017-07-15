#pragma once
#include <SFML/Graphics/Text.hpp>
#include <memory>

class Node {

public:
	Node(int left, int center, int right);
	static std::shared_ptr<Node> create(int left, int center, int right);


	int leftID;
	int centerID;
	int rightID;

	sf::String questionText;
	sf::String answerText;
};
