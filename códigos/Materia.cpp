// materia.cpp

#include "Materia.hpp"

Materia::Materia(const std::string& codigo, const std::string& nome, const std::string& departamento)
    : codigo(codigo), nome(nome), departamento(departamento) {}

// Implementação dos métodos de acesso
std::string Materia::getCodigo() const { return codigo; }
std::string Materia::getNome() const { return nome; }
std::string Materia::getDepartamento() const { return departamento; }
