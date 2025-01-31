#ifndef BATALHA_H
#define BATALHA_H

#include <string>
#include "Exercito.h"

class Batalha {
private:
    std::string data;     // Data da batalha
    Exercito* exercitoA;  // Ponteiro para o Exército A
    Exercito* exercitoB;  // Ponteiro para o Exército B
    int pontuacaoA;       // Pontuação do Exército A
    int pontuacaoB;       // Pontuação do Exército B
    std::vector<Unidade*> unidade; 
public:
    // Construtor
    Batalha(const std::string& data, Exercito* exercitoA, Exercito* exercitoB);
    
    // Métodos para simular ataques
    void ataqueExercitoA();
    void ataqueExercitoB();
    
    // Retorna o resultado da batalha
    std::string getResultado() const;
    
    // Destrutor
    ~Batalha();
};

#endif // BATALHA_H
