
#ifndef AED_PROJETO_GESTAOHORARIO_H
#define AED_PROJETO_GESTAOHORARIO_H


#include "Pedido.h"     /** O header 'Pedido.h' contém definições de constantes usadas neste header */


class GestaoHorario {

    public:

        /** Função que lê o Ficheiro 'students_classes.csv' e guarda toda a sua informação num vetor
         * @param estudantes Vetor com objetos do tipo Estudante
         */
        void lerFichEst(vector<Estudante> &estudantes);


        /** Função que lê o Ficheiro 'classes.csv' e guarda toda a sua informação num vetor
         * @param horario Vetor com objetos do tipo THorario
         */
        void lerFichHorario(vector<THorario> &horario);


        /** Função que lê o Ficheiro 'classes_per_uc.csv' e guarda toda a sua informação num vetor
         * @param ucturma Vetor com objetos do tipo UCTurma
         */
        void lerFichUCTurma(vector<UCTurma> &ucturma);


        /** Função que lê o Ficheiro 'classes.csv' e guarda toda a sua informação num vetor
         * @param slot Vetor com objetos do tipo Slot
         */
        void lerFichSlot(vector<Slot> &slot);


        /** Função que cria um vetor em que para cada UC, cria uma lista com todas as turmas existentes e suas respetivas vagas (com base num valor inicial CAP)
         * @param vagas Vetor com objetos do tipo Vaga
         */
        void prepararVagas(vector<Vaga> &vagas);


        /** Função que, ao ler o ficheiro 'students_classes.csv', atualiza o vetor criado pela função prepararVagas alterando o numero de vagas disponiveis em cada turma consoante os estudantes ja inscritos nas mesmas
         * @param vagas Vetor com objetos do tipo Vaga
         */
        void ajustarVagas(vector<Vaga> &vagas);


        /** Função que testa se um Pedido de troca entre turmas nao vai causar sobreposiçao de horarios em aulas dos tipos TP e PL
         * @param pedido Objeto do tipo Pedido
         * @param slots Vetor com objetos do tipo Slot
         * @return True se houver sobreposição
         * @return False se acontecer o contrário
         */
        static bool sobreposicao(Pedido pedido , const vector<Slot>& slots);


        /** Função que verifica se um Pedido de troca entre turmas nao vai causar desiquilibrio no numero de estudantes das mesmas
         * @param pedido Objeto do tipo Pedido
         * @param vagas Vetor com objeto do tipo Vaga
         * @return True se acontecer o contrario
         * @return False se causar desiquilibrio
         */
        static bool equilibrio(Pedido pedido , vector<Vaga> vagas);


        /** Função que dá print a 100 linhas de código vazias para facilitar a leitura dos dados pedidos */
        void clear();


        /** Função que espera por um input do utilizador para avançar com o programa. Facilita a leitura dos dados pedidos */
        void wait();


        /** Getter
         * @return Queue com objetos do tipo Pedido
         */
        queue<Pedido>& getPedidos();


        /** Função que guarda o novo Pedido numa queue
         * @param pedido Objeto do tipo Pedido
         */
        void guardar(Pedido pedido);


        /** Função que dá print a um Pedido
         * @param prt_pedido Objeto do tipo Pedido
         */
        void printPedido(Pedido prt_pedido);


        /** Função que verifica se um determinado input é um valor do tipo inteiro
         * @param x String com o Input do utilizador
         * @return True se o Input for um numero inteiro
         * @return False se isso não acontecer
         */
        static bool checkInteiro(const string& x);


        /** Função que verifica se um determinado input é uma UC existente
         * @param x String com o Input do utilizador
         * @param ucturma Vetor de objetos do tipo UCTurma
         * @return True se o Input for uma UC existente nos ficheiros .csv
         * @return False se isso não acontecer
         */
        static bool checkUC(const string& x, const vector<UCTurma>& ucturma);


        /** Função que verifica se um determinado input é uma Turma existente
         * @param x String com o Input do utilizador
         * @param ucturma Vetor de objetos do tipo UCTurma
         * @return True se o Input for uma Turma existente nos ficheiros .csv
         * @return False se isso não acontecer
         */
        static bool checkTurma(const string& x, const vector<UCTurma>& ucturma);


        /** Função que verifica se um determinado input é um numero de Estudante (UP) existente
         * @param x String com o Input do utilizador
         * @param estudantes Vetor com objetos do tipo Estudante
         * @return True se o Input for um numero de Estudante (UP) existente nos ficheiros .csv
         * @return False se isso não acontecer
         */
        static bool checkEstudante(const string& x, const vector<Estudante>& estudantes);

    private:

        vector<Estudante> estudantes;     /** Vetor com objetos do tipo Estudante */
        queue<Pedido> pedidos;            /** Queue com objetos do tipo Pedido */

};


#endif //AED_PROJETO_GESTAOHORARIO_H
