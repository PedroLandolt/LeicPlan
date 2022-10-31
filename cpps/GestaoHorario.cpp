//
// Created by pland on 28/10/2022.
//

//include functions


//include headers

#include "../headers/GestaoHorario.h"

//include cpps



/**
 * vamos ter de ter um set <Estudante> estudantes; para ir buscar toda a info dos estudantes
 *                  um vector <THorario> horarios; para ir buscar o horarios das turmas
 *                  um queue <Pedido> pedidos; para dar queue aos pedidos de mudança de turma
 */



void GestaoHorario::lerFichEst(vector<Estudante> estudantes/*string nomeFich*/) {
    
   //if(nomeFich == "students_classes"){
        ifstream file;
        //file.open(string("../data/" + nomeFich + ".csv").c_str());
        file.open("../data/students_classes.csv");
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string idEstudante, nomeEstudante, UC, Turma;
            list<UCTurma> inscrito;
            getline(ss, idEstudante, ',');
            getline(ss, nomeEstudante, ',');
            while(getline(ss, idEstudante, ',')){
                getline(ss, UC, ',');
                getline(ss, Turma, ',');
                pair<string, string> ucturma = make_pair(UC, Turma);
                UCTurma ucturma1(ucturma);
                inscrito.push_back(ucturma1);
            }
            pair<int, string> estudante = make_pair(stoi(idEstudante), nomeEstudante);
            Estudante estudante1(estudante, inscrito);
            estudantes.push_back(estudante1);
        }
        file.close();

    }
/*else if(nomeFich == "classes"){
    ifstream file;
    file.open(string("../data/" + nomeFich + ".csv").c_str());
    string line;
}
else if(nomeFich == "classes_per_uc"){
    ifstream file;
    file.open(string("../data/" + nomeFich + ".csv").c_str());
    string line;
}
*/
   // return estudantes;
    

/*
queue<Pedido> GestaoHorario::getPedidos() {
    return pedidos;
}

void GestaoHorario::guardar(Pedido pedido) {
    
    pedidos.push(pedido);

}

void GestaoHorario::processsar() {

}

void GestaoHorario::listagem() {

}
*/
//auto GestaoHorario::getEstudante(){
//    return estudante;

