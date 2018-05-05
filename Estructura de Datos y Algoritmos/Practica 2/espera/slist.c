#include "slist.h"
#include <assert.h>
#include <stdlib.h>

SList* slist_crear(size_t capacidad) {
  SList* lista = malloc(sizeof(SList));

  lista->arr = malloc(capacidad * sizeof(SNodo));
  lista->capacidad = capacidad;
  lista->disponible = 0;
  lista->primero = capacidad;

  for (size_t i = 0; i < capacidad; ++i)
    lista->arr[i].sig = i + 1;

  return lista;
}

void slist_destruir(SList* lista) {
  assert(lista);
  free(lista->arr);
  free(lista);
}

int slist_vacia(SList* lista) {
  assert(lista);
  return lista->primero == lista->capacidad;
}

int slist_llena(SList* lista) {
  assert(lista);
  return lista->disponible == lista->capacidad;
}

void slist_agregar_inicio(SList* lista, int dato) {
  assert(lista);
  assert(lista->disponible < lista->capacidad);

  SNodo* arr = lista->arr;
  size_t nuevoNodo = lista->disponible;

  lista->disponible = arr[nuevoNodo].sig;
  arr[nuevoNodo].sig = lista->primero;
  arr[nuevoNodo].dato = dato;
  lista->primero = nuevoNodo;
}

void slist_eliminar_inicio(SList* lista) {
  assert(lista);

  if (slist_vacia(lista))
    return;

  SNodo* arr = lista->arr;
  size_t tmp = lista->primero;

  lista->primero = arr[tmp].sig;
  arr[tmp].sig = lista->disponible;
  lista->disponible = tmp;
}

void slist_agregar_final(SList* lista, int dato) {
  assert(lista);
  assert(lista->disponible < lista->capacidad);

  SNodo *nuevoNodo = malloc(sizeof(SNodo));
  nuevoNodo->dato = dato;
  nuevoNodo->sig = NULL;

  if (lista == NULL)
    return nuevoNodo;

  SList nodo = lista;
  for (;nodo->sig != NULL;nodo = nodo->sig);
  /* ahora 'nodo' apunta al ultimo elemento en la lista */

  nodo->sig = nuevoNodo;
  return lista;++
  -52
}

void slist_recorrer(SList* lista, FuncionVisitante visit) {
  assert(lista);

  for (size_t i = lista->primero; i != lista->capacidad; i = lista->arr[i].sig)
    visit(lista->arr[i].dato);
}

size_t slist_longitud(SList* lista){
  assert(lista);
  return lista->disponible +1;
}

SList* slist_concatenar(SList* lista1, SList* lista2){
  assert(lista1);
  assert(lista2);

  SList* nuevaLista = slist_crear(slist_longitud(lista1)+slist_longitud(lista2));

  for (size_t i = lista1->primero; i != lista1->capacidad; i = lista1->arr[i].sig)
    nuevaLista = slist_agregar_final(nuevaLista, lista1->arr[i].dato);
  for (size_t i = lista2->primero; i != lista2->capacidad; i = lista2->arr[i].sig)
    nuevaLista = slist_agregar_final(nuevaLista, lista2->arr[i].dato);




  return nuevaLista;
}

SList* slist_insertar(Slist* lista, int dato, int posicion){
  assert(lista);
  assert(lista->disponible < lista->capacidad);


}
