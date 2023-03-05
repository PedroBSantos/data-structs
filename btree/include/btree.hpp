#ifndef BTREE_H
#define BTREE_H

#include "partition.hpp"
#include "invalid_min_degree_exception.hpp"

template<typename T>
class BTree {
private:
    int t;
    Partition<T>* root;
public:
    BTree(int t = 2);
    BTree(Partition<T>* root, int t = 2);
    BTree(const BTree<T>& tree);
    virtual ~BTree();
    void add(T value);
    bool contains(T value);
};

template<typename T>
inline BTree<T>::BTree(int t) {
    if (t < 2) throw InvalidMinDegreeException(t);
    this->t = t;
    this->root = new Partition<T>(t);
}

template<typename T>
inline BTree<T>::BTree(Partition<T>* root, int t) {
    this->root = root;
    this->t = t;
}

template<typename T>
inline BTree<T>::BTree(const BTree<T>& tree) {
    this->t = tree.t;
    this->root = tree.root;
}

template<typename T>
inline BTree<T>::~BTree() {
    delete this->root;
}

template<typename T>
inline void BTree<T>::add(T value) {
    if (this->root->full()) {
        Partition<T>* newPartition = new Partition<T>(this->t, nullptr);
        Partition<T>* oldestRoot = this->root;
        this->root = newPartition;
        oldestRoot->setFather(this->root);
        this->root->getChildrens()[0] = oldestRoot;
        this->root->setChildrensCount(1);
        oldestRoot->split(0);
        this->root->add(value);
        return;
    }
    this->root->add(value);
}

template<typename T>
inline bool BTree<T>::contains(T value) {
    return this->root->contains(value);
}
#endif