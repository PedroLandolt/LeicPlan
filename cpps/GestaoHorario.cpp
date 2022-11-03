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



void GestaoHorario::lerFichEst(vector<Estudante> &estudantes) {


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
}

//Le ficheiro classes.csv
void GestaoHorario::lerFichHorario(vector<THorario> &horarios) {

    ifstream file;
    file.open("../data/classes.csv");
    string line;

    getline(file, line); //para ignorar a primeira linha

    THorario horarioAtual;

    vector<pair<pair<string,string>,Slot>> temp;

    pair<string, string> currentUcTurma;

    while (getline(file, line)) {
        stringstream ss(line);
        string uc, turma, dia, horaInicio, tempoAula, tipo;

        getline(ss, turma, ',');
        getline(ss, uc, ',');
        getline(ss, dia, ',');
        getline(ss, horaInicio, ',');
        getline(ss, tempoAula, ',');
        getline(ss, tipo, ',');

        pair<string, string> ucturma = make_pair(uc, turma);

        pair<float,float> duracao = make_pair(stof(horaInicio), stof(tempoAula));

        Slot slots(dia, duracao, tipo);

        pair<pair<string,string>,Slot> ucturmaslot = make_pair(ucturma,slots);

        temp.push_back(ucturmaslot);
    }

    vector<UCTurma> ucturmas_temp;
    lerFichUCTurma(ucturmas_temp);

    for(auto x : ucturmas_temp){
        list<Slot> slots;
        for(auto y : temp){

            if(x.getUCTurma() == y.first){
                slots.push_back(y.second);
            }
        }
        horarioAtual = THorario(x.getUCTurma(),slots);
        horarios.push_back(horarioAtual);
    }
    horarios.push_back(horarioAtual);
    horarios.erase(horarios.end());

    file.close();
}


//Ler ficheiro classes_per_uc.csv
void GestaoHorario::lerFichUCTurma(vector<UCTurma> &ucturma) {

    ifstream file;
    file.open("../data/classes_per_uc.csv");
    string line;

    getline(file, line); //para ignorar a primeira linha

    while (getline(file, line)) {
        stringstream ss(line);
        string uc, turma;

        getline(ss, uc, ',');
        getline(ss, turma, ',');

        pair<string, string> ucturma1 = make_pair(uc, turma);

        UCTurma ucturma2(ucturma1);

        ucturma.push_back(ucturma2);
    }
}

void GestaoHorario::lerFichSlot(vector<Slot> &slot) {

        ifstream file;
        file.open("../data/classes.csv");
        string line;

        getline(file, line); //para ignorar a primeira linha

        while (getline(file, line)) {
            stringstream ss(line);
            string uc, turma, dia, horaInicio, tempoAula, tipo;

            getline(ss, turma, ',');
            getline(ss, uc, ',');
            getline(ss, dia, ',');
            getline(ss, horaInicio, ',');
            getline(ss, tempoAula, ',');
            getline(ss, tipo, ',');

            pair<string, string> ucturma = make_pair(uc, turma);

            pair<float,float> duracao = make_pair(stof(horaInicio), stof(tempoAula));

            Slot slots(dia, duracao, tipo, ucturma);

            slot.push_back(slots);
        }
        file.close();
}




void GestaoHorario::clear() {
    for (int i = 0; i < 100; i++) {
        cout << endl;
    }
}


/*
else if(nomeFich == "classes_per_uc"){
    ifstream file;
    file.open(string("../data/" + nomeFich + ".csv").c_str());
    string line;
}
*/
   // return estudantes;
    


queue<Pedido> GestaoHorario::getPedidos() {
    return pedidos;
}

void GestaoHorario::guardar(Pedido pedido) {
    pedidos.push(pedido);
}

void GestaoHorario::printPedido(Pedido prt_pedido) {

    cout << " UP: " << prt_pedido.getEstudante().getEstudantePair().first  << " | Nome: " << prt_pedido.getEstudante().getEstudantePair().second << endl;

    cout << " Trocar da turma " /*turma atual*/ << prt_pedido.getTurmaAtual() << " -> para a turma " /*qual quer mudar */ << prt_pedido.getUCTurma().getUCTurma().second << endl;
    cout << " na UC: " << prt_pedido.getUCTurma().getUCTurma().first << endl;
    cout << endl;
}
/*
void GestaoHorario::processsar() {

}

void GestaoHorario::listagem() {

}
*/
//auto GestaoHorario::getEstudante(){
//    return estudante;

