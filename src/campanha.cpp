#include "Campanha.hpp"
#include "Batalhas.hpp"
#include "Unidade.hpp" 
#include <iostream>
#include <cstdlib>  // Para rand()
#include <ctime>   
#include "Exercito.hpp" // Para inicializar números aleatórios
#include <algorithm> 
#include <limits.h>
#include <vector>
#include <iomanip>
using namespace std;

// Construtor
Campanha::Campanha() {
    srand(time(0)); // Inicializa a semente do gerador de números aleatórios
}

// Sorteia dois exércitos e inicia uma batalha entre eles
void Campanha::simularBatalhas(Exercito* a, Exercito* b) {
    
    int pontuacaoB = 0;
    int pontuacaoA = 0;

    int vitoriaA, vitoriaB;

   
    vector<Unidade*> ExB = a->getUnidades(); 
    vector<Unidade*> ExA = a->getUnidades(); 
    // Agora percorre as unidades e soma seus poderes de ataque
    
    for(unsigned int i = 0; i < ExB.size(); i++)
    {   
        
        if(i < 2 ){
        pontuacaoA+=ExA[i]->getPoderAtaque();
        pontuacaoB+=ExB[i]->getPoderAtaque();
        
        if(i == 1){
            if(compara(pontuacaoA, pontuacaoB)==1)
            {
                vitoriaA++;
            }
            else if(compara(pontuacaoA, pontuacaoB)==2)
            {
                vitoriaB++;
            }
            else
            {
                a->registraEmpate();
                b->registraEmpate();
            }
        pontuacaoA = 0;
        pontuacaoB = 0;
            }
        }
        if((i > 2) && (i<4))
        {
            pontuacaoA+=ExA[i]->getPoderAtaque();
            pontuacaoB+=ExB[i]->getPoderAtaque();
            
            if(i == 1){
                if(compara(pontuacaoA, pontuacaoB)==1)
                {
                    vitoriaA++;
                }
                else if(compara(pontuacaoA, pontuacaoB)==2)
                {
                    vitoriaB++;
                }
                else
                {
                    a->registraEmpate();
                    b->registraEmpate();
                }
                pontuacaoA = 0;
                pontuacaoB = 0;
            }
        }
            if(i == 4){
                pontuacaoA+=ExA[i]->getPoderAtaque();
                pontuacaoB+=ExB[i]->getPoderAtaque();
                
                if(i == 4){
                    if(compara(pontuacaoA, pontuacaoB)==1)
                    {
                        vitoriaA++;
                    }
                    else if(compara(pontuacaoA, pontuacaoB)==2)
                    {
                        vitoriaB++;
                    }
                    else
                    {
                        a->registraEmpate();
                        b->registraEmpate();
                    }
                    
                pontuacaoA = 0;
                pontuacaoB = 0;
                    }
                    
                    if(compara(vitoriaA, vitoriaB) == 1){
                        vitoriaA++;
                        a->registraVitoria();
                       
                        
                    }else if(compara(vitoriaA, vitoriaB) == 2){
                        vitoriaB++;
                        b->registraVitoria();

                    }
                    if (vitoriaA > vitoriaB) {
                       a->setFlag();

                        
                    } else if (vitoriaA < vitoriaB) {
                        b->setFlag();
                
                    }
                    a->imprimeUnidades();
                    b->imprimeUnidades();
               }
            }
        
        }
int Campanha::compara(int pontA, int pontB){
    if(pontA>pontB){
        return 1;
    }
    if(pontA<pontB){
        return 2;
    }else{
        return 0;
    }
}


void Campanha::adicicionaHistorico(Batalhas& a) {  // ✅ Agora está igual ao .hpp
    time_t now = time(0);
    tm* localTime = localtime(&now);
    std::ostringstream oss;
    oss << std::put_time(localTime, "%d/%m/%Y %H:%M");
    a.setData(oss.str());  
    batalhas.push_back(a);
    
}

void Campanha::exibirHistorico() const {
    if (batalhas.empty()) {
        cout << "Nenhuma batalha ocorreu ainda." << endl;
        return;
    }

    cout << "\n=== Histórico de Batalhas ===" << endl;
    for (const auto& batalha : batalhas) {
        cout << "\nExercitos envolvidos:" << endl;
        cout << batalha.getResultados() << endl;
        
        }
        
    }


void Campanha::gerarTabelaDePosicoes(vector<Exercito*> exercitos) {
    int size = exercitos.size();
    int x = 1;  // Posição do vencedor
    int vet[size] = {0};  // Inicializa o vetor todo com 0

    // Cabeçalho da tabela
    cout << left << setw(12) << "Posicao" << setw(27) << "     Exercito" << setw(25) << "Vitorias" << endl;  // Ajustei o setw para Exército
    cout << "---------------------------------------------------------------" << endl;

    for (int count = 0; count < size; count++) {
        int maior = -1000000;  // Resetando o maior antes de cada busca
        int indiceMaior = -1;
        string maiorNome;

        for (int i = 0; i < size; i++) {
            if (vet[i] == 0 && exercitos[i]->retornaVitoria() > maior) {
                maior = exercitos[i]->retornaVitoria();
                maiorNome = exercitos[i]->getNome();
                indiceMaior = i;
            }
        }

        if (indiceMaior != -1) {  // Evita marcar índice inválido
            // Impressão formatada
            cout << left << setw(20) << x            // Posição
                 << setw(25) << maiorNome         // Nome do exército ajustado para mais à direita
                 << setw(25) << maior            // Número de vitórias
                 << endl;

            vet[indiceMaior] = 1;  // Marca o maior como já impresso
            x++;  // Incrementa a posição para o próximo
        }
    }
}




// Destrutor - Libera memória das batalhas
Campanha::~Campanha() {
    batalhas.clear();  // Apenas limpa o vetor (nenhum delete necessário!)
}


