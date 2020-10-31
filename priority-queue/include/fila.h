#ifndef Queue_H
#define Queue_H

#include <malloc.h>

template <typename T>
class Queue
{
private:
    T* elements;
    int size;
    int length;
    int left(int i);
    int right(int i);
    int parent(int i);
    void upHeap(int i);
    void downHeap(int i);
    void increaseLength();

public:
    Queue(int tamanho = 5);
    Queue(const Queue<T>& Queue);
    ~Queue();
    int count();
    void add(T elemento);
    T remove();
    bool empty();
};

template <typename T>
inline Queue<T>::Queue(int length)
{
    this->length = length;
    this->elements = new T[this->length];
    this->size = 0;
}

template <typename T>
inline Queue<T>::Queue(const Queue<T>& queue)
{
    this->elements = queue.elements;
    this->size = queue.size;
    this->length = queue.length;
}

template <typename T>
inline Queue<T>::~Queue()
{
    if (this->elements != nullptr)
    {
        delete[] this->elements;
    }
}

template <typename T>
inline int Queue<T>::count()
{
    return this->size;
}

template <typename T>
inline int Queue<T>::left(int i)
{
    return (2 * i) + 1;
}

template <typename T>
inline int Queue<T>::right(int i)
{
    return (2 * i) + 2;
}

template <typename T>
inline int Queue<T>::parent(int i)
{
    return (i - 1) / 2;
}

template <typename T>
inline void Queue<T>::upHeap(int i)
{
    int p = this->parent(i);
    if (i > 0 && this->elements[i] > this->elements[p])
    {
        T aux = this->elements[p];
        this->elements[p] = this->elements[i];
        this->elements[i] = aux;
        this->upHeap(p);
    }
}

template <typename T>
inline void Queue<T>::downHeap(int i)
{
    int l = this->left(i);
    int r = this->right(i);
    int bigger;
    if (l < this->size && this->elements[l] > this->elements[i])
    {
        bigger = l;
    }
    else
    {
        bigger = i;
    }
    if (r < this->size && this->elements[r] > this->elements[bigger])
    {
        bigger = r;
    }
    if (bigger != i)
    {
        T aux = this->elements[i];
        this->elements[i] = this->elements[bigger];
        this->elements[bigger] = aux;
        this->downHeap(bigger);
    }
}

template <typename T>
inline void Queue<T>::add(T elemento)
{
    if (this->size == this->length)
    {
        this->increaseLength();
    }
    this->elements[this->size] = elemento;
    this->upHeap(this->size);
    this->size++;
}

template <typename T>
inline T Queue<T>::remove()
{
    if (this->size == 0)
    {
        return T();
    }
    T bigger = this->elements[0];
    if (this->size != 1)
    {
        this->elements[0] = this->elements[this->size - 1];
        this->downHeap(0);
    }
    this->size--;
    return bigger;
}

template <typename T>
inline bool Queue<T>::empty()
{
    return this->size == 0;
}

template <typename T>
inline void Queue<T>::increaseLength()
{
    this->elements = (T*)realloc(this->elements, this->length * 2 * sizeof(T));
    this->length *= 2;
}
#endif