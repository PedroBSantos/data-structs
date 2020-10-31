#ifndef QUEUE_H
#define QUEUE_H
#include "node.h"

template <typename T>
class Queue
{
public:
    Queue();
    Queue(const Queue<T>& queue);
    ~Queue();
    bool empty();
    int count();
    void queue(T element);
    T dequeue();

private:
    Node<T>* begin;
    Node<T>* end;
    int size;
};

template <typename T>
inline Queue<T>::Queue()
{
    this->begin = this->end = nullptr;
    this->size = 0;
}

template <typename T>
inline Queue<T>::~Queue()
{
    if (!this->begin)
    {
        delete this->begin;
    }
}

template <typename T>
inline Queue<T>::Queue(const Queue& queue)
{
    this->begin = queue.begin;
    this->end = queue.end;
    this->size = queue.size;
}

template <typename T>
inline bool Queue<T>::empty()
{
    return this->size == 0;
}

template <typename T>
inline int Queue<T>::count()
{
    return this->size;
}

template <typename T>
inline void Queue<T>::queue(T element)
{
    Node<T>* newNode = new Node<T>(element);
    if (this->size == 0)
    {
        this->begin = this->end = newNode;
    }
    else
    {
        this->end->setNext(newNode);
        this->end = newNode;
    }
    this->size++;
}

template <typename T>
inline T Queue<T>::dequeue()
{
    if (this->size == 0)
    {
        return T();
    }
    T element = this->begin->getelement();
    Node<T>* aux = this->begin;
    this->begin = this->begin->getNext();
    delete aux;
    this->size--;
    return element;
}
#endif