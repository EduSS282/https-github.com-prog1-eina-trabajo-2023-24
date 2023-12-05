/******************************************************************************\
 * Programación 1. Trabajo de asignatura del curso 2023-24
 * Autores: Miguel Ángel Latre
 * Modificado por: ¡¡¡PONED AQUÍ VUESTROS NOMBRES!!!
 * Ultima revisión: ¡¡¡!!!
 * Resumen: Fichero de interfaz de un módulo que ofrece funciones para
 *          implementar las opciones del menú del programa principal de este
 *          trabajo a partir de grupos de temperaturas ya obtenidas
 *          de un fichero.
\******************************************************************************/

#pragma once

#include <string>
#include "temperaturas.hpp"
using namespace std;

/*
 * Pre:  ---
 * Post: Escribe en la pantalla una tabla en la que se muestran los datos del
 *       registro «temperaturas»: el nombre de la localidad, el año y las temperaturas
 *       de cada mes, tanto en grados Celsius como Fahrenheit, con una precisión
 *       de un decimal, tal y como se muestra a continuación:
 *              Temperaturas medias mensuales
 *              ZARAGOZA (2021)
 *              -------------------------------------------------------
 *              Enero         7.0 °C   44.6 °F
 *              Febrero      11.6 °C   52.9 °F
 *              Marzo        12.0 °C   53.6 °F
 *              Abril        13.7 °C   56.7 °F
 *              Mayo         18.6 °C   65.5 °F
 *              Junio        23.3 °C   73.9 °F
 *              Julio        25.9 °C   78.6 °F
 *              Agosto       25.9 °C   78.6 °F
 *              Septiembre   22.2 °C   72.0 °F
 *              Octubre      16.4 °C   61.5 °F
 *              Noviembre    10.2 °C   50.4 °F
 *              Diciembre     7.6 °C   45.7 °F
 */
void listarTemperaturas(const TempsLocalAnual& temperaturas);


/*
 * Pre:  ---
 * Post: Escribe en la pantalla estadísticos (máximo, mínimo, media y
 *       desviación) en grados Celsius de los datos de temperatura del registro
 *       «temperaturas», con una precisión de un decimal, tal y como se muestra a
 *       continuación:
 *              Estadísticos
 *              TERUEL (2018)
 *              ------------------------------------------
 *              Temperatura media mensual máxima:  23.4 °C
 *              Temperatura media mensual mínima:   5.6 °C
 *              Temperatura media anual:           13.3 °C
 *              Desviación típica:                  6.5 °C
 */
void estadisticos(const TempsLocalAnual& temperaturas);

/*
 * Pre:  El vector «tempsAnuales» tiene una dimensión de «NUM_AGNOS» componentes.
 *       El valor del campo «localidad» de cada componente corresponde a una
 *       misma localidad, y el campo «agno» de cada componente tiene valores
 *       crecientes consecutivos. 
 * Post: Escribe en la pantalla la evolución de la temperatura media anual
 *       (en grados Celsius y con una precisión de un decimal)
 *       reflejada por los datos de temperatura de las distintas componentes del
 *       vector «tempsAnuales», tal y como se muestra a continuación:
 * 
 *               Evolución de temperaturas
 *               HUESCA
 *               ------------------------------------------
 *               2015   15.5 °C
 *               2016   14.6 °C   -0.9 °C
 *               2017   14.7 °C   +0.1 °C
 *               2018   14.8 °C   +0.1 °C
 *               2019   14.5 °C   -0.3 °C
 *               2020   14.8 °C   +0.3 °C
 *               2021   14.3 °C   -0.5 °C
 *       La primera columna de la tabla representa los años a los que
 *       corresponden las medias, la segunda, la temperatura media anual en sí
 *       y la tercera, la diferencia entre la temperatura media del año en
 *       cuestión con respecto al anterior. Va precedida de un signo «+» o un
 *       signo «-», dependiendo de si la diferencia representa un incremento o
 *       un decremento. En el caso del primer año, se omite esta información.
 */
void evolucion(const TempsLocalAnual tempsAnuales[]);

/*
 * Pre:  El parámetro «flujo» es «cout» o un «ofstream» asociado con un fichero
 *       de texto en el que se puede escribir.
 * Post: Escribe en «flujo» un gráfico con las temperaturas mensuales del 
 *       registro «temperaturas» con el formato que se muestra a continuación:
 * 
 *               Gráfico
 *               CALATAYUD (2015)
 *               -------------------------------------------------------
 *                  30 |                                                
 *                     |                                                
 *                     |                           *                    
 *                     |                           *                    
 *                     |                           *   *                
 *                  20 |                       *   *   *                
 *                     |                       *   *   *   *            
 *                     |                   *   *   *   *   *            
 *                     |                   *   *   *   *   *   *        
 *                     |               *   *   *   *   *   *   *        
 *                  10 |               *   *   *   *   *   *   *   *    
 *                     |           *   *   *   *   *   *   *   *   *    
 *                     |       *   *   *   *   *   *   *   *   *   *   *
 *                     |   *   *   *   *   *   *   *   *   *   *   *   *
 *                     |   *   *   *   *   *   *   *   *   *   *   *   *
 *                   0 |   *   *   *   *   *   *   *   *   *   *   *   *
 *                     |   *   *   *   *   *   *   *   *   *   *   *   *
 *                     |   *   *   *   *   *   *   *   *   *   *   *   *
 *                     |   *   *   *   *   *   *   *   *   *   *   *   *
 *                     |   *   *   *   *   *   *   *   *   *   *   *   *
 *                 -10 |   *   *   *   *   *   *   *   *   *   *   *   *
 *                     +------------------------------------------------
 *                         1   2   3   4   5   6   7   8   9  10  11  12
 */
void escribirGrafico(const TempsLocalAnual& temperaturas, ostream& flujo);

/*
 * Pre:  El vector «tempsAnuales» tiene una dimensión de «NUM_AGNOS» componentes.
 *       El valor del campo «localidad» de cada componente corresponde a una
 *       misma localidad, y el campo «agno» de cada componente tiene valores
 *       crecientes consecutivos. 
 * Post: Escribe en un fichero denominado «nombreFichero» los gráficos con
 *       las temperaturas mensuales de las componentes del vector «tempsAnuales», con
 *       exactamente el mismo formato que se muestra en la poscondición del
 *       procedimiento «escribirGrafico». Asigna a «escrituraOk» el valor «true» si
 *       el fichero denominado «nombreFichero» se ha podido crear o escribir sin
 *       problemas y «false» en caso contrario.
 */
void escribirGraficos(const TempsLocalAnual tempsAnuales[], const string nombreFichero,
                      bool& escrituraOk);
