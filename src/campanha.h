#ifndef CAMPANHA_H
#define CAMPANHA_H

#include <vector>
#include "Batalha.h"

class Campanha {
private:
    std::vector<Batalha*> batalhas; // Vetor de batalhas

public:
    // Construtor
    Campanha();

    // Adiciona uma batalha à campanha
    void adicionarBatalha(Batalha* batalha);

    // Simula todas as batalhas
    void simularBatalhas();

    // Gera a tabela de posições (resultados dos exércitos)
    void gerarTabelaDePosicoes();

    // Mostra a unidade mais destrutiva da campanha
    void mostrarUnidadeMaisDestrutiva();

    // Destrutor para liberar memória
    ~Campanha();
};

#endif
