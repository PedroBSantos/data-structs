#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "node.h"
#include <ostream>

template <typename T>
class LinkedList
{
public:
    LinkedList();
    virtual ~LinkedList();
    LinkedList(const LinkedList<T>& linkedList);
    void add(T element);
    void add(T element, int pos);
    void insert(T element, int pos);
    void clear();
    bool empty();
    bool contains(T element);
    int count();
    int indexOf(T element);
    bool remove(T element);
    T get(int pos);
    friend std::ostream& operator<<(std::ostream& os, const LinkedList<T>& linkedList)
    {
        if (linkedList.begin == nullptr)
        {
            os << "";
            return os;
        }
        Node<T>* aux = linkedList.begin;
        while (aux != nullptr)
        {
            os << aux->getData();
            aux = aux->getNext();
            if (aux != nullptr)
            {
                os << ", ";
            }
        }
        return os;
    }

private:
    int size;
    Node<T>* begin;
    Node<T>* end;
    void auxDelete(Node<T>* node);
};

template <typename T>
inline LinkedList<T>::LinkedList()
{
    this->begin = this->end = nullptr;
    this->size = 0;
}

template <typename T>
inline LinkedList<T>::~LinkedList()
{
    this->auxDelete(this->begin);
}

template <typename T>
inline void LinkedList<T>::auxDelete(Node<T>* node) {
    if (node != nullptr) {
        Node<T>* next = node->getNext();
        delete node;
        this->auxDelete(next);
    }
}

template <typename T>
inline LinkedList<T>::LinkedList(const LinkedList<T>& linkedList)
{
    this->begin = linkedList.begin;
    this->end = linkedList.end;
    this->size = linkedList.size;
}

template <typename T>
inline void LinkedList<T>::add(T element)
{
    Node<T>* node = new Node<T>(element, nullptr);
    if (this->size == 0)
    {
        this->begin = this->end = node;
    }
    else
    {
        this->end->setNext(node);
        this->end = node;
    }
    this->size++;
}

template <typename T>
inline void LinkedList<T>::add(T element, int pos)
{
    if (pos < 0 || pos > this->size)
    {
        return;
    }
    Node<T>* node = new Node<T>(element);
    if (pos == 0)
    {
        node->setNext(this->begin);
        this->begin = node;
    }
    else if (pos == this->size)
    {
        this->add(element);
        return;
    }
    else
    {
        Node<T>* aux = this->begin;
        int count = 0;
        while (count < pos - 1)
        {
            aux = aux->getNext();
            count++;
        }
        node->setNext(aux->getNext());
        aux->setNext(node);
    }
    this->size++;
}

template <typename T>
inline bool LinkedList<T>::remove(T element)
{
    if (this->size == 0) {
        return false;
    }
    if (this->begin->getData() == element) {
        Node<T>* node = this->begin;
        this->begin = this->begin->getNext();
        this->size--;
        return true;
    }
    else {
        Node<T>* previous = this->begin;
        while (previous != nullptr && previous->getNext() != nullptr && !(previous->getNext()->getData() == element)) {
            previous = previous->getNext();
        }
        if (previous != nullptr) {
            Node<T>* next = previous->getNext();
            if (next->getData() == element) {
                if (next == this->end) {
                    this->end = previous;
                    this->end->setNext(nullptr);
                }
                else {
                    previous->setNext(next->getNext());
                }
                this->size--;
            }
            delete next;
            return true;
        }
    }
    return false;
}

template <typename T>
inline T LinkedList<T>::get(int pos)
{
    if (pos < 0 || pos >= this->size)
    {
        return T();
    }
    Node<T>* aux = this->begin;
    int count = 0;
    while (count < pos)
    {
        aux = aux->getNext();
        count++;
    }
    return (T)aux->getData();
}

template <typename T>
inline int LinkedList<T>::count()
{
    return this->size;
}

template <typename T>
inline bool LinkedList<T>::empty()
{
    return this->size == 0;
}

template <typename T>
inline void LinkedList<T>::clear()
{
    if (this->begin != nullptr)
    {
        Node<T>* aux = this->begin;
        delete aux;
        this->begin = this->end = nullptr;
    }
    this->size = 0;
}

template <typename T>
inline void LinkedList<T>::insert(T element, int pos)
{
    if (pos < 0 || pos >= this->size)
    {
        return;
    }
    if (pos == 0)
    {
        this->begin->setData(element);
    }
    else if (pos == this->size - 1)
    {
        this->end->setData(element);
    }
    else
    {
        int count = 0;
        Node<T>* aux = this->begin;
        while (count < pos)
        {
            aux = aux->getNext();
            count++;
        }
        aux->setData(element);
    }
}

template <typename T>
inline bool LinkedList<T>::contains(T element)
{
    if (this->size == 0)
    {
        return false;
    }
    Node<T>* aux = this->begin;
    while (aux)
    {
        if (aux->getData() == element)
        {
            return true;
        }
        aux = aux->getNext();
    }
    return false;
}

template <typename T>
inline int LinkedList<T>::indexOf(T element) {
    int index = -1;
    int count = 0;
    Node<T>* node = this->begin;
    while (node != nullptr) {
        if (node->getData() == element) {
            index = count;
            break;
        }
        count++;
        node = node->getNext();
    }
    return index;
}
#endif