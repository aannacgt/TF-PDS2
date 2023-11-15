// aluno.cpp

#include "Aluno.hpp"

Aluno::Aluno() : nome(""), sobrenome(""), email(""), idade(0), sexo(' '), login(""), senha("") {}

Aluno::Aluno(const std::string& nome, const std::string& sobrenome, const std::string& email, int idade, char sexo, const std::string& login, const std::string& senha)
    : nome(nome), sobrenome(sobrenome), email(email), idade(idade), sexo(sexo), login(login), senha(senha) {}

// Implementação dos métodos de acesso
std::string Aluno::getNome() const { return nome; }
std::string Aluno::getSobrenome() const { return sobrenome; }
std::string Aluno::getEmail() const { return email; }
int Aluno::getIdade() const { return idade; }
char Aluno::getSexo() const { return sexo; }
std::string Aluno::getLogin() const { return login; }
std::string Aluno::getSenha() const { return senha; }
