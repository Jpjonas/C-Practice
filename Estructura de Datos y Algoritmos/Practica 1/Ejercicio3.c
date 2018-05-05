#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
int* direccion;
int capacidad;
} ArregloEnteros;

ArregloEnteros* arreglo_enteros_crear(int capacidad){
  ArregloEnteros *nuevoArreglo;
  if((nuevoArreglo = malloc(sizeof(ArregloEnteros))) == NULL)
    return NULL;
  nuevoArreglo->capacidad = capacidad;
  return nuevoArreglo;
}

void arreglo_enteros_destruir(ArregloEnteros* arreglo){
  if(arreglo != NULL){
    free(arreglo->direccion);
    free(arreglo);
  }
}

int arreglo_enteros_leer(ArregloEnteros* arreglo, int pos){
  if((arreglo != NULL) && (arreglo->capacidad > pos)){
    return arreglo->direccion[pos];
  }
  return 0;
}

void arreglo_enteros_escribir(ArregloEnteros* arreglo, int pos, int dato){
  if((arreglo != NULL) && (arreglo->capacidad > pos)){
    arreglo->direccion[pos] = dato;
  }
}

int arreglo_enteros_capacidad(ArregloEnteros* arreglo){
  if(arreglo != NULL)
    return arreglo->capacidad;
  return -1;
}

void arreglo_enteros_imprimir(ArregloEnteros* arreglo){
  if(arreglo != NULL){
    int i;
    for(i=0; i<arreglo->capacidad; i++){
      printf("%d\n",arreglo->direccion[i]);
    }
  }
}

int main(){

  return 0;
}
