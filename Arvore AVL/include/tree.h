#ifndef TREE_H
#define TREE_H

#include "node.h"
#include <sstream>

template <typename T>
class Tree
{
private:
    int size;
    Node<T>* root;
    void auxDelete(Node<T>* root);
    void auxAdd(T element, Node<T>* root);
    void auxRemove(T element, Node<T>* root);
    void leftRotation(Node<T>* node);
    void rightRotation(Node<T>* node);
    void inOrderAux(std::stringstream& stringstream, Node<T>* root);
    void preOrderAux(std::stringstream& stringstream, Node<T>* root);
    void postOrderAux(std::stringstream& stringstream, Node<T>* root);
    void balancTreeRemove(Node<T>* node);
    int balancFactor(Node<T>* node);
    Node<T>* auxMin(Node<T>* root);
    Node<T>* auxMax(Node<T>* root);
    Node<T>* auxContains(T element, Node<T>* root);

public:
    Tree();
    Tree(const Tree<T>& tree);
    virtual ~Tree();
    void add(T element);
    void remove(T element);
    bool empty();
    bool contains(T element);
    int count();
    T successor(T element);
    T predecessor(T element);
    T max();
    T min();
    std::string inOrder();
    std::string preOrder();
    std::string postOrder();
};

template <typename T>
inline Tree<T>::Tree() : root(nullptr), size(0) {}

template <typename T>
inline Tree<T>::Tree(const Tree<T>& tree) : root(tree.root), size(tree.size) {}

template <typename T>
inline int Tree<T>::count() {
    return this->size;
}

template <typename T>
inline bool Tree<T>::empty() {
    return this->size == 0;
}

template <typename T>
inline Tree<T>::~Tree() {
    this->auxDelete(root);
    this->size = 0;
}

template <typename T>
inline void Tree<T>::auxDelete(Node<T>* root) {
    if (root != nullptr) {
        this->auxDelete(root->getLeft());
        this->auxDelete(root->getRight());
        delete root;
    }
}

template <typename T>
inline void Tree<T>::add(T element) {
    if (this->root == nullptr) {
        this->root = new Node<T>(element, nullptr);
        this->size++;
    }
    else {
        this->auxAdd(element, this->root);
    }
}

template <typename T>
inline void Tree<T>::auxAdd(T element, Node<T>* root) {
    if (element != root->getData()) {
        if (element > root->getData()) {
            if (root->getRight() == nullptr) {
                Node<T>* right = new Node<T>(element, root);
                root->setRight(right);
                this->size++;
            }
            else {
                this->auxAdd(element, root->getRight());
                this->balancFactor(root);
                if (root->getBf() == -2) {
                    if (element > root->getRight()->getData()) {
                        leftRotation(root);
                    }
                    else {
                        rightRotation(root->getRight());
                        leftRotation(root);
                    }
                }
            }
        }
        else {
            if (root->getLeft() == nullptr) {
                Node<T>* left = new Node<T>(element, root);
                root->setLeft(left);
                this->size++;
            }
            else {
                this->auxAdd(element, root->getLeft());
                this->balancFactor(root);
                if (root->getBf() == 2) {
                    if (element < root->getLeft()->getData()) {
                        rightRotation(root);
                    }
                    else {
                        leftRotation(root->getLeft());
                        rightRotation(root);
                    }
                }
            }
        }
    }
}

template <typename T>
inline void Tree<T>::remove(T element) {
    this->auxRemove(element, this->root);
}

