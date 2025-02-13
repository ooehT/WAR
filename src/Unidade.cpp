#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>   
#include "Unidade.hpp"
#include "Exercito.hpp"
#include "Infantaria.hpp"

using namespace std;


Unidade::Unidade(int poderAtaque, int destruicoes){
     // Chama o construtor da classe base
    
    this->poderAtaque = poderAtaque;
    this->destruicoes = destruicoes;
}
double Unidade::getPoderAtaque(){
    return poderAtaque;
}

Unidade::~Unidade() {} 

void Unidade::somaDestruicao() {
    destruicoes++;
}







