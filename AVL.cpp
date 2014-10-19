#include "AVL.h"

void AVL::insertNode(int data, Node* NewNode) {
	int balanceFactor;
	if (data < NewNode->getData()) {
		//if left not empty
		if (NewNode->getLeft() != 0) {
			balanceFactor = NewNode->getLeft()->getBalanceFactor();
			// and balance factor is not left biased
			if (balanceFactor <= 0) {
				//each subsequent node will have +1 to its left height
				NewNode->increaseLeftHeight();
				insertNode(data, NewNode->getLeft());
			}
			//send it right
			else {
				NewNode->increaseRightHeight();
				insertNode(data, NewNode->getRight());
			}
		}
		//create left node
		else {
			Node* left = new Node(data);
			NewNode->setLeft(left);
			NewNode->increaseLeftHeight();
		}
	}
	else {
		//if right not empty keep looking
		if (NewNode->getRight() != 0) {
			balanceFactor = NewNode->getRight()->getBalanceFactor();
			//if node's balance factor is not right biased
			if (balanceFactor <= 0) {
				//each subsequent node will have +1 to its right height
				NewNode->increaseRightHeight();
				insertNode(data, NewNode->getRight());
			}
			//send it left
			else {
				NewNode->increaseLeftHeight();
				insertNode(data, NewNode->getLeft());
			}
		}
		//create right node
		else {
			Node* right = new Node(data);
			NewNode->setRight(right);
			NewNode->increaseRightHeight();
		}
	}
}