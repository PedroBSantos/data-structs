#ifndef ARVORE_BINARIA_H
#define ARVORE_BINARIA_H

#include "no.h"
#include <sstream>
#include <string>

template <typename T>
class ArvoreBinaria
{
private:
    No<T> *raiz;
    int qtdElementos;
    bool auxContains(No<T> *raiz, T elemento);
    void auxAdicionar(No<T> *raiz, T elemento);
    void auxInOrder(No<T> *raiz, std::stringstream &stringStream);
    void auxPreOrder(No<T> *raiz, std::stringstream &stringStream);
    void auxPostOrder(No<T> *raiz, std::stringstream &stringStream);
    void auxInOrderInv(No<T> *raiz, std::stringstream &stringStream);
    void auxDelete(No<T> *raiz);
    void transplante(No<T> *no1, No<T> *no2);
    No<T> *auxMax(No<T> *raiz);
    No<T> *auxMin(No<T> *raiz);
    No<T> *auxMinNo(No<T> *raiz);
    No<T> *getNo(T elemento);
    No<T> *auxGetNo(No<T> *raiz, T elemento);
    No<T> *getNoSucessor(No<T> *raiz);

public:
    ArvoreBinaria();
    ArvoreBinaria(const ArvoreBinaria<T> &arvoreBinaria);
    ~ArvoreBinaria();
    int size();
    bool contains(T elemento);
    bool isEmpty();
    void adicionar(T elemento);
    void remover(T elemento);
    std::string inOrder();
    std::string preOrder();
    std::string postOrder();
    std::string inOrderInv();
    T max();
    T min();
    T sucessor(T elemento);
    T predecessor(T elemento);
};

template <typename T>
inline ArvoreBinaria<T>::ArvoreBinaria() : raiz(nullptr), qtdElementos(0) {}

template <typename T>
inline ArvoreBinaria<T>::ArvoreBinaria(const ArvoreBinaria<T> &arvoreBinaria)
    : raiz(arvoreBinaria.raiz), qtdElementos(arvoreBinaria.qtdElementos) {}

template <typename T>
inline ArvoreBinaria<T>::~ArvoreBinaria()
{
    this->auxDelete(this->raiz);
    this->qtdElementos = 0;
}

/*
    Remove os elementos em um percurso pós-ordem.
*/
template <typename T>
inline void ArvoreBinaria<T>::auxDelete(No<T> *raiz)
{
    if (raiz != nullptr)
    {
        this->auxDelete(raiz->getDireita());
        this->auxDelete(raiz->getEsquerda());
        delete raiz;
        raiz = nullptr;
    }
}

template <typename T>
inline int ArvoreBinaria<T>::size()
{
    return this->qtdElementos;
}

template <typename T>
inline void ArvoreBinaria<T>::adicionar(T elemento)
{
    if (this->raiz == nullptr)
    {
        this->raiz = new No<T>(elemento, nullptr, nullptr);
    }
    else
    {
        this->auxAdicionar(this->raiz, elemento);
    }
    this->qtdElementos++;
}

template <typename T>
inline void ArvoreBinaria<T>::auxAdicionar(No<T> *raiz, T elemento)
{
    if (elemento < raiz->getElemento())
    {
        if (raiz->getEsquerda() != nullptr)
        {
            this->auxAdicionar(raiz->getEsquerda(), elemento);
        }
        else
        {
            No<T> *esquerda = new No<T>(elemento, nullptr, nullptr, raiz);
            raiz->setEsquerda(esquerda);
        }
    }
    else if (elemento > raiz->getElemento())
    {
        if (raiz->getDireita() != nullptr)
        {
            this->auxAdicionar(raiz->getDireita(), elemento);
        }
        else
        {
            No<T> *direita = new No<T>(elemento, nullptr, nullptr, raiz);
            raiz->setDireita(direita);
        }
    }
}

/*
    Printa primeiro os elementos que são menores que a raiz(estão a esquerda da raiz) depois printa
    o elemento da raiz e depois printa os elementos que são maiores que a raiz(estão a direita da raiz).
*/
template <typename T>
inline std::string ArvoreBinaria<T>::inOrder()
{
    std::stringstream stringStream;
    this->auxInOrder(this->raiz, stringStream);
    return stringStream.str();
}

