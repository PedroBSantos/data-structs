#ifndef NO_H
#define NO_H

#include <string>

template <typename T>
class No
{
private:
    No<T> *esquerda;
    No<T> *direita;
    No<T> *pai;
    T elemento;
    std::string cor;

public:
    No(T elemento, No<T> *pai, std::string cor);
    No(T elemento, No<T> *esquerda, No<T> *direita, No<T> *pai, std::string cor);
    No(const No<T> &No);
    ~No();
    std::string getCor() const;
    void setCor(std::string cor);
    T getElemento();
    No<T> *getEsquerda();
    void setEsquerda(No<T> *esquerda);
    No<T> *getDireita();
    void setDireita(No<T> *direita);
    No<T> *getPai();
    void setPai(No<T> *pai);
};

template <typename T>
inline No<T>::No(T elemento, No<T> *pai, std::string cor)
    : elemento(elemento), pai(pai), cor(cor), esquerda(nullptr),
      direita(nullptr) {}

template <typename T>
inline No<T>::No(T elemento, No<T> *esquerda, No<T> *direita, No<T> *pai,
                 std::string cor)
    : elemento(elemento), esquerda(esquerda), direita(direita), pai(pai),
      cor(cor) {}

template <typename T>
inline No<T>::No(const No<T> &no)
    : elemento(no.elemento), esquerda(no.esquerda), direita(no.direita),
      pai(no.pai), cor(no.cor) {}

template <typename T>
inline No<T>::~No() {}

template <typename T>
inline std::string No<T>::getCor() const { return this->cor; }

template <typename T>
inline void No<T>::setCor(std::string cor) { this->cor = cor; }

template <typename T>
inline T No<T>::getElemento() { return this->elemento; }

template <typename T>
inline No<T> *No<T>::getEsquerda() { return this->esquerda; }

template <typename T>
inline void No<T>::setEsquerda(No<T> *esquerda) { this->esquerda = esquerda; }

template <typename T>
inline No<T> *No<T>::getDireita() { return this->direita; }

template <typename T>
inline void No<T>::setDireita(No<T> *direita) { this->direita = direita; }

template <typename T>
inline No<T> *No<T>::getPai() { return this->pai; }

template <typename T>
inline void No<T>::setPai(No<T> *pai) { this->pai = pai; }
#endif