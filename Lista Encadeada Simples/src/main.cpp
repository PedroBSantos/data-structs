#include "../include/linkedlist.h"
#include <iostream>

int main()
{
    LinkedList<int> linkedList;
    for (int i = 0; i < 10; i++)
    {
        linkedList.add(i + 1);
    }
    std::cout << "Elementos:\t" << linkedList << std::endl;
    std::cout << "\nQuantidade de elementos:\t" << linkedList.size() << std::endl;
    for (int i = 0; i < linkedList.size(); i++)
    {
        std::cout << linkedList.contains(i + 1) << std::endl;
    }
    return 0;
}