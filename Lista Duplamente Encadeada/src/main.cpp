#include "../include/linkedlist.h"
#include "../include/pessoa.h"
#include <iostream>

int main()
{
    Pessoa p1("Alan", 26, "M");
    Pessoa p2("Rodrigo", 19, "M");
    Pessoa p3("Joana", 21, "F");
    Pessoa p4("Joaquim", 28, "M");
    Pessoa p5("Pedro", 20, "M");
    LinkedList<Pessoa> pessoas;
    pessoas.add(p1);
    pessoas.add(p2);
    pessoas.add(p3);
    pessoas.add(p4);
    std::cout << pessoas << std::endl;
    pessoas.insert(p4, 2);
    std::cout << "\n\n\n"
              << pessoas << std::endl;
    system("pause");
    return 0;
}