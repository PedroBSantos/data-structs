#ifndef CACHE_ENTRY
#define CACHE_ENTRY

#include <ctime>

template <typename T>
class CacheEntry {
private:
    T value;
    int key;
    long lastAccess;
    int rank;
public:
    CacheEntry(int key, T value);
    CacheEntry(const CacheEntry<T>& other);
    virtual ~CacheEntry() = default;
    T getValue();
    int getKey();
    long getLastAccess();
    int getRank();
    void hit();
};

template <typename T>
CacheEntry<T>::CacheEntry(int key, T value) {
    this->key = key;
    this->value = value;
    this->lastAccess = 0;
    this->rank = 0;
}

template <typename T>
CacheEntry<T>::CacheEntry(const CacheEntry<T>& other) {
    this->key = other.key;
    this->value = other.value;
    this->lastAccess = other.lastAccess;
    this->rank = other.rank;
}

template<typename T>
int CacheEntry<T>::getKey() {
    return this->key;
}

template<typename T>
T CacheEntry<T>::getValue() {
    return this->value;
}

template<typename T>
long CacheEntry<T>::getLastAccess() {
    return this->lastAccess;
}

template <typename T>
int CacheEntry<T>::getRank() {
    return this->rank;
}

template <typename T>
void CacheEntry<T>::hit() {
    time_t newAccess;
    time(&newAccess);
    this->lastAccess = (long)newAccess;
    this->rank++;
}
#endif