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

    static bool sobreposicao(Pedido pedido , vector<Slot> slots);

    static bool equilibrio(Pedido pedido , vector<Vaga> vagas);

    void clear();
    void wait();

    queue<Pedido> getPedidos();

    void guardar(Pedido pedido);

    void printPedido(Pedido prt_pedido);

    static bool checkInteiro(const string& x);

    static bool checkUC(const string& x, const vector<UCTurma>& ucturma);

    static bool checkTurma(const string& x, const vector<UCTurma>& ucturma);

    static bool checkEstudante(const string& x, const vector<Estudante>& estudantes);



    
private:

    vector<Estudante> estudantes;
    queue<Pedido> pedidos;



};


#endif //AED_PROJETO_GESTAOHORARIO_H
