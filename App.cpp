#include "App.h"

using std::cout;
using std::endl;
using std::cin;

void App::start(void) {
	m_running = true;
	int num = 0;
	
	do {
		cout << "1-Insert\n2-In\n3-Pre\n4-Post\n5-Balance Factor: ";
		cin >> m_userInput;
		switch (m_userInput)
		{
		case INSERT:
			cout << "Please insert number: ";
			cin >> num;
			AVLTree.insertNode(num);
			AVLTree.checkBalance(AVLTree.getRoot());
			AVLTree.printIn(AVLTree.getRoot());
			cout << endl;
			break;
		case PRINT_IN_ORDER:
			cout << "In Order: ";
			AVLTree.printIn(AVLTree.getRoot());
			cout << endl;
			break;
		case PRINT_POST_ORDER:
			cout << "Post Order: ";
			AVLTree.printPost(AVLTree.getRoot());
			cout << endl;
			break;
		case PRINT_PRE_ORDER:
			cout << "Pre Order: ";
			AVLTree.printPre(AVLTree.getRoot());
			cout << endl;
			break;
		case BALANCE_FACTOR:
			if (AVLTree.getRoot()) {
				cout << "LeftH: " << AVLTree.getRoot()->getLeftHeight() << endl;
				cout << "RightH: " << AVLTree.getRoot()->getRightHeight() << endl;
				cout << "Balance Factor: " << AVLTree.getRoot()->getBalanceFactor() << endl;
			}
			else {
				cout << "No nodes inserted, nothing to show." << endl;
			}
			break;
		default:
			m_running = false;
			break;
		}
//test	
		//if (AVLTree.getRoot()) {
		//	cout << "LeftH: " << AVLTree.getRoot()->getLeftHeight() << endl;
		//	cout << "RightH: " << AVLTree.getRoot()->getRightHeight() << endl;
		//	cout << "Balance Factor: " << AVLTree.getRoot()->getBalanceFactor() << endl;
		//}
		//else {
		//	cout << "No nodes inserted, nothing to show." << endl;
		//}
		//		cout << "Count: " << AVLTree.getCount() << endl;
		system("pause");
		system("cls");
//end test
	} while (m_running);
}