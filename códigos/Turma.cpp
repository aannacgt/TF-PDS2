#include "Turma.hpp"

Turma::Turma(const std::string& codigo, int numeroVagas, const std::string& professor)
    : codigo(codigo), numeroVagas(numeroVagas), professor(professor) {}

// Implementação dos métodos de acesso
std::string Turma::getCodigo() const { return codigo; }
int Turma::getNumeroVagas() const { return numeroVagas; }
std::string Turma::getProfessor() const { return professor; }

void Turma::cadastrarNotaFrequencia(const Professor& professor, const Aluno& aluno, double nota, double frequencia) {
    // Verifica se o professor está associado à turma
    if (std::find(professores.begin(), professores.end(), professor) == professores.end()) {
        std::cout << "Professor não associado à turma.\n";
        return;
    }  
	//Verifica se o aluno está matriculado na turma
    bool alunoMatriculado = false;
    for (int i = 0; i < totalAlunos; ++i) {
        if (alunos[i].getEmail() == aluno.getEmail()) {
            alunoMatriculado = true;
            break;
        }
    }
    if (!alunoMatriculado) {
        std::cout << "Aluno não matriculado na turma.\n";
        return;
    }

    // Adiciona a nota e frequência do aluno
    notasFrequencias[aluno.getEmail()] = std::make_pair(nota, frequencia);

    // Escreve as notas e frequências no arquivo do aluno
    std::ofstream arquivo(aluno.getLogin() + "_notas_frequencias.txt", std::ios::app);
    if (arquivo.is_open()) {
        arquivo << "Matéria: " << getCodigo() << "\n";
        arquivo << "Nota: " << nota << "\n";
        arquivo << "Frequência: " << frequencia << "\n\n";
        arquivo.close();
        std::cout << "Notas e frequência cadastradas com sucesso.\n";
    } else {
        std::cout << "Erro ao abrir o arquivo para escrita.\n";
    }
}

std::pair<double, double> Turma::consultarNotaFrequencia(const Aluno& aluno) const {
    // Lógica para consultar nota e frequência do aluno
    // Certifique-se de que o aluno está matriculado na turma
    auto it = notasFrequencias.find(aluno.getEmail());
    if (it != notasFrequencias.end()) {
        return it->second;
    } else {
        // Retornar um valor padrão se o aluno não estiver matriculado na turma
        return std::make_pair(-1.0, -1.0);
    }
}

void Turma::associarProfessor(const Professor& professor) {
    // Verifica se o professor já está associado à turma
    if (std::find(professores.begin(), professores.end(), professor) != professores.end()) {
        std::cout << "Professor já associado à turma.\n";
        return;
    }
    // Adiciona o professor à turma
    professores.push_back(professor);
    std::cout << "Professor associado à turma com sucesso.\n";
}

void Turma::desassociarProfessor(const Professor& professor) {
    // Verifica se o professor está associado à turma
    auto it = std::find(professores.begin(), professores.end(), professor);
    if (it != professores.end()) {
        // Remove o professor da turma
        professores.erase(it);
        std::cout << "Professor removido da turma com sucesso.\n";
    } else {
        std::cout << "Professor não associado à turma.\n";
    }
}
