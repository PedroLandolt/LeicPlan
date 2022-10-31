//
// Created by pland on 28/10/2022.
//

#ifndef AED_PROJETO_ESTUDANTE_H
#define AED_PROJETO_ESTUDANTE_H



#include "UCTurma.h"

class Estudante {
    public:

        Estudante();

        Estudante(pair<int, string> estudante, list<UCTurma> inscrito);

        auto getEstudante();

        pair<int,string> getEstudantePair();

        auto getEstudanteInscrito();


        void setEstudante(pair<int, string> estudante, list<UCTurma> inscrito);

        void setEstudantePair(pair<int, string> estudante);

        void setEstudanteInscrito(list<UCTurma> inscrito);


    private:

        pair<int,string> estudante; //idEstudante, nomeEstudante
        list<UCTurma> inscrito; //lista de UC/Turma em que esta inscrito


};


#endif //AED_PROJETO_ESTUDANTE_H
