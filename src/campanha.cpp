#include "Campanha.hpp"   // Inclui a definição da classe `Campanha`.
#include "Batalhas.hpp"   // Inclui a definição da classe `Batalhas`.
#include "Unidade.hpp"    // Inclui a definição da classe `Unidade`.
#include <iostream>       // Para entrada e saída.
#include <cstdlib>        // Para funções como rand().
#include <ctime>          // Para inicializar a semente do gerador aleatório e trabalhar com data/hora.
#include "Exercito.hpp"   // Para trabalhar com a classe `Exercito`.
#include <algorithm>      // Para funções de algoritmo padrão, como sort().
#include <limits.h>       // Para valores como INT_MAX e INT_MIN.
#include <vector>         // Para trabalhar com o contêiner `std::vector`.
#include <iomanip>        // Para formatação de saída, como `setw`.

using namespace std;

// Construtor
Campanha::Campanha() {
    srand(time(0)); // Inicializa a semente do gerador de números aleatórios para gerar resultados diferentes a cada execução.
}

// Simula batalhas entre dois exércitos fornecidos.
void Campanha::simularBatalhas(Exercito* a, Exercito* b) {
    int pontuacaoB = 0, pontuacaoA = 0; // Pontuações para os dois exércitos.
    int vitoriaA = 0, vitoriaB = 0;    // Contadores de vitórias.

    vector<Unidade*> ExB = b->getUnidades(); // Obtém as unidades do exército B.
    vector<Unidade*> ExA = a->getUnidades(); // Obtém as unidades do exército A.

    // Itera pelas unidades dos exércitos para calcular o poder de ataque em "rodadas".
    for (unsigned int i = 0; i < ExB.size(); i++) {
        if (i < 2) {  // Primeira rodada (duas primeiras unidades).
            pontuacaoA += ExA[i]->getPoderAtaque();
            pontuacaoB += ExB[i]->getPoderAtaque();

            if (i == 1) {  // Após a segunda unidade, compara as pontuações.
                if (compara(pontuacaoA, pontuacaoB) == 1) {
                    vitoriaA++;  // Vitória para o exército A.
                } else if (compara(pontuacaoA, pontuacaoB) == 2) {
                    vitoriaB++;  // Vitória para o exército B.
                } else {
                    a->registraEmpate();
                    b->registraEmpate();
                }
                pontuacaoA = pontuacaoB = 0; // Reseta as pontuações para a próxima rodada.
            }
        }

        // Segunda rodada (terceira e quarta unidades).
        if ((i > 2) && (i < 4)) {
            pontuacaoA += ExA[i]->getPoderAtaque();
            pontuacaoB += ExB[i]->getPoderAtaque();

            if (i == 3) {  // Após a quarta unidade, compara as pontuações.
                if (compara(pontuacaoA, pontuacaoB) == 1) {
                    vitoriaA++;
                } else if (compara(pontuacaoA, pontuacaoB) == 2) {
                    vitoriaB++;
                } else {
                    a->registraEmpate();
                    b->registraEmpate();
                }
                pontuacaoA = pontuacaoB = 0;
            }
        }

        // Última unidade (quinta).
        if (i == 4) {
            pontuacaoA += ExA[i]->getPoderAtaque();
            pontuacaoB += ExB[i]->getPoderAtaque();

            if (i == 4) {
                if (compara(pontuacaoA, pontuacaoB) == 1) {
                    vitoriaA++;
                } else if (compara(pontuacaoA, pontuacaoB) == 2) {
                    vitoriaB++;
                } else {
                    a->registraEmpate();
                    b->registraEmpate();
                }

                pontuacaoA = pontuacaoB = 0;
            }

            // Determina o vencedor geral.
            if (compara(vitoriaA, vitoriaB) == 1) {
                vitoriaA++;
                a->registraVitoria(); // Registra vitória para o exército A.
            } else if (compara(vitoriaA, vitoriaB) == 2) {
                vitoriaB++;
                b->registraVitoria(); // Registra vitória para o exército B.
            }

            // Atualiza flags de vitória/derrota.
            if (vitoriaA > vitoriaB) {
                a->setFlag();
            } else if (vitoriaA < vitoriaB) {
                b->setFlag();
            }

            // Exibe as unidades de ambos os exércitos.
            a->imprimeUnidades();
            b->imprimeUnidades();
        }
    }
}

// Função que compara duas pontuações e retorna:
// 1 se `pontA` for maior,
// 2 se `pontB` for maior,
// 0 em caso de empate.
int Campanha::compara(int pontA, int pontB) {
    if (pontA > pontB) {
        return 1;
    } else if (pontA < pontB) {
        return 2;
    } else {
        return 0;
    }
}

// Adiciona uma batalha ao histórico.
void Campanha::adicicionaHistorico(Batalhas& a) {
    time_t now = time(0);           // Obtém o horário atual.
    tm* localTime = localtime(&now); // Converte para o formato de data/hora local.
    std::ostringstream oss;
    oss << std::put_time(localTime, "%d/%m/%Y %H:%M"); // Formata a data/hora.
    a.setData(oss.str());         // Define a data na batalha.
    batalhas.push_back(a);        // Adiciona a batalha ao histórico.
}

// Exibe o histórico de batalhas armazenado.
void Campanha::exibirHistorico() const {
    if (batalhas.empty()) {
        cout << "Nenhuma batalha ocorreu ainda." << endl;
        return;
    }

    cout << "\n=== Histórico de Batalhas ===" << endl;
    for (const auto& batalha : batalhas) {
        cout << "\nExércitos envolvidos:" << endl;
        cout << batalha.getResultados() << endl;
    }
}

// Gera uma tabela de posições baseada no número de vitórias dos exércitos.
void Campanha::gerarTabelaDePosicoes(vector<Exercito*> exercitos) {
    int size = exercitos.size();
    int x = 1;               // Posição inicial.
    int vet[size] = {0};     // Marca quais exércitos já foram processados.

    // Cabeçalho da tabela.
    cout << left << setw(12) << "Posição" << setw(27) << "Exército" << setw(25) << "Vitórias" << endl;
    cout << "---------------------------------------------------------------" << endl;

    for (int count = 0; count < size; count++) {
        int maior = INT_MIN; // Define o menor valor possível.
        int indiceMaior = -1;
        string maiorNome;

        // Encontra o exército com mais vitórias que ainda não foi processado.
        for (int i = 0; i < size; i++) {
            if (vet[i] == 0 && exercitos[i]->retornaVitoria() > maior) {
                maior = exercitos[i]->retornaVitoria();
                maiorNome = exercitos[i]->getNome();
                indiceMaior = i;
            }
        }

        if (indiceMaior != -1) { // Evita processar índices inválidos.
            cout << left << setw(20) << x  // Posição.
                 << setw(25) << maiorNome  // Nome do exército.
                 << setw(25) << maior     // Número de vitórias.
                 << endl;

            vet[indiceMaior] = 1; // Marca o exército como processado.
            x++;                  // Incrementa a posição.
        }
    }
}

// Destrutor: Limpa o histórico de batalhas.
Campanha::~Campanha() {
    batalhas.clear(); // Libera memória associada ao vetor de batalhas.
}
