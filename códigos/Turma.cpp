// turma.cpp

#include "Turma.hpp"

Turma::Turma(const std::string& codigo, int numeroVagas, const std::string& professor)
    : codigo(codigo), numeroVagas(numeroVagas), professor(professor) {}

// Implementação dos métodos de acesso
std::string Turma::getCodigo() const { return codigo; }
int Turma::getNumeroVagas() const { return numeroVagas; }
std::string Turma::getProfessor() const { return professor; }

int main() {
    Turma minhaTurma;

    // Criar turmas com códigos únicos
    minhaTurma.criarTurma("T001", 30, "Prof. A");
    minhaTurma.criarTurma("T002", 25, "Prof. B");
    minhaTurma.criarTurma("T001", 40, "Prof. C");  // Código duplicado, não será criada

    return 0;
}
