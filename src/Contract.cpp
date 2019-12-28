//
// Created by Rafael on 23-12-2019.
//

#include "Contract.h"

Contract::Contract(Data dateContract, string clientName, int carId, int typeContract): contractDate(dateContract){
    this->clientName = clientName;
    this->id = carId;
    this->typeContract = typeContract;
}
Contract::Contract(string name, int type) : clientName(name),typeContract(type){

}

bool Contract::operator<(const Contract &contract1) const {
    if(this->contractDate <= contract1.getContractDate())
    {
        if(this->contractDate == contract1.getContractDate())
        {
            if(this->clientName < contract1.getClientName())
            {
                return true;
            }
        }
        return true;
    }
    return false;
}

const Data &Contract::getContractDate() const {
    return contractDate;
}
/*
const Data &Contract::getStartDate() const {
    return startDate;
}

const Data &Contract::getEndDate() const {
    return endDate;
}
*/
int Contract::getId() const {
    return id;
}

const string &Contract::getClientName() const {
    return clientName;
}

int Contract::getTypeContract() const {
    return typeContract;
}

