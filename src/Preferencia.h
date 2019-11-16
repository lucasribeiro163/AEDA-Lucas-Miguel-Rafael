//
// Created by migue on 11/13/2019.
//

#ifndef PROJECT_PREFERENCIA_H
#define PROJECT_PREFERENCIA_H


#include "Data.h"

class Preferencia {
    unsigned int precoMax, anoMax, tipo, nrPass = 0;
    float peso_carga, volume = 0 ;
    bool refrigeracao;
    string preferencias;
public:
    Preferencia(int precoMax, int anoMax, int nrPass);
    Preferencia(int precoMax, int anoMax, float peso_carga, float volume, bool refrigeracao);
    Preferencia(string preferencias);

    int getPrecoMax() const;
    void setPrecoMax(int &preco);

    int getAnoMax() const;
    void setaAnoMax(int &ano);

    int getNrPass() const;
    void setNrPass(int &nrPass);

    float getPeso_carga() const;
    void setPeso_carga(float &peso_carga);

    float getVolume() const;
    void setVolume(float &volume);

    bool getRefrigeracao() const;
    void setRefrigeracao(bool &refrigeracao);
    int getTipo() const;

};


#endif //PROJECT_PREFERENCIA_H
