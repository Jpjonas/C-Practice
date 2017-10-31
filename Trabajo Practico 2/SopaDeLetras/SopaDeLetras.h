//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

//Definiciones 
#define MAXPALABRA 100
#define PRESENTE 1
#define NOPRESENTE 0

//Prototipos de las funciones
int main();
void jugar();
void buscarPalabras(int tamanioUniverso, int numeroFilas, int numeroColumnas, char Universo[tamanioUniverso][MAXPALABRA], 
                    char SopaLetras[numeroFilas][numeroColumnas]);
void imprimeSopaLetras(int numeroFilas, int numeroColumnas, char SopaLetras[numeroFilas][numeroColumnas]);
int testearFunciones();
