#include <iostream>

#include "cpps/GestaoHorario.cpp"

int main() {

    GestaoHorario gh;
    //Leitura dos ficheiros
    auto estudantes = gh.lerFichEst("students_classes"); //retorna um set de estudantes
    gh.lerFichEst("classes");
    gh.lerFichEst("classes_per_uc");

    //Primeiro sort



    //Pedidos de mudança de turma
    gh.pedidos();
    gh.guardar();
    gh.processsar();
    gh.listagem();

    //menu

    int choice;

    do{
        cout << endl;
        cout << "0 - Sair" << endl;
        cout << "1 - Listar estudantes" << endl;
        cout << "2 - Listar estudantes inscritos numa UC" << endl;
        cout << "3 - Listar estudantes inscritos numa turma" << endl;
        cout << "4 - Listar estudantes inscritos numa UC e turma" << endl;
        cout << "5 - Mostrar horario de um estudante" << endl;
        cout << "6 - Mostrar horario de uma turma" << endl;
        cout << "7 - Mostrar horario de uma UC" << endl;
        cout << "8 - Mostrar vagas de uma turma" << endl;
        cout << "9 - Fazer pedido de mudanca de turma" << endl;
        cout << "10 - Listar pedidos de mudanca de turma" << endl;
        cout << "11 - Processar pedidos de mudanca de turma" << endl;
        cout << endl;

        cin >> choice;

        switch(choice){
            case 0:
                break;

            case 1:
                int choice1;

                do{
                    cout << endl;
                    cout << "0 - Back" << endl;
                    cout << "1 - Ordenar estudantes por UP crescente" << endl;
                    cout << "2 - Ordenar estudantes por UP decrescente" << endl;
                    cout << "3 - Ordenar estudantes por nome A-Z" << endl;
                    cout << "4 - Ordenar estudantes por nome Z-A" << endl;
                    cout << endl;

                    cin >> choice1;

                    switch(choice1){
                        case 0:
                            break;

                        case 1:
                            gh.getEstudante();
                            break;

                        case 2:
                            gh.getEstudante();
                            break;

                        case 3:
                            gh.getEstudante();
                            break;
                        
                        case 4:
                            gh.getEstudante();
                            break;

                        default:
                            cout << "Opcao invalida" << endl;
                            break;
                    }

                } while (choice1 != 0);
                
                break;

            case 2:
                break;

            case 3:
                break;

            case 4:
                break;

            case 5:
                break;

            case 6:
                break;

            case 7:
                break;

            case 8:
                break;

            case 9:
                break;

            case 10:
                break;

            case 11:
                break;

            default:
                cout << "Opcao invalida" << endl;
                break;
        }
    }while(choice != 0);

    return 0;
}
