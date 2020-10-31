#ifndef LinkedList_H
#define LinkedList_H

#include "node.h"
#include <ostream>

template <typename T>
class LinkedList
{
public:
    LinkedList();
    LinkedList(const LinkedList<T>& linkedList);
    virtual ~LinkedList();
    void clear();
    void add(T element);
    void add(T element, int pos);
    bool remove(T element);
    bool contains(T element);
    bool empty();
    int count();
    int indexOf(T element);
    T get(int pos);
    bool insert(T element, int pos);
    friend std::ostream& operator<<(std::ostream& os, const LinkedList<T>& linkedList)
    {
        if (linkedList.begin == nullptr)
        {
            os << "[]";
            return os;
        }
        Node<T>* aux = linkedList.begin;
        os << "[";
        while (aux)
        {
            os << aux->getData();
            aux = aux->getNext();
            if (aux)
            {
                os << ", ";
            }
        }
        os << "]";
        return os;
    }

private:
    Node<T>* begin;
    Node<T>* end;
    int size;
};

template <typename T>
inline LinkedList<T>::LinkedList() : begin(nullptr), end(nullptr), size(0) {}

template <typename T>
inline LinkedList<T>::~LinkedList()
{
    if (this->begin != nullptr)
    {
        delete this->begin;
    }
}

template <typename T>
inline LinkedList<T>::LinkedList(const LinkedList<T>& linkedList) : begin(linkedList.begin), end(linkedList.end), size(linkedList.size) {}

template <typename T>
inline void LinkedList<T>::add(T element)
{
    Node<T>* node = new Node<T>(element, nullptr, nullptr);
    if (this->size == 0)
    {
        this->begin = this->end = node;
    }
    else
    {
        node->setPrevious(this->end);
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
    if (pos == this->size)
    {
        this->add(element);
        return;
    }
    Node<T>* node = new Node<T>(element);
    if (pos == 0)
    {
        node->setNext(this->begin);
        this->begin->setPrevious(node);
        this->begin = node;
    }
    else if (pos == this->size - 1)
    {
        node->setNext(this->end);
        this->end->setPrevious(node);
        node->setPrevious(this->end->getPrevious());
    }
    else
    {
        Node<T>* aux = this->begin;
        int count = 0;
        while (count < pos)
        {
            aux = aux->getNext();
            count++;
        }
        aux->getPrevious()->setNext(node);
        node->setPrevious(aux->getPrevious());
        node->setNext(aux->getNext());
    }
    this->size++;
}

template <typename T>
inline bool LinkedList<T>::remove(T element)
{
    if (this->size == 0)
    {
        return false;
    }
    Node<T>* aux = this->begin;
    while (aux != nullptr) {
        if (aux->getData() == element) {
            if (aux == this->begin) {
                this->begin = this->begin->getNext();
                if (this->begin != nullptr) {
                    this->begin->setPrevious(nullptr);
                }
            }
            else if (aux == this->end) {
                this->end = this->end->getPrevious();
                if (this->end != nullptr) {
                    this->end->setNext(nullptr);
                }
            }
            else {
                Node<T>* previous = aux->getPrevious();
                Node<T>* next = aux->getNext();
                previous->setNext(next);
                next->setPrevious(previous);
            }
            this->size--;
            delete aux;
            break;
        }
        aux = aux->getNext();
    }
    return false;
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
inline T LinkedList<T>::get(int pos)
{
    if (pos < 0 || pos >= this->size || this->size == 0)
    {
        return T();
    }
    T element;
    if (pos == 0)
    {
        element = this->begin->getData();
        return element;
    }
    else if (pos == this->size - 1)
    {
        element = this->end->getData();
        return element;
    }
    Node<T>* aux = this->begin;
    int count = 0;
    while (count < pos)
    {
        aux = aux->getNext();
        count++;
    }
    element = aux->getData();
    return element;
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
inline bool LinkedList<T>::empty()
{
    return this->size == 0;
}

template <typename T>
inline int LinkedList<T>::count()
{
    return this->size;
}

template <typename T>
inline int LinkedList<T>::indexOf(T element)
{
    if (this->size == 0)
    {
        return -1;
    }
    int count = 0;
    Node<T>* aux = this->begin;
    while (aux)
    {
        if (aux->getData() == element)
        {
            return count;
        }
        count++;
        aux = aux->getNext();
    }
    return -1;
}

template <typename T>
inline bool LinkedList<T>::insert(T element, int pos)
{
    if (pos < 0 || pos >= this->size)
    {
        return false;
    }
    if (pos == this->size - 1)
    {
        this->end->setData(element);
        return true;
    }
    int count = 0;
    Node<T>* aux = this->begin;
    while (count < pos)
    {
        aux = aux->getNext();
        count++;
    }
    aux->setData(element);
    return true;
}
#endif