template <typename T>
inline void Tree<T>::auxRemove(T element, Node<T>* root) {
    if (root != nullptr) {
        if (root->getData() == element) {
            Node<T>* unbalanced = nullptr;
            if (root->getLeft() == nullptr && root->getRight() == nullptr) {
                if (root == this->root) {
                    this->root = nullptr;
                }
                else if (root->getParent()->getLeft() == root) {
                    root->getParent()->setLeft(nullptr);
                }
                else {
                    root->getParent()->setRight(nullptr);
                }
                unbalanced = root->getParent();
            }
            else if (root->getLeft() != nullptr && root->getRight() == nullptr) {
                root->getLeft()->setParent(root->getParent());
                if (root == this->root) {
                    this->root = root->getLeft();
                }
                else if (root->getParent()->getLeft() == root) {
                    root->getParent()->setLeft(root->getLeft());
                }
                else {
                    root->getParent()->setRight(root->getLeft());
                }
                unbalanced = root->getLeft();
            }
            else if (root->getLeft() == nullptr && root->getRight() != nullptr) {
                root->getRight()->setParent(root->getParent());
                if (root == this->root) {
                    this->root = root->getRight();
                }
                else if (root->getParent()->getLeft() == root) {
                    root->getParent()->setLeft(root->getRight());
                }
                else {
                    root->getParent()->setRight(root->getRight());
                }
                unbalanced = root->getRight();
            }
            else {
                Node<T>* successor = this->auxMin(root->getRight());
                unbalanced = successor;
                if (successor->getParent() != root) {
                    if (successor->getParent()->getLeft() == successor) {
                        successor->getParent()->setLeft(successor->getRight());
                    }
                    else {
                        successor->getParent()->setRight(successor->getRight());
                    }
                    if (successor->getRight() != nullptr) {
                        successor->getRight()->setParent(successor->getParent());
                    }
                    successor->setRight(root->getRight());
                    root->getRight()->setParent(successor);
                    unbalanced = successor->getParent();
                }
                successor->setParent(root->getParent());
                successor->setLeft(root->getLeft());
                root->getLeft()->setParent(successor);
                if (root == this->root) {
                    this->root = successor;
                }
                else {
                    if (root->getParent()->getLeft() == root) {
                        root->getParent()->setLeft(successor);
                    }
                    else {
                        root->getParent()->setRight(successor);
                    }
                }
            }
            delete root;
            this->balancTreeRemove(unbalanced);
        }
        else if (element > root->getData()) {
            this->auxRemove(element, root->getRight());
            // this->balancFactor(root);
            // if (root->getBf() == -2) {
            //     if (element > root->getData()) {
            //         leftRotation(root);
            //     }
            //     else {
            //         rightRotation(root->getRight());
            //         leftRotation(root);
            //     }
            // }
        }
        else {
            this->auxRemove(element, root->getLeft());
            // this->balancFactor(root);
            // if (root->getBf() == 2) {
            //     if (element < root->getData()) {
            //         rightRotation(root);
            //     }
            //     else {
            //         leftRotation(root->getLeft());
            //         rightRotation(root);
            //     }
            // }
        }
    }
}

template <typename T>
inline int Tree<T>::balancFactor(Node<T>* node) {
    int heightLeft = 0;
    int heightRight = 0;
    if (node != nullptr) {
        if (node->getLeft() != nullptr) {
            heightLeft = 1 + balancFactor(node->getLeft());
        }
        if (node->getRight() != nullptr) {
            heightRight = 1 + balancFactor(node->getRight());
        }
        // node->setBf(heightLeft - heightRight);
        // node->setHeight(heightLeft > heightRight ? heightLeft : heightRight);
        node->setHeightLeft(heightLeft);
        node->setHeightRight(heightRight);
    }
    return heightLeft > heightRight ? heightLeft : heightRight;
}

template <typename T>
inline void Tree<T>::leftRotation(Node<T>* node) {
    if (node != nullptr)
    {
        Node<T>* right = node->getRight();
        if (right != nullptr)
        {
            Node<T>* left = right->getLeft();
            Node<T>* parent = node->getParent();
            if (parent == nullptr)
            {
                right->setParent(nullptr);
                this->root = right;
            }
            else
            {
                if (node == parent->getRight())
                {
                    parent->setRight(right);
                }
                else
                {
                    parent->setLeft(right);
                }
            }
            right->setParent(parent);
            right->setLeft(node);
            node->setParent(right);
            node->setRight(left);
            if (left != nullptr)
            {
                left->setParent(node);
            }
        }
    }
}

template <typename T>
inline void Tree<T>::rightRotation(Node<T>* node) {
    if (node != nullptr) {
        Node<T>* left = node->getLeft();
        if (left != nullptr) {
            Node<T>* parent = node->getParent();
            Node<T>* right = left->getRight();
            if (parent == nullptr) {
                left->setParent(nullptr);
                this->root = left;
            }
            else {
                if (node == parent->getRight()) {
                    parent->setRight(left);
                }
                else {
                    parent->setLeft(left);
                }
            }
            left->setParent(parent);
            left->setRight(node);
            node->setParent(left);
            node->setLeft(right);
            if (right != nullptr) {
                right->setParent(node);
            }
        }
    }
}

template <typename T>
inline T Tree<T>::min() {
    if (this->root == nullptr) {
        return T();
    }
    return this->auxMin(this->root)->getData();
}

