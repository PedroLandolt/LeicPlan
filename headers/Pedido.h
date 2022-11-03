//
// Created by pland on 28/10/2022.
//

#ifndef AED_PROJETO_PEDIDO_H
#define AED_PROJETO_PEDIDO_H

#include "Sort.h"

class Pedido {
    public:

        Pedido();

        Pedido(Estudante estudante, UCTurma turma, string turma_atual);

        Estudante getEstudante();

        UCTurma getUCTurma();

        string getTurmaAtual();

        void setEstudante(Estudante estudante);

        void setUCTurma(UCTurma turma);

        void setTurmaAtual(string turma_atual);


    private:
        Estudante estudante;
        UCTurma turma;
        string turma_atual;
};


#endif //AED_PROJETO_PEDIDO_H
