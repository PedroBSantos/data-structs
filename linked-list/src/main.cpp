#include "../include/linkedlist.h"
#include <iostream>

int main()
{
    LinkedList<int> linkedList;
    for (int i = 0; i < 10; i++)
    {
        linkedList.add(i + 1);
    }
    std::cout << "Size: " << linkedList.count() << std::endl;
    std::cout << linkedList << std::endl;
    linkedList.remove(10);
    std::cout << linkedList << std::endl;
    return 0;
}