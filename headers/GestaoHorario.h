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

    void prepararVagas(vector<Vaga> &vagas);

    void ajustarVagas(vector<Vaga> &vagas);

    bool sobreposicao(Pedido pedido , vector<Slot> slots);

    bool equilibrio(Pedido pedido , vector<Vaga> vagas);

    void processarPedido(Pedido pedido);

    void clear();
    void wait();

    queue<Pedido> getPedidos();

    void guardar(Pedido pedido);

    void printPedido(Pedido prt_pedido);



    
private:

    vector<Estudante> estudantes;
    queue<Pedido> pedidos;



};


#endif //AED_PROJETO_GESTAOHORARIO_H
