#include <iostream>
#include "src/Data.cpp"

using namespace std;

void login() {
    string inputId;
    cout << "What is your id?" << endl;
    getline(cin, inputId);
    /*if(company.isRegistered(inputId)){
     * showClientMenu();
    }
     else{
        cout << "Sorry, that id doesn't match any client" << endl;
        login();
     }
     */
}

void checkRegister() {
    cout << "Are you registered? (Y/N)" << endl;
    string isRegistered;
    getline(cin, isRegistered);
    if ((isRegistered == "Y") || (isRegistered == "y")) {
        cout << "Welcome" << endl;
        login();
    }
    else {
        if ((isRegistered == "N") || (isRegistered == "n")) {
            cout << "Here are the company's offers: " << endl;
            //showOffers();
        } else {
            cout << "Sorry, wrong input" << endl;
            checkRegister();
        }
    }
}

int main() {
    cout << "Welcome to the agency" << endl;
    checkRegister();
    return 0;
}