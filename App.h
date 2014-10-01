#ifndef APP_H
#define APP_H

#include <iostream>
#include <istream>

#include "AVL.h"

class App {
private:
	bool m_running;
	int m_userInput;

	enum {
		INSERT = 1,
		PRINT_IN_ORDER,
		PRINT_PRE_ORDER,
		PRINT_POST_ORDER
	};
	AVL AVLTree;
public:
	App(void) : m_running(false), m_userInput(0) {}
	void quit(void) {
		m_running = false;
	}
	void start(void);
};

#endif