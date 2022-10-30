//
// Created by pland on 30/10/2022.
//

#ifndef AED_PROJETO_SORT_H
#define AED_PROJETO_SORT_H

#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <iterator>

#include "../cpps/Estudante.cpp"


class Sort {

    public:

        set<Estudante> sortSetIdCrescente(set<Estudante> &estudantes);

        int sortSetIdDecrescente(set<Estudante> &estudantes);

        int sortSetNomeCrescente(set<Estudante> &estudantes);

        int sortSetNomeDecrescente(set<Estudante> &estudantes);

    private:


};


#endif //AED_PROJETO_SORT_H
