#ifndef ALUNO_HPP
#define ALUNO_HPP

#include <iostream>
#include <string>

class Aluno {
public:
    Aluno(); // Construtor padrão
    Aluno(const std::string& nome, const std::string& sobrenome, const std::string& email, int idade, char sexo, const std::string& login, const std::string& senha);

    // Métodos de acesso
    std::string getNome() const;
    std::string getSobrenome() const;
    std::string getEmail() const;
    int getIdade() const;
    char getSexo() const;
    std::string getLogin() const;
    std::string getSenha() const;

private:
    std::string nome;
    std::string sobrenome;
    std::string email;
    int idade;
    char sexo;
    std::string login;
    std::string senha;
};

#endif 