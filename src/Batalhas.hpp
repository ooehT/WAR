#ifndef BATALHA_HPP
#define BATALHA_HPP

using namespace std;
#include <string>  // Para usar strings
#include "Exercito.hpp"  // Inclui a classe Exercito para associar batalhas aos exércitos

class Batalhas {
private:
    string data;  // A data da batalha
    Exercito* exercitoA;  // Ponteiro para o Exército A
    Exercito* exercitoB;  // Ponteiro para o Exército B
    int pontuacaoA, pontuacaoB;  // Armazena as pontuações dos exércitos

protected:
    vector<Exercito*> exercitos;  // Vetor que armazena os exércitos envolvidos nas batalhas

public:
    // Construtor padrão da classe Batalhas
    Batalhas();

    // Método para definir a data da batalha
    void setData(string d);

    // Método para atribuir dois exércitos à batalha
    void atribuiExercito(Exercito* a, Exercito* b);

    // Métodos para acessar a pontuação de cada exército
    int getPontuacaoA() { return pontuacaoA; };
    int getPontuacaoB() { return pontuacaoB; };

    // Método para resetar as pontuações das batalhas
    void resetarPontuacoe(Batalhas* a);

    // Métodos para definir a pontuação de cada exército
    void setPontuacaoA(int a);
    void setPontuacaoB(int a);

    // Método para obter o resultado da batalha em formato string
    string getResultados() const;

    // Destrutor da classe Batalhas
    ~Batalhas();
};

#endif // BATALHA_H
