#ifndef FILA_H
#define FILA_H

template <typename T>
class Fila
{
private:
    T *elementos;
    int qtdElementos;
    int tamanho;
    int esquerda(int i);
    int direita(int i);
    int pai(int i);
    void subir_heap(int i);
    void descer_heap(int i);
    void aumentar_tamanho();

public:
    Fila(int tamanho = 5);
    Fila(const Fila<T> &fila);
    ~Fila();
    int size();
    void add(T elemento);
    T remove();
    bool empty();
};

template <typename T>
inline Fila<T>::Fila(int tamanho)
{
    this->tamanho = tamanho;
    this->elementos = new T[this->tamanho];
    this->qtdElementos = 0;
}

template <typename T>
inline Fila<T>::Fila(const Fila<T> &fila)
{
    this->elementos = fila.elementos;
    this->qtdElementos = fila.qtdElementos;
    this->tamanho = fila.tamanho;
}

template <typename T>
inline Fila<T>::~Fila()
{
    if (this->elementos != nullptr)
    {
        delete[] this->elementos;
    }
}

template <typename T>
inline int Fila<T>::size()
{
    return this->qtdElementos;
}

template <typename T>
inline int Fila<T>::esquerda(int i)
{
    return (2 * i) + 1;
}

template <typename T>
inline int Fila<T>::direita(int i)
{
    return (2 * i) + 2;
}

template <typename T>
inline int Fila<T>::pai(int i)
{
    return (i - 1) / 2;
}

template <typename T>
inline void Fila<T>::subir_heap(int i)
{
    int p = this->pai(i);
    if (i > 0 && this->elementos[i] > this->elementos[p])
    {
        T aux = this->elementos[p];
        this->elementos[p] = this->elementos[i];
        this->elementos[i] = aux;
        this->subir_heap(p);
    }
}

template <typename T>
inline void Fila<T>::descer_heap(int i)
{
    int l = this->esquerda(i);
    int r = this->direita(i);
    int maior;
    if (l < this->qtdElementos && this->elementos[l] > this->elementos[i])
    {
        maior = l;
    }
    else
    {
        maior = i;
    }
    if (r < this->qtdElementos && this->elementos[r] > this->elementos[maior])
    {
        maior = r;
    }
    if (maior != i)
    {
        T aux = this->elementos[i];
        this->elementos[i] = this->elementos[maior];
        this->elementos[maior] = aux;
        this->descer_heap(maior);
    }
}

template <typename T>
inline void Fila<T>::add(T elemento)
{
    if (this->qtdElementos == this->tamanho)
    {
        this->aumentar_tamanho();
    }
    this->elementos[this->qtdElementos] = elemento;
    this->subir_heap(this->qtdElementos);
    this->qtdElementos++;
}

template <typename T>
inline T Fila<T>::remove()
{
    if (this->qtdElementos == 0)
    {
        return T();
    }
    T maior = this->elementos[0];
    if (this->qtdElementos != 1)
    {
        this->elementos[0] = this->elementos[this->qtdElementos - 1];
        this->descer_heap(0);
    }
    this->qtdElementos--;
    return maior;
}

template <typename T>
inline bool Fila<T>::empty()
{
    return this->qtdElementos == 0;
}

template <typename T>
inline void Fila<T>::aumentar_tamanho()
{
    this->elementos = (T *)realloc(this->elementos, this->tamanho * 2 * sizeof(T));
    this->tamanho *= 2;
}
#endif