#ifndef Fila_H
#define Fila_H
#include "no.h"

template <typename T>
class Fila
{
public:
    Fila();
    Fila(const Fila<T> &fila);
    ~Fila();
    T getElementoInicio();
    T getElementoFinal();
    bool isEmpty();
    int size();
    void queue(T elemento);
    T dequeue();

private:
    No<T> *inicio;
    No<T> *final;
    int qtdElementos;
};

template <typename T>
inline Fila<T>::Fila()
{
    this->inicio = this->final = nullptr;
    this->qtdElementos = 0;
}

template <typename T>
inline Fila<T>::~Fila()
{
    if (!this->inicio)
    {
        delete this->inicio;
    }
}

template <typename T>
inline Fila<T>::Fila(const Fila &fila)
{
    this->inicio = fila.inicio;
    this->final = fila.final;
    this->qtdElementos = fila.qtdElementos;
}

template <typename T>
inline T Fila<T>::getElementoFinal()
{
    if (!this->final)
    {
        return this->final->getElemento();
    }
    return T();
}

template <typename T>
inline T Fila<T>::getElementoInicio()
{
    if (!this->inicio)
    {
        return this->inicio->getElemento();
    }
    return T();
}

template <typename T>
inline bool Fila<T>::isEmpty()
{
    return this->qtdElementos == 0;
}

template <typename T>
inline int Fila<T>::size()
{
    return this->qtdElementos;
}

template <typename T>
inline void Fila<T>::queue(T elemento)
{
    No<T> *novoNo = new No<T>(elemento);
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
inline T Fila<T>::dequeue()
{
    if (this->qtdElementos == 0)
    {
        return T();
    }
    T elemento = this->inicio->getElemento();
    No<T> *aux = this->inicio;
    this->inicio = this->inicio->getProximo();
    delete aux;
    this->qtdElementos--;
    return elemento;
}
#endif