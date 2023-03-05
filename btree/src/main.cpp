#include <iostream>
#include "../include/btree.hpp"

int main(int argc, char const* argv[]) {
    BTree<char> tree(3);
    tree.add('G');
    tree.add('M');
    tree.add('P');
    tree.add('X');
    tree.add('A');
    tree.add('C');
    tree.add('D');
    tree.add('E');
    tree.add('J');
    tree.add('N');
    tree.add('O');
    tree.add('R');
    tree.add('S');
    tree.add('T');
    tree.add('U');
    tree.add('V');
    tree.add('Y');
    tree.add('Z');
    std::cout << tree.contains('G') << std::endl;
    std::cout << tree.contains('M') << std::endl;
    std::cout << tree.contains('P') << std::endl;
    std::cout << tree.contains('X') << std::endl;
    std::cout << tree.contains('A') << std::endl;
    std::cout << tree.contains('C') << std::endl;
    std::cout << tree.contains('D') << std::endl;
    std::cout << tree.contains('E') << std::endl;
    std::cout << tree.contains('J') << std::endl;
    std::cout << tree.contains('N') << std::endl;
    std::cout << tree.contains('O') << std::endl;
    std::cout << tree.contains('R') << std::endl;
    std::cout << tree.contains('S') << std::endl;
    std::cout << tree.contains('T') << std::endl;
    std::cout << tree.contains('U') << std::endl;
    std::cout << tree.contains('V') << std::endl;
    std::cout << tree.contains('Y') << std::endl;
    std::cout << tree.contains('Z') << std::endl;
    return 0;
}