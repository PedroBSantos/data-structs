#ifndef LRU_CACHE_H
#define LRU_CACHE_H

#include "cache_entry.h"
#include <map>

template <typename T>
class LRUCache {
private:
    std::map<int, CacheEntry<T>*> entries;
    int capacity;
    void removeLeastRecentlyUsed();
    CacheEntry<T>* getEntryWithMinRank();
public:
    LRUCache(int capacity);
    LRUCache(const LRUCache<T>& other);
    virtual ~LRUCache() = default;
    int size();
    void put(int key, T value);
    T get(int key);
    void clear();
};

template <typename T>
LRUCache<T>::LRUCache(int capacity) {
    this->capacity = capacity;
}

template <typename T>
LRUCache<T>::LRUCache(const LRUCache<T>& other) {
    this->capacity = other.capacity;
    this->entries = other.entries;
}

template <typename T>
int LRUCache<T>::size() {
    return this->entries.size();
}

template <typename T>
CacheEntry<T>* LRUCache<T>::getEntryWithMinRank() {
    CacheEntry<T>* entryWithMinRank = nullptr;
    if (this->entries.empty()) return entryWithMinRank;
    entryWithMinRank = this->entries.begin()->second;
    for (auto mapEntry : this->entries) {
        CacheEntry<T>* currentEntry = mapEntry.second;
        if (currentEntry->getRank() < entryWithMinRank->getRank())
            entryWithMinRank = currentEntry;
    }
    return entryWithMinRank;
}

template <typename T>
void LRUCache<T>::removeLeastRecentlyUsed() {
    if (this->entries.size() < this->capacity) return;
    CacheEntry<T>* leastRecentlyUsed = this->getEntryWithMinRank();
    auto mapEntry = this->entries.find(leastRecentlyUsed->getKey());
    this->entries.extract(mapEntry);
}

template <typename T>
void LRUCache<T>::put(int key, T value) {
    this->removeLeastRecentlyUsed();
    CacheEntry<T>* entry = new CacheEntry<T>(key, value);
    this->entries[key] = entry;
}

template<typename T>
T LRUCache<T>::get(int key) {
    auto mapEntry = this->entries.find(key);
    if (mapEntry == this->entries.end())
        return T();
    CacheEntry<T>* cacheEntry = mapEntry->second;
    cacheEntry->hit();
    return cacheEntry->getValue();
}

template <typename T>
void LRUCache<T>::clear() {
    this->entries.clear();
}

#endif