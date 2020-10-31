#ifndef No_H
#define No_H

template <typename T>
class Node
{
public:
    Node(T data);
    Node(T data, Node<T>* next, Node<T>* previous);
    virtual ~Node();
    Node(const Node<T>& node);
    T getData();
    void setData(T data);
    Node<T>* getNext();
    void setNext(Node<T>* next);
    Node<T>* getPrevious();
    void setPrevious(Node<T>* previous);

private:
    Node<T>* next;
    Node<T>* previous;
    T data;
};

template <typename T>
inline Node<T>::Node(T data) : data(data), next(nullptr), previous(nullptr) {}

template <typename T>
inline Node<T>::Node(T data, Node<T>* next, Node<T>* previous) : data(data), next(next), previous(previous) {}

template <typename T>
inline Node<T>::~Node()
{
    if (!this->next)
    {
        delete this->next;
    }
    if (!this->previous)
    {
        delete this->previous;
    }
}

template <typename T>
inline Node<T>::Node(const Node<T>& node) : data(node.data), previous(node.previous), next(node.next) {}

template <typename T>
inline T Node<T>::getData()
{
    return this->data;
}

template <typename T>
inline void Node<T>::setData(T data)
{
    this->data = data;
}

template <typename T>
inline Node<T>* Node<T>::getNext()
{
    return this->next;
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
inline void Node<T>::setNext(Node<T>* next)
{
    this->next = next;
}
#endif