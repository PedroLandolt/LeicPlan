//
// Created by pland on 28/10/2022.
//

#include "../headers/Slot.h"

/**
 * Aqui vamos guardar todos os diaSemana em que ocorre a UC
 *                             horaInicio da UC
 *                             horaFim da UC
 *                             tipo de UC (T, TP ou PL)
 */

//constructor
Slot::Slot() {}

Slot::Slot(string diaSemana, pair<float,float> hora, string tipo) {
    this->diaSemana = diaSemana;
    this->hora = hora;
    this->tipo = tipo;
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

string Slot::getDiaSemana() {
    return diaSemana;
}

pair<float,float> Slot::getHora() {
    return hora;
}

string Slot::getTipo() {
    return tipo;
}
