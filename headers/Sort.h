//
// Created by pland on 30/10/2022.
//

#ifndef AED_PROJETO_SORT_H
#define AED_PROJETO_SORT_H


#include "Estudante.h"


class Sort {

    public:

        vector<pair<int,string>> sortUPCrescente(vector<Estudante> &estudantes);

        vector<pair<int,string>> sortUPDecrescente(vector<Estudante> &estudantes);

        vector<pair<int,string>> sortNomeCrescente(vector<Estudante> &estudantes);

        vector<pair<int,string>> sortNomeDecrescente(vector<Estudante> &estudantes);

       //bool sortbysec(const pair<int,int> &a, const pair<int,int> &b);

    private:


};


#endif //AED_PROJETO_SORT_H
