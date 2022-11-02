//
// Created by pland on 28/10/2022.
//

#ifndef AED_PROJETO_THORARIO_H
#define AED_PROJETO_THORARIO_H

#include "Slot.h"

class THorario {

public:

    THorario();

    THorario(pair<string,string> ucturma, list<Slot> horaUCTurma);

    void setUcTurma(pair<string,string> ucturma);

    void setHoraUCTurma(list<Slot> horaUCTurma);

    pair<string,string> getUcTurma();

    list<Slot> getHoraUCTurma();

    bool operator<(const THorario &th) const;


private:

    pair<string,string> ucturma;
    list<Slot> horaUCTurma;

};

#endif //AED_PROJETO_THORARIO_H
