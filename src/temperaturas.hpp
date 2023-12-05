/******************************************************************************\
 * Programación 1. Trabajo de asignatura del curso 2023-24
 * Autores: Miguel Ángel Latre
 * Modificado por: ¡¡¡PONED AQUÍ VUESTROS NOMBRES!!!
 * Ultima revisión: ¡¡¡!!!
 * Resumen: Fichero de interfaz de un módulo para trabajar con registros que 
 *          representan grupos de temperaturas mensuales de una localidad en un
 *          año, con funciones que permiten obtener esos datos de los ficheros
 *          descritos en el enunciado del trabajo.
\******************************************************************************/

#pragma once

#include <string>
using namespace std;

const unsigned NUM_MESES = 12;
const unsigned AGNO_INICIAL = 2015;
const unsigned AGNO_FINAL = 2021;
const unsigned NUM_AGNOS = AGNO_FINAL - AGNO_INICIAL + 1;
const string RUTA_DATOS = "datos/";


struct TempsLocalAnual {
    // Define los campos necesarios para representar el grupo de temperaturas
    // mensuales de una localidad en un año.
    string localidad;
    unsigned agno;
    double temperaturas[NUM_MESES];
};


/*
 * Pre:  En el directorio «RUTA_DATOS» existen ficheros denominados 
 *       «climatologia-XXXX.csv» para cada valor XXXX entre «AGNO_INICIAL» y 
 *       «AGNO_FINAL» que siguen la sintaxis de la regla <fichero-climatología>
 *       del enunciado.
 * Post: Solicita al usuario una localidad y un año. Si el año está entre
 *       «AGNO_INICIAL» y «AGNO_FINAL» y en el fichero «climatologia-XXXX.csv»,
 *       siendo XXXX el año introducido por el usuario, hay datos
 *       correspondientes a la localidad introducida por el usuario, ha
 *       inicializado el registro «temperaturas» con los datos adecuados de
 *       temperaturas medias mensuales y asigna a «ok» el valor «true».
 *       Si el año no está entre «AGNO_INICIAL» y «AGNO_FINAL» o no hay datos
 *       para la localidad solicitada o si no se pueden leer los ficheros,
 *       muestra un mensaje de error al usuario y asigna a «ok» el valor «false». 
 */
void obtenerTempsLocalAnual(TempsLocalAnual& temperaturas, bool& ok);


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
void obtenerTodasTempsLocalidad(TempsLocalAnual tempsAnuales[], bool& todoOk);
