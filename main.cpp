#include <iostream>

#include "cpps/GestaoHorario.cpp"

int main() {
    GestaoHorario gh;
    gh.lerFichEst();
    gh.pedidos();
    gh.guardar();
    gh.processsar();
    gh.listagem();
    return 0;
}
