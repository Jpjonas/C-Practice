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

int validaCantidadJugadores(int cantidadJugadores);

int calculaCantidadCartas(int nrJugadores,int jugador);

void preguntaDadosSuposicion(int *sospechoso,int *habitacion,int *arma);

int calculaNuevaHabitacion(int direccion,int habitacionAtual, int numeroCasas);

void imprimeInformacionesJugador(struct jugador *jugador);

void imprimeCartasJugador(struct jugador *jugador);

void imprimeCartas(int primerIndice,int ultimoIndice);

void imprimeCarta(int carta);

void imprimeTablero();