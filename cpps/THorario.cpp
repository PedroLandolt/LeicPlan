#include "../headers/THorario.h"


THorario::THorario() {}

THorario::THorario(pair<string,string> ucturma, list<Slot> horaUCTurma) {
    this->ucturma = ucturma;
    this->horaUCTurma = horaUCTurma;
}

void THorario::setUcTurma(pair<string,string> ucturma) {
    this->ucturma = ucturma;
}

void THorario::setHoraUCTurma(list<Slot> horaUCTurma) {
    this->horaUCTurma = horaUCTurma;
}

pair<string,string> THorario::getUcTurma() {
    return ucturma;
}

list<Slot> THorario::getHoraUCTurma() {
    return horaUCTurma;
}

bool THorario::operator<(const THorario &th) const {
    return ucturma.first < th.ucturma.first;
}
