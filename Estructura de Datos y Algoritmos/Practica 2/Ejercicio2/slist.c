#include "slist.h"
#include <assert.h>
#include <stdlib.h>

SList* slist_crear(int capacidad){
  //Alocación de la lista
  SList* lista = malloc(sizeof(SList));
  if(lista == NULL){
    printf("Memory allocation failed");
    return;
  }
  //Definición de los datos de la lista
  lista->capacidad = capacidad;
  lista->disponible = capacidad;

  return lista;
}

void slist_destruir(SList* lista){
  assert(lista);

  free(lista->arr);
  free(lista);
}

int slist_vacia(SList* lista){
  assert(lista);

  if(lista->capacidad = lista->disponible)
    return 1;//lista vacia
  else
    return 0;
}

int slist_llena(SList* lista){
  assert(lista);

  if(lista->disponible == 0)
    return 1; //lista llena
  else
    return 0;
}

void slist_agregar_inicio(SList* lista, int dato){
  assert(lista);

  if(slist_llena(lista) == 1)
    return;

  SNodo* novoNodo = malloc(sizeof(SNodo));
  if(novoNodo == NULL){
    printf("Memory allocation failed");
    return;
  }
  novoNodo->dato = dato;
  novoNodo->sig = lista.sig;

  lista->arr = novoNodo;
  lista->disponible --;
}

void slist_eliminar_inicio(SList* lista){
  assert(lista);

  if(slist_vacia == 1){
    printf("Empty list");
    return;
  }

  SNodo* temp = lista->arr->sig; //segundo nodo
  free(lista->arr);
  lista->arr = temp;
  lista->disponible ++;
}

void slist_agregar_final(SList* lista, int dato){
  assert(lista);

  if(slist_vacia == 1){
    slist_agregar_inicio(lista, dato);
    return;
  }

  SNodo* nodotemp = malloc(sizeof(SNodo));
  nodotemp = lista->arr;
  while(nodotemp->sig != NULL)
    nodotemp = nodotemp->sig;
  SNodo* nuevoNodo = malloc(sizeof(SNodo));
  nuevoNodo->dato = dato;
  nodotemp->sig = nuevoNodo;
  lista->disponible --;
}

int slist_longitud(SList* lista){
  assert(lista);

  return lista->disponible + 1;
}

int slist_concatenar(SList* lista1, SList* lista2){
  assert(lista1);
  assert(lista2);

  SList* listaRet = slist_crear(lista1->capacidad + lista2->capacidad);
  lista->arr = lista1->arr;
  SNodo* nodotmp = lista1->arr;
  for(;nodotmp->sig =! NULL;nodotmp = nodotmp->sig){}
  nodotmp->sig = lista2->arr;
  listaRet->disponible = lista1->disponible + lista2->disponible + 1;

  free(nodotmp);
  slist_destruir(lista1);
  slist_destruir(lista2);
  return listaRet;
}

void slist_insertar(*SList lista, int dato, int posicion){
  assert(lista);

  //verficar tamano lista
  if(slist_vacia(lista) == 1)
    return;

  SNodo* nuevoNodo = malloc(sizeof(SNodo));
  nuevoNodo->dato = dato;

  int i = 0;
  for(SNodo* nodotmp = lista->arr; nodotmp->sig =! NULL; nodotmp = nodotmp->sig){
    if(i == (posicion-1)){
      nuevoNodo->sig = nodotmp->sig;
      nodotmp->sig = nuevoNodo;
    }
    i++;
  }

}
