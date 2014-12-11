#include "AVL.h"

void AVL::insertNode(int data) {
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
void AVL::insertNode(int data, Node* NewNode) {
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
void AVL::checkBalance(Node* node) {
	int balanceFactor;
	if (node) {
		//goleft
		checkBalance(node->getLeft());
		//goright
		checkBalance(node->getRight());
		//get balance factor
		balanceFactor = node->getBalanceFactor();
//test
//		cout << "Balance factor: " << balanceFactor << " for data: " << node->getData() << endl;
//end test
		//if node right heavy
		if (balanceFactor > 1) {
			if (node->getRight() != 0) {
				//if right node left heavy
				if (node->getRight()->getBalanceFactor() < -1) {
					//double left
					leftRotation(node);
					leftRotation(node);
				}
				else {
					leftRotation(node);
				}
			}
		}
		//if node left heavy
		else if (balanceFactor < -1) {
			if (node->getLeft() != 0) {
				//if left node is right heavy
				if (node->getLeft()->getBalanceFactor() > 1) {
					//double right
					rightRotation(node);
					rightRotation(node);
				}
				else {
					rightRotation(node);
				}
			}
		}
	}
}
void AVL::leftRotation(Node* node) {
//test
	cout << "Rotate left at node: " << node->getData() << endl;
//end test
	//rebalance node
	node->decreaseRightHeight();
	
	//get right
	Node* right = node->getRight();
	//connect right to left
	right->setLeft(node);
	//disconnect rotation node
	node->setRight(0);
	
	if (node == m_Root) {
		setRoot(right);
	}

//test
	//Node* testLeft = node->getLeft();
	//if (testLeft) {
	//	cout << testLeft->getData();
	//}
	//Node* testRight = node->getRight();
	//if (testRight) {
	//	cout << node->getRight()->getData() << endl;
	//}
//end
}
void AVL::rightRotation(Node* node) {
//test
	cout << "Rotate right at node: " << node->getData() << endl;
//end test
	//rebalance
	node->decreaseRightHeight();

	//get left
	Node* left = node->getLeft();
	//connect left to right
	left->setRight(node);
	//disconnect rotation node
	node->setLeft(0);

	if (node == m_Root) {
		setRoot(left);
	}
}