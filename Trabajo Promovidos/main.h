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

typedef struct direc {     
  char nombre[30];     
  char calle[40];     
  char ciudad[20];     
  char estado[3];     
  unsigned int codigo;
} sdirec;

//DEFINICIONES
#define SOSPECHOSOS 6;
#define HABITACIONES 9;
#define ARMAS 6;

//SOSPECHOSOS
#define SenoritaEscarlata 0;
#define CoronelMostaza 1;
#define ProfesorMoradillo 2;
#define SenoraAzulino 3;
#define SenorVerdi 4;
#define SenoraBlanco 5;

//HABITACIONES
#define Cocina 0;
#define Patio 1;
#define Spa 2;
#define Teatro 3;
#define Salon 4;
#define Observatorio 5;
#define Vestibulo 6;
#define HabitacionHuespedes 7;
#define Comedor 8;

//ARMAS
#define Revolver 0;
#define Cuchillo 1;
#define Lazo 2;
#define Candelabro 3;
#define LlaveInglesa 4;
#define TuboPlomo 5;
