#include "AVL.h"

int AVL::getHeight(Node* node) {
	int lheight, rheight;
	if (node) {
		//get left height
		lheight = getHeight(node->getLeft());
		//get right height
		rheight = getHeight(node->getRight());
	}
	if (lheight > rheight) {
		m_heightdiff = lheight - rheight;
	}
	else if (lheight < rheight) {
		m_heightdiff = rheight - lheight;
	}
	else {
		m_heightdiff = 0;
	}
	return m_heightdiff;
}