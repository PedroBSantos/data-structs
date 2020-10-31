#ifndef NODE_H
#define NODE_H

template <typename T>
class Node
{
public:
    Node(T data);
    ~Node();
    T getData();
    Node<T>* getPrevious();
    void setPrevious(Node<T>* previous);

private:
    Node<T>* previous;
    T data;
};

template <typename T>
inline Node<T>::Node(T data) : data(data), previous(nullptr) {}

template <typename T>
inline Node<T>::~Node()
{
    if (!this->previous)
    {
        delete this->previous;
    }
}

template <typename T>
inline Node<T>* Node<T>::getPrevious()
{
    return this->previous;
}

template <typename T>
inline void Node<T>::setPrevious(Node<T>* previous)
{
    this->previous = previous;
}

template <typename T>
inline T Node<T>::getData()
{
    return this->data;
}
#endif