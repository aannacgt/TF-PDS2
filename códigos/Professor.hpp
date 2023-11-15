// professor.hpp

#ifndef PROFESSOR_HPP
#define PROFESSOR_HPP

#include <string>

class Professor {
public:
    Professor(const std::string& nome, const std::string& email, int idade, char sexo, const std::string& areaAtuacao);

    // Métodos de acesso
    std::string getNome() const;
    std::string getEmail() const;
    int getIdade() const;
    char getSexo() const;
    std::string getAreaAtuacao() const;

private:
    std::string nome;
    std::string email;
    int idade;
    char sexo;
    std::string areaAtuacao;
};

#endif // PROFESSOR_HPP
