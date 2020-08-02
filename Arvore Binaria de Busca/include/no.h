#ifndef NO_H
#define NO_H

template <typename T>
class No
{
private:
    T elemento;
    No<T> *esquerda;
    No<T> *direita;
    No<T> *pai;

public:
    No(T elemento, No<T> *esquerda, No<T> *direita);
    No(T elemento, No<T> *esquerda, No<T> *direita, No<T> *pai);
    No(const No<T> &no);
    virtual ~No();
    T getElemento();
    No<T> *getEsquerda();
    No<T> *getDireita();
    No<T> *getPai();
    void setEsquerda(No<T> *esquerda);
    void setDireita(No<T> *direita);
    void setPai(No<T> *pai);
    void setElemento(T elemento);
};

template <typename T>
inline No<T>::No(T elemento, No<T> *esquerda, No<T> *direita) : elemento(elemento), esquerda(esquerda), direita(direita), pai(nullptr) {}

template <typename T>
inline No<T>::No(T elemento, No<T> *esquerda, No<T> *direita, No<T> *pai) : No(elemento, esquerda, direita)
{
    this->pai = pai;
}

template <typename T>
inline No<T>::No(const No<T> &no) : elemento(no.elemento), esquerda(no.esquerda), direita(no.direita), pai(no.pai) {}

template <typename T>
inline No<T>::~No() {}

template <typename T>
inline T No<T>::getElemento()
{
    return this->elemento;
}

template <typename T>
inline void No<T>::setElemento(T elemento)
{
    this->elemento = elemento;
}

template <typename T>
inline No<T> *No<T>::getEsquerda()
{
    return this->esquerda;
}

template <typename T>
inline No<T> *No<T>::getDireita()
{
    return this->direita;
}

template <typename T>
inline void No<T>::setEsquerda(No<T> *esquerda)
{
    this->esquerda = esquerda;
}

template <typename T>
inline void No<T>::setDireita(No<T> *direita)
{
    this->direita = direita;
}

template <typename T>
inline No<T> *No<T>::getPai()
{
    return this->pai;
}

template <typename T>
inline void No<T>::setPai(No<T> *pai)
{
    this->pai = pai;
}
#endif