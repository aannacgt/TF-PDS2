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

TEST_CASE("Cadastro de Turma") {
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

}

TEST_CASE("Cadastro de Notas e Frequências") {
    Sistema sistema;
    Aluno aluno("Aluno1", "Sobrenome", "aluno1@example.com", 20, 'M', "login1", "senha");
    Professor professor("Prof. Silva", "prof.silva@example.com", 35, 'F', "Matemática");
    sistema.cadastrarAluno(aluno);

    Turma turma("TUR123", 30, "Prof. Silva");
    sistema.criarNovaMateria("MAT123", "Matemática", "Departamento de Ciências Exatas");
    turma.associarProfessor(professor);

    // Teste de cadastro de notas e frequências
    CHECK_NOTHROW(turma.cadastrarNotaFrequencia(professor, aluno, 8.5, 90.0));

    // Teste de consulta de notas e frequências
    auto notasFrequencia = turma.consultarNotaFrequencia(aluno);
    CHECK_EQ(notasFrequencia.first, 8.5);
    CHECK_EQ(notasFrequencia.second, 90.0);
}

TEST_CASE("Associação e Desassociação de Professores à Turma") {
    Turma turma("TUR123", 30, "Prof. Silva");
    Professor professor1("Prof. Silva", "prof.silva@example.com", 35, 'F', "Matemática");
    Professor professor2("Prof. Souza", "prof.souza@example.com", 40, 'M', "Física");

    // Teste de associação de professores à turma
    turma.associarProfessor(professor1);
    CHECK_EQ(turma.getProfessores().size(), 1
