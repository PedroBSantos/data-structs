#include <iostream>
#include "../include/bloom_filter.h"

using namespace std;

int main(int argc, char const *argv[])
{
    BloomFilter<int> bloomFilter(10);
    bloomFilter.insert(10);
    bloomFilter.insert(20);
    std::cout << bloomFilter.contains(30) << std::endl;
    return 0;
}
