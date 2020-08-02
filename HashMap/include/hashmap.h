#ifndef HashMap_H
#define HashMap_H

#include "linkedlist.h"
#include "registro.h"
#include <ostream>

template <typename K, typename V>
class HashMap
{
public:
    HashMap(int tamanho = 5);
    ~HashMap();
    HashMap(const HashMap<K, V> &hashMap);
    void put(K chave, V valor);
    bool contains(K chave);
    bool isEmpty();
    int size();
    V get(K chave);
    V remove(K chave);
    friend std::ostream &operator<<(std::ostream &os, const HashMap<K, V> &hashMap)
    {
        if (hashMap.qtdElementos == 0)
        {
            os << "[]";
            return os;
        }
        for (int i = 0; i < hashMap.qtdElementos; i++)
        {
            if (hashMap.registros[i].size() > 0)
            {
                os << hashMap.registros[i];
            }
        }
        return os;
    }

private:
    LinkedList<Registro<K, V>> *registros;
    int qtdElementos;
    int tamanhoAtual;
    int hashing(K chave);
    void resize();
};

template <typename K, typename V>
inline HashMap<K, V>::HashMap(int tamanho)
{
    this->registros = new LinkedList<Registro<K, V>>[tamanho];
    this->tamanhoAtual = tamanho;
    this->qtdElementos = 0;
}

template <typename K, typename V>
inline HashMap<K, V>::HashMap(const HashMap<K, V> &hashMap)
{
    this->qtdElementos = hashMap.qtdElementos;
    this->registros = hashMap.registros;
    this->tamanhoAtual = hashMap.tamanhoAtual;
}

template <typename K, typename V>
inline HashMap<K, V>::~HashMap()
{
    if (!this->registros)
    {
        delete[] this->registros;
    }
}

template <typename K, typename V>
inline int HashMap<K, V>::size()
{
    return this->qtdElementos;
}

template <typename K, typename V>
inline int HashMap<K, V>::hashing(K chave)
{
    std::hash<K> hash_fn;
    //size_t result = hash_fn(chave) % this->tamanhoAtual;
    //return result;
    return hash_fn(chave) % this->tamanhoAtual;
}

template <typename K, typename V>
inline void HashMap<K, V>::put(K chave, V valor)
{
    if (this->qtdElementos / this->tamanhoAtual > 0.75)
    {
        this->resize();
    }
    int pos = this->hashing(chave);
    Registro<K, V> registro(chave, valor);
    if (!this->registros[pos].isEmpty())
    {
        int index = this->registros[pos].indexOf(registro);
        if (index != -1)
        {
            this->registros[pos].get(index).setChave(chave);
            this->registros[pos].get(index).setValor(valor);
        }
        else
        {
            this->registros[pos].add(registro);
            this->qtdElementos++;
        }
    }
    else
    {
        this->registros[pos].add(registro);
        this->qtdElementos++;
    }
}

template <typename K, typename V>
inline V HashMap<K, V>::get(K chave)
{
    if (this->qtdElementos == 0)
    {
        return V();
    }
    int pos = this->hashing(chave);
    if (this->registros[pos].isEmpty())
    {
        return V();
    }
    Registro<K, V> registro(chave);
    int index = this->registros[pos].indexOf(registro);
    if (index == -1)
    {
        return V();
    }
    registro = this->registros[pos].get(index);
    return registro.getValor();
}

template <typename K, typename V>
inline V HashMap<K, V>::remove(K chave)
{
    if (this->qtdElementos == 0)
    {
        return V();
    }
    int pos = this->hashing(chave);
    if (this->registros[pos].isEmpty())
    {
        return V();
    }
    Registro<K, V> registro1(chave);
    int index = this->registros[pos].indexOf(registro1);
    if (index == -1)
    {
        return V();
    }
    registro1 = this->registros[pos].remove(index);
    this->qtdElementos--;
    return registro1.getValor();
}

template <typename K, typename V>
inline bool HashMap<K, V>::contains(K chave)
{
    if (this->qtdElementos == 0)
    {
        return false;
    }
    int pos = this->hashing(chave);
    if (this->registros[pos].isEmpty())
    {
        return false;
    }
    Registro<K, V> registro(chave);
    return this->registros[pos].contains(registro);
}

template <typename K, typename V>
inline void HashMap<K, V>::resize()
{
    std::hash<K> hash_fn;
    int index;
    LinkedList<Registro<K, V>> *novosRegistros = new LinkedList<Registro<K, V>>[this->tamanhoAtual * 2];
    for (int i = 0; i < this->tamanhoAtual; i++)
    {
        for (int j = 0; j < this->registros[i].size(); j++)
        {
            Registro<K, V> registro = this->registros[i].get(j);
            index = hash_fn(registro.getChave()) % (this->tamanhoAtual * 2);
            novosRegistros[index].add(registro);
        }
    }
    this->tamanhoAtual *= 2;
    this->registros = novosRegistros;
}

template <typename K, typename V>
inline bool HashMap<K, V>::isEmpty()
{
    return this->qtdElementos == 0;
}

#endif