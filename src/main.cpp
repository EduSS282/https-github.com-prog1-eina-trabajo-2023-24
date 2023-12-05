/******************************************************************************\
 * Programación 1. Trabajo de asignatura del curso 2023-24
 * Autores: ¡¡¡PONED AQUÍ VUESTROS NOMBRES!!!
 * Ultima revisión: ¡¡¡!!!
 * Resumen: ¡¡¡!!!
 * Nota: El código de este programa está repartido en varios módulos.
 *       Para compilarlo, hay que ejecutar el comando
 *           make all
 *       o ejecutar la tarea "Compilar «gestor»" de VSC.
 * 
 *       Para ejecutarlo, una vez compilado, hay que ejecutar el comando
 *           bin/gestor
 *       o, en Windows,
 *           bin\gestor.exe
 *       o ejecutar la tarea "Ejecutar «gestor»" de VSC.
\******************************************************************************/
#include "temperaturas.hpp"
#include <iostream>
#include <string>
using namespace std;

int main() {
    TempsLocalAnual zaragoza[7];
    bool todook = true;
    obtenerTodasTempsLocalidad(zaragoza, todook);
    for (unsigned i = 0; i < 7; i++){
        cout << zaragoza[i].agno << " ";
        for (unsigned j = 0; j < 12; j++) {
        cout << zaragoza[i].temperaturas[j] << " ";
        }
        cout << endl;
    }
    
}
