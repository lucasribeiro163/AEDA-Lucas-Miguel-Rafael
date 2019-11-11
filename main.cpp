#include "src/Empresa.h"
#include"src/Menu.h"

int main() {
    string empresaFile = "empresa.txt";
    Empresa empresa(empresaFile);
    Menu menu(empresa);
    return 0;
}