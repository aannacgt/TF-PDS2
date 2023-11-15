// sistema.cpp

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
