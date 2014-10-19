#ifndef AVL_H
#define AVL_H

#include "BinaryTree.h"

class AVL: public BinaryTree {
public:
	//AVL.cpp
	void insertNode(int data);
	void insertNode(int data, Node* NewNode);
	void leftRotation(Node* node);
	void rightRotation(Node* node);
	void checkBalance(Node* node);
};

#endif