//
// Created by pland on 28/10/2022.
//

//include functions
#include <iostream>

//include headers

#include "../headers/GestaoHorario.h"

//include cpps

#include "THorario.cpp"
#include "Estudante.cpp"
#include "Pedido.cpp"



/**
 * vamos ter de ter um set <Estudante> estudantes; para ir buscar toda a info dos estudantes
 *                  um vector <THorario> horarios; para ir buscar o horarios das turmas
 *                  um queue <Pedido> pedidos; para dar queue aos pedidos de mudança de turma
 */

auto GestaoHorario::lerFichEst(string nomeFich) {
    
    if(nomeFich == "students_classes"){
        ifstream file;
        file.open(string("../data/" + nomeFich + ".csv").c_str());
        string line;
        set<Estudante> estudantes;
        while (getline(file, line)) {
            stringstream ss(line);
            string idEstudante, nomeEstudante, UC, Turma;
            list<UCTurma> inscrito;
            getline(ss, idEstudante, ',');
            getline(ss, nomeEstudante, ',');
            while(getline(ss, idEstudante, ',') && getline(ss, nomeEstudante, ',')){
                getline(ss, UC, ',');
                getline(ss, Turma, ',');
                pair<string, string> ucturma = make_pair(UC, Turma);
                UCTurma ucturma1(ucturma);
                inscrito.push_back(ucturma1);
            }
            pair<int, string> estudante = make_pair(stoi(idEstudante), nomeEstudante);
            Estudante estudante1(estudante, inscrito);
            estudantes.insert(estudante1);
        }
        file.close();

        

        return estudantes;
    }
    else if(nomeFich == "classes"){
        ifstream file;
        file.open(string("../data/" + nomeFich + ".csv").c_str());
        string line;
    }
    else if(nomeFich == "classes_per_uc"){
        ifstream file;
        file.open(string("../data/" + nomeFich + ".csv").c_str());
        string line;
    }
    
    
}

void GestaoHorario::pedidos() {

}

void GestaoHorario::guardar() {

}

void GestaoHorario::processsar() {

}

void GestaoHorario::listagem() {

}

auto GestaoHorario::getEstudante(){
    Estudante est;
    return est.getEstudante();
};

