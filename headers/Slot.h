//
// Created by pland on 28/10/2022.
//

#ifndef AED_PROJETO_SLOT_H
#define AED_PROJETO_SLOT_H

#include <string>
#include <vector>
#include <iostream>
#include <utility>
#include <iterator>
#include <queue>
#include <fstream>
#include <sstream>
#include <list>
#include <set>

using namespace std;

class Slot {

    public:

        Slot();

        Slot(string diaSemana, pair<float,float> hora, string tipo);

        void setDiaSemana(string diaSemana);

        void setHora(pair<float,float> hora);

        void setTipo(string tipo);

        string getDiaSemana();

        pair<float,float> getHora();

        string getTipo();

    private:

        string diaSemana;
        pair<float,float> hora;
        string tipo;
};


#endif //AED_PROJETO_SLOT_H
