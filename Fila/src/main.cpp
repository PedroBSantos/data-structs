#include "../include/fila.h"
#include <ctime>
#include <iostream>
#include <locale>

int main()
{
    setlocale(LC_ALL, "");
    srand((unsigned)time(0));
    Fila<int> fila;
    std::cout << "Quantidade de elementos: " << fila.size() << std::endl;
    int aleatorio;
    std::cout << "Elementos adicionados na Fila:\t";
    for (int i = 0; i < 10; i++)
    {
        aleatorio = rand() % 100;
        fila.queue(aleatorio);
        std::cout << aleatorio << "\t";
    }
    if (fila.isEmpty())
    {
        std::cout << "\nA Fila está vazia." << std::endl;
    }
    else
    {
        std::cout << "\nA Fila não está vazia." << std::endl;
    }
    while (!fila.isEmpty())
    {
        std::cout << "Elemento do inicio: " << fila.dequeue() << std::endl;
    }
    std::cout << "\nQuantidade de elementos: " << fila.size() << std::endl;
    std::cout << "Elementos adicionados na Fila:\t";
    for (int i = 0; i < 10; i++)
    {
        aleatorio = rand() % 100;
        fila.queue(aleatorio);
        std::cout << aleatorio << "\t";
    }
    if (fila.isEmpty())
    {
        std::cout << "\nA Fila está vazia." << std::endl;
    }
    else
    {
        std::cout << "\nA Fila não está vazia." << std::endl;
    }
    return 0;
}