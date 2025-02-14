#ifndef INFANTARIA_HPP
#define INFANTARIA_HPP
// Garantia de inclusão única do arquivo de cabeçalho

#include "Unidade.hpp"  // Inclui a classe base Unidade

// Declaração da classe Infantaria, que herda de Unidade
class Infantaria : public Unidade {
private:
    int forca;  // Atributo que representa a força da infantaria
    int velocidade;  // Atributo que representa a velocidade da infantaria

public:
    Infantaria();  // Construtor da classe Infantaria
    double getPoderAtaque() override;  // Sobrescrita do método para calcular o poder de ataque da infantaria
};

#endif
// Fim da garantia de inclusão única do arquivo de cabeçalho
