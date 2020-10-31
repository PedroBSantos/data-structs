#ifndef STACK_H
#define STACK_H

#include "node.h"

template <typename T>
class Stack
{
public:
    Stack();
    Stack(const Stack<T>& stack);
    ~Stack();
    T peek();
    void push(T data);
    T pop();
    bool empty();
    int count();

private:
    Node<T>* top;
    int size;
};

template <typename T>
inline Stack<T>::Stack() : top(nullptr), size(0) {}

template <typename T>
inline Stack<T>::Stack(const Stack<T>& stack) : top(stack.top), size(stack.size) {}

template <typename T>
inline Stack<T>::~Stack()
{
    if (this->top != nullptr)
    {
        delete this->top;
    }
}

template <typename T>
inline T Stack<T>::peek()
{
    if (this->top == nullptr)
    {
        return T();
    }
    return this->top->getdata();
}

template <typename T>
inline void Stack<T>::push(T data)
{
    Node<T>* newNode = new Node<T>(data);
    newNode->setPrevious(this->top);
    this->top = newNode;
    this->size++;
}

template <typename T>
inline T Stack<T>::pop()
{
    if (this->top == nullptr)
    {
        return T();
    }
    T data = this->top->getdata();
    Node<T>* aux = this->top;
    this->top = this->top->getPrevious();
    delete aux;
    this->size--;
    return data;
}

template <typename T>
inline int Stack<T>::count()
{
    return this->size;
}

template <typename T>
inline bool Stack<T>::empty()
{
    return this->size == 0;
}
#endif