template <typename T>
inline void ArvoreBinaria<T>::auxInOrder(No<T> *raiz, std::stringstream &stringStream)
{
    if (raiz != nullptr)
    {
        this->auxInOrder(raiz->getEsquerda(), stringStream);
        stringStream << raiz->getElemento();
        stringStream << "\t";
        this->auxInOrder(raiz->getDireita(), stringStream);
    }
}

/*
    Printa a raiz depois todos os elementos que estão a sua esquerda(elementos que são menores que a raiz)
    e depois todos os elementos que estão a sua direita(elementos que são maiores que a raiz).
*/
template <typename T>
inline std::string ArvoreBinaria<T>::preOrder()
{
    std::stringstream stringStream;
    this->auxPreOrder(this->raiz, stringStream);
    return stringStream.str();
}

template <typename T>
inline void ArvoreBinaria<T>::auxPreOrder(No<T> *raiz, std::stringstream &stringStream)
{
    if (raiz != nullptr)
    {
        stringStream << raiz->getElemento();
        stringStream << "\t";
        this->auxPreOrder(raiz->getEsquerda(), stringStream);
        this->auxPreOrder(raiz->getDireita(), stringStream);
    }
}

/*
    Printa todos os elementos que estão a direita da raiz depois todos os elementos que estão a esquerda da raiz para no final
    printar o elemento que está na raiz.
*/
template <typename T>
inline std::string ArvoreBinaria<T>::postOrder()
{
    std::stringstream stringStream;
    this->auxPostOrder(this->raiz, stringStream);
    return stringStream.str();
}

template <typename T>
inline void ArvoreBinaria<T>::auxPostOrder(No<T> *raiz, std::stringstream &stringStream)
{
    if (raiz != nullptr)
    {
        this->auxPostOrder(raiz->getDireita(), stringStream);
        this->auxPostOrder(raiz->getEsquerda(), stringStream);
        stringStream << raiz->getElemento();
        stringStream << "\t";
    }
}

/*
    Printa todos os elementos que estão a direita da raiz(maiores que a raiz) depois printa a raiz e depois todos os elementos
    que estão a esquerda da raiz(menores que a raiz).
*/
template <typename T>
inline std::string ArvoreBinaria<T>::inOrderInv()
{
    std::stringstream stringStream;
    this->auxInOrderInv(this->raiz, stringStream);
    return stringStream.str();
}

template <typename T>
inline void ArvoreBinaria<T>::auxInOrderInv(No<T> *raiz, std::stringstream &stringStream)
{
    if (raiz != nullptr)
    {
        this->auxInOrderInv(raiz->getDireita(), stringStream);
        stringStream << raiz->getElemento();
        stringStream << "\t";
        this->auxInOrderInv(raiz->getEsquerda(), stringStream);
    }
}

template <typename T>
inline bool ArvoreBinaria<T>::contains(T elemento)
{
    if (this->raiz == nullptr)
    {
        return false;
    }
    if (elemento < this->raiz->getElemento())
    {
        return this->auxContains(this->raiz->getEsquerda(), elemento);
    }
    return this->auxContains(this->raiz->getDireita(), elemento);
}

template <typename T>
inline bool ArvoreBinaria<T>::auxContains(No<T> *raiz, T elemento)
{
    if (raiz == nullptr)
    {
        return false;
    }
    if (raiz->getElemento() == elemento)
    {
        return true;
    }
    if (elemento < raiz->getElemento())
    {
        return this->auxContains(raiz->getEsquerda(), elemento);
    }
    return this->auxContains(raiz->getDireita(), elemento);
}

template <typename T>
inline T ArvoreBinaria<T>::max()
{
    return this->raiz == nullptr ? T() : this->auxMax(this->raiz)->getElemento();
}

template <typename T>
inline No<T> *ArvoreBinaria<T>::auxMax(No<T> *raiz)
{
    return raiz->getDireita() == nullptr ? raiz : this->auxMax(raiz->getDireita());
}

template <typename T>
inline T ArvoreBinaria<T>::min()
{
    return this->raiz == nullptr ? T() : this->auxMin(this->raiz)->getElemento();
}

template <typename T>
inline No<T> *ArvoreBinaria<T>::auxMin(No<T> *raiz)
{
    return raiz->getEsquerda() == nullptr ? raiz : this->auxMin(raiz->getEsquerda());
}

template <typename T>
inline bool ArvoreBinaria<T>::isEmpty()
{
    return this->raiz == nullptr;
}

