#ifndef HashMap_H
#define HashMap_H

#include "linkedlist.h"
#include "record.h"
#include <ostream>

template <typename K, typename V>
class HashMap
{
public:
    HashMap(int length = 5);
    ~HashMap();
    HashMap(const HashMap<K, V>& hashMap);
    void put(K key, V value);
    bool contains(K key);
    bool empty();
    int size();
    V get(K key);
    void remove(K key);
    friend std::ostream& operator<<(std::ostream& os, const HashMap<K, V>& hashMap)
    {
        if (hashMap.length == 0)
        {
            os << "[]";
            return os;
        }
        for (int i = 0; i < hashMap.length; i++)
        {
            if (hashMap.records[i].count() > 0)
            {
                os << hashMap.records[i];
            }
        }
        return os;
    }

private:
    LinkedList<Record<K, V>>* records;
    int length;
    int acctualLength;
    int hashing(K key);
    void resize();
};

template <typename K, typename V>
inline HashMap<K, V>::HashMap(int length) : acctualLength(0), length(length), records(new LinkedList<Record<K, V>>[length]) {}

template <typename K, typename V>
inline HashMap<K, V>::HashMap(const HashMap<K, V>& hashMap) : length(hashMap.length), records(hashMap.records), acctualLength(hashMap.acctualLength) {}

template <typename K, typename V>
inline HashMap<K, V>::~HashMap()
{
    if (!this->records)
    {
        delete[] this->records;
    }
}

template <typename K, typename V>
inline int HashMap<K, V>::size()
{
    return this->length;
}

template <typename K, typename V>
inline int HashMap<K, V>::hashing(K key)
{
    std::hash<K> hash_fn;
    return hash_fn(key) % this->length;
}

template <typename K, typename V>
inline void HashMap<K, V>::put(K key, V value)
{
    if (this->acctualLength != 0 && (float)this->length / this->acctualLength > 0.75)
    {
        this->resize();
    }
    int pos = this->hashing(key);
    Record<K, V> record(key, value);
    if (!this->records[pos].empty())
    {
        int index = this->records[pos].indexOf(record);
        if (index != -1)
        {
            this->records[pos].get(index).getKey(key);
            this->records[pos].get(index).setValue(value);
        }
        else
        {
            this->records[pos].add(record);
            this->acctualLength++;
        }
    }
    else
    {
        this->records[pos].add(record);
        this->acctualLength++;
    }
}

template <typename K, typename V>
inline V HashMap<K, V>::get(K key)
{
    if (this->length == 0)
    {
        return V();
    }
    int pos = this->hashing(key);
    if (this->records[pos].empty())
    {
        return V();
    }
    Record<K, V> record(key);
    int index = this->records[pos].indexOf(record);
    if (index == -1)
    {
        return V();
    }
    record = this->records[pos].get(index);
    return record.getValue();
}

template <typename K, typename V>
inline void HashMap<K, V>::remove(K key)
{
    if (this->length == 0)
    {
        return;
    }
    int pos = this->hashing(key);
    if (this->records[pos].empty())
    {
        return;
    }
    Record<K, V> record1(key);
    int index = this->records[pos].indexOf(record1);
    if (index == -1)
    {
        return;
    }
    this->records[pos].remove(record1);
    this->acctualLength--;
}

template <typename K, typename V>
inline bool HashMap<K, V>::contains(K key)
{
    if (this->length == 0)
    {
        return false;
    }
    int pos = this->hashing(key);
    if (this->records[pos].empty())
    {
        return false;
    }
    Record<K, V> record(key);
    return this->records[pos].contains(record);
}

template <typename K, typename V>
inline void HashMap<K, V>::resize()
{
    std::hash<K> hash_fn;
    int index;
    LinkedList<Record<K, V>>* newRecords = new LinkedList<Record<K, V>>[this->length * 2];
    for (int i = 0; i < this->length; i++)
    {
        for (int j = 0; j < this->records[i].count(); j++)
        {
            Record<K, V> record = this->records[i].get(j);
            index = hash_fn(record.getKey()) % (this->length * 2);
            newRecords[index].add(record);
        }
    }
    this->length *= 2;
    this->records = newRecords;
}

template <typename K, typename V>
inline bool HashMap<K, V>::empty()
{
    return this->length == 0;
}
#endif