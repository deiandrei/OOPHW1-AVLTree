#include <iostream>

#include "Arbore.h"
#include "Arbore_AVL.h"

int main(int argc, char** argv) {
	Arbore_AVL tree;
	tree.Insert(10);
	std::cin >> tree;
	tree = (8 + tree);
	tree = (28 + tree);
	tree = (38 + tree);
	tree.Insert(18);

	std::cout << tree << "\n";

	tree.Delete(11);

	tree.Print();

	tree.Delete(12);

	tree.Print();

	tree.PrintLeafs();

	tree.PrintEchilibru();

	std::cout << "\n\n\n" << tree.Height();

	system("pause");
	return 0;
}
