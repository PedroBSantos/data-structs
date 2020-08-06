#include "../include/fila.h"
#include <ctime>
#include <iostream>

int main(int argc, char const *argv[])
{
    srand((unsigned)time(0));
    //Fila de prioridade máxima
    Fila<int> fila;
    int aleatorio;
    std::cout << "Elementos adicionados:\t";
    for (int i = 0; i < 10; i++)
    {
        aleatorio = rand();
        fila.add(aleatorio);
        std::cout << aleatorio << "\t";
    }
    std::cout << "\nElementos removidos:\t";
    while (!fila.empty())
    {
        std::cout << fila.remove() << "\t";
    }
    return 0;
}
