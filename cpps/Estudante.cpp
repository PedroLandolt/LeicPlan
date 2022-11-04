#include "../headers/Estudante.h"


Estudante::Estudante() {}

Estudante::Estudante(pair<int, string> estudante, list<UCTurma> inscrito) {
    this->estudante = estudante;
    this->inscrito = inscrito;
}

void Estudante::setEstudante(pair<int, string> estudante, list<UCTurma> inscrito) {
    this->estudante = estudante;
    this->inscrito = inscrito;
}

void Estudante::setEstudanteInscrito(list<UCTurma> inscrito){
    this->inscrito = inscrito;
};

void Estudante::setEstudantePair(pair<int, string> estudante){
    this->estudante = estudante;
};

pair<int,string> Estudante::getEstudantePair(){
    return estudante;
}

list<UCTurma>& Estudante::getEstudanteInscrito(){
    return inscrito;
}

auto Estudante::getEstudante(){
    return estudante, inscrito;
}

bool Estudante::operator<(const Estudante &e) const {
    return estudante.first < e.estudante.first;
}
