//
// Created by pland on 30/10/2022.
//

#include "../headers/Sort.h"
#include "../cpps/Estudante.cpp"


set<Estudante> Sort::sortSetIdCrescente(set<Estudante> &estudantes) {
    set<Estudante> estudantes1;
    for(auto it = estudantes.begin(); it != estudantes.end(); it++){
        estudantes1.insert(*it);
    }
        
    
    estudantes = estudantes1;
    return estudantes;
}