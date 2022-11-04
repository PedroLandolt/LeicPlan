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

void GestaoHorario::prepararVagas(vector<Vaga> &vagas) {

    const int cap = 30;
    int temp = cap;

    vector<UCTurma> vg_ucturma;
    lerFichUCTurma(vg_ucturma);

    Vaga vaga;

    UCTurma current_ucturma;

    for(auto x : vg_ucturma){

        list<pair<string,int>> l_vaga;

        if (current_ucturma.getUCTurma().first != x.getUCTurma().first) {
            vagas.push_back(vaga);
            vaga = Vaga(x.getUCTurma().first, l_vaga);
        }

        current_ucturma = x;

        pair<string,int> vagas_temp = make_pair(x.getUCTurma().second, temp);
        vaga.getVagas().push_back(vagas_temp);
    }

    vagas.push_back(vaga);
    vagas.erase(vagas.begin());
}

void GestaoHorario::ajustarVagas(vector<Vaga> &vagas) {

    vector<pair<string, string>> ucturmas;

    ifstream file;

    file.open("../data/students_classes.csv");
    string line;

    getline(file, line); //para ignorar a primeira linha

    while (getline(file, line)) {
        stringstream ss(line);
        string uc, turma;
        string null1, null2;

        getline(ss, null1, ',');
        getline(ss, null2, ',');
        getline(ss, uc, ',');
        getline(ss, turma, ',');
        //generate turma

        pair<string, string> ucturma = make_pair(uc, turma);

        ucturmas.push_back(ucturma);
    }
    file.close();

    for(const auto& x : ucturmas){
        for(auto& y : vagas){
            if(x.first == y.getUC()){
                for(auto& z : y.getVagas()){
                    if(x.second == z.first){
                        z.second--;
                    }
                }
            }
        }
    }
}

void GestaoHorario::clear() {
    for (int i = 0; i < 100; i++) {
        cout << endl;
    }
}

void GestaoHorario::wait() {
    cout << endl;
    int c; do c = getchar(); while ((c != '\n') && (c != EOF));
    cout << " Press ENTER to continue...";
    cout << endl;
    do{ c = getchar(); }while ((c != '\n') && (c != EOF));
}

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

bool GestaoHorario::sobreposicao(Pedido pedido, vector<Slot> slots) {

    Estudante estudante = pedido.getEstudante();

    list<UCTurma> ucturmas = estudante.getEstudanteInscrito();

    UCTurma turma_pedido = pedido.getUCTurma();

    list<UCTurma> ucturma_temp;

    for(auto x : ucturmas){
        if(x.getUCTurma().first == turma_pedido.getUCTurma().first){
            ucturma_temp.push_back(turma_pedido);
        }
        else{
            ucturma_temp.push_back(x);
        }
    }

    // 2º parte
    vector<Slot> slots_temp;
    for(auto x : ucturma_temp){
        for(auto y : slots){
            if(x.getUCTurma() == y.getUcTurma()){
                slots_temp.push_back(y);
            }
        }
    }

    Slot slot;
    slot.sortSlots(slots_temp);

    for(int i = 0; i < slots_temp.size(); i++){
        if(slots_temp[i].getDiaSemana() == slots_temp[i+1].getDiaSemana()){
            if(slots_temp[i].getHora().first + slots_temp[i].getHora().second > slots_temp[i+1].getHora().first){
                if(slots_temp[i].getTipo() != "T" && slots_temp[i+1].getTipo() != "T"){
                    return true;
                }
            }
        }
    }
    return false;
}

bool GestaoHorario::equilibrio(Pedido pedido, vector<Vaga> vagas) {

        UCTurma ucturma = pedido.getUCTurma();

        int min = INT_MAX;
        int diff = 0;


        for(auto x : vagas){
            if(x.getUC() == ucturma.getUCTurma().first){
                for(const auto& y : x.getVagas()){
                    if(y.second < min){
                        min = y.second;
                    }
                }
            }
        }


        for(auto x : vagas){
            if(x.getUC() == ucturma.getUCTurma().first){
                for(const auto& y : x.getVagas()){
                    if(y.first == ucturma.getUCTurma().second){
                        if(y.second - min < 4){
                            return true;
                        }
                    }
                }
            }
        }
        return false;
}

bool GestaoHorario::checkInteiro(const string& x) {

    for(char i : x){
        if(!isdigit(i)){
            return false;
        }
    }
    return true;
}

bool GestaoHorario::checkUC(const string& x, const vector<UCTurma>& ucts) {


    for(auto a : x){
        if(a == ' '){
            return false;
        }
    }

    for(auto i : ucts){
        if(i.getUCTurma().first == x){
            return true;
        }
    }
    return false;
}

bool GestaoHorario::checkTurma(const string& x, const vector<UCTurma>& ucts) {

    for(auto a : x){
        if(a == ' '){
            return false;
        }
    }

    for(auto i : ucts){
        if(i.getUCTurma().second == x){
            return true;
        }
    }
    return false;
}

