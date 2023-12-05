#include "temperaturas.hpp"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void obtenerTempsLocalAnual(TempsLocalAnual& temperaturas, bool& ok){
    cout << "Introduzca una localidad: ";
    getline(cin, temperaturas.localidad);
    for (unsigned i = 0; i < temperaturas.localidad.length(); i++){
        temperaturas.localidad[i] = toupper(temperaturas.localidad[i]);
    }
    cout << "Introduzca un año: ";
    cin >> temperaturas.agno;
    if (temperaturas.agno>=AGNO_INICIAL && temperaturas.agno<=AGNO_FINAL){
        ifstream f;
        f.open("datos/climatologia-"+to_string(temperaturas.agno)+".csv");
        if (f.is_open()){
            string cabecera;
            // Quitamos cabecera.
            getline(f,cabecera);
            string localidad;   
            while (getline(f,localidad,',')){
                for (unsigned i = 0; i < localidad.length(); i++){
                    localidad[i] = toupper(localidad[i]);
                }  
                unsigned mes,agno;
                double precipitaciones,tempMax,tempMin,tempMedia;
                f >> mes;
                f.ignore();
                f >> agno;
                f.ignore();
                f >> precipitaciones;
                f.ignore();
                f >> tempMax;
                f.ignore();
                f >> tempMin;
                f.ignore();
                f >> tempMedia;
                // Ignoro el salto de lineap para poder leer la siguiente.
                f.ignore();
                if (localidad == temperaturas.localidad){
                    temperaturas.temperaturas[mes-1] = tempMedia;
                }                
            }
            ok = true;
            f.close();            
        } else {
            cerr << "No se ha podido abrir el fichero que contiene los datos de " << temperaturas.agno << endl;
        }
    }
    else
    {
        cout << "El año introducido no es válido." << endl;
        ok = false;
    }
}



/*
 * Pre:  En el directorio «RUTA_DATOS» existen ficheros denominados 
 *       «climatologia-XXXX.csv» para cada valor XXXX entre «AGNO_INICIAL» y 
 *       «AGNO_FINAL» que siguen la sintaxis de la regla <fichero-climatología>
 *       del enunciado.
 * Post: Solicita al usuario una localidad. Si en todos los ficheros
 *       «climatologia-XXXX.csv» hay datos correspondientes a la localidad
 *       introducida por el usuario, inicializa los registros del vector 
 *       «tempsAnuales» con los datos adecuados de temperaturas medias mensuales y
 *       asigna a «todoOk» el valor «true».
 *       Si no hay datos para la localidad solicitada en alguno de los ficheros
 *       o si no se pueden leer los ficheros, muestra un mensaje de error al
 *       usuario y asigna a «todoOk» el valor «false». 
 */
void obtenerTodasTempsLocalidad(TempsLocalAnual tempsAnuales[], bool& todoOk){
    todoOk = true;
    string localidad;
    cout << "Introduzca una localidad: ";
    getline(cin,localidad);
    
    
    for (unsigned i = 0; i < NUM_AGNOS; i++){      
        for (unsigned j = 0; j < localidad.length(); j++){
            localidad[j] = toupper(localidad[j]);
        }
        tempsAnuales[i].agno = AGNO_INICIAL+i;
        tempsAnuales[i].localidad = localidad;    
        ifstream f;
        f.open("datos/climatologia-"+to_string(AGNO_INICIAL+i)+".csv");
        if (f.is_open()){
            string cabecera;
            // Quitamos cabecera.
            getline(f,cabecera);
                    
            string localidadArchivo;
            while (getline(f,localidadArchivo,',')){
                    
                unsigned mes,agno;
                double precipitaciones,tempMax,tempMin,tempMedia;
                f >> mes;
                f.ignore();
                f >> agno;
                f.ignore();
                f >> precipitaciones;
                f.ignore();
                f >> tempMax;
                f.ignore();
                f >> tempMin;
                f.ignore();
                f >> tempMedia;
                // Ignoro el salto de lineap para poder leer la siguiente.
                f.ignore();
                if (localidadArchivo == tempsAnuales[i].localidad){
                    tempsAnuales[i].temperaturas[mes-1] = tempMedia;
                }
            }
            f.close();
        } else {
            cerr << "No se ha podido abrir el fichero que contiene los datos de " << AGNO_INICIAL+i << endl;
            todoOk = false;
        }
    }
    if (!todoOk){
        cerr << "Algún fichero no se ha podido abrir o \"" << localidad << "\" no tiene datos para todos los años." << endl;
    }
}