#include "../include/hashmap.h"
#include <iostream>

int main()
{
    HashMap<std::string, int> hashMap;
    hashMap.put("C", 1);
    hashMap.put("C++", 2);
    hashMap.put("Java", 3);
    hashMap.put("C#", 4);
    hashMap.put("Python", 5);
    std::cout << hashMap << std::endl;
    return 0;
}