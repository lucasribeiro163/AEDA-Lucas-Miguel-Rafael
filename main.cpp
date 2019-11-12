#include "src/Empresa.h"
#include"src/Menu.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    string empresaFile = "empresa.txt";
    Empresa empresa(empresaFile);
    Menu menu(empresa);
    return 0;
}