#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    ifstream f;
    f.open("datos/climatologia-2015.csv");
    string cabecera;
    string localidadArchivo;
    getline(f,cabecera);
    getline(f,localidadArchivo,',');
    
    unsigned mes,agno;
    double tempMax,tempMin,tempMedia;
    f >> mes;
    f.ignore();
    f >> agno;
    f.ignore();
    f >> tempMax;
    f.ignore();
    f >> tempMin;
    f.ignore();
    f >> tempMedia;
    cout << localidadArchivo << endl;
    cout << mes << " " << agno << " " << tempMax << " " << tempMin << " " << tempMedia << endl;
    f.close();
}