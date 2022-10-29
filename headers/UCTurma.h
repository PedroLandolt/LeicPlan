//
// Created by pland on 28/10/2022.
//

#ifndef AED_PROJETO_UCTURMA_H
#define AED_PROJETO_UCTURMA_H


class UCTurma {

public:

    UCTurma(pair<string, string> ucturma);

    auto getUCTurma(){
        return ucturma;
    }

    void setUCTurma(pair<string, string> ucturma){
        this->ucturma = ucturma;
    }

private:

    pair<string,string> ucturma; //codUC, codTurma

};



#endif //AED_PROJETO_UCTURMA_H
