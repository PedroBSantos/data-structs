#ifndef ARVORE_BINARIA_H
#define ARVORE_BINARIA_H

#include "node.h"
#include <sstream>
#include <string>

template <typename T>
class Tree
{
private:
    Node<T>* root;
    int size;
    void auxAdd(Node<T>* root, T element);
    void auxInOrder(Node<T>* root, std::stringstream& stringStream);
    void auxPreOrder(Node<T>* root, std::stringstream& stringStream);
    void auxPostOrder(Node<T>* root, std::stringstream& stringStream);
    void auxDelete(Node<T>* root);
    void changePlace(Node<T>* node1, Node<T>* node2);
    Node<T>* auxContains(Node<T>* root, T element);
    Node<T>* auxMax(Node<T>* root);
    Node<T>* auxMin(Node<T>* root);

public:
    Tree();
    Tree(const Tree<T>& tree);
    ~Tree();
    int count();
    bool contains(T element);
    bool empty();
    void add(T element);
    void remove(T element);
    std::string inOrder();
    std::string preOrder();
    std::string postOrder();
    T max();
    T min();
    T successor(T element);
    T predecessor(T element);
};

template <typename T>
inline Tree<T>::Tree() : root(nullptr), size(0) {}

template <typename T>
inline Tree<T>::Tree(const Tree<T>& tree)
    : root(tree.root), size(tree.size) {}

template <typename T>
inline Tree<T>::~Tree()
{
    this->auxDelete(this->root);
    this->size = 0;
}

/*
    Remove os elementos em um percurso pós-ordem.
*/
template <typename T>
inline void Tree<T>::auxDelete(Node<T>* root)
{
    if (root != nullptr)
    {
        this->auxDelete(root->getRight());
        this->auxDelete(root->getLeft());
        delete root;
        root = nullptr;
    }
}

template <typename T>
inline int Tree<T>::count()
{
    return this->size;
}

template <typename T>
inline void Tree<T>::add(T element)
{
    if (this->root == nullptr)
    {
        this->root = new Node<T>(element, nullptr, nullptr);
    }
    else
    {
        this->auxAdd(this->root, element);
    }
    this->size++;
}

template <typename T>
inline void Tree<T>::auxAdd(Node<T>* root, T element)
{
    if (element < root->getData())
    {
        if (root->getLeft() != nullptr)
        {
            this->auxAdd(root->getLeft(), element);
        }
        else
        {
            Node<T>* left = new Node<T>(element, nullptr, nullptr, root);
            root->setLeft(left);
        }
    }
    else if (element > root->getData())
    {
        if (root->getRight() != nullptr)
        {
            this->auxAdd(root->getRight(), element);
        }
        else
        {
            Node<T>* right = new Node<T>(element, nullptr, nullptr, root);
            root->setRight(right);
        }
    }
}

/*
    Printa primeiro os elementos que são menores que a root(estão a left da root) depois printa
    o element da root e depois printa os elementos que são maiores que a root(estão a right da root).
*/
template <typename T>
inline std::string Tree<T>::inOrder()
{
    std::stringstream stringStream;
    this->auxInOrder(this->root, stringStream);
    return stringStream.str();
}

template <typename T>
inline void Tree<T>::auxInOrder(Node<T>* root, std::stringstream& stringStream)
{
    if (root != nullptr)
    {
        this->auxInOrder(root->getLeft(), stringStream);
        stringStream << root->getData();
        stringStream << "\t";
        this->auxInOrder(root->getRight(), stringStream);
    }
}

/*
    Printa a root depois todos os elementos que estão a sua left(elementos que são menores que a root)
    e depois todos os elementos que estão a sua right(elementos que são maiores que a root).
*/
template <typename T>
inline std::string Tree<T>::preOrder()
{
    std::stringstream stringStream;
    this->auxPreOrder(this->root, stringStream);
    return stringStream.str();
}

template <typename T>
inline void Tree<T>::auxPreOrder(Node<T>* root, std::stringstream& stringStream)
{
    if (root != nullptr)
    {
        stringStream << root->getData();
        stringStream << "\t";
        this->auxPreOrder(root->getLeft(), stringStream);
        this->auxPreOrder(root->getRight(), stringStream);
    }
}

