#ifndef NODE_H
#define NODE_H

template<typename T>
class Node {
public:
    Node();
    Node(T data);
    Node(T data, Node<T>* next);
    virtual ~Node() = default;
    Node(const Node<T>& node);
    T getData();
    void setData(T data);
    Node<T>* getNext();
    void setNext(Node<T>* next);
private:
    T data;
    Node<T>* next;
};

template<typename T>
inline Node<T>::Node() : next(nullptr) {}

template<typename T>
inline Node<T>::Node(T data) : next(nullptr), data(data) {}

template<typename T>
inline Node<T>::Node(T data, Node<T>* next) : data(data), next(next) {}

template<typename T>
inline Node<T>::Node(const Node<T>& node) : next(node.next), data(node.data) {
}

template<typename T>
inline T Node<T>::getData() {
    return this->data;
}

template<typename T>
inline void Node<T>::setData(T data) {
    this->data = data;
}

template<typename T>
inline Node<T>* Node<T>::getNext() {
    return this->next;
}

template<typename T>
inline void Node<T>::setNext(Node<T>* next) {
    this->next = next;
}
#endif