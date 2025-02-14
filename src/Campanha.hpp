#ifndef CAMPANHA_HPP
#define CAMPANHA_HPP

#include <vector>  // Para usar o tipo vector
#include "Batalhas.hpp"  // Inclui a classe Batalhas
using namespace std;

class Campanha {
private:
   vector<Batalhas> batalhas; // Vetor que armazena o histórico das batalhas

public:

    // Construtor da classe Campanha
    Campanha();

    // Método para adicionar uma batalha à campanha
    void adicionarBatalha(Batalhas* batalha);

    // Método que simula todas as batalhas entre dois exércitos
    void simularBatalhas(Exercito* a, Exercito* b);

    // Método para adicionar uma batalha ao histórico
    void adicicionaHistorico(Batalhas& a);

    // Método para gerar a tabela de posições (resultados dos exércitos)
    void gerarTabelaDePosicoes(vector<Exercito*> exercitos);

    // Método para retornar o vetor de batalhas (historico)
    Batalhas getVetor();

    // Método para mostrar a unidade mais destrutiva da campanha
    void mostrarUnidadeMaisDestrutiva();

    // Destrutor da classe Campanha (libera memória alocada)
    void iniciarBatalha();

    // Método para comparar pontuação de duas batalhas
    int compara(int pontA, int pontB);

    // Método para exibir o histórico das batalhas
    void exibirHistorico() const;

    // Destrutor para liberar memória alocada
    ~Campanha();
};

#endif
