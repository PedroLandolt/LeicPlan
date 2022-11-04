#include "../headers/Slot.h"


Slot::Slot() {}

Slot::Slot(string diaSemana, pair<float,float> hora, string tipo) {
    this->diaSemana = diaSemana;
    this->hora = hora;
    this->tipo = tipo;
}

Slot::Slot(string diaSemana, pair<float,float> hora, string tipo, pair<string,string> ucturma) {
    this->diaSemana = diaSemana;
    this->hora = hora;
    this->tipo = tipo;
    this->ucturma = ucturma;
}

void Slot::setDiaSemana(string diaSemana) {
    this->diaSemana = diaSemana;
}

void Slot::setHora(pair<float,float> hora) {
    this->hora = hora;
}

void Slot::setTipo(string tipo) {
    this->tipo = tipo;
}

void Slot::setUcTurma(pair<string,string> ucturma) {
    this->ucturma = ucturma;
}

string Slot::getDiaSemana() {
    return diaSemana;
}

pair<float,float> Slot::getHora() {
    return hora;
}

string Slot::getTipo() {
    return tipo;
}

pair<string,string> Slot::getUcTurma() {
    return ucturma;
}

bool Slot::compareSlot(Slot s1, Slot s2) {
    map<string, int> mapDiaSemana = {{"Monday", 1}, {"Tuesday", 2}, {"Wednesday", 3}, {"Thursday", 4}, {"Friday", 5}};
    if(mapDiaSemana[s1.getDiaSemana()] < mapDiaSemana[s2.getDiaSemana()]) {
        return true;
    } else if(mapDiaSemana[s1.getDiaSemana()] == mapDiaSemana[s2.getDiaSemana()]) {
        if(s1.getHora().first < s2.getHora().first) {
            return true;
        } else if(s1.getHora().first == s2.getHora().first) {
            if(s1.getHora().second < s2.getHora().second) {
                return true;
            }
        }
    }
    return false;
}

void Slot::sortSlots(vector<Slot> &slots) {
    sort(slots.begin(), slots.end(), compareSlot);
}

void Slot::printSlot(vector<Slot>& slots) {

    sort(slots.begin(), slots.end(), compareSlot);

    cout << "|||||||||||||||||||||||||||||||||||||||" << endl;
    cout << endl;

    for(auto & slot : slots) {

        cout << " Dia da Semana: " << slot.getDiaSemana() << endl
        << " - Hora Inicio: " << slot.getHora().first << endl << " - Hora Fim: " << slot.getHora().first+slot.getHora().second << endl << " - Tipo: " << slot.getTipo() << endl
        << " UC: " << slot.getUcTurma().first << " | Turma: " << slot.getUcTurma().second << endl;
        cout << endl;
        cout << "|||||||||||||||||||||||||||||||||||||||" << endl;
        cout << endl;
    }
}
