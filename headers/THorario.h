#ifndef AED_PROJETO_THORARIO_H
#define AED_PROJETO_THORARIO_H

#include "Slot.h"   /** O header 'Slot.h' contém definições de constantes usadas neste header */


class THorario {

public:

    /** Default Constructor
     * @brief Complexidade O(1)
     */
    THorario();


    /** Constructor
     * @param ucturma Objeto do tipo UCTurma
     * @param horaUCTurma Lista de objetos do tipo Slot
     * @brief Complexidade O(1)
     */
    THorario(pair<string,string> ucturma, list<Slot> horaUCTurma);


    /** Setter
     * @param ucturma Objeto do tipo UCTurma
     * @brief Complexidade O(1)
     */
    void setUcTurma(pair<string,string> ucturma);


    /** Setter
     * @param horaUCTurma Lista de objetos do tipo Slot
     * @brief Complexidade O(1)
     */
    void setHoraUCTurma(list<Slot> horaUCTurma);


    /** Getter
     * @return Objeto do tipo UCTurma
     * @brief Complexidade O(1)
     */
    pair<string,string> getUcTurma();


    /** Getter
     * @return Lista de objetos do tipo Slot
     * @brief Complexidade O(1)
     */
    list<Slot> getHoraUCTurma();


    /** Operator Overload para comparar duas UC's
     * @param th Objeto do tipo THorario
     * @brief Complexidade O(1)
     */
    bool operator<(const THorario &th) const;


private:

    pair<string,string> ucturma;     /** Objeto do tipo UCTurma */
    list<Slot> horaUCTurma;          /** Lista de objetos do tipo Slot */

};


#endif //AED_PROJETO_THORARIO_H
