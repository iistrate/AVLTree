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
			BT.insertNode(num);
			std::cout << std::endl;
			break;
		case PRINT_IN_ORDER:
			std::cout << "In Order: ";
			BT.printIn(BT.getRoot());
			std::cout << std::endl;
			break;
		case PRINT_POST_ORDER:
			std::cout << "Post Order: ";
			BT.printPost(BT.getRoot());
			std::cout << std::endl;
			break;
		case PRINT_PRE_ORDER:
			std::cout << "Pre Order: ";
			BT.printPre(BT.getRoot());
			std::cout << std::endl;
			break;
		}
	} while (m_running);
}