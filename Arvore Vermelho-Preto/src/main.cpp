#include "../include/arvore_vp.h"
#include <ctime>
#include <iostream>
#include <locale>

int main(int argc, char *argv[])
{
    srand((unsigned)time(NULL));
    setlocale(LC_ALL, "");
    ArvoreVP<double> arvore_vp;
    arvore_vp.adicionar(7);
    arvore_vp.adicionar(7.5);
    arvore_vp.adicionar(5);
    arvore_vp.adicionar(6);
    arvore_vp.adicionar(13);
    arvore_vp.adicionar(11);
    arvore_vp.adicionar(12);
    arvore_vp.adicionar(9);
    arvore_vp.adicionar(10);
    arvore_vp.adicionar(8);

    std::cout << "Antes da remoção de elementos: " << std::endl;
    std::cout << "Max:\t" << arvore_vp.max() << std::endl;
    std::cout << "Min:\t" << arvore_vp.min() << std::endl;
    std::cout << "Percursso em ordem:\t" << arvore_vp.percOrdem() << std::endl;
    std::cout << "Percursso em pré-ordem:\t" << arvore_vp.percPreOrdem() << std::endl;
    std::cout << "Percursso em pós-ordem:\t" << arvore_vp.percPosOrdem() << std::endl;
    std::cout << "Sucessor de 5:\t" << arvore_vp.sucessor(5) << std::endl;
    std::cout << "Predecessor de 13:\t" << arvore_vp.predecessor(13) << std::endl;

    arvore_vp.remover(7);
    arvore_vp.remover(11);
    arvore_vp.remover(12);

    std::cout << "\nDepois da remoção de elementos: " << std::endl;
    std::cout << "Max:\t" << arvore_vp.max() << std::endl;
    std::cout << "Min:\t" << arvore_vp.min() << std::endl;
    std::cout << "Percursso em ordem:\t" << arvore_vp.percOrdem() << std::endl;
    std::cout << "Percursso em pré-ordem:\t" << arvore_vp.percPreOrdem() << std::endl;
    std::cout << "Percursso em pós-ordem:\t" << arvore_vp.percPosOrdem() << std::endl;
    std::cout << "Sucessor de 5:\t" << arvore_vp.sucessor(5) << std::endl;
    std::cout << "Predecessor de 13:\t" << arvore_vp.predecessor(13) << std::endl;
    return 0;
}
