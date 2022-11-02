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
void GestaoHorario::loadVaga(vector<Estudante> estudantes, list<Vaga> &vagas) {

    string turma1_1 = "1LEIC01", turma1_2 = "1LEIC02", turma1_3 = "1LEIC03", turma1_4 = "1LEIC04", turma1_5 = "1LEIC05", turma1_6 = "1LEIC06", turma1_7 = "1LEIC07", turma1_8 = "1LEIC08", turma1_9 = "1LEIC09", turma1_10 = "1LEIC10", turma1_11 = "1LEIC11", turma1_12 = "1LEIC12", turma1_13 = "1LEIC13", turma1_14 = "1LEIC14", turma1_15 = "1LEIC15", turma1_16 = "1LEIC16";
    string turma2_1 = "2LEIC01", turma2_2 = "2LEIC02", turma2_3 = "2LEIC03", turma2_4 = "2LEIC04", turma2_5 = "2LEIC05", turma2_6 = "2LEIC06", turma2_7 = "2LEIC07", turma2_8 = "2LEIC08", turma2_9 = "2LEIC09", turma2_10 = "2LEIC10", turma2_11 = "2LEIC11", turma2_12 = "2LEIC12", turma2_13 = "2LEIC13", turma2_14 = "2LEIC14", turma2_15 = "2LEIC15", turma2_16 = "2LEIC16";
    string turma3_1 = "3LEIC01", turma3_2 = "3LEIC02", turma3_3 = "3LEIC03", turma3_4 = "3LEIC04", turma3_5 = "3LEIC05", turma3_6 = "3LEIC06", turma3_7 = "3LEIC07", turma3_8 = "3LEIC08", turma3_9 = "3LEIC09", turma3_10 = "3LEIC10", turma3_11 = "3LEIC11", turma3_12 = "3LEIC12", turma3_13 = "3LEIC13", turma3_14 = "3LEIC14", turma3_15 = "3LEIC15", turma3_16 = "3LEIC16";

    int vagas1_1 = 0, vagas1_2 = 0, vagas1_3 = 0, vagas1_4 = 0, vagas1_5 = 0, vagas1_6 = 0, vagas1_7 = 0, vagas1_8 = 0, vagas1_9 = 0, vagas1_10 = 0, vagas1_11 = 0, vagas1_12 = 0, vagas1_13 = 0, vagas1_14 = 0, vagas1_15 = 0, vagas1_16 = 0;
    int vagas2_1 = 0, vagas2_2 = 0, vagas2_3 = 0, vagas2_4 = 0, vagas2_5 = 0, vagas2_6 = 0, vagas2_7 = 0, vagas2_8 = 0, vagas2_9 = 0, vagas2_10 = 0, vagas2_11 = 0, vagas2_12 = 0, vagas2_13 = 0, vagas2_14 = 0, vagas2_15 = 0, vagas2_16 = 0;
    int vagas3_1 = 0, vagas3_2 = 0, vagas3_3 = 0, vagas3_4 = 0, vagas3_5 = 0, vagas3_6 = 0, vagas3_7 = 0, vagas3_8 = 0, vagas3_9 = 0, vagas3_10 = 0, vagas3_11 = 0, vagas3_12 = 0, vagas3_13 = 0, vagas3_14 = 0, vagas3_15 = 0, vagas3_16 = 0;

    for(auto x: estudantes){
        for(auto y : x.getEstudanteInscrito()){
            if(y.getUCTurma().second == turma1_1){
                vagas1_1++;
            }
            if(y.getUCTurma().second == turma1_2){
                vagas1_2++;
            }
            if(y.getUCTurma().second == turma1_3){
                vagas1_3++;
            }
            if(y.getUCTurma().second == turma1_4){
                vagas1_4++;
            }
            if(y.getUCTurma().second == turma1_5){
                vagas1_5++;
            }
            if(y.getUCTurma().second == turma1_6){
                vagas1_6++;
            }
            if(y.getUCTurma().second == turma1_7){
                vagas1_7++;
            }
            if(y.getUCTurma().second == turma1_8){
                vagas1_8++;
            }
            if(y.getUCTurma().second == turma1_9){
                vagas1_9++;
            }
            if(y.getUCTurma().second == turma1_10){
                vagas1_10++;
            }
            if(y.getUCTurma().second == turma1_11){
                vagas1_11++;
            }
            if(y.getUCTurma().second == turma1_12){
                vagas1_12++;
            }
            if(y.getUCTurma().second == turma1_13){
                vagas1_13++;
            }
            if(y.getUCTurma().second == turma1_14){
                vagas1_14++;
            }
            if(y.getUCTurma().second == turma1_15){
                vagas1_15++;
            }
            if(y.getUCTurma().second == turma1_16){
                vagas1_16++;
            }
            if(y.getUCTurma().second == turma2_1){
                vagas2_1++;
            }
            if(y.getUCTurma().second == turma2_2){
                vagas2_2++;
            }
            if(y.getUCTurma().second == turma2_3){
                vagas2_3++;
            }
            if(y.getUCTurma().second == turma2_4){
                vagas2_4++;
            }
            if(y.getUCTurma().second == turma2_5){
                vagas2_5++;
            }
            if(y.getUCTurma().second == turma2_6){
                vagas2_6++;
            }
            if(y.getUCTurma().second == turma2_7){
                vagas2_7++;
            }
            if(y.getUCTurma().second == turma2_8){
                vagas2_8++;
            }
            if(y.getUCTurma().second == turma2_9){
                vagas2_9++;
            }
            if(y.getUCTurma().second == turma2_10){
                vagas2_10++;
            }
            if(y.getUCTurma().second == turma2_11){
                vagas2_11++;
            }
            if(y.getUCTurma().second == turma2_12){
                vagas2_12++;
            }
            if(y.getUCTurma().second == turma2_13){
                vagas2_13++;
            }
            if(y.getUCTurma().second == turma2_14){
                vagas2_14++;
            }
            if(y.getUCTurma().second == turma2_15){
                vagas2_15++;
            }
            if(y.getUCTurma().second == turma2_16){
                vagas2_16++;
            }
            if(y.getUCTurma().second == turma3_1){
                vagas3_1++;
            }
            if(y.getUCTurma().second == turma3_2){
                vagas3_2++;
            }
            if(y.getUCTurma().second == turma3_3){
                vagas3_3++;
            }
            if(y.getUCTurma().second == turma3_4){
                vagas3_4++;
            }
            if(y.getUCTurma().second == turma3_5){
                vagas3_5++;
            }
            if(y.getUCTurma().second == turma3_6){
                vagas3_6++;
            }
            if(y.getUCTurma().second == turma3_7){
                vagas3_7++;
            }
            if(y.getUCTurma().second == turma3_8){
                vagas3_8++;
            }
            if(y.getUCTurma().second == turma3_9){
                vagas3_9++;
            }
            if(y.getUCTurma().second == turma3_10){
                vagas3_10++;
            }
            if(y.getUCTurma().second == turma3_11){
                vagas3_11++;
            }
            if(y.getUCTurma().second == turma3_12){
                vagas3_12++;
            }
            if(y.getUCTurma().second == turma3_13){
                vagas3_13++;
            }
            if(y.getUCTurma().second == turma3_14){
                vagas3_14++;
            }
            if(y.getUCTurma().second == turma3_15){
                vagas3_15++;
            }
            if(y.getUCTurma().second == turma3_16){
                vagas3_16++;
            }
        }
    }

    pair<string,int> p_turma1_1 = make_pair("1LEIC01", vagas1_1);
    pair<string,int> p_turma1_2 = make_pair("1LEIC02", vagas1_2);
    pair<string,int> p_turma1_3 = make_pair("1LEIC03", vagas1_3);
    pair<string,int> p_turma1_4 = make_pair("1LEIC04", vagas1_4);
    pair<string,int> p_turma1_5 = make_pair("1LEIC05", vagas1_5);
    pair<string,int> p_turma1_6 = make_pair("1LEIC06", vagas1_6);
    pair<string,int> p_turma1_7 = make_pair("1LEIC07", vagas1_7);
    pair<string,int> p_turma1_8 = make_pair("1LEIC08", vagas1_8);
    pair<string,int> p_turma1_9 = make_pair("1LEIC09", vagas1_9);
    pair<string,int> p_turma1_10 = make_pair("1LEIC10", vagas1_10);
    pair<string,int> p_turma1_11 = make_pair("1LEIC11", vagas1_11);
    pair<string,int> p_turma1_12 = make_pair("1LEIC12", vagas1_12);
    pair<string,int> p_turma1_13 = make_pair("1LEIC13", vagas1_13);
    pair<string,int> p_turma1_14 = make_pair("1LEIC14", vagas1_14);
    pair<string,int> p_turma1_15 = make_pair("1LEIC15", vagas1_15);
    pair<string,int> p_turma1_16 = make_pair("1LEIC16", vagas1_16);
    pair<string,int> p_turma2_1 = make_pair("2LEIC01", vagas2_1);
    pair<string,int> p_turma2_2 = make_pair("2LEIC02", vagas2_2);
    pair<string,int> p_turma2_3 = make_pair("2LEIC03", vagas2_3);
    pair<string,int> p_turma2_4 = make_pair("2LEIC04", vagas2_4);
    pair<string,int> p_turma2_5 = make_pair("2LEIC05", vagas2_5);
    pair<string,int> p_turma2_6 = make_pair("2LEIC06", vagas2_6);
    pair<string,int> p_turma2_7 = make_pair("2LEIC07", vagas2_7);
    pair<string,int> p_turma2_8 = make_pair("2LEIC08", vagas2_8);
    pair<string,int> p_turma2_9 = make_pair("2LEIC09", vagas2_9);
    pair<string,int> p_turma2_10 = make_pair("2LEIC10", vagas2_10);
    pair<string,int> p_turma2_11 = make_pair("2LEIC11", vagas2_11);
    pair<string,int> p_turma2_12 = make_pair("2LEIC12", vagas2_12);
    pair<string,int> p_turma2_13 = make_pair("2LEIC13", vagas2_13);
    pair<string,int> p_turma2_14 = make_pair("2LEIC14", vagas2_14);
    pair<string,int> p_turma2_15 = make_pair("2LEIC15", vagas2_15);
    pair<string,int> p_turma2_16 = make_pair("2LEIC16", vagas2_16);
    pair<string,int> p_turma3_1 = make_pair("3LEIC01", vagas3_1);
    pair<string,int> p_turma3_2 = make_pair("3LEIC02", vagas3_2);
    pair<string,int> p_turma3_3 = make_pair("3LEIC03", vagas3_3);
    pair<string,int> p_turma3_4 = make_pair("3LEIC04", vagas3_4);
    pair<string,int> p_turma3_5 = make_pair("3LEIC05", vagas3_5);
    pair<string,int> p_turma3_6 = make_pair("3LEIC06", vagas3_6);
    pair<string,int> p_turma3_7 = make_pair("3LEIC07", vagas3_7);
    pair<string,int> p_turma3_8 = make_pair("3LEIC08", vagas3_8);
    pair<string,int> p_turma3_9 = make_pair("3LEIC09", vagas3_9);
    pair<string,int> p_turma3_10 = make_pair("3LEIC10", vagas3_10);
    pair<string,int> p_turma3_11 = make_pair("3LEIC11", vagas3_11);
    pair<string,int> p_turma3_12 = make_pair("3LEIC12", vagas3_12);
    pair<string,int> p_turma3_13 = make_pair("3LEIC13", vagas3_13);
    pair<string,int> p_turma3_14 = make_pair("3LEIC14", vagas3_14);
    pair<string,int> p_turma3_15 = make_pair("3LEIC15", vagas3_15);
    pair<string,int> p_turma3_16 = make_pair("3LEIC16", vagas3_16);

    vagas.push_back(p_turma1_1);
    vagas.push_back(p_turma1_2);
    vagas.push_back(p_turma1_3);
    vagas.push_back(p_turma1_4);
    vagas.push_back(p_turma1_5);
    vagas.push_back(p_turma1_6);
    vagas.push_back(p_turma1_7);
    vagas.push_back(p_turma1_8);
    vagas.push_back(p_turma1_9);
    vagas.push_back(p_turma1_10);
    vagas.push_back(p_turma1_11);
    vagas.push_back(p_turma1_12);
    vagas.push_back(p_turma1_13);
    vagas.push_back(p_turma1_14);
    vagas.push_back(p_turma1_15);
    vagas.push_back(p_turma1_16);
    vagas.push_back(p_turma2_1);
    vagas.push_back(p_turma2_2);
    vagas.push_back(p_turma2_3);
    vagas.push_back(p_turma2_4);
    vagas.push_back(p_turma2_5);
    vagas.push_back(p_turma2_6);
    vagas.push_back(p_turma2_7);
    vagas.push_back(p_turma2_8);
    vagas.push_back(p_turma2_9);
    vagas.push_back(p_turma2_10);
    vagas.push_back(p_turma2_11);
    vagas.push_back(p_turma2_12);
    vagas.push_back(p_turma2_13);
    vagas.push_back(p_turma2_14);
    vagas.push_back(p_turma2_15);
    vagas.push_back(p_turma2_16);
    vagas.push_back(p_turma3_1);
    vagas.push_back(p_turma3_2);
    vagas.push_back(p_turma3_3);
    vagas.push_back(p_turma3_4);
    vagas.push_back(p_turma3_5);
    vagas.push_back(p_turma3_6);
    vagas.push_back(p_turma3_7);
    vagas.push_back(p_turma3_8);
    vagas.push_back(p_turma3_9);
    vagas.push_back(p_turma3_10);
    vagas.push_back(p_turma3_11);
    vagas.push_back(p_turma3_12);
    vagas.push_back(p_turma3_13);
    vagas.push_back(p_turma3_14);
    vagas.push_back(p_turma3_15);
    vagas.push_back(p_turma3_16);
}
*/
/*
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

