#include "../include/tree.h"
#include <iostream>

int main(int argc, char* argv[])
{
	Tree<int> tree;
	tree.add(10);
	tree.add(5);
	tree.add(1);
	tree.add(8);
	tree.add(15);
	tree.add(12);
	tree.add(18);
	tree.add(7);
	tree.add(9);

	std::cout << "Percurso pre-ordem: " << tree.preOrder() << std::endl;
	std::cout << "Percurso in-ordem:  " << tree.inOrder() << std::endl;
	std::cout << "Percurso pos-ordem: " << tree.postOrder() << std::endl;
	std::cout << "Predecessor: " << tree.predecessor(8) << std::endl;
	std::cout << "Successor: " << tree.successor(5) << std::endl;
	tree.remove(5);

	std::cout << "Pre-Order: " << tree.preOrder() << std::endl;
	std::cout << "In-Order:  " << tree.inOrder() << std::endl;
	std::cout << "Post-Order: " << tree.postOrder() << std::endl;
	return 0;
}