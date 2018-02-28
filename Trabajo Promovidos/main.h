/* Jonas Pollnow
 * Programación 2
 *
 * Comandos de compilación y ejecución
 * gcc -o main main.c
 *./main
 */

//BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <time.h>

//STRUCTS
struct jugador{
  char nombre[30];
  int habitacion;
  int *cartas;
  int perdio; //0 -> continua en el juego. 1 -> perdio el juego
};

//DEFINICIONES
#define SOSPECHOSOS 6
#define HABITACIONES 9
#define ARMAS 6
#define SI 1
#define NO 0
#define NOGANADOR 0
#define GANADOR 1
//Sospechosos
#define SenoritaEscarlata 0
#define CoronelMostaza 1
#define ProfesorMoradillo 2
#define SenoraAzulino 3
#define SenorVerdi 4
#define SenoraBlanco 5
//Habitaciones
#define Cocina 6
#define Patio 7
#define Spa 8
#define Teatro 9
#define Salon 10
#define Observatorio 11
#define Vestibulo 12
#define HabitacionHuespedes 13
#define Comedor 14
//Armas
#define Revolver 15
#define Cuchillo 16
#define Lazo 17
#define Candelabro 18
#define LlaveInglesa 19
#define TuboPlomo 20

//PROTOTIPOS Y DOCUMENTACIÓN DE LAS FUNCIONES

int hacerAcusacion(int solSospechoso, int solHabitacion, int solArma, int ubicacionJugador);

void imprimiCartas(struct jugador *jugadorElim);
