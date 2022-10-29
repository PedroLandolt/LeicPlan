//
// Created by pland on 28/10/2022.
//

#include "../headers/UCTurma.h"

/**
 * Aqui vamos guardar todos os codUC
 *                             codTurma (estes codUC codTurma estão ligados ao estudante)
 */
    
//constructor
UCTurma::UCTurma(pair<string, string> ucturma) {
    this->ucturma = ucturma;
}

//getters and setters

auto UCTurma::getUCTurma() {
    return ucturma;
}

void UCTurma::setUCTurma(pair<string, string> ucturma) {
    this->ucturma = ucturma;
}
