//
// Created by pland on 30/10/2022.
//



#include "../headers/Sort.h"

vector<pair<int,string>> Sort::sortUPCrescente(vector<Estudante> &estudantes) {
    vector<pair<int,string>> estudantesUPCrescente;
    for (auto &estudante : estudantes) {
        estudantesUPCrescente.push_back(estudante.getEstudantePair());
    }
    sort(estudantesUPCrescente.begin(), estudantesUPCrescente.end());
    return estudantesUPCrescente;
}

vector<pair<int,string>> Sort::sortUPDecrescente(vector<Estudante> &estudantes) {
    vector<pair<int,string>> estudantesUPDecrescente;
    for (auto &estudante : estudantes) {
        estudantesUPDecrescente.push_back(estudante.getEstudantePair());
    }
    sort(estudantesUPDecrescente.begin(), estudantesUPDecrescente.end(), greater<pair<int,string>>());
    return estudantesUPDecrescente;
}

vector<pair<int,string>> Sort::sortNomeCrescente(vector<Estudante> &estudantes) {
    vector<pair<int,string>> estudantes1;
    for(auto it = estudantes.begin(); it != estudantes.end(); it++){
        pair<int,string> estudante = it -> getEstudantePair();
        estudantes1.push_back(estudante);
    }
    sort(estudantes1.begin(), estudantes1.end(), [](const std::pair<int,string> &left, const std::pair<int,string> &right) {
        return left.second < right.second;
    });
    return estudantes1;
}

vector<pair<int,string>> Sort::sortNomeDecrescente(vector<Estudante> &estudantes) {
    vector<pair<int,string>> estudantes1;
    for(auto it = estudantes.begin(); it != estudantes.end(); it++){
        pair<int,string> estudante = it -> getEstudantePair();
        estudantes1.push_back(estudante);
    }
    sort(estudantes1.begin(), estudantes1.end(), [](const std::pair<int,string> &left, const std::pair<int,string> &right) {
        return left.second < right.second;
    });
    reverse(estudantes1.begin(), estudantes1.end());
    return estudantes1;
}

/*
bool sortbysec(const pair<int, string> &a, const pair<int, string> &b) {
    return (a.second < b.second);
}
*/