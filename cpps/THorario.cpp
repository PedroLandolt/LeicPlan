//
// Created by pland on 28/10/2022.
//

#include "../headers/THorario.h"

/**
 * Aqui vamos guardar todos os codUC
 *                             codTurma (estes codUC codTurma não estão ligados a estudante)
 *                             lista <Slot> horaUCTurma; onde vamos guardar quando começa e acaba cada aula.
 */

//constructor
THorario::THorario() {}

THorario::THorario(pair<string,string> ucturma, list<Slot> horaUCTurma) {
    this->ucturma = ucturma;
    this->horaUCTurma = horaUCTurma;
}

//getters and setters
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

//operator overload
bool THorario::operator<(const THorario &th) const {
    return ucturma.first < th.ucturma.first;
}