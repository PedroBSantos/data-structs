#include "../include/array_list.h"
#include <ctime>
#include <iostream>

int main()
{
    srand((unsigned)time(0));
    ArrayList<int> arrayList;
    for (int i = 0; i < 20; i++)
    {
        arrayList.add(rand() % 100);
    }
    std::cout << arrayList << std::endl;
    arrayList.sort();
    std::cout << arrayList << std::endl;
    system("pause");
    return 0;
}