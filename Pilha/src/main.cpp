#include "../include/pilha.h"
#include <ctime>
#include <iostream>
#include <locale>

int main()
{
    setlocale(LC_ALL, "");
    srand((unsigned)time(0));
    Pilha<int> pilha;
    std::cout << "Quantidade de elementos:\t" << pilha.size() << std::endl;
    int aleatorio;
    std::cout << "Elementos adicionados na pilha:\t";
    for (int i = 0; i < 10; i++)
    {
        aleatorio = rand() % 100;
        pilha.push(aleatorio);
        std::cout << aleatorio << "\t";
    }
    if (pilha.isEmpty())
    {
        std::cout << "\nA pilha está vazia." << std::endl;
    }
    else
    {
        std::cout << "\nA pilha não está vazia." << std::endl;
    }
    while (!pilha.isEmpty())
    {
        std::cout << "Elemento do topo:\t" << pilha.pop() << std::endl;
    }
    std::cout << "\nQuantidade de elementos:\t" << pilha.size() << std::endl;
    std::cout << "Elementos adicionados na pilha:\t";
    for (int i = 0; i < 10; i++)
    {
        aleatorio = rand() % 100;
        pilha.push(aleatorio);
        std::cout << aleatorio << "\t";
    }
    if (pilha.isEmpty())
    {
        std::cout << "\nA pilha está vazia." << std::endl;
    }
    else
    {
        std::cout << "\nA pilha não está vazia." << std::endl;
    }
    return 0;
}