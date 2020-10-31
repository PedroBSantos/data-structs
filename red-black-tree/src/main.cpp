#include "../include/tree.h"
#include <iostream>

int main(int argc, char* argv[])
{
    Tree<double> tree;
    tree.add(7);
    tree.add(7.5);
    tree.add(5);
    tree.add(6);
    tree.add(13);
    tree.add(11);
    tree.add(12);
    tree.add(9);
    tree.add(10);
    tree.add(8);

    std::cout << "Max: " << tree.max() << std::endl;
    std::cout << "Min: " << tree.min() << std::endl;
    std::cout << "In-Order: " << tree.percOrdem() << std::endl;
    std::cout << "Pre-Order: " << tree.percPreOrdem() << std::endl;
    std::cout << "Post-Order: " << tree.percPosOrdem() << std::endl;
    std::cout << "Successor: " << tree.successor(5) << std::endl;
    std::cout << "Predecessor: " << tree.predecessor(13) << std::endl;

    tree.remove(7);
    tree.remove(11);
    tree.remove(12);

    std::cout << "\nMax: " << tree.max() << std::endl;
    std::cout << "Min: " << tree.min() << std::endl;
    std::cout << "In-Order: " << tree.percOrdem() << std::endl;
    std::cout << "Pre-Order: " << tree.percPreOrdem() << std::endl;
    std::cout << "Post-Order: " << tree.percPosOrdem() << std::endl;
    std::cout << "Successor: " << tree.successor(5) << std::endl;
    std::cout << "Predecessor: " << tree.predecessor(13) << std::endl;
    return 0;
}
