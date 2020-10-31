#ifndef NODE_H
#define NODE_H

template <typename T>
class Node
{
public:
    Node(T element);
    virtual ~Node();
    T getData();
    Node<T>* getNext();
    void setNext(Node<T>* next);

private:
    Node<T>* next;
    T element;
};

template <typename T>
inline Node<T>::Node(T element)
{
    this->element = element;
    this->next = nullptr;
}

template <typename T>
inline Node<T>::~Node()
{
    if (!this->next)
    {
        delete this->next;
    }
}

template <typename T>
inline Node<T>* Node<T>::getNext()
{
    return this->next;
}

template <typename T>
inline void Node<T>::setNext(Node<T>* next)
{
    this->next = next;
}

template <typename T>
inline T Node<T>::getData()
{
    return this->element;
}
#endif