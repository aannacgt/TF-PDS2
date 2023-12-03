#include <fstream>
#include "Sistema.hpp"
#include <iostream>

Sistema::Sistema() {
    // Inicializar a matriz de alunos
    for (int i = 0; i < 100; ++i) {
        alunos[i] = Aluno("", "", "", 0, ' ', "", "");
    }
}

void Sistema::cadastrarAluno(const Aluno& aluno) {
    // Verificar se o aluno já está cadastrado
    for (int i = 0; i < totalAlunos; ++i) {
        if (alunos[i].getEmail() == aluno.getEmail()) {
            std::cout << "Aluno já cadastrado. Use o login existente.\n";
            return;
        }
    }
    // Cadastrar o aluno
    alunos[totalAlunos] = aluno;
    ++totalAlunos;
    // Exibir mensagem de confirmação
    std::cout << "Cadastro realizado com sucesso. Login: " << aluno.getLogin() << "\n";
}

void Sistema::acessarSistema(const std::string& login, const std::string& senha) {
    // Verificar as credenciais do aluno
    for (int i = 0; i < totalAlunos; ++i) {
        if (alunos[i].getLogin() == login && alunos[i].getSenha() == senha) {
            std::cout << "Login bem-sucedido. Bem-vindo, " << alunos[i].getNome() << "!\n";
            return;
        }
    }
    // Se não encontrar, exibir mensagem de erro
    std::cout << "Login ou senha incorretos. Tente novamente.\n";
}

void Sistema::gerarArquivoNotasFrequencias(const Aluno& aluno) const {
    // Verifica se o aluno está cadastrado no sistema
    bool alunoCadastrado = false;
    for (int i = 0; i < totalAlunos; ++i) {
        if (alunos[i].getEmail() == aluno.getEmail()) {
            alunoCadastrado = true;
            break;
        }
    }
    if (!alunoCadastrado) {
        std::cout << "Aluno não cadastrado no sistema.\n";
        return;
    }
    // Gerar o arquivo com notas e frequências:
    std::ofstream arquivo(aluno.getLogin() + "_notas_frequencias.txt");
    if (arquivo.is_open()) {
        // Escreva as notas e frequências no arquivo
        // ...

        arquivo.close();
        std::cout << "Arquivo gerado com sucesso.\n";
    } else {
        std::cout << "Erro ao abrir o arquivo para escrita.\n";
    }
}

void Sistema::criarNovaMateria(const std::string& codigo, const std::string& nome, const std::string& departamento) {
    Materia novaMateria(codigo, nome, departamento);

    // Lógica para cadastrar a nova matéria
    // Certifique-se de verificar se a matéria já existe antes de cadastrá-la
    // ...

    materias.push_back(novaMateria);
    std::cout << "Nova matéria cadastrada com sucesso.\n";
}

void Sistema::excluirMateria(const std::string& codigo) {
    auto it = std::find_if(materias.begin(), materias.end(),
                           [codigo](const Materia& materia) { return materia.getCodigo() == codigo; });

    if (it != materias.end()) {
        // Remove alunos e professores associados à matéria
        // ...

        materias.erase(it);
        std::cout << "Matéria removida com sucesso.\n";
    } else {
        std::cout << "Matéria não encontrada.\n";
    }
}