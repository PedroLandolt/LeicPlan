//
// Created by pland on 28/10/2022.
//

#include "../headers/Pedido.h"

/**
 * Aqui vamos ter de guardar os pedidos e processar os pedidos de mudança de turma
 */

Pedido::Pedido() {}

Pedido::Pedido(Estudante estudante, UCTurma turma, string turma_atual) {
    this->estudante = estudante;
    this->turma = turma;
    this->turma_atual = turma_atual;
}

Estudante Pedido::getEstudante() {
    return this->estudante;
}

UCTurma Pedido::getUCTurma() {
    return this->turma;
}

string Pedido::getTurmaAtual() {
    return this->turma_atual;
}

void Pedido::setEstudante(Estudante estudante) {
    this->estudante = estudante;
}

void Pedido::setUCTurma(UCTurma turma) {
    this->turma = turma;
}

void Pedido::setTurmaAtual(string turma_atual) {
    this->turma_atual = turma_atual;
}




