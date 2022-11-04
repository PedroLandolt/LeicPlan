#ifndef AED_PROJETO_SORT_H
#define AED_PROJETO_SORT_H

#include "Estudante.h"   /** O header 'Estudante.h' contém definições de constantes usadas neste header */


class Sort {

public:

    /** Função que ordena o vetor estudantes por ordem crescente do seu numero de estudante(UP)
     * @param estudantes Vetor constituido por objetos do tipo Estudante
     */
    void sortUPCrescente(vector<Estudante> &estudantes);


    /** Função que ordena o vetor estudantes por ordem decrescente do seu numero de estudante(UP)
     * @param estudantes Vetor constituido por objetos do tipo Estudante
     */
    void sortUPDecrescente(vector<Estudante> &estudantes);


    /** Função que ordena o vetor estudantes por ordem alfabetica do seu nome
     * @param estudantes Vetor constituido por objetos do tipo Estudante
     */
    void sortNomeCrescente(vector<Estudante> &estudantes);


    /** Função que ordena o vetor estudantes por ordem contraria a ordem alfabetica do seu nome
     * @param estudantes Vetor constituido por objetos do tipo Estudante
     */
    void sortNomeDecrescente(vector<Estudante> &estudantes);


    /** Função que ordena o vetor estudantes por ordem crescente do seu numero de estudante(UP)
     * @param estudantes Vetor de pares compostos pelo numero de estudante(UP) e o nome do estudante
     */
    void sortPairCrescente(vector<pair<int, string>> &estudantes);


    /** Função que ordena o vetor estudantes por ordem decrescente do seu numero de estudante(UP)
     * @param estudantes Vetor de pares compostos pelo numero de estudante(UP) e o nome do estudante
     */
    void sortPairDecrescente(vector<pair<int, string>> &estudantes);


    /** Função que ordena o vetor estudantes por ordem alfabetica do seu nome
     * @param estudantes Vetor de pares compostos pelo numero de estudante(UP) e o nome do estudante
     */
    void sortPairNomeCrescente(vector<pair<int, string>> &estudantes);


    /** Função que ordena o vetor estudantes por ordem contraria a ordem alfabetica do seu nome
     * @param estudantes Vetor de pares compostos pelo numero de estudante(UP) e o nome do estudante
     */
    void sortPairNomeDecrescente(vector<pair<int, string>> &estudantes);

};


#endif //AED_PROJETO_SORT_H
