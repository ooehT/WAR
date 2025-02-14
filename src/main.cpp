#include <iostream>
#include <vector>
#include <cstdlib>
#include "Unidade.hpp"
#include "Infantaria.hpp"
#include "Veiculo.hpp"
#include "Aeronave.hpp"
#include "Exercito.hpp"
#include "Campanha.hpp"
#include "date.hpp"
#include <algorithm> 

using namespace std;

int main() {
    Campanha campanha;  // Objeto principal que gerencia as batalhas e o histórico
    Batalhas aux;       // Objeto auxiliar para registrar informações sobre batalhas
    vector<Exercito*> exercitos;  // Vetor para armazenar os ponteiros para os exércitos criados
    int numExercitos;   // Número de exércitos que o usuário deseja criar
    int cont = 0;       // Variável auxiliar para controle de batalhas de ida e volta
    Exercito a;         // Objeto de exemplo (não utilizado diretamente aqui)

    // Solicita ao usuário a quantidade de exércitos a serem criados
    cout << "Quantos exercitos deseja criar? ";
    cin >> numExercitos;

    // Loop para criar os exércitos com nomes fornecidos pelo usuário
    for (int i = 0; i < numExercitos; i++) {
        string nome;
        cout << "Digite o nome do exercito " << (i + 1) << ": ";
        cin >> ws;  // Limpa o buffer do teclado para evitar problemas ao ler strings
        getline(cin, nome);

        // Cria um novo exército dinamicamente e adiciona ao vetor
        Exercito* novoExercito = new Exercito(nome);
        exercitos.push_back(novoExercito);
        exercitos[i]->adicionaUnidades();  // Adiciona as unidades ao exército
    }

    // Menu principal para gerenciar as batalhas e histórico
    int opcao;
    do {
        int idxA = 0;  // Índice do primeiro exército para batalhas
        int idxB = 0;  // Índice do segundo exército para batalhas

        // Apresenta as opções disponíveis ao usuário
        cout << "\nMENU DE BATALHAS" << endl;
        cout << "1. Iniciar batalha aleatoria" << endl;
        cout << "2. Escolher exercitos para batalhar" << endl;
        cout << "3. Exibir historico de batalhas" << endl;
        cout << "4. Rank" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        // Opção 1: Iniciar batalha aleatória
        if (opcao == 1) {
            idxA = rand() % exercitos.size();  // Escolhe um exército aleatoriamente

            // Garante que o segundo exército escolhido seja diferente do primeiro
            do {
                idxB = rand() % exercitos.size();
            } while (idxA == idxB);

            // Loop para realizar as batalhas de ida e volta
            do {
                if (cont == 0) {
                    cout << "BATALHA DE IDA" << endl;
                } else {
                    cout << "BATALHA DE VOLTA" << endl;
                }

                // Simula a batalha entre os dois exércitos escolhidos
                campanha.simularBatalhas(exercitos[idxA], exercitos[idxB]);
                
                // Registra os exércitos envolvidos e adiciona ao histórico
                aux.atribuiExercito(exercitos[idxA], exercitos[idxB]);
                campanha.adicicionaHistorico(aux);

                // Exibe o resultado da batalha
                cout << aux.getResultados() << endl;

                // Reforça os exércitos adicionando novas unidades
                exercitos[idxA]->adicionaUnidades();
                exercitos[idxB]->adicionaUnidades();
                exercitos[idxA]->resetFlag();  // Reseta alguma configuração após a batalha
                exercitos[idxB]->resetFlag();  // Reseta alguma configuração após a batalha
                cont++;
            } while (cont < 2);  // Garante que as batalhas de ida e volta sejam realizadas
            cont = 0;  // Reseta o contador
        }
        // Opção 2: Escolher exércitos para batalhar
        else if (opcao == 2) {
            if (exercitos.size() < 2) {
                cout << "Nao ha exercitos suficientes para batalhar!" << endl;
                continue;  // Sai da iteração do menu
            }

            // Solicita ao usuário os índices dos exércitos para batalhar
            cout << "Digite o numero do primeiro exercito: ";
            cin >> idxA;
            cout << "Digite o numero do segundo exercito: ";
            cin >> idxB;

            // Valida os índices informados pelo usuário
            if (idxA >= 1 && idxA <= exercitos.size() && idxB >= 1 && idxB <= exercitos.size() && idxA != idxB) {
                // Loop para realizar as batalhas de ida e volta
                do {
                    if (cont == 0) {
                        cout << "BATALHA DE IDA" << endl;
                    } else {
                        cout << "BATALHA DE VOLTA" << endl;
                    }

                    // Simula a batalha entre os exércitos selecionados
                    campanha.simularBatalhas(exercitos[idxA - 1], exercitos[idxB - 1]);
                    
                    // Registra os exércitos envolvidos e adiciona ao histórico
                    aux.atribuiExercito(exercitos[idxA - 1], exercitos[idxB - 1]);
                    campanha.adicicionaHistorico(aux);

                    // Exibe o resultado da batalha
                    cout << aux.getResultados() << endl;

                    // Reforça os exércitos adicionando novas unidades
                    exercitos[idxA - 1]->adicionaUnidades();
                    exercitos[idxB - 1]->adicionaUnidades();
                    cont++;
                } while (cont < 2);  // Garante que as batalhas de ida e volta sejam realizadas
                cont = 0;  // Reseta o contador
            }
        }
        // Opção 3: Exibir histórico de batalhas
        else if (opcao == 3) {
            campanha.exibirHistorico();  // Chama a função para exibir o histórico de batalhas
        }
        // Opção 4: Exibir ranking
        else if (opcao == 4) {
            campanha.gerarTabelaDePosicoes(exercitos);  // Gera e exibe a tabela de ranking
        }

    } while (opcao != 0);  // Sai do menu quando o usuário digitar 0

    // Libera a memória alocada para os exércitos
    for (Exercito* e : exercitos) {
        delete e;
    }

    cout << "Programa encerrado!" << endl;
    return 0;  // Finaliza o programa
}

