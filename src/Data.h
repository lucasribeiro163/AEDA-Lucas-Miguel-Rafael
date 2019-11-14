//
// Created by Lucas on 11/2/2019.
//

#ifndef UNTITLED_DATA_H
#define UNTITLED_DATA_H

#include "Hora.h"

class Data {

    int ano;
    int mes;
    int dia;
    Hora hora;

public:

    int getAno() const;

    void setAno(int ano);

    int getMes() const;

    void setMes(int mes);

    int getDia() const;

    void setDia(int dia);

    bool operator<=(Data data);
};


#endif //UNTITLED_DATA_H
