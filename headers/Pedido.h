//
// Created by pland on 28/10/2022.
//

#ifndef AED_PROJETO_PEDIDO_H
#define AED_PROJETO_PEDIDO_H

#include "Sort.h"

class Pedido {
    public:

        Pedido(Estudante estudante, UCTurma turma);

        auto getEstudante();

        auto getTurma();

        void setEstudante(Estudante estudante);

        void setTurma(UCTurma turma);


    private:
        Estudante estudante;
        UCTurma turma;
};


#endif //AED_PROJETO_PEDIDO_H
