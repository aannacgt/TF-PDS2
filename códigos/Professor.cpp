// professor.cpp

#include "Professor.hpp"

Professor::Professor(const std::string& nome, const std::string& email, int idade, char sexo, const std::string& areaAtuacao)
    : nome(nome), email(email), idade(idade), sexo(sexo), areaAtuacao(areaAtuacao) {}

// Implementação dos métodos de acesso
std::string Professor::getNome() const { return nome; }
std::string Professor::getEmail() const { return email; }
int Professor::getIdade() const { return idade; }
char Professor::getSexo() const { return sexo; }
std::string Professor::getAreaAtuacao() const { return areaAtuacao; }
