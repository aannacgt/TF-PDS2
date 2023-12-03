#ifndef TURMA_HPP
#define TURMA_HPP
#include "Professor.hpp"
#include <string>

class Turma {
public:
    Turma(const std::string& codigo, int numeroVagas, const std::string& professor);

    // Métodos de acesso
    std::string getCodigo() const;
    int getNumeroVagas() const;
    std::string getProfessor() const;
    void cadastrarNotaFrequencia(const Professor& professor, const Aluno& aluno, double nota, double frequencia);
    std::pair<double, double> consultarNotaFrequencia(const Aluno& aluno) const;
	void associarProfessor(const Professor& professor);
    void desassociarProfessor(const Professor& professor);

private:
    std::string codigo;
    int numeroVagas;
    std::string professor;
	std::vector<Professor> professores; // Adiciona um vetor para armazenar os professores associados à turma
};

#endif
