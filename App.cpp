#include "App.h"


void App::start(void) {
	m_running = true;
	int num = 0;

	do {
		std::cout << "Please enter 1 to insert node; 2 for in order; 3 for pre order; 4 for post order: ";
		std::cin >> m_userInput;
		switch (m_userInput)
		{
		case INSERT:
			std::cout << "Please insert number: ";
			std::cin >> num;
			AVLTree.insertNode(num);
			std::cout << std::endl;
			break;
		case PRINT_IN_ORDER:
			std::cout << "In Order: ";
			AVLTree.printIn(AVLTree.getRoot());
			std::cout << std::endl;
			break;
		case PRINT_POST_ORDER:
			std::cout << "Post Order: ";
			AVLTree.printPost(AVLTree.getRoot());
			std::cout << std::endl;
			break;
		case PRINT_PRE_ORDER:
			std::cout << "Pre Order: ";
			AVLTree.printPre(AVLTree.getRoot());
			std::cout << std::endl;
			break;
		}
	} while (m_running);
}