#include "../include/arvore_vp.h"
#include <iostream>

int main(int argc, char *argv[])
{
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

    std::cout << "Max: " << arvore_vp.max() << std::endl;
    std::cout << "Min: " << arvore_vp.min() << std::endl;
    std::cout << "In-Order: " << arvore_vp.percOrdem() << std::endl;
    std::cout << "Pre-Order: " << arvore_vp.percPreOrdem() << std::endl;
    std::cout << "Post-Order: " << arvore_vp.percPosOrdem() << std::endl;
    std::cout << "Sucessor de 5: " << arvore_vp.sucessor(5) << std::endl;
    std::cout << "Predecessor de 13: " << arvore_vp.predecessor(13) << std::endl;

    arvore_vp.remover(7);
    arvore_vp.remover(11);
    arvore_vp.remover(12);

    std::cout << "\nMax: " << arvore_vp.max() << std::endl;
    std::cout << "Min: " << arvore_vp.min() << std::endl;
    std::cout << "In-Order: " << arvore_vp.percOrdem() << std::endl;
    std::cout << "Pre-Order: " << arvore_vp.percPreOrdem() << std::endl;
    std::cout << "Post-Order: " << arvore_vp.percPosOrdem() << std::endl;
    std::cout << "Sucessor de 5: " << arvore_vp.sucessor(5) << std::endl;
    std::cout << "Predecessor de 13: " << arvore_vp.predecessor(13) << std::endl;
    return 0;
}
