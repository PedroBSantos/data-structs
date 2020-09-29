#include "../include/arvore_binaria.h"
#include <iostream>
#include <vector>

int main(int argc, char* argv[])
{
	ArvoreBinaria<int> arvoreBinaria;
	arvoreBinaria.adicionar(10);
	arvoreBinaria.adicionar(5);
	arvoreBinaria.adicionar(1);
	arvoreBinaria.adicionar(8);
	arvoreBinaria.adicionar(15);
	arvoreBinaria.adicionar(12);
	arvoreBinaria.adicionar(18);
	arvoreBinaria.adicionar(7);
	arvoreBinaria.adicionar(9);

	std::cout << "Percurso pre-ordem: " << arvoreBinaria.preOrder() << std::endl;
	std::cout << "Percurso in-ordem:  " << arvoreBinaria.inOrder() << std::endl;
	std::cout << "Percurso pos-ordem: " << arvoreBinaria.postOrder() << std::endl;
	std::cout << "Predecessor de 8: " << arvoreBinaria.predecessor(8) << std::endl;
	std::cout << "Sucessor de 5: " << arvoreBinaria.sucessor(5) << std::endl;
	arvoreBinaria.remover(5);

	std::cout << "Percurso pre-ordem: " << arvoreBinaria.preOrder() << std::endl;
	std::cout << "Percurso in-ordem:  " << arvoreBinaria.inOrder() << std::endl;
	std::cout << "Percurso pos-ordem: " << arvoreBinaria.postOrder() << std::endl;
	return 0;
}