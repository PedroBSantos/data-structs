#ifndef Pilha_H
#define Pilha_H

#include "no.h"

template <typename T>
class Pilha
{
public:
    Pilha();
    Pilha(const Pilha<T> &pilha);
    ~Pilha();
    T peek();
    void push(T elemento);
    T pop();
    bool isEmpty();
    int size();

private:
    No<T> *topo;
    int qtdElementos;
};

template <typename T>
inline Pilha<T>::Pilha() : topo(nullptr), qtdElementos(0) {}

template <typename T>
inline Pilha<T>::Pilha(const Pilha<T> &pilha) : topo(pilha.topo), qtdElementos(pilha.qtdElementos) {}

template <typename T>
inline Pilha<T>::~Pilha()
{
    if (this->topo)
    {
        delete this->topo;
    }
}

template <typename T>
inline T Pilha<T>::peek()
{
    if (this->topo == nullptr)
    {
        return T();
    }
    return this->topo->getElemento();
}

template <typename T>
inline void Pilha<T>::push(T elemento)
{
    No<T> *novoNo = new No<T>(elemento);
    novoNo->setAnterior(this->topo);
    this->topo = novoNo;
    this->qtdElementos++;
}

template <typename T>
inline T Pilha<T>::pop()
{
    if (this->topo == nullptr)
    {
        return T();
    }
    T elemento = this->topo->getElemento();
    No<T> *aux = this->topo;
    this->topo = this->topo->getAnterior();
    delete aux;
    this->qtdElementos--;
    return elemento;
}

template <typename T>
inline int Pilha<T>::size()
{
    return this->qtdElementos;
}

template <typename T>
inline bool Pilha<T>::isEmpty()
{
    return this->qtdElementos == 0;
}
#endif