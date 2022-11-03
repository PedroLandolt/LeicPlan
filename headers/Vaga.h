//
// Created by pland on 02/11/2022.
//

#ifndef AED_PROJETO_VAGA_H
#define AED_PROJETO_VAGA_H

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

#include "conio.h"
#include "windows.h"

using namespace std;

class Vaga {
public:

        Vaga();

        Vaga(string uc , pair<string, int> vagas); // uc e pair<turma,nº vagas>

        pair<string,int> getVagas();

        string getUC();

        void setVagas(pair<string,int> vagas);

        void setUC(string uc);

        //bool operator<(const Vaga &v) const;

private:

        pair<string,int> vagas;
        string uc;

};

#endif //AED_PROJETO_VAGA_H
