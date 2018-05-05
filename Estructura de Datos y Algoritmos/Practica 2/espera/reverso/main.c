#include "reverso.h"
#include <stdio.h>
#include <assert.h>

static void imprimir_entero(int dato) {
  printf("%d ", dato);
}

static void test_slist_reverso_copia() {
  SList lista = slist_crear();

  // Testeamos con la lista vacia.
  SList copia = slist_reverso_copia(lista);
  assert(slist_vacia(copia));
  slist_destruir(copia);

  // Testeamos con la lista: 1, 2, 3, 4, 5.
  for (int i = 1; i <= 5; ++i)
    lista = slist_agregar_final(lista, i);

  printf("slist_reverso_copia: ");
  slist_recorrer(lista, imprimir_entero);
  printf(" => ");

  copia = slist_reverso_copia(lista);
  slist_recorrer(copia, imprimir_entero);
  puts("");
  slist_destruir(copia);

  slist_destruir(lista);
}

static void test_slist_reverso_recursivo() {
  SList lista = slist_crear();

  // Testeamos con la lista vacia.
  lista = slist_reverso_recursivo(lista);
  assert(slist_vacia(lista));

  // Testeamos con la lista: 1, 2, 3, 4, 5.
  for (int i = 1; i <= 5; ++i)
    lista = slist_agregar_final(lista, i);

  printf("slist_reverso_recursivo: ");
  slist_recorrer(lista, imprimir_entero);
  printf(" => ");

  lista = slist_reverso_recursivo(lista);
  slist_recorrer(lista, imprimir_entero);
  puts("");

  slist_destruir(lista);
}

static void test_slist_reverso() {
  SList lista = slist_crear();

  // Testeamos con la lista vacia.
  lista = slist_reverso(lista);
  assert(slist_vacia(lista));

  // Testeamos con la lista: 1, 2, 3, 4, 5.
  for (int i = 1; i <= 5; ++i)
    lista = slist_agregar_final(lista, i);

  printf("slist_reverso: ");
  slist_recorrer(lista, imprimir_entero);
  printf(" => ");

  lista = slist_reverso(lista);
  slist_recorrer(lista, imprimir_entero);
  puts("");

  slist_destruir(lista);
}

int main(int argc, char *argv[]) {

  test_slist_reverso_copia();
  test_slist_reverso_recursivo();
  test_slist_reverso();

  return 0;
}
