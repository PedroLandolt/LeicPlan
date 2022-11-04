#include "../headers/UCTurma.h"


UCTurma::UCTurma() { }

UCTurma::UCTurma(pair<std::string, std::string> ucturma) {
    this->ucturma = ucturma;
}

pair<string,string> UCTurma::getUCTurma() {
    return ucturma;
}

void UCTurma::setUCTurma(pair<string, string> ucturma) {
    this->ucturma = ucturma;
}

bool UCTurma::operator<(const UCTurma &uct) const {
    return ucturma.first < uct.ucturma.first;
}
