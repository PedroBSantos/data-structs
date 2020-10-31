#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {
private:
    int heightLeft;
    int heightRight;
    T data;
    Node<T>* left;
    Node<T>* right;
    Node<T>* parent;

public:
    Node(T data, Node<T>* parent);
    Node(T data, Node<T>* parent, Node<T>* left, Node<T>* right);
    Node(const Node<T>& node);
    virtual ~Node() = default;
    const int getBf() const;
    const int getHeightLeft() const;
    const int getHeightRight() const;
    T getData();
    Node<T>* getLeft();
    Node<T>* getRight();
    Node<T>* getParent();
    void setHeightLeft(int heightLeft);
    void setHeightRight(int heightRight);
    void setLeft(Node<T>* left);
    void setRight(Node<T>* right);
    void setParent(Node<T>* parent);
};

template <typename T>
inline Node<T>::Node(T data, Node<T>* parent) : data(data), parent(parent), left(nullptr), right(nullptr) {}

template <typename T>
inline Node<T>::Node(T data, Node<T>* parent, Node<T>* left, Node<T>* right) : data(data), parent(parent), left(left), right(right) {}

template <typename T>
inline Node<T>::Node(const Node<T>& node)
    : data(node.data), parent(node.parent), left(node.left), right(node.right), heightLeft(node.heightLeft), heightRight(node.heightRight) {}

template <typename T>
inline const int Node<T>::getBf() const {
    return heightLeft - heightRight;
}

template <typename T>
inline const int Node<T>::getHeightLeft() const {
    return heightLeft;
}

template <typename T>
inline const int Node<T>::getHeightRight() const {
    return heightRight;
}

template <typename T>
inline T Node<T>::getData() {
    return data;
}

template <typename T>
inline Node<T>* Node<T>::getLeft() {
    return left;
}

template <typename T>
inline Node<T>* Node<T>::getRight() {
    return right;
}

template <typename T>
inline Node<T>* Node<T>::getParent() {
    return parent;
}

template <typename T>
inline void Node<T>::setHeightLeft(int heightLeft) {
    this->heightLeft = heightLeft;
}

template <typename T>
inline void Node<T>::setHeightRight(int heightRight) {
    this->heightRight = heightRight;
}

template <typename T>
inline void Node<T>::setLeft(Node<T>* left) {
    this->left = left;
}

template <typename T>
inline void Node<T>::setRight(Node<T>* right) {
    this->right = right;
}

template <typename T>
inline void Node<T>::setParent(Node<T>* parent) {
    this->parent = parent;
}
#endif