//
// Created by pland on 30/10/2022.
//

#ifndef AED_PROJETO_SORT_H
#define AED_PROJETO_SORT_H


#include "Estudante.h"


class Sort {

    public:

        void sortUPCrescente(vector<Estudante> &estudantes);

        void sortUPDecrescente(vector<Estudante> &estudantes);

        void sortNomeCrescente(vector<Estudante> &estudantes);

        void sortNomeDecrescente(vector<Estudante> &estudantes);

        void sortPairCrescente(vector<pair<int, string>> &estudantes);

        void sortPairDecrescente(vector<pair<int, string>> &estudantes);

        void sortPairNomeCrescente(vector<pair<int, string>> &estudantes);

        void sortPairNomeDecrescente(vector<pair<int, string>> &estudantes);

       //bool sortbysec(const pair<int,int> &a, const pair<int,int> &b);

    private:


};


#endif //AED_PROJETO_SORT_H
