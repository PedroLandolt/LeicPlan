#include "../headers/Vaga.h"


Vaga::Vaga() {}

Vaga::Vaga(string uc, list<pair<string, int>> vagas) {
    this->uc = uc;
    this->vagas = vagas;
}

list<pair<string,int>>& Vaga::getVagas() {
    return vagas;
}

string Vaga::getUC() {
    return uc;
}

void Vaga::setVagas(list<pair<string,int>> vagas) {
    this->vagas = vagas;
}

void Vaga::setUC(string uc) {
    this->uc = uc;
}
