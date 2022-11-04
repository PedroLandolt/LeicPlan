#ifndef AED_PROJETO_PEDIDO_H
#define AED_PROJETO_PEDIDO_H

#include "Sort.h"  /** O header 'Sort.h' contém definições de constantes usadas neste header */


class Pedido {
public:

    /** Default constructor */
    Pedido();


    /** Constructor
     * @param estudante Objeto do tipo Estudante
     * @param turma Par constituido pela UC na qual deve ocorrer a troca e a turma para qual o Estudante quer trocar
     * @param turma_atual Turma em que o Estudante está inscrito atualmente
    */
    Pedido(Estudante estudante, UCTurma turma, string turma_atual);


    /** Getter
     * @return Um objeto do tipo Estudante
    */
    Estudante getEstudante();


    /** Getter
     * @return Um objeto do tipo UCTurma
    */
    UCTurma getUCTurma();


    /** Getter
     * @return Um uma string com a turma em que o Estudante está inscrito atualmente
    */
    string getTurmaAtual();


    /** Setter
     * @param estudante Objeto do tipo Estudante
     */
    void setEstudante(Estudante estudante);


    /**
     * @param turma Par constituido pela UC na qual deve ocorrer a troca e a turma para qual o Estudante quer trocar
     */
    void setUCTurma(UCTurma turma);


    /**
     * @param turma_atual Turma em que o Estudante está inscrito atualmente
     */
    void setTurmaAtual(string turma_atual);


private:
    Estudante estudante;    /** Objeto do tipo Estudante */
    UCTurma turma;          /** Par constituido pela UC na qual deve ocorrer a troca e a turma para qual o Estudante quer trocar */
    string turma_atual;     /** Turma em que o Estudante está inscrito atualmente */
};


#endif //AED_PROJETO_PEDIDO_H
