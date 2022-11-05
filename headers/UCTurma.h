#ifndef AED_PROJETO_UCTURMA_H
#define AED_PROJETO_UCTURMA_H

#include "THorario.h"    /** O header 'THorario.h' contém definições de constantes usadas neste header */


class UCTurma {

public:

    /** Default Constructor
     * @brief Complexidade O(1)
     */
    UCTurma();


    /** Constructor
     * @param ucturma Par de duas strings, código da UC e código da turma
     * @brief Complexidade O(1)
     */
    UCTurma(pair<string, string> ucturma);


    /** Getter
     * @return Par de duas strings, código da UC e código da turma
     * @brief Complexidade O(1)
     */
    pair<string,string> getUCTurma();


    /** Setter
     * @param ucturma Par de duas strings, código da UC e código da turma
     * @brief Complexidade O(1)
     */
    void setUCTurma(pair<string, string> ucturma);


    /** Operator overload para comparar objetos do tipo UCTurma
     * @param uct Par de duas strings, código da UC e código da turma
     * @return True se a UC tem um codigo menor do que o do parametro uct
     * @return False se acontece o contrário
     * @brief Complexidade O(1)
     */
    bool operator<(const UCTurma &uct) const;

private:

    pair<string,string> ucturma;      /** Par de duas strings, código da UC e código da turma */

};


#endif //AED_PROJETO_UCTURMA_H
