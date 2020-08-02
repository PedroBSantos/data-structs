#ifndef Registro_H
#define Registro_H

#include <ostream>

template <typename K, typename V>
class Registro
{
public:
    Registro();
    ~Registro();
    Registro(K chave);
    Registro(K chave, V valor);
    Registro(const Registro<K, V> &registro);
    V getValor();
    K getChave();
    void setValor(V valor);
    void setChave(K chave);
    friend bool operator==(const Registro<K, V> &registro1, const Registro<K, V> &registro2)
    {
        return registro1.chave == registro2.chave;
    }
    friend std::ostream &operator<<(std::ostream &os, const Registro<K, V> &registro)
    {
        os << "\nChave: " << registro.chave << "\nValor: " << registro.valor;
        return os;
    }

private:
    V valor;
    K chave;
};

template <typename K, typename V>
inline Registro<K, V>::Registro()
{
    this->chave = K();
    this->valor = V();
}

template <typename K, typename V>
inline Registro<K, V>::~Registro() {}

template <typename K, typename V>
inline Registro<K, V>::Registro(const Registro<K, V> &registro)
{
    this->valor = registro.valor;
    this->chave = registro.chave;
}

template <typename K, typename V>
inline Registro<K, V>::Registro(K chave)
{
    this->chave = chave;
}

template <typename K, typename V>
inline Registro<K, V>::Registro(K chave, V valor) : Registro(chave)
{
    this->valor = valor;
}

template <typename K, typename V>
inline V Registro<K, V>::getValor()
{
    return this->valor;
}

template <typename K, typename V>
inline void Registro<K, V>::setValor(V valor)
{
    this->valor = valor;
}

template <typename K, typename V>
inline K Registro<K, V>::getChave()
{
    return this->chave;
}

template <typename K, typename V>
inline void Registro<K, V>::setChave(K chave)
{
    this->chave = chave;
}

#endif