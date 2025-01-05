#ifndef BLOOM_FILTER_H
#define BLOOM_FILTER_H

#include <cmath>
#include <functional>

enum ContainsResult 
{
    NOT_CONTAINS,
    POSSIBLE_CONTAINS
};

template <typename T>
class BloomFilter
{
private:
    int *arrayOfBits;
    int lenghtOfBitsArray;
    int f(T element);
    int h(T element);

public:
    BloomFilter(int expectedNumberOfElements = 5, double falsePositiveRate = 0.08);
    BloomFilter(const BloomFilter &bloomFilter);
    virtual ~BloomFilter();
    void insert(T element);
    ContainsResult contains(T element);
};

template <typename T>
BloomFilter<T>::BloomFilter(int expectedNumberOfElements, double falsePositiveRate)
{
    this->lenghtOfBitsArray = (-expectedNumberOfElements * std::log(falsePositiveRate)) / pow(std::log(2), 2);
    this->arrayOfBits = new int[this->lenghtOfBitsArray];
    for (int i = 0; i < this->lenghtOfBitsArray; i++)
        this->arrayOfBits[i] = 0;
}

template <typename T>
BloomFilter<T>::BloomFilter(const BloomFilter &bloomFilter)
{
    this->lenghtOfBitsArray = bloomFilter.lenghtOfBitsArray;
    for (int i = 0; i < bloomFilter.lenghtOfBitsArray; i++)
        this->arrayOfBits[i] = bloomFilter.arrayOfBits[i];
}

template <typename T>
BloomFilter<T>::~BloomFilter()
{
    delete[] this->arrayOfBits;
    this->arrayOfBits = nullptr;
}

template <typename T>
int BloomFilter<T>::f(T element)
{
    std::hash<T> hash_fn;
    return std::abs((long)(hash_fn(element) * 5 / 2)) % this->lenghtOfBitsArray;
}

template <typename T>
int BloomFilter<T>::h(T element)
{
    std::hash<T> hash_fn;
    return std::abs((long)(hash_fn(element) + 3 / 33)) % this->lenghtOfBitsArray;
}

template <typename T>
void BloomFilter<T>::insert(T element) 
{
    int hashResult1 = this->f(element);
    this->arrayOfBits[hashResult1] = 1;
    int hashResult2 = this->h(element);
    this->arrayOfBits[hashResult2] = 1;
}

template <typename T>
ContainsResult BloomFilter<T>::contains(T element)
{
    int hashResult1 = this->f(element);
    int hashResult2 = this->h(element);
    if (this->arrayOfBits[hashResult1] == 1 && this->arrayOfBits[hashResult2] == 1)
        return POSSIBLE_CONTAINS;
    return NOT_CONTAINS;    
}

#endif