#ifndef No_H
#define No_H

template <typename T>
class No
{
public:
    No(T elemento);
    ~No();
    T getElemento();
    No<T> *getProximo();
    void setProximo(No<T> *proximo);

private:
    No<T> *proximo;
    T elemento;
};

template <typename T>
inline No<T>::No(T elemento)
{
    this->elemento = elemento;
    this->proximo = nullptr;
}

template <typename T>
inline No<T>::~No()
{
    if (!this->proximo)
    {
        delete this->proximo;
    }
}

template <typename T>
inline No<T> *No<T>::getProximo()
{
    return this->proximo;
}

template <typename T>
inline void No<T>::setProximo(No<T> *proximo)
{
    this->proximo = proximo;
}

template <typename T>
inline T No<T>::getElemento()
{
    return this->elemento;
}
#endif