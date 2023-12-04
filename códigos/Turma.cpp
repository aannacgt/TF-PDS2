#include "Turma.hpp"

Turma::Turma(const std::string& codigo, int numeroVagas, const std::string& professor)
    : codigo(codigo), numeroVagas(numeroVagas), professor(professor) {}

Aluno::Aluno() {
    // Construtor padrão
}

Aluno::Aluno(const std::string& nome, const std::string& sobrenome, const std::string& email, int idade, char sexo, const std::string& login, const std::string& senha)
    : nome(nome), sobrenome(sobrenome), email(email), idade(idade), sexo(sexo), login(login), senha(senha) {
    // Construtor com parâmetros
}

Aluno::Materia* Aluno::encontrarMateria(const std::string& nomeMateria) {
    for (auto& materia : materias) {
        if (materia.nomeMateria == nomeMateria) {
            return &materia;
        }
    }
    return nullptr;
}

std::string Aluno::getNome() const {
    return nome;
}

std::string Aluno::getSobrenome() const {
    return sobrenome;
}

std::string Aluno::getEmail() const {
    return email;
}

int Aluno::getIdade() const {
    return idade;
}

char Aluno::getSexo() const {
    return sexo;
}

std::string Aluno::getLogin() const {
    return login;
}

std::string Aluno::getSenha() const {
    return senha;
}

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

	void Aluno::adicionarMateria(const std::string& nomeMateria, const std::string& nomeProfessor) {
    Materia materia;
    materia.nomeMateria = nomeMateria;
    materia.nomeProfessor = nomeProfessor;
    materia.nota = 0.0; // Inicializando a nota com 0.0
    materias.push_back(materia);
}

void Aluno::adicionarNota(const std::string& nomeMateria, double nota) {
    for (auto& materia : materias) {
        if (materia.nomeMateria == nomeMateria) {
            materia.nota = nota;
            return;
        }
    }
    std::cerr << "Erro: Matéria não encontrada\n";
}

void Aluno::mostrarNotas() const {
    std::cout << "Notas do aluno:\n";
    for (const auto& materia : materias) {
        std::cout << "- " << materia.nomeMateria << ": " << materia.nota << "\n";
    }
}

void Aluno::adicionarFaltas(const std::string& nomeMateria, int faltas) {
    Materia* materia = encontrarMateria(nomeMateria);
    if (materia) {
        materia->faltas += faltas;
    } else {
        std::cerr << "Erro: Matéria não encontrada\n";
    }
}

void Aluno::mostrarFaltas() const {
    std::cout << "Faltas do aluno:\n";
    for (const auto& materia : materias) {
        std::cout << "- " << materia.nomeMateria << ": " << materia.faltas << " faltas\n";
    }
}
}