/*
    Printa todos os elementos que estão a right da root depois todos os elementos que estão a left da root para no final
    printar o element que está na root.
*/
template <typename T>
inline std::string Tree<T>::postOrder()
{
    std::stringstream stringStream;
    this->auxPostOrder(this->root, stringStream);
    return stringStream.str();
}

template <typename T>
inline void Tree<T>::auxPostOrder(Node<T>* root, std::stringstream& stringStream)
{
    if (root != nullptr)
    {
        this->auxPostOrder(root->getRight(), stringStream);
        this->auxPostOrder(root->getLeft(), stringStream);
        stringStream << root->getData();
        stringStream << "\t";
    }
}

template <typename T>
inline bool Tree<T>::contains(T element)
{
    if (this->root == nullptr)
    {
        return false;
    }
    return this->auxContains(this->root, element) == nullptr ? false : true;
}

template <typename T>
inline Node<T>* Tree<T>::auxContains(Node<T>* root, T element)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    if (root->getData() == element)
    {
        return root;
    }
    if (element < root->getData())
    {
        return this->auxContains(root->getLeft(), element);
    }
    return this->auxContains(root->getRight(), element);
}

template <typename T>
inline T Tree<T>::max()
{
    return this->root == nullptr ? T() : this->auxMax(this->root)->getData();
}

template <typename T>
inline Node<T>* Tree<T>::auxMax(Node<T>* root)
{
    return root->getRight() == nullptr ? root : this->auxMax(root->getRight());
}

template <typename T>
inline T Tree<T>::min()
{
    return this->root == nullptr ? T() : this->auxMin(this->root)->getData();
}

template <typename T>
inline Node<T>* Tree<T>::auxMin(Node<T>* root)
{
    return root->getLeft() == nullptr ? root : this->auxMin(root->getLeft());
}

template <typename T>
inline bool Tree<T>::empty()
{
    return this->root == nullptr;
}

template <typename T>
inline void Tree<T>::remove(T element)
{
    Node<T>* node = this->auxContains(this->root, element);
    if (node != nullptr)
    {
        if (node->getLeft() != nullptr || node->getRight() != nullptr)
        {
            if (node->getLeft() == nullptr)
            {
                this->changePlace(node, node->getRight());
            }
            else if (node->getRight() == nullptr)
            {
                this->changePlace(node, node->getLeft());
            }
            else
            {
                Node<T>* successor = this->auxMin(node->getRight());
                if (successor->getParent() != node)
                {
                    this->changePlace(successor, successor->getRight());
                    successor->setRight(node->getRight());
                    successor->getRight()->setParent(successor);
                }
                this->changePlace(node, successor);
                successor->setLeft(node->getLeft());
                successor->getLeft()->setParent(successor);
            }
        }
        delete node;
        this->size--;
    }
}

template <typename T>
inline void Tree<T>::changePlace(Node<T>* node1, Node<T>* node2)
{
    if (node1->getParent() == nullptr)
    {
        this->root = node2;
    }
    else if (node1 == node1->getParent()->getLeft())
    {
        node1->getParent()->setLeft(node2);
    }
    else
    {
        node1->getParent()->setRight(node2);
    }
    if (node2 != nullptr)
    {
        node2->setParent(node1->getParent());
    }
}

/*
    Retorna o element successor ao element passado no parâmetro da função.
*/
template <typename T>
inline T Tree<T>::successor(T element)
{
    Node<T>* node = this->auxContains(this->root, element);
    if (node != nullptr)
    {
        if (node->getRight() != nullptr)
        {
            return this->auxMin(node->getRight())->getData();
        }
        Node<T>* parent = node->getParent();
        while (parent != nullptr && node == parent->getRight())
        {
            node = parent;
            parent = parent->getParent();
        }
        return parent->getData();
    }
    return T();
}

/*
    Retorna o element anterior ao element passado no parâmetro da função.
*/
template <typename T>
inline T Tree<T>::predecessor(T element)
{
    Node<T>* node = this->auxContains(this->root, element);
    if (node != nullptr)
    {
        if (node->getLeft() != nullptr)
        {
            return this->auxMax(node->getLeft())->getData();
        }
        Node<T>* parent = node->getParent();
        while (parent != nullptr && node == parent->getLeft())
        {
            node = parent;
            parent = parent->getParent();
        }
        return parent->getData();
    }
    return T();
}
#endif