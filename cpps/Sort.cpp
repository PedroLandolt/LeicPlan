#include "../headers/Sort.h"


void Sort::sortUPCrescente(vector<Estudante> &estudantes) {

    sort(estudantes.begin(), estudantes.end(), [](Estudante &a, Estudante &b) {
        return a.getEstudantePair().first < b.getEstudantePair().first;
    });
}

void Sort::sortUPDecrescente(vector<Estudante> &estudantes) {

    sort(estudantes.begin(), estudantes.end(), [](Estudante &a, Estudante &b) {
        return a.getEstudantePair().first > b.getEstudantePair().first;
    });
}

void Sort::sortNomeCrescente(vector<Estudante> &estudantes) {

    sort(estudantes.begin(), estudantes.end(), [](Estudante &a, Estudante &b) {
        return a.getEstudantePair().second < b.getEstudantePair().second;
    });
}

void Sort::sortNomeDecrescente(vector<Estudante> &estudantes) {

    sort(estudantes.begin(), estudantes.end(), [](Estudante &a, Estudante &b) {
        return a.getEstudantePair().second > b.getEstudantePair().second;
    });
}

void Sort::sortPairCrescente(vector<pair<int, string>> &estudantes) {

    sort(estudantes.begin(), estudantes.end(), [](pair<int, string> &a, pair<int, string> &b) {
        return a.first < b.first;
    });
}

void Sort::sortPairDecrescente(vector<pair<int, string>> &estudantes) {

    sort(estudantes.begin(), estudantes.end(), [](pair<int, string> &a, pair<int, string> &b) {
        return a.first > b.first;
    });
}

void Sort::sortPairNomeCrescente(vector<pair<int, string>> &estudantes) {

    sort(estudantes.begin(), estudantes.end(), [](pair<int, string> &a, pair<int, string> &b) {
        return a.second < b.second;
    });
}

void Sort::sortPairNomeDecrescente(vector<pair<int, string>> &estudantes) {

    sort(estudantes.begin(), estudantes.end(), [](pair<int, string> &a, pair<int, string> &b) {
        return a.second > b.second;
    });
}
