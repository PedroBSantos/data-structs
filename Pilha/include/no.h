#ifndef No_H
#define No_H

template <typename T>
class No
{
public:
    No(T elemento);
    ~No();
    T getElemento();
    No<T> *getAnterior();
    void setAnterior(No<T> *anterior);

private:
    No<T> *anterior;
    T elemento;
};

template <typename T>
inline No<T>::No(T elemento) : elemento(elemento), anterior(nullptr) {}

template <typename T>
inline No<T>::~No()
{
    if (!this->anterior)
    {
        delete this->anterior;
    }
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
inline T No<T>::getElemento()
{
    return this->elemento;
}
#endif