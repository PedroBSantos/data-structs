#ifndef Pessoa_H
#define Pessoa_H

#include <ostream>
#include <string>

class Pessoa
{
public:
    Pessoa();
    Pessoa(const Pessoa &pessoa);
    Pessoa(std::string nome, int idade, std::string sexo);
    ~Pessoa();
    int getIdade();
    void setIdade(int idade);
    std::string getNome();
    std::string getSexo();
    friend bool operator==(const Pessoa &pessoa1, const Pessoa &pessoa2)
    {
        return pessoa1.nome == pessoa2.nome;
    }
    friend std::ostream &operator<<(std::ostream &os, const Pessoa &pessoa)
    {
        os << "\nNome: " << pessoa.nome << "\nIdade: " << std::to_string(pessoa.idade) << "\nSexo: " << pessoa.sexo << "\n";
        return os;
    }

private:
    std::string nome;
    int idade;
    std::string sexo;
};

#endif