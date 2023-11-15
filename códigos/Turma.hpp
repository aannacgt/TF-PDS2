// turma.hpp

#ifndef TURMA_HPP
#define TURMA_HPP

#include <string>

class Turma {
public:
    Turma(const std::string& codigo, int numeroVagas, const std::string& professor);

    // Métodos de acesso
    std::string getCodigo() const;
    int getNumeroVagas() const;
    std::string getProfessor() const;

private:
    std::string codigo;
    int numeroVagas;
    std::string professor;
};

#endif // TURMA_HPP
