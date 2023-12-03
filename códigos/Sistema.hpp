#ifndef SISTEMA_HPP
#define SISTEMA_HPP

#include "Aluno.hpp"
#include <iostream>

class Sistema {
public:
    Sistema();  // Construtor padrão
    void cadastrarAluno(const Aluno& aluno);
    void acessarSistema(const std::string& login, const std::string& senha);
    void criarNovaMateria(const std::string& codigo, const std::string& nome, const std::string& departamento);
    void excluirMateria(const std::string& codigo);
    void gerarArquivoNotasFrequencias(const Aluno& aluno) const;

private:
    Aluno alunos[100]; // Limite de 100 alunos para simplificar
    int totalAlunos = 0;
};

#endif
