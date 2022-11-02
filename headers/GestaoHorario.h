//
// Created by pland on 28/10/2022.
//

#ifndef AED_PROJETO_GESTAOHORARIO_H
#define AED_PROJETO_GESTAOHORARIO_H


#include "Pedido.h"


class GestaoHorario {

public:

    void lerFichEst(vector<Estudante> &estudantes);

    void lerFichHorario(vector<THorario> &horario);

    void lerFichUCTurma(vector<UCTurma> &ucturma);

    void lerFichSlot(vector<Slot> &slot);

    void clear();

    //void loadVaga(vector<Estudante> estudantes, list<Vaga> &vagas);

    queue<Pedido> getPedidos();

    void guardar(Pedido pedido);

    void processsar();

    void listagem();

    auto getEstudante();

    
private:

    vector<Estudante> estudantes;
    queue<Pedido> pedidos;



};


#endif //AED_PROJETO_GESTAOHORARIO_H
