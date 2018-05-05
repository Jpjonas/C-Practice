#include "slist.h"
#include <stdio.h>
#include <assert.h>

static void imprimir_entero(int dato) {
  printf("%d ", dato);
}

int main(int argc, char *argv[]) {

  SList* lista = slist_crear(10);

  assert(slist_vacia(lista));
  assert(!slist_llena(lista));

  slist_agregar_inicio(lista, 6);
  slist_agregar_inicio(lista, 5);
  slist_agregar_inicio(lista, 3);
  slist_agregar_inicio(lista, 1);
  slist_agregar_inicio(lista, 2);

  slist_eliminar_inicio(lista);

  slist_agregar_final(lista, 7);

  slist_recorrer(lista, imprimir_entero);
  puts("");

  slist_destruir(lista);

  return 0;
}
