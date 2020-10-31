#ifndef ARVORE_VP
#define ARVORE_VP

#include <sstream>
#include <string>

#include "node.h"

template <typename T>
class Tree
{
public:
    Tree();
    Tree(const Tree<T>& tree);
    ~Tree();
    void add(T data);
    bool remove(T data);
    bool contains(T data) const;
    bool empty() const;
    int count() const;
    std::string percOrdem() const;
    std::string percPreOrdem() const;
    std::string percPosOrdem() const;
    std::string percOrdemInv() const;
    T max() const;
    T min() const;
    T successor(T data) const;
    T predecessor(T data) const;

private:
    Node<T>* root;
    int size;
    void leftRotation(Node<T>* node);
    void rightRotation(Node<T>* node);
    void balancAdd(Node<T>* node);
    void balancRemove(Node<T>* node);
    void auxPercOrdem(std::stringstream& stringStream, Node<T>* root) const;
    void auxPercPreOrdem(std::stringstream& stringStream, Node<T>* root) const;
    void auxPercPosOrdem(std::stringstream& stringStream, Node<T>* root) const;
    void auxPercOrdemInv(std::stringstream& stringStream, Node<T>* root) const;
    void auxDelete(Node<T>* root);
    void changePlace(Node<T>* node1, Node<T>* node2);
    Node<T>* auxMax(Node<T>* root) const;
    Node<T>* auxMin(Node<T>* root) const;
    Node<T>* getNode(T data) const;
    Node<T>* auxGetNode(T data, Node<T>* root) const;
    Node<T>* auxAdd(T data, Node<T>* root);
    Node<T>* auxSuccessor(T data) const;
    Node<T>* auxPredecessor(T data) const;
};

template <typename T>
inline Tree<T>::Tree() : root(nullptr), size(0) {}

template <typename T>
inline Tree<T>::~Tree()
{
    this->auxDelete(this->root);
}

/*
      Desaloca os nós em um percuso em pós-ordem
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
inline Tree<T>::Tree(const Tree<T>& tree)
    : root(tree.root), size(tree.size) {}

/*
      Retorna se a árvore está vazia.
  */
template <typename T>
inline bool Tree<T>::empty() const
{
    return this->root == nullptr;
}

/*
      Retorna a quantidade de elementos(nós) que estão na árvore.
  */
template <typename T>
inline int Tree<T>::count() const
{
    return this->size;
}

/*
      Adiciona um data a árvore.
  */
template <typename T>
inline void Tree<T>::add(T data)
{
    if (this->root == nullptr)
    {
        this->root = new Node<T>(data, nullptr, nullptr, nullptr, "black");
    }
    else
    {
        Node<T>* parent = this->auxAdd(data, this->root);
        Node<T>* node = new Node<T>(data, parent, "red");
        if (parent->getData() > data)
        {
            parent->setLeft(node);
        }
        else
        {
            parent->setRight(node);
        }
        this->balancAdd(node);
        this->root->setColor("black");
    }
    this->size++;
}

template <typename T>
inline Node<T>* Tree<T>::auxAdd(T data, Node<T>* root)
{
    if (root->getData() > data)
    {
        return root->getLeft() == nullptr
            ? root
            : this->auxAdd(data, root->getLeft());
    }
    return root->getRight() == nullptr
        ? root
        : this->auxAdd(data, root->getRight());
}

/*
      Remove um data da árvore.
  */
