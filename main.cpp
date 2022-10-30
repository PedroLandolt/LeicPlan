#include <iostream>



#include "cpps/GestaoHorario.cpp"
#include "cpps/Sort.cpp"


int main() {
    
    cout << " A iniciar o programa..." << endl;
    

    GestaoHorario gh;

    cout << " A ler o ficheiro students_classes.csv..." << endl;

    //Leitura dos ficheiros
    auto estudantes = gh.lerFichEst("students_classes"); //retorna um set de estudantes

    cout << " Ficheiro lido com sucesso!" << endl;
    cout << " A ler o ficheiro classes.csv..." << endl;

    auto uc_turmas = gh.lerFichEst("classes");

    cout << " Ficheiro lido com sucesso!" << endl;
    cout << " A ler o ficheiro classes_per_uc.csv..." << endl;

    auto horarios = gh.lerFichEst("classes_per_uc");

    cout << " Ficheiro lido com sucesso!" << endl;

    //Primeiro sort



    //Pedidos de mudança de turma
    gh.pedidos();
    gh.guardar();
    gh.processsar();
    gh.listagem();


    //menu

    cout << " A inciar o menu..." << endl;

    int choice;

    string uc_caso2 , uc_caso4, uc_caso8;
    string turma_caso3, turma_caso4, turma_caso7, turma_caso9;
    string nome_estudante_caso6;
    int id_estudante_caso6;
    pair<string,string> uc_turma_caso4;
    pair<int,string> estudante_caso6;

    do{
        cout << endl;
        cout << " 0 - Sair" << endl;
        cout << " 1 - Listar estudantes" << endl;
        cout << " 2 - Listar estudantes inscritos numa UC" << endl;
        cout << " 3 - Listar estudantes inscritos numa turma" << endl;
        cout << " 4 - Listar estudantes inscritos numa UC e turma" << endl;
        cout << " 5 - Listar estudantes incritos num dado ano" << endl;
        cout << " 6 - Mostrar horario de um estudante" << endl;
        cout << " 7 - Mostrar horario de uma turma" << endl;
        cout << " 8 - Mostrar horario de uma UC" << endl;
        cout << " 9 - Mostrar vagas de uma turma" << endl;
        cout << " 10 - Fazer pedido de mudanca de turma" << endl;
        cout << " 11 - Listar pedidos de mudanca de turma" << endl;
        cout << " 12 - Processar pedidos de mudanca de turma" << endl;
        cout << endl;

        cin >> choice;

        int choice1;

        switch(choice){
            case 0:
                choice = 0;
                break;


            //Listar estudantes
            case 1:
                
                int choice1;
                choice = 1;

                do{
                    cout << endl;
                    cout << " 0 - Back" << endl;
                    cout << " 1 - Ordenar estudantes por UP crescente" << endl;
                    cout << " 2 - Ordenar estudantes por UP decrescente" << endl;
                    cout << " 3 - Ordenar estudantes por nome A-Z" << endl;
                    cout << " 4 - Ordenar estudantes por nome Z-A" << endl;
                    cout << endl;

                    cin >> choice1;

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
                            
                            break;

                        case 2:
                            choice1 = 2;
                            /**
                             * @return lista ordenada estudantes por UP de forma decrescente
                             */
                            break;

                        case 3:
                            choice1 = 3;
                            /**
                             * @return lista ordenada estudantes por nome de forma A-Z
                             */
                            
                            break;
                        
                        case 4:
                            choice1 = 4;
                            /**
                             * @return lista ordenada estudantes por nome de forma Z-A
                             */
                            
                            break;

                        default:
                            cout << " Opcao invalida" << endl;
                            break;
                    }

                } while (choice1 != 0);
                
                break;


            //Listar estudantes inscritos numa UC
            
            case 2:

                choice = 2;
                int choice2;
                
                cout << " UC: ";
                cin >> uc_caso2;

                do{

                    cout << endl;
                    cout << " UC escolhida: " << uc_caso2 << endl;
                    cout << endl;
                    cout << " 0 - Back" << endl;
                    cout << " 1 - Ordenar estudantes por UP crescente" << endl;
                    cout << " 2 - Ordenar estudantes por UP decrescente" << endl;
                    cout << " 3 - Ordenar estudantes por nome A-Z" << endl;
                    cout << " 4 - Ordenar estudantes por nome Z-A" << endl;
                    cout << " 5 - Escolher outra UC" << endl;
                    cout << endl;

                    cin >> choice2;

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
                            break;

                        case 2:
                            choice2 = 2;
                            /**
                             * @return lista ordenada estudantes por UP de forma decrescente
                             */
                            break;

                        case 3:
                            choice2 = 3;
                            /**
                             * @return lista ordenada estudantes por nome de forma A-Z
                             */
                            break;
                        
                        case 4:
                            choice2 = 4;
                            /**
                             * @return lista ordenada estudantes por nome de forma Z-A
                             */
                            break;

                        case 5:
                            choice2 = 5;

                            /**
                             * @brief Escolher outra UC
                             */

                            cout << " UC: ";
                            cin >> uc_caso2;

                            break;

                        default:
                            cout << " Opcao invalida" << endl;
                            break;
                    }

                } while (choice2 != 0);
                
                break;
            

            //Listar estudantes inscritos numa turma
            case 3:
                choice = 3;
                int choice3;
                

                cout << " Turma: ";
                cin >> turma_caso3;

                do{
                        
                    cout << endl;
                    cout << " Turma escolhida: " << turma_caso3 << endl;
                    cout << endl;
                    cout << " 0 - Back" << endl;
                    cout << " 1 - Ordenar estudantes por UP crescente" << endl;
                    cout << " 2 - Ordenar estudantes por UP decrescente" << endl;
                    cout << " 3 - Ordenar estudantes por nome A-Z" << endl;
                    cout << " 4 - Ordenar estudantes por nome Z-A" << endl;
                    cout << " 5 - Escolher outra turma" << endl;
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
                            break;

                        case 2:
                            choice3 = 2;
                            /**
                            * @return lista ordenada estudantes por UP de forma decrescente
                            */
                            break;

                        case 3:
                            choice3 = 3;
                            /**
                            * @return lista ordenada estudantes por nome de forma A-Z
                            */
                            break;
                        
                        case 4:
                            choice3 = 4;
                            /**
                            * @return lista ordenada estudantes por nome de forma Z-A
                            */
                            break;

                        case 5:
                            choice3 = 5;

                            /**
                            * @brief Escolher outra turma
                            */

                            cout << " Turma: ";
                            cin >> turma_caso3;

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
                cout << " Turma: ";
                cin >> uc_caso4 >> turma_caso4;

                uc_turma_caso4 = make_pair(uc_caso4, turma_caso4);

                do{
                        
                    cout << endl;
                    cout << " UC escolhida: " << uc_caso4 << endl;
                    cout << " Turma escolhida: " << turma_caso4 << endl;
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
                            break;

                        case 2:
                            choice4 = 2;
                            /**
                            * @return lista ordenada estudantes por UP de forma decrescente
                            */
                            break;

                        case 3:
                            choice4 = 3;
                            /**
                            * @return lista ordenada estudantes por nome de forma A-Z
                            */
                            break;
                        
                        case 4:
                            choice4 = 4;
                            /**
                            * @return lista ordenada estudantes por nome de forma Z-A
                            */
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

                int ano_caso5;

                cout << " Ano: ";
                cin >> ano_caso5;

                do{
                        
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
                            break;

                        case 2:
                            choice5 = 2;
                            /**
                            * @return lista ordenada estudantes por UP de forma decrescente
                            */
                            break;

                        case 3:
                            choice5 = 3;
                            /**
                            * @return lista ordenada estudantes por nome de forma A-Z
                            */
                            break;
                        
                        case 4:
                            choice5 = 4;
                            /**
                            * @return lista ordenada estudantes por nome de forma Z-A
                            */
                            break;
                        
                        case 5:
                            choice5 = 5;

                            /**
                            * @brief Escolher outro ano
                            */

                            cout << " Ano: ";
                            cin >> ano_caso5;

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

                cout << " Nome: ";
                cin >> nome_estudante_caso6;

                estudante_caso6 = make_pair(id_estudante_caso6, nome_estudante_caso6);


                do{
                        
                    //cout horario estudante
                
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

                            cout << " UP: ";
                            cin >> id_estudante_caso6;

                            cout << " Nome: ";
                            cin >> nome_estudante_caso6;

                            estudante_caso6 = make_pair(id_estudante_caso6, nome_estudante_caso6);

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
                        
                    //cout horario turma

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

            //Mostrar vagas de uma turma
            case 9:
                choice = 9;
                int choice9;

                cout << " Turma: ";
                cin >> turma_caso9;

                do{
                            
                    //cout vagas turma

                    cout << endl;
                    cout << " 0 - Back" << endl;
                    cout << " 1 - Escolher outra turma" << endl;
                    cout << endl;

                    cin >> choice9;

                    switch(choice9){
                        case 0:
                            choice9 = 0;
                            /**
                            * Deve voltar ao menu principal
                            */
                            break;

                        case 1:
                            choice9 = 1;

                            /**
                            * @brief Escolher outra turma
                            */

                            cout << " Turma: ";
                            cin >> turma_caso9;

                            break;

                        default:
                            cout << " Opcao invalida" << endl;
                            break;
                    }
                    
                } while (choice9 != 0);
                break;

            //Fazer pedido de mudanca de turma
            case 10:
                choice = 10;
                break;

            //Listar pedidos de mudanca de turma
            case 11:
                choice = 11;
                break;

            //Processar pedidos de mudanca de turma
            case 12:
                choice = 12;
                break;
            
            

            default:
                cout << " Opcao invalida" << endl;
                break;
        }
    }while(choice != 0);

    return 0;
}
