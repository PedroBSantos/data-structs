#include <iostream>
#include "../include/lru_cache.h"

int main(int argc, char const *argv[]) {
    LRUCache<std::string> cache(5);
    cache.put(1, "a");
    cache.put(2, "ab");
    cache.put(3, "abc");
    cache.put(4, "abcd");
    cache.put(5, "abcde");
    cache.get(5);
    cache.get(5);
    cache.get(5);
    cache.get(4);
    cache.get(3);
    cache.get(4);
    cache.get(1);
    cache.put(6, "abcdef");
    return 0;
}
