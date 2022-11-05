/*! \file */

/**
 * @brief Ficheiro onde estao implementados todos os diferentes menus e funçoes de print para visualizaçao das listagens e pedidos (a restante documentaçao do ficheiro main.cpp deve ser consultada no proprio ficheiro para mais facil visualizaçao)*/
/** |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||| */


#include "headers/GestaoHorario.h"

int main() {

    //Mudança de cor do output
    system("Color 09");

    cout << " A iniciar o programa..." << endl;

    GestaoHorario gh;
    Sort sorts;

    cout << " A ler o ficheiro students_classes.csv..." << endl;

    vector<Estudante> v_estudantes;
    gh.lerFichEst(v_estudantes);

    struct EstudanteCompare {
        bool operator()(Estudante* lhs, Estudante* rhs) const {
            return lhs->getEstudantePair().first < rhs->getEstudantePair().first;
        }
    };

    set<Estudante*, EstudanteCompare> s_estudantes;

    for(const auto& i : v_estudantes){
        auto *p = new Estudante(i);
        s_estudantes.insert(p);
    }

    cout << " Ficheiro lido com sucesso!" << endl;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    cout << " A ler o ficheiro classes.csv..." << endl;

    vector<THorario> v_horarios;
    gh.lerFichHorario(v_horarios);

    set<THorario> s_horarios(v_horarios.begin(), v_horarios.end());

    vector<Slot> v_slots;
    gh.lerFichSlot(v_slots);

    struct slotCompareTurma {
        bool operator()(Slot* lhs, Slot* rhs) const {
            return lhs->getUcTurma().second < rhs->getUcTurma().second;
        }
    };

    struct slotCompareUc {
        bool operator()(Slot* lhs, Slot* rhs) const {
            return lhs->getUcTurma().first < rhs->getUcTurma().first;
        }
    };

    set<Slot*, slotCompareTurma> s_slots_turma;
    set<Slot*, slotCompareUc> s_slots_uc;

    for(const auto& i : v_slots){
        auto *p = new Slot(i);
        s_slots_turma.insert(p);
        s_slots_uc.insert(p);
    }

    cout << " Ficheiro lido com sucesso!" << endl;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    cout << " A ler o ficheiro classes_per_uc.csv..." << endl;

    vector<UCTurma> v_ucturma;
    gh.lerFichUCTurma(v_ucturma);

    set<UCTurma> s_ucturma(v_ucturma.begin(), v_ucturma.end());


    cout << " Ficheiro lido com sucesso!" << endl;
    cout << " A iniciar o processamento..." << endl;

    struct vagaCompare {
        bool operator()(Vaga* lhs, Vaga* rhs) const {
            return lhs->getUC() < rhs->getUC();
        }
    };

    vector<Vaga> v_vagas;
    gh.prepararVagas(v_vagas);

    set<Vaga*, vagaCompare> s_vagas;

    for(const auto& i : v_vagas){
        auto *p = new Vaga(i);
        s_vagas.insert(p);
    }

    gh.ajustarVagas(v_vagas);

    //Declaraçao das variaveis usadas

    string opcao, opcao1, opcao2, opcao3, opcao_menu;
    int choice;
    string ano_caso5;
    int id_estudante_caso6, id_estudante_caso10;
    string uc_caso2 , uc_caso4, uc_caso8, uc_caso10;
    string turma_caso3, turma_caso4, turma_caso7, turma_caso9, turma_caso10, turma_caso_atual10;
    string nome_estudante_caso6, nome_estudante_caso10;
    pair<string,string> uc_turma_caso4, uc_turma_caso10;
    pair<int,string> estudante_caso6, estudante_caso10, estudante_caso1;
    vector<pair<int,string>> v_estudante_caso2, v_estudante_caso3, v_estudante_caso4, v_estudante_caso5;
    queue<Pedido> q_pedidos = gh.getPedidos();
    Pedido p_temp10;
    Estudante temp_est;


    cout << " A inciar o menu..." << endl;
    cout << endl;


    do{
        /**
         * Menu do programa com as opcoes disponiveis para o utilizador.
         */

        gh.clear();
        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << "||------------------------ MENU -------------------------||" << endl;
        cout << "|| Escolha uma opcao:                                    ||" << endl;
        cout << "||_______________________________________________________||" << endl;
        cout << "||                                                       ||" << endl;
        cout << "||   1 - Listar estudantes                               ||" << endl;
        cout << "||   2 - Listar estudantes inscritos numa UC             ||" << endl;
        cout << "||   3 - Listar estudantes inscritos numa turma          ||" << endl;
        cout << "||   4 - Listar estudantes inscritos numa UC e turma     ||" << endl;
        cout << "||   5 - Listar estudantes incritos num dado ano         ||" << endl;
        cout << "||   6 - Mostrar horario de um estudante                 ||" << endl;
        cout << "||   7 - Mostrar horario de uma turma                    ||" << endl;
        cout << "||   8 - Mostrar horario de uma UC                       ||" << endl;
        cout << "||   9 - Fazer pedidos de mudanca de turma               ||" << endl;
        cout << "||   10 - Informacoes sobre pedidos de mudanca de turma  ||" << endl;
        cout << "||   11 - Processar pedidos de mudanca de turma          ||" << endl;
        cout << "||                                                       ||" << endl;
        cout << "||   0 - Sair                                            ||" << endl;
        cout << "||                                                       ||" << endl;
        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << endl;

        /**
         * Leitura da opcao (input) escolhida pelo utilizador.
         */
        cin >> opcao_menu;

        while(!GestaoHorario::checkInteiro(opcao_menu) || stoi(opcao_menu) < 0 || stoi(opcao_menu) > 11){
            cout << endl;
            cout << " Opcao invalida! Escolha uma opcao valida: ";
            cin >> opcao_menu;
            cout << endl;
        }
        choice = stoi(opcao_menu);

        cout << endl;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        /** Estrutura utillizada para realizar as varias funçoes disponibilizadas no menu. */

        switch(choice){
            case 0:
                /** Opcao para sair do programa. */
                choice = 0;
                break;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        /** Listar Estudantes */
            case 1:
                
                int choice1;
                choice = 1;

                do{
                    /**
                     * Menu para listar estudantes com opcoes de ordenacao.
                     */

                    gh.clear();
                    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
                    cout << "||------------------- LISTAR ESTUDANTES -----------------||" << endl;
                    cout << "|| Escolha uma opcao:                                    ||" << endl;
                    cout << "||_______________________________________________________||" << endl;
                    cout << "||                                                       ||" << endl;
                    cout << "||   1 - Ordenar estudantes por UP crescente             ||" << endl;
                    cout << "||   2 - Ordenar estudantes por UP decrescente           ||" << endl;
                    cout << "||   3 - Ordenar estudantes por nome A-Z                 ||" << endl;
                    cout << "||   4 - Ordenar estudantes por nome Z-A                 ||" << endl;
                    cout << "||                                                       ||" << endl;
                    cout << "||   0 - Back                                            ||" << endl;
                    cout << "||                                                       ||" << endl;
                    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
                    cout << endl;

                    /**
                     * Leitura da opcao escolhida pelo utilizador.
                     */
                    cin >> opcao_menu;

                    while(!GestaoHorario::checkInteiro(opcao_menu) || stoi(opcao_menu) < 0 || stoi(opcao_menu) > 4) {
                        cout << endl;
                        cout << " Opcao invalida! Escolha uma opcao valida: ";
                        cin >> opcao_menu;
                        cout << endl;
                    }
                    cout << endl;
                    choice1 = stoi(opcao_menu);

                    switch(choice1){
                        case 0:
                            choice1 = 0;
                            /** Voltar ao menu principal. */
                            break;

                        case 1:
                            choice1 = 1;
                            /**
                             * Lista de estudantes ordenada por numero de estudante (UP) de forma crescente.
                             */

                            gh.clear();

                            sorts.sortUPCrescente(v_estudantes);

                            /** Print da lista ordenada. */
                            for(auto p : v_estudantes){
                                cout << " UP: " << p.getEstudantePair().first << " | Nome: " << p.getEstudantePair().second << endl;
                            }

                            gh.wait();
                            break;

                        case 2:
                            choice1 = 2;
                            /**
                             * Lista de estudantes ordenada por numero de estudante (UP) de forma decrescente.
                             */

                            gh.clear();

                            sorts.sortUPDecrescente(v_estudantes);

                            /** Print da lista ordenada. */
                            for(auto p : v_estudantes){
                                cout << " UP: " << p.getEstudantePair().first << " | Nome: " << p.getEstudantePair().second << endl;
                            }

                            gh.wait();
                            break;

                        case 3:
                            choice1 = 3;
                            /**
                             * Lista de estudantes ordenada por ordem alfabetica do seu nome.
                             */

                            gh.clear();

                            sorts.sortNomeCrescente(v_estudantes);

                            /** Print da lista ordenada. */
                            for(auto p : v_estudantes){
                                cout << " UP: " << p.getEstudantePair().first << " | Nome: " << p.getEstudantePair().second << endl;
                            }

                            gh.wait();
                            break;
                        
                        case 4:
                            choice1 = 4;
                            /**
                             * Lista de estudantes ordenada por ordem contraria a ordem alfabetica do seu nome.
                             */

                            gh.clear();

                            sorts.sortNomeDecrescente(v_estudantes);

                            /** Print da lista ordenada. */
                            for(auto p : v_estudantes){
                                cout << " UP: " << p.getEstudantePair().first << " | Nome: " << p.getEstudantePair().second << endl;
                            }

                            gh.wait();
                            break;

                            /** Quando o Input nao esta dentro das opcoes validas */

                        default:

                            gh.clear();

                            cout << " Opcao invalida" << endl;

                            gh.wait();
                            break;
                    }

                } while (choice1 != 0);
                
                break;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                /** Listar estudantes inscritos numa UC */
            case 2:

                choice = 2;
                int choice2;

                gh.clear();
                cout << " UC: ";
                cin >> opcao;
                cout << endl;

                do{

                    /**
                     * Verificacao da opcao escolhida pelo utilizador.
                    */

                    while(!GestaoHorario::checkUC(opcao, v_ucturma)) {
                        cout << endl;
                        cout << " UC invalida! Escolha uma UC valida: ";
                        cin >> opcao;
                        cout << endl;
                    }
                    uc_caso2 = opcao;

                    v_estudante_caso2.clear();

                    for(auto p : v_estudantes){
                        auto j = p.getEstudanteInscrito();
                        for(auto i : j){
                            if(i.getUCTurma().first == uc_caso2){
                                v_estudante_caso2.push_back(p.getEstudantePair());
                            }
                        }
                    }

                    /**
                     * Menu de opcoes para listar estudantes inscritos numa UC.
                     * Apenas entra no menu se e só se a UC tiver alunos inscritos.
                     */

                    if(v_estudante_caso2.empty()){
                        gh.clear();
                        cout << " Nao existem estudantes inscritos nesta UC" << endl;
                        choice2 = 0;
                        gh.wait();
                    }
                    else {

                        gh.clear();
                        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
                        cout << "||-------------- LISTAR ESTUDANTES NUMA UC --------------||" << endl;
                        cout << "|| Escolha uma opcao:                                    ||" << endl;
                        cout << "||_______________________________________________________||" << endl;
                        cout << "||                                                       ||" << endl;
                        cout << "||   UC escolhida -> " << uc_caso2 << "                            ||" << endl;
                        cout << "||                                                       ||" << endl;
                        cout << "||   1 - Ordenar estudantes por UP crescente             ||" << endl;
                        cout << "||   2 - Ordenar estudantes por UP decrescente           ||" << endl;
                        cout << "||   3 - Ordenar estudantes por nome A-Z                 ||" << endl;
                        cout << "||   4 - Ordenar estudantes por nome Z-A                 ||" << endl;
                        cout << "||   5 - Escolher outra UC                               ||" << endl;
                        cout << "||                                                       ||" << endl;
                        cout << "||   0 - Back                                            ||" << endl;
                        cout << "||                                                       ||" << endl;
                        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
                        cout << endl;


                        cin >> opcao_menu;

                        /**
                        * Verificacao da opcao escolhida pelo utilizador.
                        */
                        while(!GestaoHorario::checkInteiro(opcao_menu) || stoi(opcao_menu) < 0 || stoi(opcao_menu) > 5){
                            cout << endl;
                            cout << " Opcao invalida! Escolha uma opcao valida: ";
                            cin >> opcao_menu;
                        }
                        choice2 = stoi(opcao_menu);
                        cout << endl;
                    }

                    switch(choice2){
                        case 0:
                            choice2 = 0;
                            /** Deve voltar ao menu principal */
                            break;

                        case 1:
                            choice2 = 1;
                            /**
                             * Lista de estudantes ordenada por numero de estudante (UP) de forma crescente.
                             */

                            gh.clear();

                            sorts.sortPairCrescente(v_estudante_caso2);

                            for(const auto& pup : v_estudante_caso2){
                                cout << " UP: " << pup.first << " | Nome: " << pup.second << endl;
                            }

                            gh.wait();

                            break;

                        case 2:
                            choice2 = 2;
                            /**
                             * Lista de estudantes ordenada por numero de estudante (UP) de forma decrescente.
                             */

                            gh.clear();

                            sorts.sortPairDecrescente(v_estudante_caso2);

                            for(const auto& pup : v_estudante_caso2){
                                cout << " UP: " << pup.first << " | Nome: " << pup.second << endl;
                            }

                            gh.wait();

                            break;

                        case 3:
                            choice2 = 3;
                            /**
                             * Lista de estudantes ordenada por ordem alfabetica do seu nome.
                             */

                            gh.clear();

                            sorts.sortPairNomeCrescente(v_estudante_caso2);

                            for(const auto& pup : v_estudante_caso2){
                                cout << " UP: " << pup.first << " | Nome: " << pup.second << endl;
                            }

                            gh.wait();

                            break;
                        
                        case 4:
                            choice2 = 4;
                            /**
                             * Lista de estudantes ordenada por ordem contraria a ordem alfabetica do seu nome.
                             */

                            gh.clear();

                            sorts.sortPairNomeDecrescente(v_estudante_caso2);

                            for(const auto& pup : v_estudante_caso2){
                                cout << " UP: " << pup.first << " | Nome: " << pup.second << endl;
                            }

                            gh.wait();

                            break;

                        case 5:
                            choice2 = 5;

                            /** Escolher outra UC */
                            gh.clear();

                            cout << " UC: ";
                            cin >> opcao;
                            cout << endl;

                            break;

                        default:

                            gh.clear();
                            cout << " Opcao invalida" << endl;
                            gh.wait();

                            break;
                    }

                } while (choice2 != 0);
                
                break;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            /** Listar estudantes inscritos numa turma */
            case 3:
                choice = 3;
                int choice3;

                gh.clear();
                cout << " Turma: ";
                cin >> opcao;
                cout << endl;

                do{
                    while(!GestaoHorario::checkTurma(opcao, v_ucturma)) {
                        cout << endl;
                        cout << " Turma invalida! Escolha uma Turma valida: ";
                        cin >> opcao;
                        cout << endl;
                    }
                    turma_caso3 = opcao;

                    v_estudante_caso3.clear();

                    for(auto p : v_estudantes){
                        auto j = p.getEstudanteInscrito();
                        for(auto i : j){
                            if(i.getUCTurma().second == turma_caso3){
                                v_estudante_caso3.push_back(p.getEstudantePair());
                            }
                        }
                    }

                    /** Remover duplicados */
                    for(auto x = v_estudante_caso3.begin(); x != v_estudante_caso3.end(); x++){
                        for(auto y = x + 1; y != v_estudante_caso3.end(); y++){
                            if(x->first == y->first){
                                v_estudante_caso3.erase(y);
                                y--;
                            }
                        }
                    }

                    if(v_estudante_caso3.empty()){
                        gh.clear();
                        cout << " Nao existem estudantes inscritos na turma " << turma_caso3 << endl;
                        choice3 = 0;
                        gh.wait();
                    }

                    else {
                        gh.clear();
                        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
                        cout << "||------------- LISTAR ESTUDANTES NUMA TURMA ------------||" << endl;
                        cout << "|| Escolha uma opcao:                                    ||" << endl;
                        cout << "||_______________________________________________________||" << endl;
                        cout << "||                                                       ||" << endl;
                        cout << "||   Turma escolhida -> " << turma_caso3 << "                          ||" << endl;
                        cout << "||                                                       ||" << endl;
                        cout << "||   1 - Ordenar estudantes por UP crescente             ||" << endl;
                        cout << "||   2 - Ordenar estudantes por UP decrescente           ||" << endl;
                        cout << "||   3 - Ordenar estudantes por nome A-Z                 ||" << endl;
                        cout << "||   4 - Ordenar estudantes por nome Z-A                 ||" << endl;
                        cout << "||   5 - Escolher outra Turma                            ||" << endl;
                        cout << "||                                                       ||" << endl;
                        cout << "||   0 - Back                                            ||" << endl;
                        cout << "||                                                       ||" << endl;
                        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
                        cout << endl;

                        cin >> opcao_menu;

                        /**
                        * Verificacao da opcao escolhida pelo utilizador.
                        */
                        while(!GestaoHorario::checkInteiro(opcao_menu) || stoi(opcao_menu) < 0 || stoi(opcao_menu) > 5){
                            cout << endl;
                            cout << " Opcao invalida! Escolha uma opcao valida: ";
                            cin >> opcao_menu;
                        }
                        choice3 = stoi(opcao_menu);
                        cout << endl;
                    }

                    switch(choice3){
                        case 0:
                            choice3 = 0;
                            /** Deve voltar ao menu principal */
                            break;

                        case 1:
                            choice3 = 1;
                            /**
                            * Lista de estudantes ordenada por numero de estudante (UP) de forma crescente.
                            */

                            gh.clear();

                            //Ordenar estudantes por UP de forma crescente.
                            sorts.sortPairCrescente(v_estudante_caso3);

                            //Imprimir estudantes de forma ordenada crescente.
                            for(const auto& pup : v_estudante_caso3){
                                cout << " UP: " << pup.first << " | Nome: " << pup.second << endl;
                            }

                            gh.wait();

                            break;

                        case 2:
                            choice3 = 2;
                            /**
                            * Lista de estudantes ordenada por numero de estudante (UP) de forma decrescente.
                            */

                            gh.clear();

                            sorts.sortPairDecrescente(v_estudante_caso3);

                            for(const auto& pup : v_estudante_caso3){
                                cout << " UP: " << pup.first << " | Nome: " << pup.second << endl;
                            }

                            gh.wait();

                            break;

                        case 3:
                            choice3 = 3;
                            /**
                            * Lista de estudantes ordenada por ordem alfabetica do seu nome.
                            */

                            gh.clear();

                            sorts.sortPairNomeCrescente(v_estudante_caso3);

                            for(const auto& pup : v_estudante_caso3){
                                cout << " UP: " << pup.first << " | Nome: " << pup.second << endl;
                            }

                            gh.wait();

                            break;
                        
                        case 4:
                            choice3 = 4;
                            /**
                            * Lista de estudantes ordenada por ordem contraria a ordem alfabetica do seu nome.
                            */

                            gh.clear();

                            sorts.sortPairNomeDecrescente(v_estudante_caso3);

                            for(const auto& pup : v_estudante_caso3){
                                cout << " UP: " << pup.first << " | Nome: " << pup.second << endl;
                            }

                            gh.wait();

                            break;

                        case 5:
                            choice3 = 5;

                            /** Escolher outra turma */

                            cout << " Turma: ";
                            cin >> opcao;
                            cout << endl;

                            break;

                        default:
                            cout << " Opcao invalida" << endl;
                            break;
                    }
    
                } while (choice3 != 0);
                break;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            /** Listar estudantes inscritos num par UC, turma */
            case 4:
                choice = 4;
                int choice4;

                cout << " UC: ";
                cin >> opcao1;
                cout << " Turma: ";
                cin >> opcao2;
                cout << endl;

                do{
                    while(!GestaoHorario::checkUC(opcao1, v_ucturma)) {
                        cout << endl;
                        cout << " UC invalida! Escolha uma UC valida: ";
                        cin >> opcao1;
                        cout << endl;
                    }
                    uc_caso4 = opcao1;

                    while(!GestaoHorario::checkTurma(opcao2, v_ucturma)) {
                        cout << endl;
                        cout << " Turma invalida! Escolha uma turma valida: ";
                        cin >> opcao2;
                        cout << endl;
                    }
                    turma_caso4 = opcao2;
                    uc_turma_caso4 = make_pair(uc_caso4, turma_caso4);

                    v_estudante_caso4.clear();

                    for(auto p : v_estudantes){
                        auto j = p.getEstudanteInscrito();
                        for(auto i : j){
                            if(i.getUCTurma() == uc_turma_caso4){
                                v_estudante_caso4.push_back(p.getEstudantePair());
                            }
                        }
                    }

                    if(v_estudante_caso4.empty()){
                        gh.clear();
                        cout << " Nao existem estudantes inscritos nesta UC / Turma " << turma_caso3 << endl;
                        choice4 = 0;
                        gh.wait();
                    }

                    else {
                        gh.clear();
                        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
                        cout << "||----------- LISTAR ESTUDANTES NUMA UC/TURMA -----------||" << endl;
                        cout << "|| Escolha uma opcao:                                    ||" << endl;
                        cout << "||_______________________________________________________||" << endl;
                        cout << "||                                                       ||" << endl;
                        cout << "||   UC escolhida -> " << uc_caso4 << "                            ||" << endl;
                        cout << "||   Turma escolhida -> " << turma_caso4 << "                          ||" << endl;
                        cout << "||                                                       ||" << endl;
                        cout << "||   1 - Ordenar estudantes por UP crescente             ||" << endl;
                        cout << "||   2 - Ordenar estudantes por UP decrescente           ||" << endl;
                        cout << "||   3 - Ordenar estudantes por nome A-Z                 ||" << endl;
                        cout << "||   4 - Ordenar estudantes por nome Z-A                 ||" << endl;
                        cout << "||   5 - Escolher outra UC                               ||" << endl;
                        cout << "||   6 - Escolher outra turma                            ||" << endl;
                        cout << "||   7 - Escolher outra UC e turma                       ||" << endl;
                        cout << "||                                                       ||" << endl;
                        cout << "||   0 - Back                                            ||" << endl;
                        cout << "||                                                       ||" << endl;
                        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
                        cout << endl;

                        cin >> opcao_menu;

                        /**
                        * Verificacao da opcao escolhida pelo utilizador.
                        */
                        while(!GestaoHorario::checkInteiro(opcao_menu) || stoi(opcao_menu) < 0 || stoi(opcao_menu) > 7){
                            cout << endl;
                            cout << " Opcao invalida! Escolha uma opcao valida: ";
                            cin >> opcao_menu;
                        }
                        choice4 = stoi(opcao_menu);
                        cout << endl;
                    }

                    switch(choice4){
                        case 0:
                            choice4 = 0;
                            /** Deve voltar ao menu principal */
                            break;

                        case 1:
                            choice4 = 1;
                            /**
                            * Lista de estudantes ordenada por numero de estudante (UP) de forma crescente.
                            */

                            gh.clear();

                            sorts.sortPairCrescente(v_estudante_caso4);

                            for(const auto& pup : v_estudante_caso4){
                                cout << " UP: " << pup.first << " | Nome: " << pup.second << endl;
                            }

                            gh.wait();

                            break;

                        case 2:
                            choice4 = 2;
                            /**
                            * Lista de estudantes ordenada por numero de estudante (UP) de forma decrescente.
                            */

                            gh.clear();

                            sorts.sortPairDecrescente(v_estudante_caso4);

                            for(const auto& pup : v_estudante_caso4){
                                cout << " UP: " << pup.first << " | Nome: " << pup.second << endl;
                            }

                            gh.wait();

                            break;

                        case 3:
                            choice4 = 3;
                            /**
                            * Lista de estudantes ordenada por ordem alfabetica do seu nome.
                            */

                            gh.clear();

                            sorts.sortPairNomeCrescente(v_estudante_caso4);

                            for(const auto& pup : v_estudante_caso4){
                                cout << " UP: " << pup.first << " | Nome: " << pup.second << endl;
                            }

                            gh.wait();

                            break;
                        
                        case 4:
                            choice4 = 4;
                            /**
                            * Lista de estudantes ordenada por ordem contraria a ordem alfabetica do seu nome.
                            */

                            gh.clear();

                            sorts.sortPairNomeDecrescente(v_estudante_caso4);

                            for(const auto& pup : v_estudante_caso4){
                                cout << " UP: " << pup.first << " | Nome: " << pup.second << endl;
                            }

                            gh.wait();

                            break;

                        case 5:
                            choice4 = 5;

                            /** Escolher outra UC */

                            cout << " UC: ";
                            cin >> opcao1;
                            cout << endl;

                            break;

                        case 6:
                            choice4 = 6;

                            /** Escolher outra turma */

                            cout << " Turma: ";
                            cin >> opcao2;
                            cout << endl;

                            break;
                        
                        case 7:
                            choice4 = 7;

                            /** Escolher outra UC e turma */

                            cout << " UC: ";
                            cin >> opcao1;
                            cout << " Turma: ";
                            cin >> opcao2;
                            cout << endl;

                            break;

                        default:
                            cout << " Opcao invalida" << endl;
                            break;

                    }
                } while(choice4 != 0);

                break;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            /** Listar estudantes incritos num determinado ano */
            case 5:
                choice = 5;
                int choice5;

                cout << " Ano: ";
                cin >> opcao;

                do{
                    while(!GestaoHorario::checkInteiro(opcao) || stoi(opcao) < 1 || stoi(opcao) > 3){
                        cout << endl;
                        cout << " Opcao invalida! Ano inexistente. Escolha um ano valido: ";
                        cin >> opcao;
                    }
                    ano_caso5 = opcao;

                    v_estudante_caso5.clear();

                    for(auto p : v_estudantes){
                        auto j = p.getEstudanteInscrito();
                        for(auto i : j){
                            if(i.getUCTurma().second[0] == ano_caso5[0]){
                                v_estudante_caso5.push_back(p.getEstudantePair());
                            }
                        }
                    }

                    /** Limpar duplicados */
                    for(auto x = v_estudante_caso5.begin(); x != v_estudante_caso5.end(); x++){
                        for(auto y = x + 1; y != v_estudante_caso5.end(); y++){
                            if(x->first == y->first){
                                v_estudante_caso5.erase(y);
                                y--;
                            }
                        }
                    }

                    if(v_estudante_caso5.empty()){
                        gh.clear();
                        cout << " Nao existem estudantes inscritos neste Ano " << turma_caso3 << endl;
                        choice5 = 0;
                        gh.wait();
                    }

                    else {
                        gh.clear();
                        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
                        cout << "||--------------- LISTAR ESTUDANTES NUM ANO -------------||" << endl;
                        cout << "|| Escolha uma opcao:                                    ||" << endl;
                        cout << "||_______________________________________________________||" << endl;
                        cout << "||                                                       ||" << endl;
                        cout << "||   Ano escolhido -> " << ano_caso5 << "                                  ||" << endl;
                        cout << "||                                                       ||" << endl;
                        cout << "||   1 - Ordenar estudantes por UP crescente             ||" << endl;
                        cout << "||   2 - Ordenar estudantes por UP decrescente           ||" << endl;
                        cout << "||   3 - Ordenar estudantes por nome A-Z                 ||" << endl;
                        cout << "||   4 - Ordenar estudantes por nome Z-A                 ||" << endl;
                        cout << "||   5 - Escolher outro Ano                              ||" << endl;
                        cout << "||                                                       ||" << endl;
                        cout << "||   0 - Back                                            ||" << endl;
                        cout << "||                                                       ||" << endl;
                        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
                        cout << endl;

                        cin >> opcao_menu;

                        /**
                        * Verificacao da opcao escolhida pelo utilizador.
                        */
                        while(!GestaoHorario::checkInteiro(opcao_menu) || stoi(opcao_menu) < 0 || stoi(opcao_menu) > 5){
                            cout << endl;
                            cout << " Opcao invalida! Escolha uma opcao valida: ";
                            cin >> opcao_menu;
                        }
                        choice5 = stoi(opcao_menu);
                        cout << endl;
                    }

                    switch(choice5){
                        case 0:
                            choice5 = 0;
                            /** Deve voltar ao menu principal */
                            break;

                        case 1:
                            choice5 = 1;
                            /**
                            * Lista de estudantes ordenada por numero de estudante (UP) de forma crescente.
                            */

                            gh.clear();

                            sorts.sortPairCrescente(v_estudante_caso5);

                            for(const auto& pup : v_estudante_caso5){
                                cout << " UP: " << pup.first << " | Nome: " << pup.second << endl;
                            }

                            gh.wait();

                            break;

                        case 2:
                            choice5 = 2;
                            /**
                            * Lista de estudantes ordenada por numero de estudante (UP) de forma decrescente.
                            */

                            gh.clear();

                            sorts.sortPairDecrescente(v_estudante_caso5);

                            for(const auto& pup : v_estudante_caso5){
                                cout << " UP: " << pup.first << " | Nome: " << pup.second << endl;
                            }

                            gh.wait();

                            break;

                        case 3:
                            choice5 = 3;
                            /**
                            * Lista de estudantes ordenada por ordem alfabetica do seu nome.
                            */

                            gh.clear();

                            sorts.sortPairNomeCrescente(v_estudante_caso5);

                            for(const auto& pup : v_estudante_caso5){
                                cout << " UP: " << pup.first << " | Nome: " << pup.second << endl;
                            }

                            gh.wait();

                            break;
                        
                        case 4:
                            choice5 = 4;
                            /**
                            * Lista de estudantes ordenada por ordem contraria a ordem alfabetica do seu nome.
                            */

                            gh.clear();

                            sorts.sortPairNomeDecrescente(v_estudante_caso5);

                            for(const auto& pup : v_estudante_caso5){
                                cout << " UP: " << pup.first << " | Nome: " << pup.second << endl;
                            }

                            gh.wait();

                            break;
                        
                        case 5:
                            choice5 = 5;

                            /** Escolher outro ano */

                            cout << " Ano: ";
                            cin >> opcao;
                            cout << endl;

                            break;

                        default:
                            cout << " Opcao invalida" << endl;
                            break;
                    }
                } while(choice5 != 0);
                break;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            /** Mostrar horario de um estudante */
            case 6:
                choice = 6;
                int choice6;

                cout << " UP: ";
                cin >> opcao;

                do{
                    while(!GestaoHorario::checkEstudante(opcao, v_estudantes)){
                        cout << endl;
                        cout << " Opcao invalida! Estudante inexistente: ";
                        cin >> opcao;
                    }
                    id_estudante_caso6 = stoi(opcao);


                    /** Guarda as UC's de um estudante numa lista */
                    list<UCTurma> l_ucturma_caso6;
                    for(auto p : v_estudantes){
                        if(p.getEstudantePair().first == id_estudante_caso6){
                            l_ucturma_caso6 = p.getEstudanteInscrito();
                            nome_estudante_caso6 = p.getEstudantePair().second;
                        }
                    }
                    /** Guarda as aulas de um estudante numa lista */
                    vector<Slot> slot_ucturma_caso6;
                    Slot slot_caso6;
                    for(auto p : l_ucturma_caso6){
                        for(auto i : v_slots){
                            if(p.getUCTurma() == i.getUcTurma()){
                                slot_ucturma_caso6.push_back(i);
                            }
                        }
                    }

                    /** Print do harario */

                    if(slot_ucturma_caso6.empty()){
                        cout << " Nao tem disciplinas inscritas neste estudante" << endl;
                        gh.wait();
                    }
                    else {
                        gh.clear();
                        cout << "UP: " << id_estudante_caso6 << " | Nome: " << nome_estudante_caso6 << endl;
                        cout << endl;
                        slot_caso6.printSlot(slot_ucturma_caso6);
                        gh.wait();
                    }


                    gh.clear();
                    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
                    cout << "||----------------- HORARIO DO ESTUDANTE ----------------||" << endl;
                    cout << "|| Escolha uma opcao:                                    ||" << endl;
                    cout << "||_______________________________________________________||" << endl;
                    cout << "||                                                       ||" << endl;
                    cout << "||   UP Escolhido -> " << id_estudante_caso6 << "                           ||" << endl;
                    cout << "||   Nome -> " << nome_estudante_caso6 << endl;
                    cout << "||                                                       ||" << endl;
                    cout << "||   1 - Escolher outro estudante                        ||" << endl;
                    cout << "||                                                       ||" << endl;
                    cout << "||   0 - Back                                            ||" << endl;
                    cout << "||                                                       ||" << endl;
                    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
                    cout << endl;

                    cin >> opcao_menu;

                    /**
                    * Verificacao da opcao escolhida pelo utilizador.
                    */
                    while(!GestaoHorario::checkInteiro(opcao_menu) || stoi(opcao_menu) < 0 || stoi(opcao_menu) > 1){
                        cout << endl;
                        cout << " Opcao invalida! Escolha uma opcao valida: ";
                        cin >> opcao_menu;
                    }
                    choice6 = stoi(opcao_menu);
                    cout << endl;

                    switch(choice6){
                        case 0:
                            choice6 = 0;
                            /** Deve voltar ao menu principal */
                            break;

                        case 1:
                            choice6 = 1;

                            /** Escolher outro estudante */

                            cout << endl;
                            cout << " UP: ";
                            cin >> opcao;
                            cout << endl;

                            break;

                        default:
                            cout << " Opcao invalida" << endl;
                            break;
                    }
                } while(choice6 != 0);

                break;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            /** Mostrar horario de uma turma */
            case 7:
                choice = 7;
                int choice7;

                cout << " Turma: ";
                cin >> opcao;

                do{
                    while(!GestaoHorario::checkTurma(opcao, v_ucturma)){
                        cout << endl;
                        cout << " Opcao invalida! Turma inexistente. Insira uma turma valida: ";
                        cin >> opcao;
                    }
                    turma_caso7 = opcao;

                    /** Guarda numa lista todos as aulas correspondentes a uma turma */
                    vector<Slot> slot_ucturma_caso7;
                    Slot slot_caso7;
                    for(auto p : v_slots){
                        if(p.getUcTurma().second == turma_caso7){
                            slot_ucturma_caso7.push_back(p);
                        }
                    }

                    /** Print do horario de uma turma */

                    if(slot_ucturma_caso7.empty()){
                        cout << " Nao tem disciplinas inscritas nesta turma" << endl;
                        gh.wait();
                    }
                    else {
                        gh.clear();
                        cout << "Turma: " << turma_caso7 << endl;
                        cout << endl;
                        slot_caso7.printSlot(slot_ucturma_caso7);
                        gh.wait();
                    }

                    gh.clear();
                    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
                    cout << "||------------------- HORARIO DA TURMA ------------------||" << endl;
                    cout << "|| Escolha uma opcao:                                    ||" << endl;
                    cout << "||_______________________________________________________||" << endl;
                    cout << "||                                                       ||" << endl;
                    cout << "||   Turma escolhida -> " << turma_caso7 << "                          ||" << endl;
                    cout << "||                                                       ||" << endl;
                    cout << "||   1 - Escolher outra Turma                            ||" << endl;
                    cout << "||                                                       ||" << endl;
                    cout << "||   0 - Back                                            ||" << endl;
                    cout << "||                                                       ||" << endl;
                    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
                    cout << endl;

                    cin >> opcao_menu;

                    /**
                    * Verificacao da opcao escolhida pelo utilizador.
                    */
                    while(!GestaoHorario::checkInteiro(opcao_menu) || stoi(opcao_menu) < 0 || stoi(opcao_menu) > 1){
                        cout << endl;
                        cout << " Opcao invalida! Escolha uma opcao valida: ";
                        cin >> opcao_menu;
                    }
                    choice7 = stoi(opcao_menu);
                    cout << endl;

                    switch(choice7){
                        case 0:
                            choice7 = 0;
                            /** Deve voltar ao menu principal */
                            break;

                        case 1:
                            choice7 = 1;

                            /** Escolher outra turma */

                            cout << " Turma: ";
                            cin >> opcao;
                            cout << endl;
                            break;

                        default:
                            cout << " Opcao invalida" << endl;
                            break;
                    }
                } while(choice7 != 0);
                
                break;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            /** Mostrar horario de uma UC */
            case 8:
                choice = 8;
                int choice8;

                cout << " UC: ";
                cin >> opcao;

                do{
                    while(!GestaoHorario::checkUC(opcao, v_ucturma)){
                        cout << endl;
                        cout << " Opcao invalida! UC inexistente. Insira uma UC valida: ";
                        cin >> opcao;
                    }
                    uc_caso8 = opcao;

                    vector<Slot> slot_ucturma_caso8;
                    Slot slot_caso8;

                    /** Guarda numa lista todas as aulas correspondentes a uma UC */
                    for(auto p : v_slots){
                        if(p.getUcTurma().first == uc_caso8){
                            slot_ucturma_caso8.push_back(p);
                        }
                    }

                    /** Print do horario de uma UC */
                    if(slot_ucturma_caso8.empty()){
                        cout << " Nao tem disciplinas inscritas nesta UC" << endl;
                        gh.wait();
                    }
                    else {
                        gh.clear();
                        cout << "UC: " << uc_caso8 << endl;
                        cout << endl;
                        slot_caso8.printSlot(slot_ucturma_caso8);
                        gh.wait();
                    }

                    gh.clear();
                    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
                    cout << "||-------------------- HORARIO DA UC --------------------||" << endl;
                    cout << "|| Escolha uma opcao:                                    ||" << endl;
                    cout << "||_______________________________________________________||" << endl;
                    cout << "||                                                       ||" << endl;
                    cout << "||   UC escolhida -> " << uc_caso8 << "                            ||" << endl;
                    cout << "||                                                       ||" << endl;
                    cout << "||   1 - Escolher outra UC                               ||" << endl;
                    cout << "||                                                       ||" << endl;
                    cout << "||   0 - Back                                            ||" << endl;
                    cout << "||                                                       ||" << endl;
                    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
                    cout << endl;

                    cin >> opcao_menu;

                    /**
                    * Verificacao da opcao escolhida pelo utilizador.
                    */
                    while(!GestaoHorario::checkInteiro(opcao_menu) || stoi(opcao_menu) < 0 || stoi(opcao_menu) > 1){
                        cout << endl;
                        cout << " Opcao invalida! Escolha uma opcao valida: ";
                        cin >> opcao_menu;
                    }
                    choice8 = stoi(opcao_menu);
                    cout << endl;

                    switch(choice8){
                        case 0:
                            choice8 = 0;
                            /** Deve voltar ao menu principal */
                            break;

                        case 1:
                            choice8 = 1;

                            /** Escolher outra UC */

                            cout << " UC: ";
                            cin >> opcao;
                            cout << endl;

                            break;

                        default:
                            cout << " Opcao invalida" << endl;
                            break;
                    }
                    
                } while (choice8 != 0);
                
                break;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            /** Fazer pedido de mudanca de turma */
            case 9:
                choice = 9;
                int choice9;

                do{

                    gh.clear();
                    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
                    cout << "||-------------- PEDIDO DE MUDANCA DE TURMA -------------||" << endl;
                    cout << "|| Escolha uma opcao:                                    ||" << endl;
                    cout << "||_______________________________________________________||" << endl;
                    cout << "||                                                       ||" << endl;
                    cout << "||   1 - Fazer Pedido                                    ||" << endl;
                    cout << "||                                                       ||" << endl;
                    cout << "||   0 - Back                                            ||" << endl;
                    cout << "||                                                       ||" << endl;
                    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
                    cout << endl;

                    cin >> opcao_menu;

                    /**
                    * Verificacao da opcao escolhida pelo utilizador.
                    */
                    while(!GestaoHorario::checkInteiro(opcao_menu) || stoi(opcao_menu) < 0 || stoi(opcao_menu) > 1){
                        cout << endl;
                        cout << " Opcao invalida! Escolha uma opcao valida: ";
                        cin >> opcao_menu;
                    }
                    choice9 = stoi(opcao_menu);
                    cout << endl;

                    Estudante e_caso10;
                    bool flag;

                    switch (choice9) {

                        case 0:

                            choice9 = 0;
                            /** Deve voltar ao menu principal */
                            break;

                        case 1:

                            /** Fazer um pedido */

                            choice9 = 1;


                            gh.clear();
                            cout << " Introduza o seu UP: ";
                            cin >> opcao;


                            while(!GestaoHorario::checkEstudante(opcao, v_estudantes)){
                                cout << endl;
                                cout << " Opcao invalida! Insira um UP valido: ";
                                cin >> opcao;
                            }
                            id_estudante_caso10 = stoi(opcao);

                            for (auto p: v_estudantes) {

                                if (p.getEstudantePair().first == id_estudante_caso10) {
                                    e_caso10 = p;
                                }
                            }

                            gh.clear();
                            cout << " Introduza o codigo da UC a que quer mudar de turma: ";
                            cin >> opcao1;

                            while(!GestaoHorario::checkUC(opcao1, v_ucturma)) {
                                cout << endl;
                                cout << " UC invalida! Escolha uma UC valida: ";
                                cin >> opcao1;
                                cout << endl;
                            }
                            uc_caso10 = opcao1;

                            cout << " Introduza o codigo da turma em que se encontra: ";
                            cin >> opcao2;

                            while(!GestaoHorario::checkTurma(opcao2, v_ucturma)) {
                                cout << endl;
                                cout << " Turma invalida! Escolha uma turma atual valida: ";
                                cin >> opcao2;
                                cout << endl;
                            }
                            turma_caso_atual10 = opcao2;

                            cout << " Introduza o codigo da turma para qual quer mudar: ";
                            cin >> opcao3;

                            while(!GestaoHorario::checkTurma(opcao3, v_ucturma)) {
                                cout << endl;
                                cout << " Turma invalida! Escolha uma turma para qual quer mudar valida: ";
                                cin >> opcao3;
                                cout << endl;
                            }
                            turma_caso10 = opcao3;

                            uc_turma_caso10 = make_pair(uc_caso10, turma_caso10);

                            flag = false;

                            /** Guarda o pedido de troca de turma numa queue */

                            for (auto p: e_caso10.getEstudanteInscrito()) {

                                if (p.getUCTurma() == uc_turma_caso10) {
                                    gh.clear();
                                    cout << " Ja esta inscrito nessa turma" << endl;
                                    gh.wait();
                                    flag = true;
                                    break;
                                } else if (p.getUCTurma().first == uc_caso10 &&
                                           p.getUCTurma().second != turma_caso10 &&
                                           p.getUCTurma().second[0] == turma_caso10[0]) {
                                    gh.clear();
                                    UCTurma uc_turma_caso10_tmp(uc_turma_caso10);
                                    Pedido pedido_caso10(e_caso10, uc_turma_caso10, turma_caso_atual10);
                                    gh.guardar(pedido_caso10);
                                    cout << " Pedido de mudanca de turma enviado" << endl;
                                    flag = true;
                                    gh.wait();
                                    break;
                                }
                            }

                            /** Se o estudante nao estiver inscrito na UC escolhida ou nao for possivel fazer a troca devido ao conflito entre as turmas */
                            if(!flag){
                                gh.clear();
                                cout << " Nao esta inscrito nesta UC ou Turma errada. " << uc_caso10 << endl;
                                gh.wait();
                            }
                            break;

                        default:

                            cout << " Opcao invalida" << endl;
                            gh.wait();
                            break;
                    }
                } while (choice9 != 0);

                break;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            /** Listar pedidos de mudanca de turma */
            case 10:
                choice = 10;
                int choice10;

                do{
                    gh.clear();
                    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
                    cout << "||------------------ INFO SOBRE PEDIDOS -----------------||" << endl;
                    cout << "|| Escolha uma opcao:                                    ||" << endl;
                    cout << "||_______________________________________________________||" << endl;
                    cout << "||                                                       ||" << endl;
                    cout << "||   1 - Mostrar Pedido mais antigo                      ||" << endl;
                    cout << "||   2 - Mostrar Pedido mais recente                     ||" << endl;
                    cout << "||   3 - Mostrar todos os pedidos                        ||" << endl;
                    cout << "||                                                       ||" << endl;
                    cout << "||   0 - Back                                            ||" << endl;
                    cout << "||                                                       ||" << endl;
                    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
                    cout << endl;

                    cin >> opcao_menu;

                    /**
                    * Verificacao da opcao escolhida pelo utilizador.
                    */
                    while(!GestaoHorario::checkInteiro(opcao_menu) || stoi(opcao_menu) < 0 || stoi(opcao_menu) > 3){
                        cout << endl;
                        cout << " Opcao invalida! Escolha uma opcao valida: ";
                        cin >> opcao_menu;
                    }
                    choice10 = stoi(opcao_menu);
                    cout << endl;

                    switch (choice10) {

                        case 0:
                            choice10 = 0;
                            /** Deve voltar ao menu principal */
                            break;

                        case 1:
                            choice10 = 1;

                            /** Mostrar Pedido mais antigo */

                            gh.clear();

                            if(gh.getPedidos().empty()){
                                cout << " Nao existem pedidos" << endl;
                            }
                            else {
                                p_temp10 = gh.getPedidos().front();
                                cout << " Pedido mais antigo: " << endl;
                                cout << endl;
                                gh.printPedido(p_temp10);
                            }

                            gh.wait();

                            break;

                        case 2:
                            choice10 = 2;

                            /** Mostrar Pedido mais recente */

                            gh.clear();



                            if(gh.getPedidos().empty()){
                                cout << " Nao existem pedidos" << endl;
                            }
                            else {
                                p_temp10 = gh.getPedidos().back();
                                cout << " Pedido mais recente: " << endl;
                                cout << endl;
                                gh.printPedido(p_temp10);
                            }

                            gh.wait();

                            break;

                        case 3:
                            choice10 = 3;

                            /** Mostrar todos os pedidos */

                            gh.clear();

                            if(gh.getPedidos().empty()){
                                cout << " Nao existem pedidos" << endl;
                            }
                            else {
                                queue<Pedido> pedidos_caso10 = gh.getPedidos();
                                int i = 1;
                                while(!pedidos_caso10.empty()){
                                    p_temp10 = pedidos_caso10.front();
                                    cout << " Pedido -> " << i << endl;
                                    cout << endl;
                                    gh.printPedido(p_temp10);
                                    pedidos_caso10.pop();
                                    i++;
                                }
                            }

                            gh.wait();

                            break;

                        default:
                            cout << " Opcao invalida" << endl;
                            break;
                    }

                }while(choice10 != 0);

                break;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            /** Processar os pedidos de mudanca de turma */
            case 11:
                choice = 11;
                int choice12;

                do{
                    unsigned long long contador = gh.getPedidos().size();
                    int numero = 1;

                    gh.clear();
                    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
                    cout << "||------------------- PROCESSAR PEDIDOS -----------------||" << endl;
                    cout << "|| Escolha uma opcao:                                    ||" << endl;
                    cout << "||_______________________________________________________||" << endl;
                    cout << "||                                                       ||" << endl;
                    cout << "||   1 - Processar Pedido                                ||" << endl;
                    cout << "||                                                       ||" << endl;
                    cout << "||   0 - Back                                            ||" << endl;
                    cout << "||                                                       ||" << endl;
                    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
                    cout << endl;

                    cin >> opcao_menu;

                    /**
                    * Verificacao da opcao escolhida pelo utilizador.
                    */
                    while(!GestaoHorario::checkInteiro(opcao_menu) || stoi(opcao_menu) < 0 || stoi(opcao_menu) > 1){
                        cout << endl;
                        cout << " Opcao invalida! Escolha uma opcao valida: ";
                        cin >> opcao_menu;
                    }
                    choice12 = stoi(opcao_menu);
                    cout << endl;

                    bool flag2 = true;

                    switch(choice12){
                        case 0:
                            choice12 = 0;
                            /** Deve voltar ao menu principal */
                            break;

                        case 1:
                            choice12 = 1;

                            /**
                             * Aceita pedido e remove-o da queue
                             * Altera a turma do estudante para a qual ele quer fazer a troca
                            */


                            /** Processar os pedidos */
                            do{
                                gh.clear();

                                if(gh.getPedidos().empty() || contador == 0){
                                    cout << " Nao existem pedidos" << endl;
                                    gh.wait();
                                    flag2 = false;
                                }
                                else {
                                    p_temp10 = gh.getPedidos().front();
                                    gh.getPedidos().pop();
                                    gh.printPedido(p_temp10);

                                    cout << " Pedido numero: " << numero << " | Faltam: " << contador - 1 << endl;
                                    contador--;
                                    numero++;

                                    gh.wait();

                                    if (GestaoHorario::sobreposicao(p_temp10, v_slots) || !GestaoHorario::equilibrio(p_temp10, v_vagas)) {
                                        gh.clear();
                                        gh.printPedido(p_temp10);
                                        cout << " Pedido nao processado devido a sobreposicao ou desequilibrio de Turmas." << endl;
                                        gh.wait();
                                    }
                                    else {
                                        gh.clear();

                                        for (auto& x: v_estudantes) {
                                            if (x.getEstudantePair().first == p_temp10.getEstudante().getEstudantePair().first) {
                                                for (auto &y: x.getEstudanteInscrito()) {
                                                    if (y.getUCTurma().first == p_temp10.getUCTurma().getUCTurma().first) {
                                                        pair<string, string> temp_pair = make_pair(p_temp10.getUCTurma().getUCTurma().first, p_temp10.getUCTurma().getUCTurma().second);
                                                        y.setUCTurma(temp_pair);
                                                        cout << " Pedido aceite" << endl;
                                                    }
                                                }
                                            }
                                        }
                                        gh.printPedido(p_temp10);
                                        cout << " Pedido processado com sucesso." << endl;
                                        gh.wait();

                                    }
                                }

                            }while(flag2);
                            break;

                        default:

                            cout << " Opcao invalida" << endl;
                            break;
                    }
                    
                } while (choice12 != 0);
                break;

            default:
                cout << " Opcao invalida" << endl;
                break;
        }
    }while(choice != 0);

    return 0;
}
