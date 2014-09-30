#include "BinaryTree.h"

void BinaryTree::insertNode(int data) {
	//if empty assign to node
	if (m_count == 0) {
		m_Root = new Node(data);
		m_count++;
	}
	//if more than one node
	else {
		insertNode(data, m_Root);
	}
}

void BinaryTree::insertNode(int data, Node* NewNode) {
	if (data < NewNode->getData()) {
		if (NewNode->getLeft() != 0) {
			//if left not empty keep looking
			insertNode(data, NewNode->getLeft());
		}
		//create left node
		else {
			Node* left = new Node(data);
			NewNode->setLeft(left);
		}
	}
	else {
		if (NewNode->getRight() != 0) {
			//if right not empty keep looking
			insertNode(data, NewNode->getRight());
		}
		//create left node
		else {
			Node* right = new Node(data);
			NewNode->setRight(right);
		}
	}
}

void BinaryTree::printIn(Node* node) {
	if (node) {
		//go left
		printIn(node->getLeft());
		std::cout << node->getData() << " ";
		//go right
		printIn(node->getRight());
	}
}
void BinaryTree::printPost(Node* node) {
	if (node) {
		//go left
		printPost(node->getLeft());
		//go right
		printPost(node->getRight());
		std::cout << node->getData() << " ";
	}
}
void BinaryTree::printPre(Node* node) {
	if (node) {
		//go right
		printPost(node->getRight());
		//go left
		printPost(node->getLeft());
		std::cout << node->getData() << " ";
	}
}