#ifndef NO_H
#define NO_H

template <typename T>
class Node
{
private:
    T data;
    Node<T>* left;
    Node<T>* right;
    Node<T>* parent;

public:
    Node(T data, Node<T>* left, Node<T>* right);
    Node(T data, Node<T>* left, Node<T>* right, Node<T>* parent);
    Node(const Node<T>& no);
    virtual ~Node() = default;
    T getData();
    Node<T>* getLeft();
    Node<T>* getRight();
    Node<T>* getParent();
    void setLeft(Node<T>* left);
    void setRight(Node<T>* right);
    void setParent(Node<T>* parent);
};

template <typename T>
inline Node<T>::Node(T data, Node<T>* left, Node<T>* right) : data(data), left(left), right(right), parent(nullptr) {}

template <typename T>
inline Node<T>::Node(T data, Node<T>* left, Node<T>* right, Node<T>* parent) : Node(data, left, right)
{
    this->parent = parent;
}

template <typename T>
inline Node<T>::Node(const Node<T>& no) : data(no.data), left(no.left), right(no.right), parent(no.parent) {}

template <typename T>
inline T Node<T>::getData()
{
    return this->data;
}

template <typename T>
inline Node<T>* Node<T>::getLeft()
{
    return this->left;
}

template <typename T>
inline Node<T>* Node<T>::getRight()
{
    return this->right;
}

template <typename T>
inline void Node<T>::setLeft(Node<T>* left)
{
    this->left = left;
}

template <typename T>
inline void Node<T>::setRight(Node<T>* right)
{
    this->right = right;
}

template <typename T>
inline Node<T>* Node<T>::getParent()
{
    return this->parent;
}

template <typename T>
inline void Node<T>::setParent(Node<T>* parent)
{
    this->parent = parent;
}
#endif