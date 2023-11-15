// materia.hpp

#ifndef MATERIA_HPP
#define MATERIA_HPP

#include <string>

class Materia {
public:
    Materia(const std::string& codigo, const std::string& nome, const std::string& departamento);

    // Métodos de acesso
    std::string getCodigo() const;
    std::string getNome() const;
    std::string getDepartamento() const;

private:
    std::string codigo;
    std::string nome;
    std::string departamento;
};

#endif // MATERIA_HPP
