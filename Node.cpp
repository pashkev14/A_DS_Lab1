#include "Node.h"

Node::Node(int val = 0) {
	this->val = val;
	this->next = nullptr;
}

Node::~Node() {
	this->val = 0;
	this->next = nullptr;
}