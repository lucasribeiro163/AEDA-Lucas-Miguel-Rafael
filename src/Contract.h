//
// Created by Rafael on 23-12-2019.
//

#ifndef AEDA_LUCAS_MIGUEL_RAFAEL_CONTRACT_H
#define AEDA_LUCAS_MIGUEL_RAFAEL_CONTRACT_H

#include "Data.h"

class Contract {
    Data contractDate;
    //Data startDate;
    //Data endDate;
    int id; // using id of car instead of license plates
    string clientName;
    int typeContract; // Cedencia ou aluger de veiculo

public:
    Contract(string name, int type);
    Contract(Data contractDate, string clientName, int carId, int typeContract);

    const Data &getContractDate() const;

    //const Data &getStartDate() const;

    //const Data &getEndDate() const;

    int getId() const;

    const string &getClientName() const;

    int getTypeContract() const;

    bool operator <(const Contract &contract1) const;
    bool operator ==(const Contract &contract1) const;

};


#endif //AEDA_LUCAS_MIGUEL_RAFAEL_CONTRACT_H
