#ifndef NODE_H
#define NODE_H

#include <string>

template <typename T>
class Node
{
private:
    Node<T>* left;
    Node<T>* right;
    Node<T>* parent;
    T data;
    std::string color;

public:
    Node(T data, Node<T>* parent, std::string color);
    Node(T data, Node<T>* left, Node<T>* right, Node<T>* parent, std::string color);
    Node(const Node<T>& Node);
    ~Node();
    std::string getColor() const;
    void setColor(std::string color);
    T getData();
    Node<T>* getLeft();
    void setLeft(Node<T>* left);
    Node<T>* getRight();
    void setRight(Node<T>* right);
    Node<T>* getParent();
    void setParent(Node<T>* parent);
};

template <typename T>
inline Node<T>::Node(T data, Node<T>* parent, std::string color)
    : data(data), parent(parent), color(color), left(nullptr),
    right(nullptr) {}

template <typename T>
inline Node<T>::Node(T data, Node<T>* left, Node<T>* right, Node<T>* parent,
    std::string color)
    : data(data), left(left), right(right), parent(parent),
    color(color) {}

template <typename T>
inline Node<T>::Node(const Node<T>& Node)
    : data(Node.data), left(Node.left), right(Node.right),
    parent(Node.parent), color(Node.color) {}

template <typename T>
inline Node<T>::~Node() {}

template <typename T>
inline std::string Node<T>::getColor() const { return this->color; }

template <typename T>
inline void Node<T>::setColor(std::string color) { this->color = color; }

template <typename T>
inline T Node<T>::getData() { return this->data; }

template <typename T>
inline Node<T>* Node<T>::getLeft() { return this->left; }

template <typename T>
inline void Node<T>::setLeft(Node<T>* left) { this->left = left; }

template <typename T>
inline Node<T>* Node<T>::getRight() { return this->right; }

template <typename T>
inline void Node<T>::setRight(Node<T>* right) { this->right = right; }

template <typename T>
inline Node<T>* Node<T>::getParent() { return this->parent; }

template <typename T>
inline void Node<T>::setParent(Node<T>* parent) { this->parent = parent; }
#endif