template <typename T>
inline bool Tree<T>::remove(T data)
{
    Node<T>* node = this->getNode(data);
    if (node == nullptr)
    {
        return false;
    }
    if (node->getLeft() != nullptr ||
        node->getRight() != nullptr)
    {
        Node<T>* aux1 = node;
        std::string colorNode = node->getColor();
        if (node->getLeft() == nullptr)
        {
            aux1 = node->getRight();
            this->changePlace(node, node->getRight());
        }
        else if (node->getRight() == nullptr)
        {
            aux1 = node->getLeft();
            this->changePlace(node, node->getLeft());
        }
        else
        {
            Node<T>* successor = this->auxMin(node->getRight());
            colorNode = successor->getColor();
            aux1 = successor->getRight();
            if (successor->getParent() != node)
            {
                if (successor->getRight() != nullptr)
                {
                    this->changePlace(successor, successor->getRight());
                }
                else
                {
                    if (successor == successor->getParent()->getLeft())
                    {
                        successor->getParent()->setLeft(nullptr);
                    }
                    else
                    {
                        successor->getParent()->setRight(nullptr);
                    }
                }
                successor->setRight(node->getRight());
                successor->getRight()->setParent(successor);
            }
            this->changePlace(node, successor);
            successor->setLeft(node->getLeft());
            successor->getLeft()->setParent(successor);
            successor->setColor(node->getColor());
        }
        if (colorNode == "black" && aux1 != nullptr)
        {
            this->balancRemove(aux1);
        }
    }
    delete node;
    node = nullptr;
    this->size--;
    return true;
}

/*
      Coloca o no2 no lugar do no1.
  */
template <typename T>
inline void Tree<T>::changePlace(Node<T>* node1, Node<T>* node2)
{
    if (node1->getParent() == nullptr)
    {
        this->root = node2;
    }
    else if (node1->getParent()->getLeft() == node1)
    {
        node1->getParent()->setLeft(node2);
    }
    else
    {
        node1->getParent()->setRight(node2);
    }
    node2->setParent(node1->getParent());
}

/*
      Rotaciona o nó(X) passado no parâmetro da função para a left
      no sentido horário. O filho a right de X passa a ser o parent de X. A
      left do filho a right de X passa a ser a right de X.
  */
template <typename T>
inline void Tree<T>::leftRotation(Node<T>* node)
{
    Node<T>* right = node->getRight();
    if (right != nullptr)
    {
        node->setRight(right->getLeft());
        if (right->getLeft() != nullptr)
        {
            right->getLeft()->setParent(node);
        }
        right->setParent(node->getParent());
        if (node->getParent() == nullptr)
        {
            this->root = right;
        }
        else if (node == node->getParent()->getLeft())
        {
            node->getParent()->setLeft(right);
        }
        else
        {
            node->getParent()->setRight(right);
        }
        right->setLeft(node);
        node->setParent(right);
    }
}

/*
      Rotaciona o nó(X) passado no parâmetro da função para a right
      no sentido horário. O filho a left de X passa a ser o parent de X.
      A right do filho passa a ser X e a left de X passa a ser a right
      do filho de X. A right da left vira a left do nó a ser rotacionado
  */
template <typename T>
inline void Tree<T>::rightRotation(Node<T>* node)
{
    Node<T>* left = node->getLeft();
    if (left != nullptr)
    {
        node->setLeft(left->getRight());
        if (left->getRight() != nullptr)
        {
            left->getRight()->setParent(node);
        }
        left->setParent(node->getParent());
        if (node->getParent() == nullptr)
        {
            this->root = left;
        }
        else if (node == node->getParent()->getRight())
        {
            node->getParent()->setRight(left);
        }
        else
        {
            node->getParent()->setLeft(left);
        }
        left->setRight(node);
        node->setParent(left);
    }
}

/*
    Método utilizado para balancAdd a árvore após a inserção de um novo
    data na árvore. 3 casos: 1 - O parent e o tio do nó inserido é da color
    vermelha. 2 - O tio do nó inserido é black e o nó inserido é um filho à
    right. 3 - O tio do nó inserido é black e o nó inserido é um filho à
    left. O balanceamento é feito com base na posição do tio do nó inserido.
      Se o tio do nó inserido está a right e o nó inserido a left do seu
    parent(caso 2), primeiro fazemos uma rotação a right. Depois trocamos a color do
    parent do nó inserido para black e do seu avô para red e fazemos uma
    rotação a right(caso 3) em relação ao avô do nó inserido. Caso o tio do nó
    inserido esteja a left, basta fazer o que foi descrito acima apenas
    trocando right por left. O balanceamento no caso 1 não precisa realizar
    rotações na árvore, apenas trocar a color do tio e do parent do nó para black e a
    color do avô para red.
  */