template <typename T>
inline void ArvoreBinaria<T>::remover(T elemento)
{
    No<T> *no_elemento = this->getNo(elemento);
    if (no_elemento != nullptr)
    {
        if (no_elemento->getEsquerda() != nullptr || no_elemento->getDireita() != nullptr)
        {
            if (no_elemento->getEsquerda() == nullptr)
            {
                this->transplante(no_elemento, no_elemento->getDireita());
            }
            else if (no_elemento->getDireita() == nullptr)
            {
                this->transplante(no_elemento, no_elemento->getEsquerda());
            }
            else
            {
                No<T> *sucessor = this->auxMin(no_elemento->getDireita());
                if (sucessor->getPai() != no_elemento)
                {
                    this->transplante(sucessor, sucessor->getDireita());
                    sucessor->setDireita(no_elemento->getDireita());
                    sucessor->getDireita()->setPai(sucessor);
                }
                this->transplante(no_elemento, sucessor);
                sucessor->setEsquerda(no_elemento->getEsquerda());
                sucessor->getEsquerda()->setPai(sucessor);
            }
        }
        delete no_elemento;
        no_elemento = nullptr;
    }
}

template <typename T>
inline void ArvoreBinaria<T>::transplante(No<T> *no1, No<T> *no2)
{
    if (no1->getPai() == nullptr)
    {
        this->raiz = no2;
    }
    else if (no1 == no1->getPai()->getEsquerda())
    {
        no1->getPai()->setEsquerda(no2);
    }
    else
    {
        no1->getPai()->setDireita(no2);
    }
    if (no2 != nullptr)
    {
        no2->setPai(no1->getPai());
    }
}

/*
    Retorna o nó da arvore que possui T como elemento
*/
template <typename T>
inline No<T> *ArvoreBinaria<T>::getNo(T elemento)
{
    return this->auxGetNo(this->raiz, elemento);
}

template <typename T>
inline No<T> *ArvoreBinaria<T>::auxGetNo(No<T> *raiz, T elemento)
{
    if (raiz == nullptr)
    {
        return nullptr;
    }
    if (elemento == raiz->getElemento())
    {
        return raiz;
    }
    if (elemento < raiz->getElemento())
    {
        return this->auxGetNo(raiz->getEsquerda(), elemento);
    }
    return this->auxGetNo(raiz->getDireita(), elemento);
}

/*
    Retorna o elemento sucessor ao elemento passado no parâmetro da função.
*/
template <typename T>
inline T ArvoreBinaria<T>::sucessor(T elemento)
{
    No<T> *no = this->getNo(elemento);
    if (no != nullptr)
    {
        if (no->getDireita() != nullptr)
        {
            //Retorna o menor dos maiores elementos abaixo do nó que contém o elemento T.
            return this->auxMin(no->getDireita())->getElemento();
        }
        //Subindo na arvore
        No<T> *pai = no->getPai();
        while (pai != nullptr && no == pai->getDireita())
        {
            no = pai;
            pai = pai->getPai();
        }
        return pai->getElemento();
    }
    return T();
}

/*
    Retorna o elemento anterior ao elemento passado no parâmetro da função.
*/
template <typename T>
inline T ArvoreBinaria<T>::predecessor(T elemento)
{
    No<T> *no = this->getNo(elemento);
    if (no != nullptr)
    {
        if (no->getEsquerda() != nullptr)
        {
            return this->auxMax(no->getEsquerda())->getElemento();
        }
        No<T> *pai = no->getPai();
        while (pai != nullptr && no == pai->getEsquerda())
        {
            no = pai;
            pai = pai->getPai();
        }
        return pai->getElemento();
    }
    return T();
}

template <typename T>
inline No<T> *ArvoreBinaria<T>::getNoSucessor(No<T> *raiz)
{
    if (raiz != nullptr)
    {
        if (raiz->getDireita() != nullptr)
        {
            return this->auxMinNo(raiz->getDireita());
        }
        No<T> *pai = raiz->getPai();
        while (pai != nullptr && raiz == pai->getDireita())
        {
            raiz = pai;
            pai = pai->getPai();
        }
        return pai;
    }
    return nullptr;
}

template <typename T>
inline No<T> *ArvoreBinaria<T>::auxMinNo(No<T> *raiz)
{
    return raiz->getEsquerda() == nullptr ? raiz : this->auxMinNo(raiz->getEsquerda());
}
#endif