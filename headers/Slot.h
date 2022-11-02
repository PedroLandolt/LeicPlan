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
#include <map>

using namespace std;

class Slot {

    public:

        Slot();

        Slot(string diaSemana, pair<float,float> hora, string tipo);

        Slot(string diaSemana, pair<float,float> hora, string tipo, pair<string,string> ucturma);

        void setDiaSemana(string diaSemana);

        void setHora(pair<float,float> hora);

        void setTipo(string tipo);

        void setUcTurma(pair<string,string> ucturma);

        string getDiaSemana();

        pair<float,float> getHora();

        string getTipo();

        pair<string,string> getUcTurma();

        static bool compareSlot(Slot s1, Slot s2);

        void printSlot(vector<Slot>& slots);

    private:

        string diaSemana;
        pair<float,float> hora;
        string tipo;
        pair<string,string> ucturma;
};


#endif //AED_PROJETO_SLOT_H
