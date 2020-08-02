#ifndef No_H
#define No_H

template<typename T>
class No {
public:
    No();
    No(T elemento);
    No(T elemento, No<T>* proximo);
    ~No();
    No(const No<T>& no);
    T getElemento();
    void setElemento(T elemento);
    No<T>* getProximo();
    void setProximo(No<T>* proximo);
private:
    T elemento;
    No *proximo;
};

template<typename T>
inline No<T>::No(){
    this->elemento = T();
    this->proximo = nullptr;
}

template<typename T>
inline No<T>::No(T elemento){
    this->elemento = elemento;
    this->proximo = nullptr;
}

template<typename T>
inline No<T>::No(T elemento, No<T>* proximo){
    this->elemento = elemento;
    this->proximo = proximo;
}

template<typename T>
inline No<T>::~No(){
    if(!this->proximo){
        delete this->proximo;
    }
}

template<typename T>
inline No<T>::No(const No<T>& no){
    this->proximo = no.proximo;
    this->elemento = no.elemento;
}

template<typename T>
inline T No<T>::getElemento(){
    return this->elemento;
}

template<typename T>
inline void No<T>::setElemento(T elemento){
   this->elemento = elemento;
}

template<typename T>
inline No<T>* No<T>::getProximo(){
    return this->proximo;
}

template<typename T>
inline void No<T>::setProximo(No<T>* proximo){
    this->proximo = proximo;
}
#endif