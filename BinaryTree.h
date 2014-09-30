#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>

class BinaryTree {
private:
	class Node {
	private:
		Node* m_Right;
		Node* m_Left;
		const int m_data;
	public:
		//empty node
		Node(void) : m_Right(0), m_Left(0), m_data(0) {}
		//node with data
		Node(int data) : m_Right(0), m_Left(0), m_data(data) {}

		void setRight(Node* Right) {
			m_Right = Right;
		}
		void setLeft(Node* Left) {
			m_Left = Left;
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
	//get count
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