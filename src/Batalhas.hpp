#ifndef BATALHA_HPP
#define BATALHA_HPP
using namespace std;
#include <string>
#include "Exercito.hpp"

class Batalhas {
private:
    string data;     // Data da batalha
    Exercito* exercitoA;  // Ponteiro para o Exército A
    Exercito* exercitoB;  // Ponteiro para o Exército B
    int pontuacaoA, pontuacaoB;
protected:
    vector<Exercito*> exercitos;
public:
    Batalhas();
    void setData(string d);
    // Métodos para simular ataques
    void atribuiExercitoA(Exercito* a);
    void atribuiExercitoB(Exercito* b);
    int getPontuacaoA()  { return pontuacaoA; };
    int getPontuacaoB() { return pontuacaoB; };
    void resetarPontuacoes();
    // Retorna o resultado da batalha
    string getResultados() const;
    
    // Destrutor
    ~Batalhas();

};


#endif // BATALHA_H
