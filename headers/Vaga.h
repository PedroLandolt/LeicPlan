#ifndef AED_PROJETO_VAGA_H
#define AED_PROJETO_VAGA_H

/** Dependencies */

#include <string>
#include <vector>
#include <iostream>
#include <utility>
#include <iterator>
#include <queue>
#include <fstream>
#include <sstream>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <cctype>

#include "conio.h"
#include "windows.h"

using namespace std;


class Vaga {

public:

    /** Default Constructor */
    Vaga();


    /** Constructor
     * @param uc String com o código de uma UC
     * @param vagas Lista de pares composto por uma string, codigo da turma, e um inteiro, numero de vagas dessa turma
     */
    Vaga(string uc , list<pair<string, int>> vagas);


    /** Getter
     * @return Lista de pares composto por uma string, codigo da turma, e um inteiro, numero de vagas dessa turma
     */
    list<pair<string,int>>& getVagas();


    /** Getter
     * @return String com o código de uma UC
     */
    string getUC();


    /** Setter
     * @param vagas Lista de pares composto por uma string, codigo da turma, e um inteiro, numero de vagas dessa turma
     */
    void setVagas(list<pair<string,int>> vagas);


    /** Setter
     * @param uc String com o código de uma UC
     */
    void setUC(string uc);


private:

    list<pair<string,int>> vagas;     /** Lista de pares composto por uma string (codigo da turma), e um inteiro (numero de vagas dessa turma) */
    string uc;                        /** String com o código de uma UC */

};


#endif //AED_PROJETO_VAGA_H