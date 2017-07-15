#include "Node.h"

Node::Node(int left, int center, int right)
{
	leftID = left;
	rightID = right;
	centerID = center;
}

std::shared_ptr<Node> Node::create(int left, int center, int right)
{
	return std::make_shared<Node>(left, center, right);
}
