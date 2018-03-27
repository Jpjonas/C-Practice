/* JONAS POLLNOW
 * PROGRAMACIÓN 2
 *
 * COMANDOS DE COMPILACIÓN Y EJECUCIÓN
 * EJECUTAR EN LINUX
 * gcc -o main main.c
 *./main
 */

//BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <time.h>

//STRUCT
struct jugador{
  char nombre[30];
  int habitacion;
  int *cartas;
  int cantidadeCartas;
  int perdio;
};

//DEFINICIONES
#define SOSPECHOSO 1
#define HABITACION 2
#define ARMA 3
#define SI 1
#define NO 0
#define HORARIO 0
#define ANTIHORARIO 1
#define Cocina 6
#define Spa 8
#define Observatorio 11
#define HabitacionHuespedes 13

//PROTOTIPOS Y DOCUMENTACIÓN DE LAS FUNCIONES

/* REPRESENTAMOS LA CANTIDADE DE JUGADORES MEDIANTE NÚMEROS ENTEROS
 * validaCantidadJugadores: INT -> INT
 * EL PARÁMETRO REPRESENTA LA CANTIDAD DE JUGADORES
 * RETORNA 1 SI EL PARAMETRO ESTA ENTRE TRES Y SEIS, O CERO SI NO ESTA
 */
int validaCantidadJugadores(int cantidadJugadores);

/* REPRESENTAMOS LA CANTIDAD DE JUGADORES Y EL JUGADOR CON NÚMEROS ENTEROS
 * calculaCantidadCartas: INT INT -> INT
 * EL PARÁMETRO nrJugadores REPRESENTA LA CANTIDAD TOTAL DE JUGADORES Y
 * EL PARÁMETRO jugador REPRESENTA EL INDICE DEL JUGADOR EN LA LISTA DE JUGADORES
 * RETORNA LA CANTIDAD DE CARTAS DEL JUGADOR
 */
int calculaCantidadCartas(int cantidadJugadores,int jugador);

/* REPRESENTAMOS LA DIRECCIÓN(HORARIO/ANTIHORARIO), LA HABITACIÓN ATUAL DEL JUGADOR Y
 * LA CANTIDADE DE HABITACIONES QUE EL JUGADOR VA A DESPLAZAR CON NÚMEROS ENTEROS
 * calculaNuevaHabitacion: INT INT INT -> INT
 * EL PARÁMETRO direccion REPRESENTA SI EL JUGADOR VA A DESPLAZAR EN EL SENTIDO HORARIO O ANTIHORARIO
 * EL PARÁMETRO habitacionAtual ES LA HABITACIÓN DONDE EL JUGADOR ESTA
 * EL PARÁMETRO numeroHabitaones REPRESENTA LA CANTIDAD DE HABITACIONES Q EL JUGADOR VA A DESPLAZAR
 */
int calculaNuevaHabitacion(int direccion,int habitacionAtual, int numeroHabitaciones);

/* REPRESENTAMOS SOSPECHOSO, HABITACIÓN Y ARMA CON NÚMEROS ENTEROS
 * preguntaDadosSuposicion: INT* INT* INT* -> VOID
 * LAS TRES INFORMACIONES SON PREGUNTADOS AL JUGADOR Y GRAVADAS EN LAS VARIABLES APUNTADAS
 * POR LOS APUNTADORES
 * ENTRADA TECLADO: 5 9 17 -> *sospechoso=5 *habitacion=9 *arma=17
 * ENTRADA TECLADO: 2 8 19 -> *sospechoso=2 *habitacion=8 *arma=19
 * ENTRADA TECLADO: 0 12 20 -> *sospechoso=0 *habitacion=12 *arma=20
 */
void preguntaDadosSuposicion(int *sospechoso,int *habitacion,int *arma);

