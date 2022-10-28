cmake_minimum_required(VERSION 3.23)
project(aed_projeto)

set(CMAKE_CXX_STANDARD 20)

add_executable(aed_projeto main.cpp cpps/GestaoHorario.cpp headers/GestaoHorario.h cpps/Estudante.cpp headers/Estudante.h cpps/THorario.cpp headers/THorario.h cpps/Pedido.cpp headers/Pedido.h cpps/UCTurma.cpp headers/UCTurma.h cpps/Slot.cpp headers/Slot.h)
