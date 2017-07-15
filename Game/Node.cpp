#include "Node.h"

Node::Node(int left, int centre, int right)
{
	leftID = left;
	rightID = right;
	centreID = centre;
}

std::shared_ptr<Node> Node::create(int left, int centre, int right)
{
	return std::make_shared<Node>(left, centre, right);
}
