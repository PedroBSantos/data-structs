#ifndef LinkedList_H
#define LinkedList_H

#include "no.h"
#include <ostream>

template <typename T>
class LinkedList
{
public:
    LinkedList();
    LinkedList(const LinkedList<T> &linkedList);
    virtual ~LinkedList();
    void clear();
    void add(T elemento);
    void add(T elemento, int pos);
    bool removeElemento(T elemento);
    bool contains(T elemento);
    bool isEmpty();
    int size();
    int indexOf(T elemento);
    T get(int pos);
    T remove(int pos);
    bool insert(T elemento, int pos);
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
    No<T> *inicio;
    No<T> *final;
    int qtdElementos;
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
    if (!this->inicio)
    {
        delete this->inicio;
    }
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
    No<T> *novoNo = new No<T>(elemento, nullptr, nullptr);
    if (this->qtdElementos == 0)
    {
        this->inicio = this->final = novoNo;
    }
    else
    {
        novoNo->setAnterior(this->final);
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
    if (pos == this->qtdElementos)
    {
        this->add(elemento);
        return;
    }
    No<T> *novoNo = new No<T>(elemento);
    if (pos == 0)
    {
        novoNo->setProximo(this->inicio);
        this->inicio->setAnterior(novoNo);
        this->inicio = novoNo;
    }
    else if (pos == this->qtdElementos - 1)
    {
        novoNo->setProximo(this->final);
        this->final->setAnterior(novoNo);
        novoNo->setAnterior(this->final->getAnterior());
    }
    else
    {
        No<T> *aux = this->inicio;
        int contador = 0;
        while (contador < pos)
        {
            aux = aux->getProximo();
            contador++;
        }
        aux->getAnterior()->setProximo(novoNo);
        novoNo->setAnterior(aux->getAnterior());
        novoNo->setProximo(aux->getProximo());
    }
    this->qtdElementos++;
}

template <typename T>
inline T LinkedList<T>::remove(int pos)
{
    if (pos < 0 || pos >= this->qtdElementos)
    {
        return T();
    }
    T elemento;
    No<T> *aux;
    if (pos == 0)
    {
        elemento = this->inicio->getElemento();
        aux = this->inicio;
        this->inicio = this->inicio->getProximo();
        delete aux;
        this->qtdElementos--;
        return elemento;
    }
    else if (pos == this->qtdElementos - 1)
    {
        elemento = this->final->getElemento();
        this->qtdElementos--;
        aux = this->final;
        this->final = this->final->getAnterior();
        this->final->setProximo(nullptr);
        delete aux;
        return elemento;
    }
    aux = this->inicio;
    int contador = 0;
    while (contador < pos)
    {
        aux = aux->getProximo();
        contador++;
    }
    elemento = aux->getElemento();
    //aux->getProximo()->setProximo(aux->getProximo());
    aux->getAnterior()->setProximo(aux->getProximo());
    aux->getProximo()->setAnterior(aux->getAnterior());
    delete aux;
    this->qtdElementos--;
    return elemento;
}

template <typename T>
inline bool LinkedList<T>::removeElemento(T elemento)
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

template <typename T>
inline T LinkedList<T>::get(int pos)
{
    if (pos < 0 || pos >= this->qtdElementos || this->qtdElementos == 0)
    {
        return T();
    }
    T elemento;
    if (pos == 0)
    {
        elemento = this->inicio->getElemento();
        return elemento;
    }
    else if (pos == this->qtdElementos - 1)
    {
        elemento = this->final->getElemento();
        return elemento;
    }
    No<T> *aux = this->inicio;
    int contador = 0;
    while (contador < pos)
    {
        aux = aux->getProximo();
        contador++;
    }
    elemento = aux->getElemento();
    return elemento;
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
inline bool LinkedList<T>::isEmpty()
{
    return this->qtdElementos == 0;
}

template <typename T>
inline int LinkedList<T>::size()
{
    return this->qtdElementos;
}

template <typename T>
inline int LinkedList<T>::indexOf(T elemento)
{
    if (this->qtdElementos == 0)
    {
        return -1;
    }
    int contador = 0;
    No<T> *aux = this->inicio;
    while (aux)
    {
        if (aux->getElemento() == elemento)
        {
            return contador;
        }
        contador++;
        aux = aux->getProximo();
    }
    return -1;
}

template <typename T>
inline bool LinkedList<T>::insert(T elemento, int pos)
{
    if (pos < 0 || pos >= this->qtdElementos)
    {
        return false;
    }
    if (pos == this->qtdElementos - 1)
    {
        this->final->setElemento(elemento);
        return true;
    }
    int contador = 0;
    No<T> *aux = this->inicio;
    while (contador < pos)
    {
        aux = aux->getProximo();
        contador++;
    }
    aux->setElemento(elemento);
    return true;
}
#endif