template <typename T>
inline Node<T>* Tree<T>::auxMin(Node<T>* root) {
    return root->getLeft() == nullptr ? root : this->auxMin(root->getLeft());
}

template <typename T>
inline T Tree<T>::max() {
    if (this->root == nullptr) {
        return T();
    }
    return this->auxMax(this->root)->getData();
}

template <typename T>
inline Node<T>* Tree<T>::auxMax(Node<T>* root) {
    return root->getRight() == nullptr ? root : this->auxMax(root->getRight());
}

template <typename T>
inline bool Tree<T>::contains(T element) {
    Node<T>* node = this->auxContains(element, this->root);
    return node == nullptr ? false : true;
}

template <typename T>
inline Node<T>* Tree<T>::auxContains(T element, Node<T>* root) {
    if (root != nullptr) {
        if (root->getData() == element) {
            return root;
        }
        return element > root->getData() ? auxContains(element, root->getRight()) : auxContains(element, root->getLeft());
    }
    return nullptr;
}

template <typename T>
inline std::string Tree<T>::inOrder() {
    std::stringstream stringstream;
    this->inOrderAux(stringstream, this->root);
    return stringstream.str();
}

template <typename T>
inline void Tree<T>::inOrderAux(std::stringstream& stringstream, Node<T>* root) {
    if (root != nullptr) {
        this->inOrderAux(stringstream, root->getLeft());
        stringstream << root->getData() << "\t";
        this->inOrderAux(stringstream, root->getRight());
    }
}

template <typename T>
inline std::string Tree<T>::preOrder() {
    std::stringstream stringstream;
    this->preOrderAux(stringstream, this->root);
    return stringstream.str();
}

template <typename T>
inline void Tree<T>::preOrderAux(std::stringstream& stringstream, Node<T>* root) {
    if (root != nullptr) {
        stringstream << root->getData() << "\t";
        this->preOrderAux(stringstream, root->getLeft());
        this->preOrderAux(stringstream, root->getRight());
    }
}

template <typename T>
inline std::string Tree<T>::postOrder() {
    std::stringstream stringstream;
    this->postOrderAux(stringstream, this->root);
    return stringstream.str();
}

template <typename T>
inline void Tree<T>::postOrderAux(std::stringstream& stringstream, Node<T>* root) {
    if (root != nullptr) {
        this->postOrderAux(stringstream, root->getLeft());
        this->postOrderAux(stringstream, root->getRight());
        stringstream << root->getData() << "\t";
    }
}

template <typename T>
inline T Tree<T>::successor(T element) {
    Node<T>* node = this->auxContains(element, this->root);
    if (node == nullptr) {
        return T();
    }
    if (node->getRight() != nullptr) {
        return this->auxMin(node->getRight())->getData();
    }
    Node<T>* parent = node->getParent();
    while (parent != nullptr && node == parent->getRight()) {
        node = parent;
        parent = parent->getParent();
    }
    return parent->getData();
}

template <typename T>
inline T Tree<T>::predecessor(T element) {
    Node<T>* node = this->auxContains(element, this->root);
    if (node == nullptr) {
        return T();
    }
    if (node->getLeft() != nullptr) {
        return this->auxMax(node->getLeft())->getData();
    }
    Node<T>* parent = node->getParent();
    while (parent != nullptr && node == parent->getLeft()) {
        node = parent;
        parent = parent->getParent();
    }
    return parent->getData();
}

template <typename T>
inline void Tree<T>::balancTreeRemove(Node<T>* node) {
    if (node != nullptr) {
        this->balancFactor(node);
        Node<T>* left = node->getLeft();
        Node<T>* right = node->getRight();
        if (node->getBf() == 2) {
            if (left != nullptr && left->getBf() == 1) {
                rightRotation(node);
            }
            else if (right != nullptr && right->getBf() == -1) {
                leftRotation(right);
                rightRotation(node);
            }
            else if (node->getHeightLeft() > node->getHeightRight()) {
                rightRotation(node);
            }
        }
        else if (node->getBf() == -2) {
            if (right != nullptr && right->getBf() == -1) {
                leftRotation(node);
            }
            else if (left != nullptr && left->getBf() == 1) {
                rightRotation(left);
                leftRotation(node);
            }
            else if (node->getHeightLeft() < node->getHeightRight()) {
                leftRotation(node);
            }
        }
        this->balancTreeRemove(node->getParent());
    }
}
#endif