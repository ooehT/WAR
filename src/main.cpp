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
    Campanha campanha;
    Batalhas aux;
    vector<Exercito*> exercitos;  // Vetor para armazenar os exercitos
    int numExercitos;
    int cont = 0;
    Exercito a;
    cout << "Quantos exercitos deseja criar? ";
    cin >> numExercitos;

    // Criando os exercitos com nomes definidos pelo usuario
    for (int i = 0; i < numExercitos; i++) {
        string nome;
        cout << "Digite o nome do exercito " << (i + 1) << ": ";
        cin >> ws;  // Limpa o buffer do teclado
        getline(cin, nome);

        Exercito* novoExercito = new Exercito(nome);
        exercitos.push_back(novoExercito);
        exercitos[i]->adicionaUnidades();
        
    }
    

    // Menu para batalhas
    int opcao;
    do {
    int idxA = 0;
    int idxB = 0;
        cout << "\nMENU DE BATALHAS" << endl;
        cout << "1. Iniciar batalha aleatoria" << endl;
        cout << "2. Escolher exercitos para batalhar" << endl;
        cout << "3. Exibir historico de batalhas" << endl;
        cout << "4. Rank" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;
        if (opcao == 1) {
            idxA = rand() % exercitos.size();

            do {
                idxB = rand() % exercitos.size();
            } while (idxA == idxB);

            do{
                if(cont == 0){
                    cout << "BATALHA DE IDA" << endl;
                }else{
                    cout << "BATALHA DE VOLTA" << endl;
                }
           
            campanha.simularBatalhas(exercitos[idxA], exercitos[idxB]);
            aux.atribuiExercito(exercitos[idxA], exercitos[idxB]);
            
            campanha.adicicionaHistorico(aux);
            cout << aux.getResultados() << endl;
            //aux.registraVitoria(exercitos[idxA], exercitos[idxB]);
            exercitos[idxA]->adicionaUnidades();
            exercitos[idxB]->adicionaUnidades();
            exercitos[idxA]->resetFlag();
            exercitos[idxB]->resetFlag();
            cont++;
            }while(cont < 2);
            cont = 0;
        }
        else if (opcao == 2) {
            if (exercitos.size() < 2) {
                cout << "Nao ha exercitos suficientes para batalhar!" << endl;
                continue;
            }

            
            cout << "Digite o numero do primeiro exercito: ";
            cin >> idxA;
            cout << "Digite o numero do segundo exercito: ";
            cin >> idxB;

            if (idxA >= 1 && idxA <= exercitos.size() && idxB >= 1 && idxB <= exercitos.size() && idxA != idxB) {
            do{
            if(cont == 0){
                cout << "BATALHA DE IDA" << endl;
            }else{
                cout << "BATALHA DE VOLTA" << endl;
            }
           
            campanha.simularBatalhas(exercitos[idxA], exercitos[idxB]);
            
            aux.atribuiExercito(exercitos[idxA], exercitos[idxB]);
            
            campanha.adicicionaHistorico(aux);
            cout << aux.getResultados() << endl;
            //aux.registraVitoria(exercitos[idxA - 1], exercitos[idxB - 1]);
            exercitos[idxA - 1]->adicionaUnidades();
            exercitos[idxB - 1]->adicionaUnidades();
            cont++;
            }while(cont < 2);
            cont = 0;



            }
        }
        else if (opcao == 3) {
            campanha.exibirHistorico();
        }else if (opcao == 4){
            campanha.gerarTabelaDePosicoes(exercitos);

        }

    } while (opcao != 0);

    // Liberando memoria
    for (Exercito* e : exercitos) {
        delete e;
    }

    cout << "Programa encerrado!" << endl;
    return 0;
}
