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



void GestaoHorario::lerFichEst(vector<Estudante> &estudantes/*string nomeFich*/) {


    ifstream file;

    file.open("../data/students_classes.csv");
    string line;

    getline(file, line); //para ignorar a primeira linha

    Estudante estudanteAtual;

    pair<int, string> currentEstudante;

    while (getline(file, line)) {
        stringstream ss(line);
        string idEstudante, nomeEstudante, uc, turma;

        list<UCTurma> inscrito;
        getline(ss, idEstudante, ',');
        getline(ss, nomeEstudante, ',');
        getline(ss, uc, ',');
        getline(ss, turma, ',');
        //generate turma

        if (currentEstudante.second != nomeEstudante) {
            pair<int, string> estudante = make_pair(stoi(idEstudante), nomeEstudante);
            estudantes.push_back(estudanteAtual);
            estudanteAtual = Estudante(estudante, inscrito);
        }

        currentEstudante = make_pair(stoi(idEstudante), nomeEstudante);

        pair<string, string> ucturma = make_pair(uc, turma);
        UCTurma ucturma1(ucturma);

        estudanteAtual.getEstudanteInscrito().push_back(ucturma1);
    }

    estudantes.push_back(estudanteAtual);
    estudantes.erase(estudantes.begin());

    file.close();

    /*
     *
     * mario
    ifstream file;
    file.open("../data/students_classes.csv");
    string line;

    getline(file, line); //para ignorar a primeira linha

    while (getline(file, line)) { // lê uma linha do ficheiro para line
        stringstream ss(line);    // cria um stringstream para a linha
        string idEstudante, nomeEstudante, uc, turma;
        list<UCTurma> inscrito;
        getline(ss, idEstudante, ',');    // lê conteúdo do stream até à ',' e guarda em idEstudante
        getline(ss, nomeEstudante, ',');  // lê conteúdo do stream até à ',' e guarda em nomeEstudante
        getline(ss, uc, ',');             // lê conteúdo do stream até à ',' e guarda em uc
        getline(ss, turma, ',');          // lê conteúdo do stream até à ',' e guarda em turma
        cout << idEstudante << "|" << nomeEstudante << "|" << uc << "|" << turma << endl;
    }
    */

    /*
    ifstream file;
    file.open("../data/students_classes.csv");
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string idEstudante, nomeEstudante, uc, turma;
        list<UCTurma> inscrito;
        getline(ss, idEstudante, ',');
        getline(ss, nomeEstudante, ',');
        while(getline(ss, idEstudante, ',')){
            getline(ss, uc, ',');
            getline(ss, turma, ',');
            pair<string, string> ucturma = make_pair(uc, turma);
            UCTurma ucturma1(ucturma);
            inscrito.push_back(ucturma1);
        }
        pair<int, string> estudante = make_pair(stoi(idEstudante), nomeEstudante);
        Estudante estudante1(estudante, inscrito);
        estudantes.push_back(estudante1);
    }
    file.close();
*/
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

