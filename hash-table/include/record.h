#ifndef RECORD_H
#define RECORD_H

#include <ostream>

template <typename K, typename V>
class Record
{
public:
    Record();
    virtual ~Record() = default;
    Record(K key);
    Record(K key, V value);
    Record(const Record<K, V>& record);
    V getValue();
    K getKey();
    void setValue(V value);
    void getKey(K key);
    friend bool operator==(const Record<K, V>& record1, const Record<K, V>& record2)
    {
        return record1.key == record2.key;
    }
    friend std::ostream& operator<<(std::ostream& os, const Record<K, V>& record)
    {
        os << "\nKey: " << record.key << "\nValue: " << record.value;
        return os;
    }

private:
    V value;
    K key;
};

template <typename K, typename V>
inline Record<K, V>::Record()
{
    this->key = K();
    this->value = V();
}

template <typename K, typename V>
inline Record<K, V>::Record(const Record<K, V>& record) : value(record.value), key(record.key) {}

template <typename K, typename V>
inline Record<K, V>::Record(K key) : key(key) {}

template <typename K, typename V>
inline Record<K, V>::Record(K key, V value) : Record(key) {
    this->value = value;
}

template <typename K, typename V>
inline V Record<K, V>::getValue()
{
    return this->value;
}

template <typename K, typename V>
inline void Record<K, V>::setValue(V value)
{
    this->value = value;
}

template <typename K, typename V>
inline K Record<K, V>::getKey()
{
    return this->key;
}

template <typename K, typename V>
inline void Record<K, V>::getKey(K key)
{
    this->key = key;
}
#endif