template <typename T>
inline void Tree<T>::balancAdd(Node<T>* node)
{
    while (node != this->root && node->getParent()->getColor() == "red")
    {
        if (node->getParent() == node->getParent()->getParent()->getLeft())
        {
            Node<T>* tio = node->getParent()->getParent()->getRight();
            if (tio != nullptr && tio->getColor() == "red") // Trata o caso 1
            {
                tio->setColor("black");
                node->getParent()->setColor("black");
                node->getParent()->getParent()->setColor("red");
                node = node->getParent()->getParent();
            }
            else
            {
                if (node == node->getParent()->getRight()) // Trata o caso 2
                {
                    node = node->getParent();
                    this->leftRotation(node);
                }
                // Trata o caso 3
                node->getParent()->setColor("black");
                node->getParent()->getParent()->setColor("red");
                this->rightRotation(node->getParent()->getParent());
            }
        }
        else
        {
            Node<T>* tio = node->getParent()->getParent()->getLeft();
            if (tio != nullptr && tio->getColor() == "red") // Trata o caso 1
            {
                tio->setColor("black");
                node->getParent()->setColor("black");
                node->getParent()->getParent()->setColor("red");
                node = node->getParent()->getParent();
            }
            else
            {
                if (node == node->getParent()->getLeft()) // Trata o caso 2
                {
                    node = node->getParent();
                    this->rightRotation(node);
                }
                // Trata o caso 3
                node->getParent()->setColor("black");
                node->getParent()->getParent()->setColor("red");
                this->leftRotation(node->getParent()->getParent());
            }
        }
    }
}

/*
      O balanceamento após remoção possui o mesmo loop while do balanceamento após
    inserção com a mesma condição de parada a diferença é que trocamos por black
    a color do nó a ser balanceado e não estamos comparando mais a color do parent do nó
    a ser balanceado. O balanceamento é feito com base na posição do nó em
    relação ao seu parent. Temos 4 casos a analisar ao realizar o balanceamento após
    remove algum nó da árvore. O balanceamento irá ocorrer no nó que foi
    substituido pelo nó que foi removido. Esse nó a ser balanceado é passado no
    parâmetro da função, o balanceamento só irá ocorrer caso ele seja black. 1º
    caso: O irmão W do nó a ser balanceado é red. Se W é red, então
    ambos os seus filhos são blacks. Alteramos a color de W para black e a color de
    seu parent para red e fazemos uma rotação a left sobre o parent do nó a
    ser balanceado. A resolução deste caso pode levar aos casos 2, 3 e 4. O loop
    prossegue com W = nó a right de seu parent. 2º caso: Os filhos de W são
    blacks. Basta alterar a color de W para red. O loop prossegue com o nó a
    ser balanceado = parent do nó a ser balanceado. 3º caso: O filho a right de W
    é black e o filho a left é red. Devemos trocar as cores de W e seu
    filho a left, ou seja, W passa a ser da color vermelha e o seu filho a
    left passa a ser da color preta. Por fim realizar uma rotação a right
    sobre W. O loop prossegue com W = nó a right de seu parent. 4º caso: o filho a
    right de W é red. A color de W passa a ser a color de seu parent. A color do
    parent de W e do filho a right de W passa a ser preta. Por fim, realizar uma
    rotação a left sobre o parent de W. O loop prossegue com o nó a ser
    balanceado = root da árvore. Esses casos foram descritos para caso o irmão W
    do nó a ser balanceado esteja a sua right. Caso o irmão W do nó a ser
    balanceado esteja a sua left, basta fazer os casos acima com left e
    right trocadas.
  */
