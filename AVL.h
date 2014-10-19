#ifndef AVL_H
#define AVL_H

#include "BinaryTree.h"

class AVL: public BinaryTree {
public:
	//AVL.cpp
	void insertNode(int data) {
		BinaryTree::insertNode(data);
	}
	void insertNode(int data, Node* NewNode);
};

#endif