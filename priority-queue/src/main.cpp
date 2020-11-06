#include "../include/queue.h"
#include <ctime>
#include <iostream>

int main(int argc, char const* argv[])
{
    srand((unsigned)time(0));
    Queue<int> queue;
    int random;
    for (int i = 0; i < 10; i++)
    {
        random = rand();
        queue.add(random);
        std::cout << random << "\t";
    }
    std::cout << "\n" << std::endl;
    while (!queue.empty())
    {
        std::cout << queue.remove() << "\t";
    }
    return 0;
}
