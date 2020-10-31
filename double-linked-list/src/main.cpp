#include "../include/linkedlist.h"
#include <iostream>

int main()
{
    LinkedList<int> linkedList;
    for (int i = 0; i < 10; i++) {
        linkedList.add(i);
    }
    std::cout << linkedList << std::endl;
    std::cout << linkedList.indexOf(9) << std::endl;
    std::cout << linkedList.get(1) << std::endl;
    return 0;
}