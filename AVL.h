#ifndef AVL_H
#define AVL_H

#include "BinaryTree.h"

class AVL: public BinaryTree {
private:
	int m_lheight;
	int m_rheight;
	int m_heightdiff;
public:
	//check for heights, return height difference
	int getHeight(Node* node);
};

#endif