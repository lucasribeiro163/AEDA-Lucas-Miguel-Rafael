cmake_minimum_required(VERSION 3.14)
project(Project)

set(CMAKE_CXX_STANDARD 14)

add_executable(Project main.cpp src/Data.cpp src/Empresa.cpp src/Hora.cpp src/Reserva.cpp
        src/Utilizador.cpp src/Veiculo.cpp src/Menu.cpp src/Preferencia.cpp src/Preferencia.h src/bst.h src/Contract.cpp src/Contract.h)