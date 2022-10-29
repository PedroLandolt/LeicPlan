//
// Created by pland on 28/10/2022.
//


//include functions

#include <fstream>
#include <sstream>
#include <set>

//include headers

#include "../headers/Estudante.h"

//include cpps

#include "UCTurma.cpp"


/**
 * Aqui vamos guardar todos os idEstudante (ex.: up2323****)
 *                             nomeEstudante
 *                             lista <UCTurma> turma; onde vamos guardar em que UC e Turma em que estudante está
 */


//constructor
Estudante::Estudante(pair<int, string> estudante, list<UCTurma> inscrito) {
    this->estudante = estudante;
    this->inscrito = inscrito;
}

//getters and setters
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

auto Estudante::getEstudantePair(){
    return estudante;
}

auto Estudante::getEstudanteInscrito(){
    return inscrito;
}

auto Estudante::getEstudante(){
    return estudante, inscrito;
}

