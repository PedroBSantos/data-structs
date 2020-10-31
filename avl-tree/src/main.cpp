#include <iostream>
#include "../include/tree.h"

int main(int, char**) {
    Tree<int> tree;
    tree.add(10);
    tree.add(20);
    tree.add(35);
    tree.add(50);
    tree.add(30);
    tree.add(40);
    tree.add(41);
    tree.add(42);
    tree.add(45);
    tree.add(60);
    tree.add(70);
    tree.add(46);
    tree.add(80);
    tree.remove(60);
    tree.remove(70);
    tree.remove(50);
    tree.remove(46);
    std::cout << "Pre-Order: " << tree.preOrder() << std::endl;
    std::cout << "Post-Order: " << tree.postOrder() << std::endl;
    std::cout << "In-Order: " << tree.inOrder() << std::endl;
    std::cout << "Max: " << tree.max() << std::endl;
    std::cout << "Min: " << tree.min() << std::endl;
    std::cout << "Size: " << tree.count() << std::endl;
    std::cout << "Contains: " << tree.contains(10) << std::endl;
    std::cout << "Empty: " << tree.empty() << std::endl;
    std::cout << "Successor: " << tree.successor(10) << std::endl;
    std::cout << "Predecessor: " << tree.predecessor(20) << std::endl;
    return 0;
}
