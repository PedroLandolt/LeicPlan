//
// Created by pland on 02/11/2022.
//

#include "../headers/Vaga.h"

Vaga::Vaga() {}

Vaga::Vaga(string uc, pair<string, int> vagas) {
    this->uc = uc;
    this->vagas = vagas;
}

pair<string,int> Vaga::getVagas() {
    return vagas;
}

string Vaga::getUC() {
    return uc;
}

void Vaga::setVagas(pair<string,int> vagas) {
    this->vagas = vagas;
}

void Vaga::setUC(string uc) {
    this->uc = uc;
}

//bool Vaga::operator<(const Vaga &v) const {
//    return this->uc < v.uc;
//}