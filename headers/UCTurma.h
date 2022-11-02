//
// Created by pland on 28/10/2022.
//

#ifndef AED_PROJETO_UCTURMA_H
#define AED_PROJETO_UCTURMA_H

#include "THorario.h"

class UCTurma {

public:

    UCTurma();

    UCTurma(pair<string, string> ucturma);

    pair<string,string> getUCTurma();

    void setUCTurma(pair<string, string> ucturma);

    bool operator<(const UCTurma &uct) const;

private:

    pair<string,string> ucturma; //codUC, codTurma

};

#endif //AED_PROJETO_UCTURMA_H
