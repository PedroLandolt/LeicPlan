#include "headers/GestaoHorario.h"

int main() {

    //Output do programa têm cor azul com fundo preto
    system("Color 09");

    cout << " A iniciar o programa..." << endl;

    //Inicializar GestaoHorario e Sort
    GestaoHorario gh;
    Sort sorts;

    cout << " A ler o ficheiro students_classes.csv..." << endl;

    //Leitura de students_classes.csv
    vector<Estudante> v_estudantes;
    gh.lerFichEst(v_estudantes); //retorna um set de estudantes

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
    cout << " A ler o ficheiro classes.csv..." << endl;


    //Leitura de classes.csv
    vector<THorario> v_horarios;
    gh.lerFichHorario(v_horarios); //retorna um vector de horarios

    set<THorario> s_horarios(v_horarios.begin(), v_horarios.end());


    //Leitura de classes.csv para formar o vector de slots
    vector<Slot> v_slots;
    gh.lerFichSlot(v_slots); //retorna um vector de slots

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
    cout << " A ler o ficheiro classes_per_uc.csv..." << endl;

    //Leitura de classes_per_uc.csv
    vector<UCTurma> v_ucturma;
    gh.lerFichUCTurma(v_ucturma); //retorna um vector de ucturma

    set<UCTurma> s_ucturma(v_ucturma.begin(), v_ucturma.end());


    cout << " Ficheiro lido com sucesso!" << endl;
    cout << " A iniciar o processamento..." << endl;

    struct vagaCompare {
        bool operator()(Vaga* lhs, Vaga* rhs) const {
            return lhs->getUC() < rhs->getUC();
        }
    };

    //Inicializar vector de vagas
    vector<Vaga> v_vagas;
    gh.prepararVagas(v_vagas); //retorna um vector de vagas

    set<Vaga*, vagaCompare> s_vagas;

    for(const auto& i : v_vagas){
        auto *p = new Vaga(i);
        s_vagas.insert(p);
    }

    //Ajustar vagas para o numero de vagas - numero de estudantes inscritos nas mesmas
    gh.ajustarVagas(v_vagas);

    //Varaveis para o menu

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

    //menu
    cout << " A inciar o menu..." << endl;
    cout << endl;


    do{
        /**
         * @brief Menu do programa com as opcoes disponiveis para o utilizador.
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
         * @brief Leitura da opcao escolhida pelo utilizador.
         */
        cin >> opcao_menu;

        /**
         * @brief Verificacao da opcao escolhida pelo utilizador.
         */
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

        //switch case para as opcoes do menu.
        switch(choice){
            case 0:
                /**
                 * @brief Opcao para sair do programa.
                 */
                choice = 0;
                break;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                //Listar estudantes
            case 1:
                
                int choice1;
                choice = 1;

                do{
                    /**
                     * @brief Menu para listar estudantes com opcoes de ordenacao.
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
                     * @brief Leitura da opcao escolhida pelo utilizador.
                     */
                    cin >> opcao_menu;

                    /**
                     * @brief Verificacao da opcao escolhida pelo utilizador.
                     */

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
                            /**
                             * @brief Voltar ao menu principal.
                             */
                            break;

                        case 1:
                            choice1 = 1;
                            /**
                             * @return lista ordenada estudantes por UP de forma crescente.
                             */

                            gh.clear();

                            //Ordenar estudantes por UP de forma crescente.
                            sorts.sortUPCrescente(v_estudantes);

                            //Imprimir estudantes de forma ordenada crescente.
                            for(auto p : v_estudantes){
                                cout << " UP: " << p.getEstudantePair().first << " | Nome: " << p.getEstudantePair().second << endl;
                            }

                            gh.wait();
                            break;

                        case 2:
                            choice1 = 2;
                            /**
                             * @return lista ordenada estudantes por UP de forma decrescente.
                             */

                            gh.clear();

                            //Ordenar estudantes por UP de forma decrescente.
                            sorts.sortUPDecrescente(v_estudantes);

                            //Imprimir estudantes de forma ordenada decrescente.
                            for(auto p : v_estudantes){
                                cout << " UP: " << p.getEstudantePair().first << " | Nome: " << p.getEstudantePair().second << endl;
                            }

                            gh.wait();
                            break;

                        case 3:
                            choice1 = 3;
                            /**
                             * @return lista ordenada estudantes por nome de forma A-Z.
                             */

                            gh.clear();

                            //Ordenar estudantes por nome de forma A-Z.
                            sorts.sortNomeCrescente(v_estudantes);

                            //Imprimir estudantes de forma ordenada A-Z.
                            for(auto p : v_estudantes){
                                cout << " UP: " << p.getEstudantePair().first << " | Nome: " << p.getEstudantePair().second << endl;
                            }

                            gh.wait();
                            break;
                        
                        case 4:
                            choice1 = 4;
                            /**
                             * @return lista ordenada estudantes por nome de forma Z-A.
                             */

                            gh.clear();

                            //Ordenar estudantes por nome de forma Z-A.
                            sorts.sortNomeDecrescente(v_estudantes);

                            //Imprimir estudantes de forma ordenada Z-A.
                            for(auto p : v_estudantes){
                                cout << " UP: " << p.getEstudantePair().first << " | Nome: " << p.getEstudantePair().second << endl;
                            }

                            gh.wait();
                            break;

                        default:

                            gh.clear();

                            //Imprimir mensagem de erro.
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

                //Listar estudantes inscritos numa UC
            case 2:

                choice = 2;
                int choice2;

                gh.clear();
                cout << " UC: ";
                cin >> opcao;
                cout << endl;

                do{

                    /**
                     * @brief Verificacao da opcao escolhida pelo utilizador.
                    */

                    while(!GestaoHorario::checkUC(opcao, v_ucturma)) {
                        cout << endl;
                        cout << " UC invalida! Escolha uma UC valida: ";
                        cin >> opcao;
                        cout << endl;
                    }
                    uc_caso2 = opcao;

                    //limpar lixo de v_estudante_caso2
                    v_estudante_caso2.clear();

                    //listar estudantes inscritos na UC
                    for(auto p : s_estudantes){
                        auto j = p->getEstudanteInscrito();
                        for(auto i : j){
                            if(i.getUCTurma().first == uc_caso2){
                                v_estudante_caso2.push_back(p->getEstudantePair());
                            }
                        }
                    }

                    /**
                     * Menu de opcoes para listar estudantes inscritos numa UC.
                     * @brief Apenas entra no menu se e só se a UC tiver alunos inscritos.
                     */

                    if(v_estudante_caso2.empty()){
                        gh.clear();
                        cout << " Nao existem estudantes inscritos nesta UC" << endl;
                        choice2 = 5;
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

                        /**
                         * @brief Verificacao da opcao escolhida pelo utilizador.
                         */
                        cin >> opcao_menu;

                        /**
                        * @brief Verificacao da opcao escolhida pelo utilizador.
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
                            /**
                             * Deve voltar ao menu principal
                             */
                            break;

                        case 1:
                            choice2 = 1;
                            /**
                             * @return lista ordenada estudantes por UP de forma crescente
                             */

                            gh.clear();

                            //Ordenar estudantes por UP de forma crescente.
                            sorts.sortPairCrescente(v_estudante_caso2);

                            //Imprimir estudantes de forma ordenada crescente.
                            for(const auto& pup : v_estudante_caso2){
                                cout << " UP: " << pup.first << " | Nome: " << pup.second << endl;
                            }

                            gh.wait();

                            break;

                        case 2:
                            choice2 = 2;
                            /**
                             * @return lista ordenada estudantes por UP de forma decrescente
                             */

                            gh.clear();

                            //Ordenar estudantes por UP de forma decrescente.
                            sorts.sortPairDecrescente(v_estudante_caso2);

                            //Imprimir estudantes de forma ordenada decrescente.
                            for(const auto& pup : v_estudante_caso2){
                                cout << " UP: " << pup.first << " | Nome: " << pup.second << endl;
                            }

                            gh.wait();

                            break;

                        case 3:
                            choice2 = 3;
                            /**
                             * @return lista ordenada estudantes por nome de forma A-Z
                             */

                            gh.clear();

                            //Ordenar estudantes por nome de forma A-Z.
                            sorts.sortPairNomeCrescente(v_estudante_caso2);

                            //Imprimir estudantes de forma ordenada A-Z.
                            for(const auto& pup : v_estudante_caso2){
                                cout << " UP: " << pup.first << " | Nome: " << pup.second << endl;
                            }

                            gh.wait();

                            break;
                        
                        case 4:
                            choice2 = 4;
                            /**
                             * @return lista ordenada estudantes por nome de forma Z-A
                             */

                            gh.clear();

                            //Ordenar estudantes por nome de forma Z-A.
                            sorts.sortPairNomeDecrescente(v_estudante_caso2);

                            //Imprimir estudantes de forma ordenada Z-A.
                            for(const auto& pup : v_estudante_caso2){
                                cout << " UP: " << pup.first << " | Nome: " << pup.second << endl;
                            }

                            gh.wait();

                            break;

                        case 5:
                            choice2 = 5;

                            /**
                             * @brief Escolher outra UC
                             */
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

            //Listar estudantes inscritos numa turma
            case 3:
                choice = 3;
                int choice3;

                gh.clear();
                cout << " Turma: ";
                cout << endl;
                cin >> opcao;

                do{

                    /**
                     * @brief Verificacao da opcao escolhida pelo utilizador.
                    */
                    while(!GestaoHorario::checkTurma(opcao, v_ucturma)) {
                        cout << endl;
                        cout << " Turma invalida! Escolha uma Turma valida: ";
                        cin >> opcao;
                        cout << endl;
                    }
                    turma_caso3 = opcao;

                    //limpa o lixo de v_estudante_caso3
                    v_estudante_caso3.clear();

                    //listar estudantes inscritos na turma
                    for(auto p : v_estudantes){
                        auto j = p.getEstudanteInscrito();
                        for(auto i : j){
                            if(i.getUCTurma().second == turma_caso3){
                                v_estudante_caso3.push_back(p.getEstudantePair());
                            }
                        }
                    }

                    //remover dups
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
                        choice3 = 5;
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
                        cout << "||   5 - Escolher outra UC                               ||" << endl;
                        cout << "||                                                       ||" << endl;
                        cout << "||   0 - Back                                            ||" << endl;
                        cout << "||                                                       ||" << endl;
                        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
                        cout << endl;

                        /**
                         * @brief Verificacao da opcao escolhida pelo utilizador.
                         */
                        cin >> opcao_menu;

                        /**
                        * @brief Verificacao da opcao escolhida pelo utilizador.
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
                            /**
                            * Deve voltar ao menu principal
                            */
                            break;

                        case 1:
                            choice3 = 1;
                            /**
                            * @return lista ordenada estudantes por UP de forma crescente
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
                            * @return lista ordenada estudantes por UP de forma decrescente
                            */

                            gh.clear();

                            //Ordenar estudantes por UP de forma decrescente.
                            sorts.sortPairDecrescente(v_estudante_caso3);

                            //Imprimir estudantes de forma ordenada decrescente.
                            for(const auto& pup : v_estudante_caso3){
                                cout << " UP: " << pup.first << " | Nome: " << pup.second << endl;
                            }

                            gh.wait();

                            break;

                        case 3:
                            choice3 = 3;
                            /**
                            * @return lista ordenada estudantes por nome de forma A-Z
                            */

                            gh.clear();

                            //Ordenar estudantes por nome de forma A-Z.
                            sorts.sortPairNomeCrescente(v_estudante_caso3);

                            //Imprimir estudantes de forma ordenada A-Z.
                            for(const auto& pup : v_estudante_caso3){
                                cout << " UP: " << pup.first << " | Nome: " << pup.second << endl;
                            }

                            gh.wait();

                            break;
                        
                        case 4:
                            choice3 = 4;
                            /**
                            * @return lista ordenada estudantes por nome de forma Z-A
                            */

                            gh.clear();

                            //Ordenar estudantes por nome de forma Z-A.
                            sorts.sortPairNomeDecrescente(v_estudante_caso3);

                            //Imprimir estudantes de forma ordenada Z-A.
                            for(const auto& pup : v_estudante_caso3){
                                cout << " UP: " << pup.first << " | Nome: " << pup.second << endl;
                            }

                            gh.wait();

                            break;

                        case 5:
                            choice3 = 5;

                            /**
                            * @brief Escolher outra turma
                            */

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

            //Listar estudantes inscritos numa UC e turma
            case 4:
                choice = 4;
                int choice4;

                cout << " UC: ";
                cin >> opcao1;
                cout << " Turma: ";
                cin >> opcao2;
                cout << endl;

                do{

                    /**
                     * @brief Verificacao da opcao escolhida pelo utilizador.
                    */

                    //Verificar se a UC existe.
                    while(!GestaoHorario::checkUC(opcao1, v_ucturma)) {
                        cout << endl;
                        cout << " UC invalida! Escolha uma UC valida: ";
                        cin >> opcao1;
                        cout << endl;
                    }
                    uc_caso4 = opcao1;

                    //Verificar se a turma existe.
                    while(!GestaoHorario::checkTurma(opcao2, v_ucturma)) {
                        cout << endl;
                        cout << " Turma invalida! Escolha uma turma valida: ";
                        cin >> opcao2;
                        cout << endl;
                    }
                    turma_caso4 = opcao2;
                    uc_turma_caso4 = make_pair(uc_caso4, turma_caso4);

                    //limpar o lixo dentro de v_estudante_caso4
                    v_estudante_caso4.clear();

                    //listar estudantes inscritos na uc / turma
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
                        choice4 = 7;
                        gh.wait();
                    }

                    else {
                        gh.clear();
                        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
                        cout << "||----------- LISTAR ESTUDANTES NUMA UC/TURMA -----------||" << endl;
                        cout << "|| Escolha uma opcao:                                    ||" << endl;
                        cout << "||_______________________________________________________||" << endl;
                        cout << "||                                                       ||" << endl;
                        cout << "||   UC escolhida -> " << uc_caso2 << "                            ||" << endl;
                        cout << "||   Turma escolhida -> " << turma_caso3 << "                          ||" << endl;
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

                        /**
                         * @brief Verificacao da opcao escolhida pelo utilizador.
                         */
                        cin >> opcao_menu;

                        /**
                        * @brief Verificacao da opcao escolhida pelo utilizador.
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
                            /**
                            * Deve voltar ao menu principal
                            */
                            break;

                        case 1:
                            choice4 = 1;
                            /**
                            * @return lista ordenada estudantes por UP de forma crescente
                            */

                            gh.clear();

                            //Ordenar estudantes por UP de forma crescente.
                            sorts.sortPairCrescente(v_estudante_caso4);

                            //Imprimir estudantes de forma ordenada A-Z.
                            for(const auto& pup : v_estudante_caso4){
                                cout << " UP: " << pup.first << " | Nome: " << pup.second << endl;
                            }

                            gh.wait();

                            break;

                        case 2:
                            choice4 = 2;
                            /**
                            * @return lista ordenada estudantes por UP de forma decrescente
                            */

                            gh.clear();

                            //Ordenar estudantes por UP de forma decrescente.
                            sorts.sortPairDecrescente(v_estudante_caso4);

                            //Imprimir estudantes de forma ordenada A-Z.
                            for(const auto& pup : v_estudante_caso4){
                                cout << " UP: " << pup.first << " | Nome: " << pup.second << endl;
                            }

                            gh.wait();

                            break;

                        case 3:
                            choice4 = 3;
                            /**
                            * @return lista ordenada estudantes por nome de forma A-Z
                            */

                            gh.clear();

                            //Ordenar estudantes por nome por nome de A-Z.
                            sorts.sortPairNomeCrescente(v_estudante_caso4);

                            //Imprimir estudantes de forma ordenada A-Z.
                            for(const auto& pup : v_estudante_caso4){
                                cout << " UP: " << pup.first << " | Nome: " << pup.second << endl;
                            }

                            gh.wait();

                            break;
                        
                        case 4:
                            choice4 = 4;
                            /**
                            * @return lista ordenada estudantes por nome de forma Z-A
                            */

                            gh.clear();

                            //Ordenar estudantes por nome de forma Z-A.
                            sorts.sortPairNomeDecrescente(v_estudante_caso4);

                            //Imprimir estudantes de forma ordenada Z-A.
                            for(const auto& pup : v_estudante_caso4){
                                cout << " UP: " << pup.first << " | Nome: " << pup.second << endl;
                            }

                            gh.wait();

                            break;

                        case 5:
                            choice4 = 5;

                            /**
                            * @brief Escolher outra UC
                            */

                            cout << " UC: ";
                            cin >> opcao1;
                            cout << endl;

                            break;

                        case 6:
                            choice4 = 6;

                            /**
                            * @brief Escolher outra turma
                            */

                            cout << " Turma: ";
                            cin >> opcao2;
                            cout << endl;

                            break;
                        
                        case 7:
                            choice4 = 7;

                            /**
                            * @brief Escolher outra UC e turma
                            */

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

            //Listar estudantes incritos num determinado ano
            case 5:
                choice = 5;
                int choice5;

                cout << " Ano: ";
                cin >> opcao;

                do{

                    //Verificar se o ano introduzido e valido
                    while(!GestaoHorario::checkInteiro(opcao) || stoi(opcao) < 1 || stoi(opcao) > 3){
                        cout << endl;
                        cout << " Opcao invalida! Ano inexistente. Escolha um ano valido: ";
                        cin >> opcao;
                    }
                    ano_caso5 = opcao;


                    //limpar o lixo dentro de v_estudante_caso5
                    v_estudante_caso5.clear();
                    //listar estudantes inscritos no ano
                    for(auto p : v_estudantes){
                        auto j = p.getEstudanteInscrito();
                        for(auto i : j){
                            if(i.getUCTurma().second[0] == ano_caso5[0]){
                                v_estudante_caso5.push_back(p.getEstudantePair());
                            }
                        }
                    }

                    //limpar dups
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
                        choice5 = 5;
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
                        cout << "||   5 - Escolher outra UC                               ||" << endl;
                        cout << "||                                                       ||" << endl;
                        cout << "||   0 - Back                                            ||" << endl;
                        cout << "||                                                       ||" << endl;
                        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
                        cout << endl;

                        /**
                         * @brief Verificacao da opcao escolhida pelo utilizador.
                         */
                        cin >> opcao_menu;

                        /**
                        * @brief Verificacao da opcao escolhida pelo utilizador.
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
                            /**
                            * @brief Deve voltar ao menu principal
                            */
                            break;

                        case 1:
                            choice5 = 1;
                            /**
                            * @return lista ordenada estudantes por UP de forma crescente
                            */

                            gh.clear();

                            //Ordenar estudantes por UP de forma crescente
                            sorts.sortPairCrescente(v_estudante_caso5);

                            //Imprimir estudantes ordenados por UP de forma crescente
                            for(const auto& pup : v_estudante_caso5){
                                cout << " UP: " << pup.first << " | Nome: " << pup.second << endl;
                            }

                            gh.wait();

                            break;

                        case 2:
                            choice5 = 2;
                            /**
                            * @return lista ordenada estudantes por UP de forma decrescente
                            */

                            gh.clear();

                            //Ordenar estudantes por UP de forma decrescente
                            sorts.sortPairDecrescente(v_estudante_caso5);

                            //Imprimir estudantes ordenados por UP de forma decrescente
                            for(const auto& pup : v_estudante_caso5){
                                cout << " UP: " << pup.first << " | Nome: " << pup.second << endl;
                            }

                            gh.wait();

                            break;

                        case 3:
                            choice5 = 3;
                            /**
                            * @return lista ordenada estudantes por nome de forma A-Z
                            */

                            gh.clear();

                            //Ordenar estudantes por nome de forma A-Z
                            sorts.sortPairNomeCrescente(v_estudante_caso5);

                            //Imprimir estudantes ordenados por nome de forma A-Z
                            for(const auto& pup : v_estudante_caso5){
                                cout << " UP: " << pup.first << " | Nome: " << pup.second << endl;
                            }

                            gh.wait();

                            break;
                        
                        case 4:
                            choice5 = 4;
                            /**
                            * @return lista ordenada estudantes por nome de forma Z-A
                            */

                            gh.clear();

                            //Ordenar estudantes por nome de forma Z-A
                            sorts.sortPairNomeDecrescente(v_estudante_caso5);

                            //Imprimir estudantes ordenados por nome de forma Z-A
                            for(const auto& pup : v_estudante_caso5){
                                cout << " UP: " << pup.first << " | Nome: " << pup.second << endl;
                            }

                            gh.wait();

                            break;
                        
                        case 5:
                            choice5 = 5;

                            /**
                            * @brief Escolher outro ano
                            */

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

            //Mostrar horario de um estudante
            case 6:
                choice = 6;
                int choice6;

                cout << " UP: ";
                cin >> opcao;

                do{

                    //Verificar se o estudante existe
                    while(!GestaoHorario::checkEstudante(opcao, v_estudantes)){
                        cout << endl;
                        cout << " Opcao invalida! Estudante inexistente: ";
                        cin >> opcao;
                    }
                    id_estudante_caso6 = stoi(opcao);


                    //Lista as disciplinas do estudante
                    list<UCTurma> l_ucturma_caso6;
                    for(auto p : s_estudantes){
                        if(p->getEstudantePair().first == id_estudante_caso6){
                            l_ucturma_caso6 = p->getEstudanteInscrito();
                            nome_estudante_caso6 = p->getEstudantePair().second;
                        }
                    }
                    //Lista o horario do estudante
                    vector<Slot> slot_ucturma_caso6;
                    Slot slot_caso6;
                    for(auto p : l_ucturma_caso6){
                        for(auto i : v_slots){
                            if(p.getUCTurma() == i.getUcTurma()){
                                slot_ucturma_caso6.push_back(i);
                            }
                        }
                    }

                    //print do horario do estudante
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

                    /**
                     * @brief Verificacao da opcao escolhida pelo utilizador.
                     */
                    cin >> opcao_menu;

                    /**
                    * @brief Verificacao da opcao escolhida pelo utilizador.
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
                            /**
                            * Deve voltar ao menu principal
                            */
                            break;

                        case 1:
                            choice6 = 1;

                            /**
                            * @brief Escolher outro estudante
                            */
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

            //Mostrar horario de uma turma
            case 7:
                choice = 7;
                int choice7;

                cout << " Turma: ";
                cin >> opcao;

                do{

                    //Verificar se a turma existe
                    while(!GestaoHorario::checkTurma(opcao, v_ucturma)){
                        cout << endl;
                        cout << " Opcao invalida! Turma inexistente. Insira uma turma valida: ";
                        cin >> opcao;
                    }
                    turma_caso7 = opcao;

                    //Lista o horario da turma
                    vector<Slot> slot_ucturma_caso7;
                    Slot slot_caso7;
                    for(auto p : v_slots){
                        if(p.getUcTurma().second == turma_caso7){
                            slot_ucturma_caso7.push_back(p);
                        }
                    }

                    //Print do horario da turma
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
                    cout << "||   Turma escolhida -> " << turma_caso3 << "                          ||" << endl;
                    cout << "||                                                       ||" << endl;
                    cout << "||   1 - Escolher outro estudante                        ||" << endl;
                    cout << "||                                                       ||" << endl;
                    cout << "||   0 - Back                                            ||" << endl;
                    cout << "||                                                       ||" << endl;
                    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
                    cout << endl;

                    /**
                     * @brief Verificacao da opcao escolhida pelo utilizador.
                     */
                    cin >> opcao_menu;

                    /**
                    * @brief Verificacao da opcao escolhida pelo utilizador.
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
                            /**
                            * Deve voltar ao menu principal
                            */
                            break;

                        case 1:
                            choice7 = 1;

                            /**
                            * @brief Escolher outra turma
                            */

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

            //Mostrar horario de uma UC
            case 8:
                choice = 8;
                int choice8;

                cout << " UC: ";
                cin >> opcao;

                do{

                    //Verificar se a UC existe
                    while(!GestaoHorario::checkUC(uc_caso8, v_ucturma)){
                        cout << endl;
                        cout << " Opcao invalida! UC inexistente. Insira uma turma valida: ";
                        cin >> opcao;
                    }
                    uc_caso8 = opcao;

                    //cout horario UC
                    vector<Slot> slot_ucturma_caso8;
                    Slot slot_caso8;

                    for(auto p : v_slots){
                        if(p.getUcTurma().first == uc_caso8){
                            slot_ucturma_caso8.push_back(p);
                        }
                    }

                    //Print do horario da uc
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
                    cout << "||   1 - Escolher outro estudante                        ||" << endl;
                    cout << "||                                                       ||" << endl;
                    cout << "||   0 - Back                                            ||" << endl;
                    cout << "||                                                       ||" << endl;
                    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
                    cout << endl;

                    /**
                     * @brief Verificacao da opcao escolhida pelo utilizador.
                     */
                    cin >> opcao_menu;

                    /**
                    * @brief Verificacao da opcao escolhida pelo utilizador.
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
                            /**
                            * Deve voltar ao menu principal
                            */
                            break;

                        case 1:
                            choice8 = 1;

                            /**
                            * @brief Escolher outra UC
                            */

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

            //Fazer pedido de mudanca de turma
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

                    /**
                     * @brief Verificacao da opcao escolhida pelo utilizador.
                     */
                    cin >> opcao_menu;

                    /**
                    * @brief Verificacao da opcao escolhida pelo utilizador.
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
                            /**
                            * Deve voltar ao menu principal
                            */
                            break;

                        case 1:

                            /**
                             * @brief Fazer um pedido
                             */

                            choice9 = 1;

                            //do {
                            gh.clear();
                            cout << " Introduza o seu UP: ";
                            cin >> id_estudante_caso10;
                            // } while (gh.checkUP(id_estudante_caso10) == false);

                            //confirmar se o estudante existe

                            //confirmado



                            //Complexidade O(n)
                            for (auto p: s_estudantes) {

                                if (p->getEstudantePair().first == id_estudante_caso10) {
                                    e_caso10 = *p;
                                }
                            }

                            /////////////////////////////////////////////
                            gh.clear();
                            cout << " Introduza o codigo da UC a que quer mudar de turma: ";
                            cin >> opcao1;

                            cout << " Introduza o codigo da turma em que se encontra: ";
                            cin >> opcao2;

                            cout << " Introduza o codigo da turma para qual quer mudar: ";
                            cin >> opcao3;

                            //confirmar se a UC existe
                            while(!GestaoHorario::checkUC(opcao1, v_ucturma)) {
                                cout << endl;
                                cout << " UC invalida! Escolha uma UC valida: ";
                                cin >> opcao1;
                                cout << endl;
                            }
                            uc_caso10 = opcao1;

                            //Verificar se a turma em que se encontra existe.
                            while(!GestaoHorario::checkTurma(opcao2, v_ucturma)) {
                                cout << endl;
                                cout << " Turma invalida! Escolha uma turma valida: ";
                                cin >> opcao2;
                                cout << endl;
                            }
                            turma_caso_atual10 = opcao2;

                            //Verificar se a turma para qual quer mudar existe.
                            while(!GestaoHorario::checkTurma(opcao3, v_ucturma)) {
                                cout << endl;
                                cout << " Turma invalida! Escolha uma turma valida: ";
                                cin >> opcao3;
                                cout << endl;
                            }
                            turma_caso10 = opcao3;

                            uc_turma_caso10 = make_pair(uc_caso10, turma_caso10);

                            flag = false;

                            //Guarda o pedido caso o estudante nao esteja inscrito na turma para qual quer mudar
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

                            //Caso o estudante nao esteja inscrito na UC
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

            //Listar pedidos de mudanca de turma
            case 10:
                choice = 10;
                int choice10;
                //cout pedidos de mudanca de turma

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

                    /**
                     * @brief Verificacao da opcao escolhida pelo utilizador.
                     */
                    cin >> opcao_menu;

                    /**
                    * @brief Verificacao da opcao escolhida pelo utilizador.
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
                            /**
                            * Deve voltar ao menu principal
                            */
                            break;

                        case 1:
                            choice10 = 1;

                            /**
                            * @brief Mostrar Pedido mais antigo
                            */

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

                            /**
                            * @brief Mostrar Pedido mais recente
                            */

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

                            /**
                            * @brief Mostrar todos os pedidos
                            */

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

            //Processar pedidos de mudanca de turma "FIFO"
            case 11:
                choice = 11;
                int choice12;

                do{
                    unsigned long long contador = gh.getPedidos().size();
                    int numero = 1;
                    //cout primeiro pedido de mudanca de turma

                    cout << endl;
                    cout << " 0 - Back" << endl;
                    cout << " 1 - Processar Pedido" << endl;
                    cout << endl;

                    cin >> choice12;

                    bool flag2 = true;

                    switch(choice12){
                        case 0:
                            choice12 = 0;
                            /**
                            * Deve voltar ao menu principal
                            */
                            break;

                        case 1:
                            choice12 = 1;

                            /**
                             * Aceita pedido e remove da queue 
                             * Mudar uc e turma do estudante
                             *
                             * @brief Processar pedidos
                            */



                            do{
                                gh.clear();

                                if(gh.getPedidos().empty()){
                                    cout << " Nao existem pedidos" << endl;
                                    gh.wait();
                                    flag2 = false;
                                }
                                else {
                                    p_temp10 = gh.getPedidos().front();
                                    gh.getPedidos().pop();
                                    gh.printPedido(p_temp10);

                                    cout << " Pedido numero: " << numero << " | Faltam: " << contador << endl;
                                    contador--;
                                    numero++;

                                    gh.wait();


                                    cout << "antes do if" << endl;
                                    if (!GestaoHorario::sobreposicao(p_temp10, v_slots) || !GestaoHorario::equilibrio(p_temp10, v_vagas)) {
                                        gh.printPedido(p_temp10);
                                        cout << " Pedido nao processado devido a sobreposicao ou desequilibrio de Turmas." << endl;
                                        gh.wait();
                                    }
                                    else {
                                        cout << "depois do if" << endl;
                                        for (auto x: s_estudantes) {
                                            if (x->getEstudantePair().first ==
                                                temp_est.getEstudantePair().first) {
                                                for (auto &y: x->getEstudanteInscrito()) {
                                                    if (y.getUCTurma().first ==
                                                        p_temp10.getUCTurma().getUCTurma().first) {
                                                        pair<string, string> temp_pair = make_pair(
                                                                p_temp10.getUCTurma().getUCTurma().second,
                                                                p_temp10.getUCTurma().getUCTurma().first);
                                                        y.setUCTurma(temp_pair);
                                                        gh.printPedido(p_temp10);
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
