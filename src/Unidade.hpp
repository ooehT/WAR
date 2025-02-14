#ifndef UNIDADE_HPP
#define UNIDADE_HPP

using namespace std;  // Permite o uso de elementos do namespace `std` sem qualificação explícita.

// Incluímos aqui dependências necessárias.
#include <iostream>   // Biblioteca padrão para entrada e saída.
#include <vector>     // Biblioteca padrão para vetores.
#include <string>     // Biblioteca padrão para manipulação de strings.
#include <iomanip>    // Biblioteca padrão para formatação de saída.
#include "Exercito.hpp" // Inclui a classe Exercito (presumivelmente usada em implementações futuras).

// Declaração da classe base Unidade.
class Unidade {
protected:
    int poderAtaque;   // Representa o poder de ataque da unidade.
    int destruicoes;   // Representa o número de destruições realizadas pela unidade.

public:
    // Construtores
    Unidade();                               // Construtor padrão.
    Unidade(int poderAtaque, int destruicoes); // Construtor parametrizado para inicializar atributos.

    // Destrutor virtual
    virtual ~Unidade();  // Define um destrutor virtual, permitindo destruição apropriada de classes derivadas.

    // Métodos virtuais
    virtual double getPoderAtaque(); // Retorna o poder de ataque da unidade. Pode ser sobrescrito por subclasses.
    virtual void somaDestruicao();  // Incrementa o número de destruições realizadas pela unidade.
};

#endif
