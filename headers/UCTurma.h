//
// Created by pland on 28/10/2022.
//

#ifndef AED_PROJETO_UCTURMA_H
#define AED_PROJETO_UCTURMA_H

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
#include <bits/stdc++.h>

using namespace std;

class UCTurma {

public:

    UCTurma();

    UCTurma(pair<string, string> ucturma);

    pair<string,string> getUCTurma();

    void setUCTurma(pair<string, string> ucturma);

private:

    pair<string,string> ucturma; //codUC, codTurma

};

#endif //AED_PROJETO_UCTURMA_H
