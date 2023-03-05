#ifndef PARTITION_H
#define PARTITION_H

#include "invalid_min_degree_exception.hpp"

template<typename T>
class Partition {
private:
    int t;
    int keysCount;
    int childrensCount;
    T* keys;
    Partition<T>* father;
    Partition<T>** childrens;
    bool isLeaf();
    void setKeysCount(int count);
public:
    Partition(int t = 2, Partition<T>* father = nullptr);
    Partition(const Partition<T>& partition);
    virtual ~Partition() = default;
    Partition<T>** getChildrens();
    T* getKeys();
    void add(T key);
    void split(int splitIndex);
    bool full();
    bool contains(T key);
    int countKeys();
    int countChildrens();
    void setFather(Partition<T>* father);
    void setChildrensCount(int count);
};

template<typename T>
inline Partition<T>::Partition(int t, Partition<T>* father) {
    if (t < 2) throw InvalidMinDegreeException(t);
    this->t = t;
    this->father = father;
    this->keys = new T[(2 * this->t) - 1];
    this->childrens = new Partition<T>*[(2 * this->t) - 1];
}

template<typename T>
inline Partition<T>::Partition(const Partition<T>& partition) {
    this->t = partition.t;
    this->keys = partition.keys;
    this->father = partition.father;
    this->childrens = partition.childrens;
    this->keysCount = partition.keysCount;
    this->childrensCount = partition.childrensCount;
}

template<typename T>
inline Partition<T>** Partition<T>::getChildrens() {
    return this->childrens;
}

template<typename T>
inline T* Partition<T>::getKeys() {
    return this->keys;
}

// Ao repartir uma partição y cheia (n chaves = 2 * t - 1) uma outra partição z é gerada. O posição
// de z na partição pai será logo após a posição de y (splitIndex + 1). A chave mediana
// de y (y.chaves[t - 1]) será removida e colocada em x.chaves[splitIndex]. splitIndex é indice que y ocupa no array de filhos de x.
template<typename T>
inline void Partition<T>::split(int splitIndex) {
    if (!this->full()) {
        return;
    }
    T medianKey = this->keys[this->t - 1];
    Partition<T>* newPartition = new Partition<T>(this->t, this->father);
    for (int i = this->t; i < this->keysCount; i++) {
        newPartition->getKeys()[i - t] = this->keys[i];
        newPartition->setKeysCount(newPartition->countKeys() + 1);
    }
    if (!this->isLeaf()) {
        for (int i = this->t; i < this->childrensCount; i++) {
            Partition<T>* children = this->childrens[i];
            children->setFather(newPartition);
            newPartition->getChildrens()[i - t] = children;
            newPartition->setChildrensCount(newPartition->countChildrens() + 1);
        }
        this->childrensCount = this->t - 1;
    }
    this->keysCount = this->t - 1;
    int fatherKeysCount = this->father->countKeys();
    for (int i = fatherKeysCount; i > splitIndex; i--) {
        this->father->getKeys()[i] = this->father->getKeys()[i - 1];
    }
    this->father->getKeys()[splitIndex] = medianKey;
    int fatherChildrensCount = this->father->countChildrens();
    for (int i = fatherChildrensCount; i > splitIndex + 1; i--) {
        this->father->getChildrens()[i] = this->father->getChildrens()[i - 1];
    }
    this->father->getChildrens()[splitIndex + 1] = newPartition;
    this->father->setChildrensCount(fatherChildrensCount + 1);
    this->father->setKeysCount(fatherKeysCount + 1);
}

template<typename T>
inline void Partition<T>::setFather(Partition<T>* father) {
    this->father = father;
}

template<typename T>
inline void Partition<T>::add(T key) {
    if (this->countKeys() == 0) {
        this->keys[0] = key;
        this->keysCount++;
        return;
    }
    int currentIndex = this->countKeys() - 1;
    if (this->isLeaf()) {
        while (currentIndex >= 0 && key < this->keys[currentIndex]) {
            this->keys[currentIndex + 1] = this->keys[currentIndex];
            currentIndex--;
        }
        this->keys[++currentIndex] = key;
        this->keysCount++;
        return;
    }
    while (currentIndex >= 0 && key < this->keys[currentIndex])
        currentIndex--;
    currentIndex++;
    if (this->childrens[currentIndex]->full()) {
        this->childrens[currentIndex]->split(currentIndex);
        if (key > this->keys[currentIndex])
            currentIndex++;
    }
    this->childrens[currentIndex]->add(key);
}

template<typename T>
inline bool Partition<T>::full() {
    return this->keysCount >= (2 * this->t) - 1;
}

template<typename T>
inline bool Partition<T>::contains(T searchKey) {
    int searchIndex = 0;
    while (searchIndex < this->countKeys() && searchKey > this->keys[searchIndex])
        searchIndex++;
    if (searchIndex < this->countKeys() && searchKey == this->keys[searchIndex])
        return true;
    if (this->isLeaf())
        return false;
    Partition<T>* nextSearchPartition = this->childrens[searchIndex];
    return nextSearchPartition->contains(searchKey);
}

template<typename T>
inline bool Partition<T>::isLeaf() {
    return this->childrensCount == 0;
}

template<typename T>
inline void Partition<T>::setKeysCount(int count) {
    this->keysCount = count;
}

template<typename T>
inline void Partition<T>::setChildrensCount(int count) {
    this->childrensCount = count;
}

template<typename T>
inline int Partition<T>::countKeys() {
    return this->keysCount;
}

template<typename T>
inline int Partition<T>::countChildrens() {
    return this->childrensCount;
}
#endif