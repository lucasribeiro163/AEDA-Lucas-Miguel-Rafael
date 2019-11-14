//
// Created by Lucas on 11/2/2019.
//

#ifndef UNTITLED_HORA_H
#define UNTITLED_HORA_H
#include <string>

using namespace std;

class Hora {
    int hora;
    int minuto;
    int segundo;

public:

    Hora(string &horaRecebida);

    int getHora() const;

    void setHora(int hora);

    int getMinuto() const;

    void setMinuto(int minuto);

    int getSegundo() const;

    void setSegundo(int segundo);

    bool operator<=(Hora hora);
};


#endif //UNTITLED_HORA_H
