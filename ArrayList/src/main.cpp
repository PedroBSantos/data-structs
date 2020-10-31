#include "../include/arraylist.h"
#include <ctime>
#include <iostream>

int main()
{
    srand((unsigned)time(0));
    ArrayList<int> arraylist;
    for (int i = 0; i < 20; i++)
    {
        arraylist.add(rand() % 100);
    }
    std::cout << arraylist << std::endl;
    arraylist.sort();
    std::cout << arraylist << std::endl;
    return 0;
}