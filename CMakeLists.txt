cmake_minimum_required(VERSION 3.10)
project(AEDA_PROJ)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)



add_executable(AEDA_PROJ src/main.cpp src/tests.cpp src/Data.cpp src/Hora.cpp src/Reserva.cpp src/Transacao.cpp src/Utilizador.cpp src/Veiculo.cpp)

target_link_libraries(AEDA_PROJ gtest gtest_main)
