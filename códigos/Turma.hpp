// turma.hpp

#ifndef TURMA_HPP
#define TURMA_HPP

#include <vector>

class Turma {
public:
    Turma(const std::string& codigo, int numeroVagas, const std::string& professor);

    // Métodos de acesso
    std::string getCodigo() const;
    int getNumeroVagas() const;
    std::string getProfessor() const;
    
    // Função para criar uma turma com código único
    void criarTurma(const std::string& codigo, int numeroVagas, const std::string& professor);

private:
    std::string codigo;
    int numeroVagas;
    std::string professor;
	std::vector<Turma> turmas;
};

Turma::Turma(const std::string& codigo, int numeroVagas, const std::string& professor)
    : codigo(codigo), numeroVagas(numeroVagas), professor(professor) {}

std::string Turma::getCodigo() const {
    return codigo;
}

int Turma::getNumeroVagas() const {
    return numeroVagas;
}

std::string Turma::getProfessor() const {
    return professor;
}

void Turma::criarTurma(const std::string& codigo, int numeroVagas, const std::string& professor) {
    // Verificar se o código já foi utilizado
    for (const auto& turma : turmas) {
        if (turma.getCodigo() == codigo) {
            // Código duplicado, não criar a turma
            return;
        }
    }

    // Código único, criar a turma
    Turma novaTurma(codigo, numeroVagas, professor);
    turmas.push_back(novaTurma);
}


#endif // TURMA_HPP