template <typename T>
inline void Tree<T>::balancRemove(Node<T>* node)
{
    Node<T>* aux;
    while (node != this->root && node->getColor() == "black")
    {
        if (node == node->getParent()->getLeft())
        {
            aux = node->getParent()->getRight();
            if (aux->getColor() == "red")
            {
                aux->setColor("black");
                aux->getParent()->setColor("red");
                this->leftRotation(aux->getParent());
                aux = node->getParent()->getRight();
            }
            if (aux->getLeft()->getColor() == "black" &&
                aux->getRight()->getColor() == "black")
            {
                aux->setColor("red");
                node = node->getParent();
            }
            else
            {
                if (aux->getRight()->getColor() == "black")
                {
                    aux->getLeft()->setColor("black");
                    aux->setColor("red");
                    this->rightRotation(aux);
                    aux = node->getParent()->getRight();
                }
                aux->setColor(node->getParent()->getColor());
                node->getParent()->setColor("black");
                aux->getRight()->setColor("black");
                this->leftRotation(node->getParent());
                node = this->root;
            }
        }
        else
        {
            aux = node->getParent()->getLeft();
            if (aux->getColor() == "red")
            {
                aux->setColor("black");
                aux->getParent()->setColor("red");
                this->rightRotation(aux->getParent());
                aux = node->getParent()->getLeft();
            }
            if (aux->getLeft()->getColor() == "black" &&
                aux->getRight()->getColor() == "black")
            {
                aux->setColor("red");
                node = node->getParent();
            }
            else
            {
                if (aux->getLeft()->getColor() == "black")
                {
                    aux->getRight()->setColor("black");
                    aux->setColor("red");
                    this->leftRotation(aux);
                    aux = node->getParent()->getLeft();
                }
                aux->setColor(node->getParent()->getColor());
                node->getParent()->setColor("black");
                aux->getLeft()->setColor("black");
                this->rightRotation(node->getParent());
                node = this->root;
            }
        }
    }
    node->setColor("black");
}

/*
      Retorna o maior data da árvore.
  */
template <typename T>
inline T Tree<T>::max() const
{
    if (this->empty())
    {
        return T();
    }
    Node<T>* max = this->auxMax(this->root);
    return max == nullptr ? T() : max->getData();
}

template <typename T>
inline Node<T>* Tree<T>::auxMax(Node<T>* root) const
{
    if (root->getRight() == nullptr)
    {
        return root;
    }
    return this->auxMax(root->getRight());
}

/*
      Retorna o menor data da árvore
  */
template <typename T>
inline T Tree<T>::min() const
{
    if (this->empty())
    {
        return T();
    }
    Node<T>* min = this->auxMin(this->root);
    return min == nullptr ? T() : min->getData();
}

template <typename T>
inline Node<T>* Tree<T>::auxMin(Node<T>* root) const
{
    if (root->getLeft() == nullptr)
    {
        return root;
    }
    return this->auxMin(root->getLeft());
}

template <typename T>
inline Node<T>* Tree<T>::getNode(T data) const
{
    Node<T>* node = this->auxGetNode(data, this->root);
    return node;
}

template <typename T>
inline Node<T>* Tree<T>::auxGetNode(T data, Node<T>* root) const
{
    if (root == nullptr)
    {
        return nullptr;
    }
    if (root->getData() == data)
    {
        return root;
    }
    if (root->getData() > data)
    {
        return this->auxGetNode(data, root->getLeft());
    }
    return this->auxGetNode(data, root->getRight());
}

/*
      Verifica se um data existe ou não na árvore.
  */
template <typename T>
inline bool Tree<T>::contains(T data) const
{
    return this->getNode(data) == nullptr ? false : true;
}

/*
      Retorna o successor de um data da árvore.
  */
