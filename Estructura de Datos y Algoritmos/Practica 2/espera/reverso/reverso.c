#include "reverso.h"
#include <stdlib.h>
#include <assert.h>

SList slist_reverso_copia(SList lista) {
  SList nuevaLista = slist_crear();
  for (SNodo* it = lista; it != NULL; it = it->sig)
    nuevaLista = slist_agregar_inicio(nuevaLista, it->dato);
  return nuevaLista;
}

SList slist_reverso_recursivo(SList lista) {
  if (lista == NULL || lista->sig == NULL)
    return lista;
  SNodo* ultimo = slist_reverso_recursivo(lista->sig);
  lista->sig->sig = lista;
  lista->sig = NULL;
  return ultimo;
}

SList slist_reverso(SList lista) {
  SNodo* reversa = NULL;
  for (SNodo* it = lista; it != NULL;) {
    SNodo* resto = it->sig;
    it->sig = reversa;
    reversa = it;
    it = resto;
  }
  return reversa;
}
