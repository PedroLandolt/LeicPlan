#ifndef AED_PROJETO_SLOT_H
#define AED_PROJETO_SLOT_H

#include "Vaga.h"  /** O header 'Vaga.h' contém definições de constantes usadas neste header */


class Slot {

public:

    /** Default constructor */
    Slot();


    /** Constructor
     * @param diaSemana String com o dia da semana no qual há uma determinada aula
     * @param hora Par constituido por dois floats, a hora e a duração de uma aula
     * @param tipo String com o tipo de aula (T, TP ou PL)
    */
    Slot(string diaSemana, pair<float,float> hora, string tipo);


    /** Constructor
     * @param diaSemana String com o dia da semana no qual há uma determinada aula
     * @param hora Par constituido por dois floats, a hora e a duração de uma aula
     * @param tipo String com o tipo de aula (T, TP ou PL)
     * @param ucturma Objeto UCTurma
    */
    Slot(string diaSemana, pair<float,float> hora, string tipo, pair<string,string> ucturma);


    /** Setter
     * @param diaSemana String com o dia da semana no qual há uma determinada aula
    */
    void setDiaSemana(string diaSemana);


    /** Setter
     * @param hora Par constituido por dois floats, a hora e a duração de uma aula
    */
    void setHora(pair<float,float> hora);


    /** Setter
     * @param tipo String com o tipo de aula (T, TP ou PL)
    */
    void setTipo(string tipo);


    /** Setter
     * @param ucturma Objeto UCTurma
    */
    void setUcTurma(pair<string,string> ucturma);


    /** Getter
     * @return String com o dia da semana no qual há uma determinada aula
    */
    string getDiaSemana();


    /** Getter
     * @return Par constituido por dois floats, a hora e a duração de uma aula
    */
    pair<float,float> getHora();


    /** Getter
     * @return String com o tipo de aula (T, TP ou PL)
    */
    string getTipo();


    /** Getter
     * @return Objeto UCTurma
    */
    pair<string,string> getUcTurma();


    /** Função que compara dois objetos do tipo Slot
     * @param s1 Objeto do tipo Slot
     * @param s2 Objeto do tipo Slot
     * @return True quando o primeiro parametro "acontece" antes do segundo, isto é, acontece num dia da semana anterior ou ,se acontecer no mesmo dia, acontece numa hora anterior
     * @return False quando isso não acontece
    */
    static bool compareSlot(Slot s1, Slot s2);


    /** Função que dá print ao conteudo do vetor 'slots', aula a aula (com todas as informaçoes necessarias), de forma a facilitar a leitura
     * @param slots Vetor constituido por objetos do tipo Slot
    */
    void printSlot(vector<Slot>& slots);


    /** Função que ordena o vetor 'slots' utilizando a função compareSlot()
     * @param slots Vetor constituido por objetos do tipo Slot
    */
    void sortSlots(vector<Slot>& slots);

private:

    string diaSemana;              /** String com o dia da semana no qual há uma determinada aula */
    pair<float,float> hora;        /** Par constituido por dois floats, a hora e a duração de uma aula */
    string tipo;                   /** String com o tipo de aula (T, TP ou PL) */
    pair<string,string> ucturma;   /** Objeto UCTurma */
};


#endif //AED_PROJETO_SLOT_H
