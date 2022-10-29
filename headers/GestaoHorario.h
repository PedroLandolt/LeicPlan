//
// Created by pland on 28/10/2022.
//

#ifndef AED_PROJETO_GESTAOHORARIO_H
#define AED_PROJETO_GESTAOHORARIO_H


#include <string>
#include <vector>
#include <iostream>
#include <utility>
#include <iterator>

using namespace std;

class GestaoHorario {

public:

    auto lerFichEst(string nomeFich);

    void pedidos();

    void guardar();

    void processsar();

    void listagem();

    void getEstudante();

private:


};


#endif //AED_PROJETO_GESTAOHORARIO_H
