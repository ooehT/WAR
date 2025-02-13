#ifndef CAMPANHA_HPP
#define CAMPANHA_HPP

#include <vector>
#include "Batalhas.hpp"
using namespace std;

class Campanha {
private:
   vector<Batalhas> batalhas; // Vetor de batalhas

public:

    // Construtor
    Campanha();

    // Adiciona uma batalha à campanha
    void adicionarBatalha(Batalhas* batalha);

    // Simula todas as batalhas
    void simularBatalhas(Exercito* a, Exercito* b);
    void adicicionaHistorico(Batalhas& a);
    // Gera a tabela de posições (resultados dos exércitos)
    void gerarTabelaDePosicoes(vector<Exercito*> exercitos);
    Batalhas getVetor();
    // Mostra a unidade mais destrutiva da campanha
    void mostrarUnidadeMaisDestrutiva();
    // Destrutor para liberar memóri
    void iniciarBatalha();
    int compara(int pontA, int pontB);
    void exibirHistorico() const;
    
    ~Campanha();
};

#endif
