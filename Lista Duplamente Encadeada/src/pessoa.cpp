#include "../include/pessoa.h"

Pessoa::Pessoa()
{
    this->nome = "";
    this->idade = 0;
    this->sexo = "";
}

Pessoa::Pessoa(std::string nome, int idade, std::string sexo)
{
    this->nome = nome;
    this->idade = idade;
    this->sexo = sexo;
}

Pessoa::Pessoa(const Pessoa &pessoa)
{
    this->nome = pessoa.nome;
    this->idade = pessoa.idade;
    this->sexo = pessoa.sexo;
}

Pessoa::~Pessoa() {}

std::string Pessoa::getNome()
{
    return this->nome;
}

int Pessoa::getIdade()
{
    return this->idade;
}

std::string Pessoa::getSexo()
{
    return this->sexo;
}

void Pessoa::setIdade(int idade)
{
    this->idade = idade;
}