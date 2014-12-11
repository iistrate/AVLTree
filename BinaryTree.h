#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>

using std::cout;
using std::endl;

class BinaryTree {
protected:
	class Node {
	private:
		Node* m_Right;
		Node* m_Left;

		const int m_data;
		int m_lheight;
		int m_rheight;
	public:
		//empty node
		Node(void): m_Right(0), m_Left(0), m_data(0), m_lheight(0), m_rheight(0) {}
		//node with data
		Node(int data): m_Right(0), m_Left(0), m_data(data), m_lheight(0), m_rheight(0) {}

		void setRight(Node* Right) {
			m_Right = Right;
		}
		void setLeft(Node* Left) {
			m_Left = Left;
		}
		void increaseRightHeight(void) {
			m_rheight++;
		}
		void increaseLeftHeight(void) {
			m_lheight++;
		}
		void decreaseRightHeight(void) {
			m_rheight--;
		}
		void decreaseLeftHeight(void) {
			m_lheight--;
		}

		Node* getRight(void) {
			return m_Right;
		}
		Node* getLeft(void) {
			return m_Left;
		}
		const int getData(void) const {
			return m_data;
		}
		//if negative right is bigger
		int getBalanceFactor(void) {
			return m_rheight - m_lheight;
		}
		//get max height
		int getHeight(void) {
			return m_lheight > m_rheight ? m_lheight : m_rheight;
		}
		int getRightHeight(void) {
			return m_rheight;
		}
		int getLeftHeight(void) {
			return m_lheight;
		}
	}; // end Node class

	int m_count;
	Node* m_Root;


public:
	BinaryTree(void): m_Root(0), m_count(0) {}
	

	/* Inline
	*/
	Node* getRoot(void) {
		return m_Root;
	}
	void setRoot(Node* Root) {
		m_Root = Root;
	}
	int getCount(void) {
		return m_count;
	}
	//Binary.cpp
	void insertNode(int data);
	void insertNode(int data, Node* NewNode);
	void printIn(Node* node);
	void printPre(Node* node);
	void printPost(Node* node);

}; // end Binary.H

#endif