template <typename T>
inline T Tree<T>::successor(T data) const
{
    Node<T>* successor = this->auxSuccessor(data);
    return successor == nullptr ? T() : successor->getData();
}

template <typename T>
inline Node<T>* Tree<T>::auxSuccessor(T data) const
{
    Node<T>* node = this->getNode(data);
    if (node == nullptr)
    {
        return nullptr;
    }
    Node<T>* right = node->getRight();
    if (right != nullptr)
    {
        Node<T>* successor = this->auxMin(right);
        return successor;
    }
    Node<T>* parent = node->getParent();
    while (parent != nullptr && node == parent->getRight())
    {
        node = parent;
        parent = parent->getParent();
    }
    return parent;
}

/*
      Retorna o antecessor de um data na árvore.
  */
template <typename T>
inline T Tree<T>::predecessor(T data) const
{
    Node<T>* predecessor = this->auxPredecessor(data);
    return predecessor == nullptr ? T() : predecessor->getData();
}

template <typename T>
inline Node<T>* Tree<T>::auxPredecessor(T data) const
{
    Node<T>* node = this->getNode(data);
    if (node == nullptr)
    {
        return nullptr;
    }
    Node<T>* left = node->getLeft();
    if (left != nullptr)
    {
        Node<T>* predecessor = this->auxMax(left);
        return predecessor;
    }
    Node<T>* parent = node->getParent();
    while (parent != nullptr && node == parent->getLeft())
    {
        node = parent;
        parent = parent->getParent();
    }
    return parent;
}

/*
      Realiza um percurso in-order.
  */
template <typename T>
inline std::string Tree<T>::percOrdem() const
{
    std::stringstream stringStream;
    this->auxPercOrdem(stringStream, this->root);
    return stringStream.str();
}

template <typename T>
inline void Tree<T>::auxPercOrdem(std::stringstream& stringStream,
    Node<T>* root) const
{
    if (root != nullptr)
    {
        this->auxPercOrdem(stringStream, root->getLeft());
        stringStream << root->getData() << "\t";
        this->auxPercOrdem(stringStream, root->getRight());
    }
}

/*
      Realiza um percurso pre-order.
  */
template <typename T>
inline std::string Tree<T>::percPreOrdem() const
{
    std::stringstream stringStream;
    this->auxPercPreOrdem(stringStream, this->root);
    return stringStream.str();
}

template <typename T>
inline void Tree<T>::auxPercPreOrdem(std::stringstream& stringStream,
    Node<T>* root) const
{
    if (root != nullptr)
    {
        stringStream << root->getData() << "\t";
        this->auxPercPreOrdem(stringStream, root->getLeft());
        this->auxPercPreOrdem(stringStream, root->getRight());
    }
}

/*
      Realiza um percurso post-order.
  */
template <typename T>
inline std::string Tree<T>::percPosOrdem() const
{
    std::stringstream stringStream;
    this->auxPercPosOrdem(stringStream, this->root);
    return stringStream.str();
}

template <typename T>
inline void Tree<T>::auxPercPosOrdem(std::stringstream& stringStream,
    Node<T>* root) const
{
    if (root != nullptr)
    {
        this->auxPercPosOrdem(stringStream, root->getRight());
        this->auxPercPosOrdem(stringStream, root->getLeft());
        stringStream << root->getData() << "\t";
    }
}

/*
      Realiza um percurso post-order-inv.
  */
template <typename T>
inline std::string Tree<T>::percOrdemInv() const
{
    std::stringstream stringStream;
    this->auxPercOrdemInv(stringStream, this->root);
    return stringStream.str();
}

template <typename T>
inline void Tree<T>::auxPercOrdemInv(std::stringstream& stringStream,
    Node<T>* root) const
{
    if (root != nullptr)
    {
        this->auxPercOrdemInv(stringStream, root->getRight());
        stringStream << root->getData() << "\t";
        this->auxPercOrdemInv(stringStream, root->getLeft());
    }
}
#endif