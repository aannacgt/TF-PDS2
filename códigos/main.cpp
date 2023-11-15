// main.cpp

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "Aluno.hpp"
#include "Sistema.hpp"
#include "Materia.hpp"
#include "Professor.hpp"
#include "Turma.hpp"

TEST_CASE("Cadastro de Aluno e Acesso ao Sistema") {
    Sistema sistema;
    Aluno aluno("Nome", "Sobrenome", "email@example.com", 20, 'M', "login", "senha");

    // Teste de cadastro de aluno
    CHECK_NOTHROW(sistema.cadastrarAluno(aluno));

    // Teste de acesso ao sistema
    std::stringstream output;
    std::streambuf* coutBuffer = std::cout.rdbuf();  // Salva o buffer atual
    std::cout.rdbuf(output.rdbuf());  // Redireciona a saída padrão para o stringstream

    sistema.acessarSistema("login", "senha");

    std::cout.rdbuf(coutBuffer);  // Restaura o buffer original

    CHECK(output.str().find("Login bem-sucedido") != std::string::npos);
}

TEST_CASE("Cadastro de Matéria") {
    Materia materia("MAT123", "Matemática", "Departamento de Ciências Exatas");

    // Teste de cadastro de matéria
    CHECK_EQ(materia.getCodigo(), "MAT123");
    CHECK_EQ(materia.getNome(), "Matemática");
    CHECK_EQ(materia.getDepartamento(), "Departamento de Ciências Exatas");
}

TEST_CASE("Cadastro de Professor") {
    Professor professor("Prof. Silva", "prof.silva@example.com", 35, 'F', "Matemática");

    // Teste de cadastro de professor
    CHECK_EQ(professor.getNome(), "Prof. Silva");
    CHECK_EQ(professor.getEmail(), "prof.silva@example.com");
    CHECK_EQ(professor.getIdade(), 35);
    CHECK_EQ(professor.getSexo(), 'F');
    CHECK_EQ(professor.getAreaAtuacao(), "Matemática");
}

TEST_CASE("Cadastro de Turma e Organização de Alunos") {
    Sistema sistema;
    Aluno aluno1("Aluno1", "Sobrenome", "aluno1@example.com", 20, 'M', "login1", "senha");
    Aluno aluno2("Aluno2", "Sobrenome", "aluno2@example.com", 22, 'F', "login2", "senha");
    sistema.cadastrarAluno(aluno1);
    sistema.cadastrarAluno(aluno2);

    Turma turma("TUR123", 30, "Prof. Silva");

    // Teste de cadastro de turma
    CHECK_EQ(turma.getCodigo(), "TUR123");
    CHECK_EQ(turma.getNumeroVagas(), 30);
    CHECK_EQ(turma.getProfessor(), "Prof. Silva");

    // Teste de organização de alunos na turma
    // (Você precisará adicionar funcionalidades ao seu sistema para testar essa parte)
    // Exemplo hipotético:
    // sistema.organizarAlunoNaTurma(aluno1, turma);
    // sistema.organizarAlunoNaTurma(aluno2, turma);
    // CHECK_EQ(turma.getNumeroAlunos(), 2);
}
