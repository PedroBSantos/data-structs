#ifndef No_H
#define No_H

template <typename T>
class No
{
public:
    No();
    ~No();
    No(const No<T> &no);
    No(T elemento);
    No(T elemento, No<T> *proximo, No<T> *anterior);
    T getElemento();
    No<T> *getProximo();
    No<T> *getAnterior();
    void setProximo(No<T> *proximo);
    void setAnterior(No<T> *anterior);

private:
    No<T> *proximo;
    No<T> *anterior;
    T elemento;
};

template <typename T>
inline No<T>::No()
{
    this->elemento = T();
    this->proximo = this->anterior = nullptr;
}

template <typename T>
inline No<T>::No(T elemento)
{
    this->elemento = elemento;
    this->proximo = this->anterior = nullptr;
}

template <typename T>
inline No<T>::No(T elemento, No<T> *proximo, No<T> *anterior)
{
    this->elemento = elemento;
    this->proximo = proximo;
    this->anterior = anterior;
}

template <typename T>
inline No<T>::~No()
{
    if (!this->proximo)
    {
        delete this->proximo;
    }
    if (!this->anterior)
    {
        delete this->anterior;
    }
}

template <typename T>
inline No<T>::No(const No<T> &no)
{
    this->elemento = no.elemento;
    this->anterior = no.anterior;
    this->proximo = no.proximo;
}

template <typename T>
inline T No<T>::getElemento()
{
    return this->elemento;
}

template <typename T>
inline No<T> *No<T>::getProximo()
{
    return this->proximo;
}

template <typename T>
inline No<T> *No<T>::getAnterior()
{
    return this->anterior;
}

template <typename T>
inline void No<T>::setAnterior(No<T> *anterior)
{
    this->anterior = anterior;
}

template <typename T>
inline void No<T>::setProximo(No<T> *proximo)
{
    this->proximo = proximo;
}
#endif