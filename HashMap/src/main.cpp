#include "../include/hashmap.h"
#include "../include/pessoa.h"
#include <fstream>
#include <iostream>
#include <string>

int main()
{
    Pessoa p1("Alan", 26, "M");
    Pessoa p2("Rodrigo", 19, "M");
    Pessoa p3("Joana", 21, "F");
    Pessoa p4("Joaquim", 28, "M");
    Pessoa p5("Pedro", 20, "M");
    HashMap<std::string, Pessoa> pessoas;
    pessoas.put(p1.getNome(), p1);
    pessoas.put(p2.getNome(), p2);
    pessoas.put(p3.getNome(), p3);
    pessoas.put(p4.getNome(), p4);
    pessoas.put(p5.getNome(), p5);
    std::cout << "Quantidade de elementos:\t" << pessoas.size() << std::endl;
    std::cout << pessoas << std::endl;
    system("pause");
    return 0;
}