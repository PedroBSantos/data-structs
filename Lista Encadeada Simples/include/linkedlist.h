#ifndef LinkedList_H
#define LinkedList_H

#include "no.h"
#include <ostream>

template <typename T>
class LinkedList
{
public:
    LinkedList();
    ~LinkedList();
    LinkedList(const LinkedList<T> &linkedList);
    void add(T elemento);
    void add(T elemento, int pos);
    void insert(T elemento, int pos);
    void clear();
    bool isEmpty();
    bool removerElemento(T elemento);
    bool contains(T elemento);
    int size();
    T remove(int pos);
    T get(int pos);
    friend std::ostream &operator<<(std::ostream &os, const LinkedList<T> &linkedList)
    {
        if (linkedList.inicio == nullptr)
        {
            os << "[]";
            return os;
        }
        No<T> *aux = linkedList.inicio;
        os << "[";
        while (aux)
        {
            //os << *aux->getElemento(); Caso seja uma lista de ponteiros.
            os << aux->getElemento();
            aux = aux->getProximo();
            if (aux)
            {
                os << ", ";
            }
        }
        os << "]";
        return os;
    }

private:
    int qtdElementos;
    No<T> *inicio;
    No<T> *final;
};

template <typename T>
inline LinkedList<T>::LinkedList()
{
    this->inicio = this->final = nullptr;
    this->qtdElementos = 0;
}

template <typename T>
inline LinkedList<T>::~LinkedList()
{
    if (this->inicio != nullptr)
    {
        delete this->inicio;
    }
    this->qtdElementos = 0;
}

template <typename T>
inline LinkedList<T>::LinkedList(const LinkedList<T> &linkedList)
{
    this->inicio = linkedList.inicio;
    this->final = linkedList.final;
    this->qtdElementos = linkedList.qtdElementos;
}

template <typename T>
inline void LinkedList<T>::add(T elemento)
{
    No<T> *novoNo = new No<T>(elemento, nullptr);
    if (this->qtdElementos == 0)
    {
        this->inicio = this->final = novoNo;
    }
    else
    {
        this->final->setProximo(novoNo);
        this->final = novoNo;
    }
    this->qtdElementos++;
}

template <typename T>
inline void LinkedList<T>::add(T elemento, int pos)
{
    if (pos < 0 || pos > this->qtdElementos)
    {
        return;
    }
    No<T> *novoNo = new No<T>(elemento);
    if (pos == 0)
    {
        novoNo->setProximo(this->inicio);
        this->inicio = novoNo;
    }
    else if (pos == this->qtdElementos)
    {
        this->add(elemento);
        return;
    }
    else
    {
        No<T> *aux = this->inicio;
        int contador = 0;
        while (contador < pos - 1)
        {
            aux = aux->getProximo();
            contador++;
        }
        novoNo->setProximo(aux->getProximo());
        aux->setProximo(novoNo);
    }
    this->qtdElementos++;
}

template <typename T>
inline T LinkedList<T>::remove(int pos)
{
    if (this->qtdElementos == 0 || pos < 0 || pos >= this->qtdElementos)
    {
        return T();
    }
    T elemento;
    if (pos == 0)
    {
        No<T> *inicioAux = this->inicio;
        elemento = this->inicio->getElemento();
        this->inicio = this->inicio->getProximo();
        delete inicioAux;
    }
    else
    {
        int contador = 0;
        No<T> *aux = this->inicio;
        while (contador < pos - 1)
        {
            aux = aux->getProximo();
            contador++;
        }
        elemento = aux->getProximo()->getElemento();
        No<T> *proximo = aux->getProximo();
        aux->setProximo(aux->getProximo()->getProximo());
        if (pos == this->qtdElementos - 1)
        {
            this->final = aux;
        }
        delete proximo;
    }
    this->qtdElementos--;
    return elemento;
}

template <typename T>
inline bool LinkedList<T>::removerElemento(T elemento)
{
    if (this->qtdElementos == 0)
    {
        return false;
    }
    No<T> *aux = this->inicio;
    int contador = 0;
    while (aux)
    {
        if (aux->getElemento() == elemento)
        {
            this->remove(contador);
            return true;
        }
        aux = aux->getProximo();
        contador++;
    }
    return false;
}

template <typename T>
inline T LinkedList<T>::get(int pos)
{
    if (pos < 0 || pos >= this->qtdElementos)
    {
        return T();
    }
    No<T> *aux = this->inicio;
    int contador = 0;
    while (contador < pos)
    {
        aux = aux->getProximo();
        contador++;
    }
    return (T)aux->getElemento();
}

template <typename T>
inline int LinkedList<T>::size()
{
    return this->qtdElementos;
}

template <typename T>
inline bool LinkedList<T>::isEmpty()
{
    return this->qtdElementos == 0;
}

template <typename T>
inline void LinkedList<T>::clear()
{
    if (this->inicio != nullptr)
    {
        No<T> *aux = this->inicio;
        delete aux;
        this->inicio = this->final = nullptr;
    }
    this->qtdElementos = 0;
}

template <typename T>
inline void LinkedList<T>::insert(T elemento, int pos)
{
    if (pos < 0 || pos >= this->qtdElementos)
    {
        return;
    }
    if (pos == 0)
    {
        this->inicio->setElemento(elemento);
    }
    else if (pos == this->qtdElementos - 1)
    {
        this->final->setElemento(elemento);
    }
    else
    {
        int contador = 0;
        No<T> *aux = this->inicio;
        while (contador < pos)
        {
            aux = aux->getProximo();
            contador++;
        }
        aux->setElemento(elemento);
    }
}

template <typename T>
inline bool LinkedList<T>::contains(T elemento)
{
    if (this->qtdElementos == 0)
    {
        return false;
    }
    No<T> *aux = this->inicio;
    while (aux)
    {
        if (aux->getElemento() == elemento)
        {
            return true;
        }
        aux = aux->getProximo();
    }
    return false;
}
#endif