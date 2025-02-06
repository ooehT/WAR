#ifndef AERONAVE_HPP
#define AERONAVE_HPP

#include "Unidade.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

class Aeronave : public Unidade {
private:
    int manobrabilidade;
    int alcance;

public:
    Aeronave();
    double getPoderAtaque() override;
};
#endif 