/* REPRESENTAMOS UN JUGADOR CON UNA ESTRUCTURA JUGADOR
 * imprimeInformacionesJugador: STRUCT JUGADOR -> VOID
 * LA FUNCIÓN RECIBE UN REGISTRO DEL TIPO JUGADOR, Y IMPRIME SU HABITACIÓN
 * Y LAS CARTAS, PARA QUE EL JUGADOR NO TENGA DUDA DE SUS CARTAS E SU HABITACIÓN
 * ENTRADA:  jugador{
 *             nombre: Fernando
 *             habitacion: 7
 *             cartas: 0 5 17 12 19
 *             cantidadCartas: 5
 *             perdio: NO
 *            }
 * SALIDA:  Habitacion: 7-Patio
 *          Cartas: 0-Senorita Escarlata
 *                  5-Senora Blanco
 *                  17-Lazo
 *                  12-Vestibulo
 *                  19-Llave Inglesa
 * ENTRADA:  jugador{
 *             nombre: Tomas
 *             habitacion: 9
 *             cartas: 3 7 18
 *             cantidadCartas: 3
 *             perdio: NO
 *            }
 * SALIDA:  Habitacion: 9-Teatro
 *          Cartas: 3-Senora Azulino
 *                  7-Patio
 *                  18-Candelabro
 * ENTRADA:  jugador{
 *             nombre: Juan
 *             habitacion: 8
 *             cartas: 2 4 15 16
 *             cantidadCartas: 4
 *             perdio: NO
 *            }
 * SALIDA:  Habitacion: 8-Spa
 *          Cartas: 2-Profesor Moradillo
 *                  4-Senor Verdi
 *                  15-Revolver
 *                  16-Cuchillo
 */
void imprimeInformacionesJugador(struct jugador *jugador);

/* REPRESENTAMOS UN JUGADOR CON UNA ESTRUCTURA JUGADOR
 * imprimeCartasJugador: STRUCT JUGADOR -> VOID
 * LA FUNCIÓN RECIBE UN REGISTRO DEL TIPO JUGADOR,
 * Y IMPRIME TODAS LAS CARTAS DEL JUGADOR
 * ENTRADA:  jugador{
 *             nombre: Fernando
 *             habitacion: 7
 *             cartas: 0 5 17 12 19
 *             cantidadCartas: 5
 *             perdio: NO
 *            }
 * SALIDA:  0-Senorita Escarlata
 *          5-Senora Blanco
 *          17-Lazo
 *          12-Vestibulo
 *          9-Llave Inglesa
 * ENTRADA:  jugador{
 *             nombre: Tomas
 *             habitacion: 9
 *             cartas: 3 7 18
 *             cantidadCartas: 3
 *             perdio: NO
 *            }
 * SALIDA:  3-Senora Azulino
 *          7-Patio
 *          18-Candelabro
 * ENTRADA:  jugador{
 *             nombre: Juan
 *             habitacion: 8
 *             cartas: 2 4 15 16
 *             cantidadCartas: 4
 *             perdio: NO
 *            }
 * SALIDA:  2-Profesor Moradillo
 *          4-Senor Verdi
 *          15-Revolver
 *          16-Cuchillo
 */
void imprimeCartasJugador(struct jugador *jugador);

/* REPRESENTAMOS LOS INDICES DE LAS CARTAS CON NÚMEROS ENTEROS
 * imprimeCartas: INT INT -> VOID
 * LA FUNCIÓN RECIBE DOS INDICES DE CARTAS, Y IMPRIME TODAS LAS CARTAS
 * CON INDICES ENTRE ESTOS DOS INDICES
 * ENTRADA: 4 7
 * SALIDA: 4-Senor Verdi
 *         5-Senora Blanco
 *         6-Cocina
 *         7-Patio
 * ENTRADA: 8 10
 * SALIDA: 8-Spa
 *         9-Teatro
 *         10-Salon
 * ENTRADA:16 17
 * SALIDA: 16-Cuchillo
 *         17-Lazo
 */
void imprimeCartas(int primerIndice,int ultimoIndice);

/* REPRESENTAMOS LAS CARTAS CON NÚMEROS ENTEROS
 * imprimeCarta: INT -> VOID
 * LA FUNCIÓN RECIBE UN ENTERO QUE REPRESENTA EL INDICE DE UNA CARTA
 * Y IMPRIME ESTA CARTA
 * ENTRADA: 5
 * SALIDA: 5-Senora Blanco
 * ENTRADA: 10
 * SALIDA: 10-Salon
 * ENTRADA: 18
 * SALIDA: 18-Candelabro
 */
void imprimeCarta(int carta);

/* FUNCIÓN QUE IMPRIME EL TABLERO DE HABITACIONES
 * EN TELA PARA EL JUGADOR
 * imprimeTablero: VOID -> VOID
 * SALIDA:
 * ====================================================
 * |     6-Cocina    |    7-Patio   |      8-Spa      |
 * ====================================================
 * |                 |    \   /     |     9-Teatro    |
 * |    14-Comedor   |      X       |=================|
 * |                 |    /   \     |     10-Salon    |
 * ====================================================
 * |  13-Habitacion  | 12-Vestibulo | 11-Observatorio |
 * |   de huespedes  |              |                 |
 * ====================================================
 */
void imprimeTablero();
