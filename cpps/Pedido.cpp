//
// Created by pland on 28/10/2022.
//

#include "../headers/Pedido.h"

/**
 * Aqui vamos ter de guardar os pedidos e processar os pedidos de mudança de turma
 */

Pedido::Pedido(Estudante estudante, UCTurma turma){
    this->estudante = estudante;
    this->turma = turma;
}

auto Pedido::getEstudante() {
    return this->estudante;
}

auto Pedido::getTurma() {
    return this->turma;
}

void Pedido::setEstudante(Estudante estudante) {
    this->estudante = estudante;
}

void Pedido::setTurma(UCTurma turma) {
    this->turma = turma;
}



