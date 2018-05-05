#ifndef __SLIST_REVERSO__
#define __SLIST_REVERSO__

#include "slist/slist.h"

/**
 * Copia la lista en una nueva lista de orden inverso.
 */
SList slist_reverso_copia(SList lista);

/**
 * Modifica la lista dada, obteniendo un orden inverso.
 * Implementacion recursiva.
 */
SList slist_reverso_recursivo(SList lista);

/**
 * Modifica la lista dada, obteniendo un orden inverso.
 * Implementacion iterativa.
 */
SList slist_reverso(SList lista);

#endif // __SLIST_REVERSO__
