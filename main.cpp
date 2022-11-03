#include "headers/GestaoHorario.h"

int main() {

    system("Color 09");

    cout << " A iniciar o programa..." << endl;
    

    GestaoHorario gh;
    Sort sorts;


    cout << " A ler o ficheiro students_classes.csv..." << endl;

    //Leitura dos ficheiros
    vector<Estudante> v_estudantes;
    gh.lerFichEst(v_estudantes); //retorna um set de estudantes



// dar print ao vector de estudantes choura de minas!
/*
    int estudante_n = 1;
    for(auto i : v_estudantes){
        cout << choura << " - " << i.getEstudantePair().first << " " << i.getEstudantePair().second << endl;
        for(auto j : i.getEstudanteInscrito()){
            cout << j.getUCTurma().first << " " << j.getUCTurma().second << endl;
        }
        cout << "UC's: " << i.getEstudanteInscrito().size() << endl;
        cout << endl;
        cout << "||||||||||||||||||||||||||||||||" << endl;
        cout << endl;
        estudante_n++;
    }
*/

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

    vector<THorario> v_horarios;
    gh.lerFichHorario(v_horarios); //retorna um vector de horarios

    set<THorario> s_horarios(v_horarios.begin(), v_horarios.end());

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
/*
    for(auto i : v_slots){
        cout << i.getUcTurma().first << " " << i.getUcTurma().second << " " << i.getDiaSemana() << endl;
    }
*/
/* print do vector de horarios

    int horario_n = 1;
    for(auto i : v_horarios){
        cout << horario_choura << " - " << i.getUcTurma().first << " " << i.getUcTurma().second << endl;
        for(auto j : i.getHoraUCTurma()){
            cout << j.getDiaSemana() << " | Inicio: " << j.getHora().first << " | Duracao: " << j.getHora().second << " | Tipo: " << j.getTipo()  << endl;
        }
        cout << " Numero de aulas por semana: " << i.getHoraUCTurma().size() << endl;
        cout << endl;
        cout << "||||||||||||||||||||||||||||||||" << endl;
        cout << endl;
        horario_n++;
    }
*/

    cout << " Ficheiro lido com sucesso!" << endl;
    cout << " A ler o ficheiro classes_per_uc.csv..." << endl;

    vector<UCTurma> v_ucturma;
    gh.lerFichUCTurma(v_ucturma); //retorna um vector de ucturma

    set<UCTurma> s_ucturma(v_ucturma.begin(), v_ucturma.end());

// print do vector de ucturma
/*
    int ucturma_n = 1;
    for(auto i : v_ucturma){
        cout << ucturma_n << " - " << i.getUCTurma().first << " " << i.getUCTurma().second << endl;
        ucturma_n++;
        cout << endl;
        cout << "||||||||||||||||||||||||||||||||" << endl;
        cout << endl;
    }
*/

    cout << " Ficheiro lido com sucesso!" << endl;

    cout << " A iniciar o processamento..." << endl;

    struct vagaCompare {
        bool operator()(Vaga* lhs, Vaga* rhs) const {
            return lhs->getUC() < rhs->getUC();
        }
    };

    vector<Vaga> v_vagas;
    gh.prepararVagas(v_vagas); //retorna um vector de vagas

    set<Vaga*, vagaCompare> s_vagas;

    for(const auto& i : v_vagas){
        auto *p = new Vaga(i);
        s_vagas.insert(p);
    }


    gh.ajustarVagas(v_vagas);



/*
    for(auto i : v_vagas){
        for(const auto& j : i.getVagas()){
            cout << i.getUC() << endl;
            cout << j.first << " " << j.second << " " << endl;
        }
    }
*/



    //Varaveis para o menu
    int choice;

    string uc_caso2 , uc_caso4, uc_caso8, uc_caso10;
    string turma_caso3, turma_caso4, turma_caso7, turma_caso9, turma_caso10, turma_caso_atual10;
    string nome_estudante_caso6, nome_estudante_caso10;
    char ano_caso5;
    int id_estudante_caso6, id_estudante_caso10;
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

        cin >> choice;
        cout << endl;



        switch(choice){
            case 0:
                choice = 0;
                break;


            //Listar estudantes
            case 1:
                
                int choice1;
                choice = 1;

                do{
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

                    cin >> choice1;
                    cout << endl;

                    switch(choice1){
                        case 0:
                            choice1 = 0;
                            /**
                             * Deve voltar ao menu principal
                             */
                            break;

                        case 1:
                            choice1 = 1;
                            /**
                             * @return lista ordenada estudantes por UP de forma crescente
                             */

                            gh.clear();

                            sorts.sortUPCrescente(v_estudantes);

                            for(auto p : v_estudantes){
                                cout << " UP: " << p.getEstudantePair().first << " | Nome: " << p.getEstudantePair().second << endl;
                            }

                            gh.wait();

                            break;

                        case 2:
                            choice1 = 2;
                            /**
                             * @return lista ordenada estudantes por UP de forma decrescente
                             */

                            gh.clear();

                            sorts.sortUPDecrescente(v_estudantes);
                            
                            for(auto p : v_estudantes){
                                cout << " UP: " << p.getEstudantePair().first << " | Nome: " << p.getEstudantePair().second << endl;
                            }

                            gh.wait();

                            break;

                        case 3:
                            choice1 = 3;
                            /**
                             * @return lista ordenada estudantes por nome de forma A-Z
                             */

                            gh.clear();
                            
                            sorts.sortNomeCrescente(v_estudantes);

                            for(auto p : v_estudantes){
                                cout << " UP: " << p.getEstudantePair().first << " | Nome: " << p.getEstudantePair().second << endl;
                            }

                            gh.wait();

                            break;
                        
                        case 4:
                            choice1 = 4;
                            /**
                             * @return lista ordenada estudantes por nome de forma Z-A
                             */

                            gh.clear();

                            sorts.sortNomeDecrescente(v_estudantes);

                            for(auto p : v_estudantes){
                                cout << " UP: " << p.getEstudantePair().first << " | Nome: " << p.getEstudantePair().second << endl;
                            }

                            gh.wait();
                            
                            break;

                        default:

                            gh.clear();
                            cout << " Opcao invalida" << endl;

                            gh.wait();
                            break;
                    }

                } while (choice1 != 0);
                
                break;


            //Listar estudantes inscritos numa UC
            case 2:

                choice = 2;
                int choice2;

                gh.clear();
                cout << " UC: ";
                cout << endl;
                cin >> uc_caso2;

                do{

                    //iff com while para verificar se a UC existe


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

                    if(v_estudante_caso2.empty()){
                        gh.clear();
                        cout << " Nao existem estudantes inscritos nesta UC" << endl;
                        choice2 = 5;

                        gh.wait();

                        break;
                    }

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

                    cin >> choice2;
                    cout << endl;

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

                            sorts.sortPairCrescente(v_estudante_caso2);

                            for(auto pup : v_estudante_caso2){
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

                            sorts.sortPairDecrescente(v_estudante_caso2);

                            for(auto pup : v_estudante_caso2){
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

                            sorts.sortPairNomeCrescente(v_estudante_caso2);

                            for(auto pup : v_estudante_caso2){
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

                            sorts.sortPairNomeDecrescente(v_estudante_caso2);

                            for(auto pup : v_estudante_caso2){
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
                            cin >> uc_caso2;
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
            

            //Listar estudantes inscritos numa turma
            case 3:
                choice = 3;
                int choice3;

                gh.clear();
                cout << " Turma: ";
                cout << endl;
                cin >> turma_caso3;



                do{

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

                    cin >> choice3;

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

                            sorts.sortPairCrescente(v_estudante_caso3);

                            for(auto pup : v_estudante_caso3){
                                cout << " UP: " << pup.first << " | Nome: " << pup.second << endl;
                            }

                            break;

                        case 2:
                            choice3 = 2;
                            /**
                            * @return lista ordenada estudantes por UP de forma decrescente
                            */

                            sorts.sortPairDecrescente(v_estudante_caso3);

                            for(auto pup : v_estudante_caso3){
                                cout << " UP: " << pup.first << " | Nome: " << pup.second << endl;
                            }

                            break;

                        case 3:
                            choice3 = 3;
                            /**
                            * @return lista ordenada estudantes por nome de forma A-Z
                            */

                            sorts.sortPairNomeCrescente(v_estudante_caso3);

                            for(auto pup : v_estudante_caso3){
                                cout << " UP: " << pup.first << " | Nome: " << pup.second << endl;
                            }

                            break;
                        
                        case 4:
                            choice3 = 4;
                            /**
                            * @return lista ordenada estudantes por nome de forma Z-A
                            */

                            sorts.sortPairNomeDecrescente(v_estudante_caso3);

                            for(auto pup : v_estudante_caso3){
                                cout << " UP: " << pup.first << " | Nome: " << pup.second << endl;
                            }

                            break;

                        case 5:
                            choice3 = 5;

                            /**
                            * @brief Escolher outra turma
                            */

                            cout << " Turma: ";
                            cin >> turma_caso3;
                            cout << endl;

                            break;

                        default:
                            cout << " Opcao invalida" << endl;
                            break;
                    }
    
                } while (choice3 != 0);
                break;

            //Listar estudantes inscritos numa UC e turma
            case 4:
                choice = 4;
                int choice4;

                cout << " UC: ";
                cin >> uc_caso4;
                cout << " Turma: ";
                cin >> turma_caso4;

                uc_turma_caso4 = make_pair(uc_caso4, turma_caso4);

                do{
                        
                    cout << endl;
                    cout << " UC escolhida: " << uc_caso4 << endl;
                    cout << " Turma escolhida: " << turma_caso4 << endl;
                    cout << endl;

                    //iff com while para verificar se a uc / turma existe

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

                    cout << " Escolha uma opcao: " << endl;
                    cout << endl;
                    cout << " 0 - Back" << endl;
                    cout << " 1 - Ordenar estudantes por UP crescente" << endl;
                    cout << " 2 - Ordenar estudantes por UP decrescente" << endl;
                    cout << " 3 - Ordenar estudantes por nome A-Z" << endl;
                    cout << " 4 - Ordenar estudantes por nome Z-A" << endl;
                    cout << " 5 - Escolher outra UC" << endl;
                    cout << " 6 - Escolher outra turma" << endl;
                    cout << " 7 - Escolher outra UC e turma" << endl;
                    cout << endl;

                    cin >> choice4;

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

                            sorts.sortPairCrescente(v_estudante_caso4);

                            for(auto pup : v_estudante_caso4){
                                cout << " UP: " << pup.first << " | Nome: " << pup.second << endl;
                            }

                            break;

                        case 2:
                            choice4 = 2;
                            /**
                            * @return lista ordenada estudantes por UP de forma decrescente
                            */

                            sorts.sortPairDecrescente(v_estudante_caso4);

                            for(auto pup : v_estudante_caso4){
                                cout << " UP: " << pup.first << " | Nome: " << pup.second << endl;
                            }

                            break;

                        case 3:
                            choice4 = 3;
                            /**
                            * @return lista ordenada estudantes por nome de forma A-Z
                            */

                            sorts.sortPairNomeCrescente(v_estudante_caso4);

                            for(auto pup : v_estudante_caso4){
                                cout << " UP: " << pup.first << " | Nome: " << pup.second << endl;
                            }

                            break;
                        
                        case 4:
                            choice4 = 4;
                            /**
                            * @return lista ordenada estudantes por nome de forma Z-A
                            */

                            sorts.sortPairNomeDecrescente(v_estudante_caso4);

                            for(auto pup : v_estudante_caso4){
                                cout << " UP: " << pup.first << " | Nome: " << pup.second << endl;
                            }

                            break;

                        case 5:
                            choice4 = 5;

                            /**
                            * @brief Escolher outra UC
                            */

                            cout << " UC: ";
                            cin >> uc_caso4;

                            uc_turma_caso4 = make_pair(uc_caso4, turma_caso4);

                            break;

                        case 6:
                            choice4 = 6;

                            /**
                            * @brief Escolher outra turma
                            */

                            cout << " Turma: ";
                            cin >> turma_caso4;

                            uc_turma_caso4 = make_pair(uc_caso4, turma_caso4);

                            break;
                        
                        case 7:
                            choice4 = 7;

                            /**
                            * @brief Escolher outra UC e turma
                            */

                            cout << " UC: ";
                            cout << " Turma: ";
                            cin >> uc_caso4 >> turma_caso4;

                            uc_turma_caso4 = make_pair(uc_caso4, turma_caso4);

                            break;

                        default:
                            cout << " Opcao invalida" << endl;
                            break;

                    }
                } while(choice4 != 0);

                break;

            //Listar estudantes incritos num determinado ano
            case 5:
                choice = 5;
                int choice5;



                cout << " Ano: ";
                cin >> ano_caso5;

                do{

                    cout << endl;
                    cout << " Ano escolhido: " << ano_caso5 << endl;
                    cout << endl;


                    //limpar o lixo dentro de v_estudante_caso5
                    v_estudante_caso5.clear();
                    //listar estudantes inscritos no ano
                    for(auto p : v_estudantes){
                        auto j = p.getEstudanteInscrito();
                        for(auto i : j){
                            if(i.getUCTurma().second[0] == ano_caso5){
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

                    cout << " Escolha uma opcao: " << endl;
                    cout << endl;
                    cout << " 0 - Back" << endl;
                    cout << " 1 - Ordenar estudantes por UP crescente" << endl;
                    cout << " 2 - Ordenar estudantes por UP decrescente" << endl;
                    cout << " 3 - Ordenar estudantes por nome A-Z" << endl;
                    cout << " 4 - Ordenar estudantes por nome Z-A" << endl;
                    cout << " 5 - Escolher outro ano" << endl;
                    cout << endl;

                    cin >> choice5;

                    switch(choice5){
                        case 0:
                            choice5 = 0;
                            /**
                            * Deve voltar ao menu principal
                            */
                            break;

                        case 1:
                            choice5 = 1;
                            /**
                            * @return lista ordenada estudantes por UP de forma crescente
                            */

                            sorts.sortPairCrescente(v_estudante_caso5);

                            for(auto pup : v_estudante_caso5){
                                cout << " UP: " << pup.first << " | Nome: " << pup.second << endl;
                            }

                            break;

                        case 2:
                            choice5 = 2;
                            /**
                            * @return lista ordenada estudantes por UP de forma decrescente
                            */

                            sorts.sortPairDecrescente(v_estudante_caso5);

                            for(auto pup : v_estudante_caso5){
                                cout << " UP: " << pup.first << " | Nome: " << pup.second << endl;
                            }

                            break;

                        case 3:
                            choice5 = 3;
                            /**
                            * @return lista ordenada estudantes por nome de forma A-Z
                            */

                            sorts.sortPairNomeCrescente(v_estudante_caso5);

                            for(auto pup : v_estudante_caso5){
                                cout << " UP: " << pup.first << " | Nome: " << pup.second << endl;
                            }

                            break;
                        
                        case 4:
                            choice5 = 4;
                            /**
                            * @return lista ordenada estudantes por nome de forma Z-A
                            */

                            sorts.sortPairNomeDecrescente(v_estudante_caso5);

                            for(auto pup : v_estudante_caso5){
                                cout << " UP: " << pup.first << " | Nome: " << pup.second << endl;
                            }

                            break;
                        
                        case 5:
                            choice5 = 5;

                            /**
                            * @brief Escolher outro ano
                            */

                            cout << " Ano: ";
                            cin >> ano_caso5;
                            cout << endl;

                            break;

                        default:
                            cout << " Opcao invalida" << endl;
                            break;
                    }
                } while(choice5 != 0);
                break;

            //Mostrar horario de um estudante
            case 6:
                choice = 6;
                int choice6;

                cout << " UP: ";
                cin >> id_estudante_caso6;


                do{

                    //Lista as disciplinas do estudante
                    list<UCTurma> l_ucturma_caso6;
                    for(auto p : s_estudantes){
                        if(p->getEstudantePair().first == id_estudante_caso6){
                            l_ucturma_caso6 = p->getEstudanteInscrito();
                            cout << " Estudante: " << p->getEstudantePair().second << endl;
                        }
                    }


                    vector<Slot> slot_ucturma_caso6;
                    Slot slot_caso6;

                    for(auto p : l_ucturma_caso6){
                        for(auto i : v_slots){
                            if(p.getUCTurma() == i.getUcTurma()){
                                slot_ucturma_caso6.push_back(i);
                            }
                        }
                    }

                    slot_caso6.printSlot(slot_ucturma_caso6);

                    //cout horario estudante
                    cout << " Escolha uma opcao: " << endl;
                    cout << endl;
                    cout << " 0 - Back" << endl;
                    cout << " 1 - Escolher outro estudante" << endl;
                    cout << endl;

                    cin >> choice6;

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
                            cin >> id_estudante_caso6;


                            break;

                        default:
                            cout << " Opcao invalida" << endl;
                            break;
                    }
                } while(choice6 != 0);

                break;

            //Mostrar horario de uma turma
            case 7:
                choice = 7;
                int choice7;

                cout << " Turma: ";
                cin >> turma_caso7;

                do{

                    vector<Slot> slot_ucturma_caso7;
                    Slot slot_caso7;

                    for(auto p : v_slots){
                        if(p.getUcTurma().second == turma_caso7){
                            slot_ucturma_caso7.push_back(p);
                        }
                    }

                    slot_caso7.printSlot(slot_ucturma_caso7);

                    //cout horario turma
                    cout << " Escolha uma opcao: " << endl;
                    cout << endl;
                    cout << " 0 - Back" << endl;
                    cout << " 1 - Escolher outra turma" << endl;
                    cout << endl;

                    cin >> choice7;

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
                            cin >> turma_caso7;

                            break;

                        default:
                            cout << " Opcao invalida" << endl;
                            break;
                    }
                } while(choice7 != 0);
                
                break;

            //Mostrar horario de uma UC
            case 8:
                choice = 8;
                int choice8;

                cout << " UC: ";
                cin >> uc_caso8;

                do{
                    //cout horario UC
                    vector<Slot> slot_ucturma_caso8;
                    Slot slot_caso8;

                    for(auto p : v_slots){
                        if(p.getUcTurma().first == uc_caso8){
                            slot_ucturma_caso8.push_back(p);
                        }
                    }

                    slot_caso8.printSlot(slot_ucturma_caso8);


                    cout << " Escolha uma opcao: " << endl;
                    cout << endl;
                    cout << " 0 - Back" << endl;
                    cout << " 1 - Escolher outra UC" << endl;
                    cout << endl;

                    cin >> choice8;

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
                            cin >> uc_caso8;

                            break;

                        default:
                            cout << " Opcao invalida" << endl;
                            break;
                    }
                    
                } while (choice8 != 0);
                
                break;

            //Fazer pedido de mudanca de turma
            case 9:
                choice = 9;
                int choice9;

                do{
                    cout << " Escolha uma opcao: " << endl;
                    cout << endl;
                    cout << " 0 - Back" << endl;
                    cout << " 1 - Fazer um pedido" << endl;
                    cout << endl;


                    cin >> choice9;
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
                            cout << " Introduza o nome da UC que quer fazer mudança de turma: ";
                            cin >> uc_caso10;

                            cout << " Introduza o nome da turma que quer fazer mudança de turma: ";
                            cin >> turma_caso_atual10;

                            cout << " Introduza o nome da turma para qual quer mudar: ";
                            cin >> turma_caso10;

                            uc_turma_caso10 = make_pair(uc_caso10, turma_caso10);


                            flag = false;

                            for (auto p: e_caso10.getEstudanteInscrito()) {

                                if (p.getUCTurma() == uc_turma_caso10) {
                                    cout << " Ja esta inscrito nessa turma" << endl;
                                    flag = true;
                                    break;
                                } else if (p.getUCTurma().first == uc_caso10 &&
                                           p.getUCTurma().second != turma_caso10 &&
                                           p.getUCTurma().second[0] == turma_caso10[0]) {
                                    UCTurma uc_turma_caso10_tmp(uc_turma_caso10);
                                    Pedido pedido_caso10(e_caso10, uc_turma_caso10, turma_caso_atual10);
                                    gh.guardar(pedido_caso10);
                                    cout << " Pedido de mudanca de turma enviado" << endl;
                                    flag = true;
                                    break;
                                }
                            }

                            if(!flag){
                                cout << " Nao esta inscrito nessa UC ou Turma invalida" << endl;
                            }
                            break;

                        default:

                            cout << " Opcao invalida" << endl;
                            break;
                    }
                } while (choice9 != 0);

                break;


            //Listar pedidos de mudanca de turma
            case 10:
                choice = 10;
                int choice10;
                //cout pedidos de mudanca de turma

                do{

                    cout << " Escolha uma opcao: " << endl;
                    cout << endl;
                    cout << " 0 - Back" << endl;
                    cout << " 1 - Mostrar Pedido mais antigo" << endl;
                    cout << " 2 - Mostrar Pedido mais recente" << endl;
                    cout << " 3 - Mostrar todos os pedidos" << endl;
                    //cout << " talvez - Mostrar pedidos de um estudante" << endl;
                    cout << endl;

                    cin >> choice10;

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
                                    cout << " Pedido -: " << i << ": " << endl;
                                    cout << endl;
                                    gh.printPedido(p_temp10);
                                    pedidos_caso10.pop();
                                    i++;
                                }
                            }

                            break;

                        default:
                            cout << " Opcao invalida" << endl;
                            break;
                    }

                }while(choice10 != 0);

                break;

            //Processar pedidos de mudanca de turma "FIFO"
            case 11:
                choice = 11;
                int choice12;

                do{
                    unsigned long long contador = gh.getPedidos().size();
                    int numero = 0;
                    //cout primeiro pedido de mudanca de turma

                    cout << endl;
                    cout << " 0 - Back" << endl;
                    cout << " 1 - Processar Pedido" << endl;
                    cout << endl;

                    cin >> choice12;

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
                                }
                                else {
                                    p_temp10 = gh.getPedidos().front();

                                    gh.printPedido(p_temp10);

                                    cout << " Pedido numero: " << numero << " | Faltam: " << contador << endl;
                                    contador--;
                                    numero++;

                                    gh.wait();

                                    if (!gh.sobreposicao(p_temp10, v_slots) || !gh.equilibrio(p_temp10, v_vagas)) {
                                        gh.getPedidos().pop();
                                        gh.printPedido(p_temp10);
                                        cout << " Nao foi possivel processar o pedido" << endl;
                                    }

                                    else {

                                        gh.getPedidos().pop();
                                        gh.printPedido(p_temp10);

                                        int choice11_1;

                                        do {
                                            cout << " Escolha uma opcao: " << endl;
                                            cout << endl;
                                            cout << " 1 - Aceitar Pedido" << endl;
                                            cout << " 2 - Recusar Pedido" << endl;
                                            cout << endl;

                                            switch (choice11_1) {
                                                case 2:
                                                    choice11_1 = 2;
                                                    /**
                                                     * Recusa pedido e remove da queue
                                                     *
                                                     * @brief Recusar pedido
                                                     */

                                                    gh.clear();

                                                    gh.printPedido(p_temp10);

                                                    cout << " Pedido recusado" << endl;
                                                    gh.wait();
                                                    break;

                                                case 1:
                                                    choice11_1 = 1;
                                                    /**
                                                     * Aceita pedido e remove da queue
                                                     * Mudar uc e turma do estudante
                                                     *
                                                     * @brief Processar pedidos
                                                    */

                                                    gh.clear();

                                                    temp_est = p_temp10.getEstudante();

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
                                                                    gh.getPedidos().pop();
                                                                    gh.printPedido(p_temp10);
                                                                    cout << " Pedido aceite" << endl;
                                                                    gh.wait();
                                                                    break;
                                                                }
                                                            }
                                                        }
                                                    }
                                                    break;

                                                default:
                                                    cout << " Opcao invalida" << endl;
                                                    break;
                                            }

                                        } while (true);

                                        gh.processarPedido(p_temp10);

                                        cout << " Pedido processado com sucesso" << endl;
                                    }

                                }
                            }while(true);
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
