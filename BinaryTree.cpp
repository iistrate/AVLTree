#include "BinaryTree.h"

void BinaryTree::insertNode(int data) {
	//if empty assign to node
	if (m_count == 0) {
		m_Root = new Node(data);
	}
	//if more than one node
	else {
		insertNode(data, m_Root);
	}
	m_count++;
}

void BinaryTree::insertNode(int data, Node* NewNode) {
	if (data < NewNode->getData()) {
		if (NewNode->getLeft() != 0) {
			//each subsequent node will have +1 to its height
			NewNode->increaseLeftHeight();
			//if left not empty keep looking
			insertNode(data, NewNode->getLeft());
		}
		//create left node
		else {
			Node* left = new Node(data);
			NewNode->setLeft(left);
			NewNode->increaseLeftHeight();
		}
	}
	else {
		if (NewNode->getRight() != 0) {
			//each subsequent node will have +1 to its height
			NewNode->increaseRightHeight();
			//if right not empty keep looking
			insertNode(data, NewNode->getRight());
		}
		//create right node
		else {
			Node* right = new Node(data);
			NewNode->setRight(right);
			NewNode->increaseRightHeight();
		}
	}
}

void BinaryTree::printIn(Node* node) {
	if (node) {
		//go left
		printIn(node->getLeft());
		cout << node->getData() << " ";
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
		cout << node->getData() << " ";
	}
}
void BinaryTree::printPre(Node* node) {
	if (node) {
		//go right
		printPost(node->getRight());
		//go left
		printPost(node->getLeft());
		cout << node->getData() << " ";
	}
}