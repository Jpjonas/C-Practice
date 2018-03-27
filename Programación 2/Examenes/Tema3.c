#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define CANTIDAD_JUGADORES 11
//Representamos los jugadores mediante una estructura de la forma (char*, char*, int, int)
//los cuales son un nombre, un equipo, el número que usan y una edad en ese orden.
struct unJugador {
	char* nombre;
	char* club;
	int numero;
	int edad;
};

/* Toma un nombre, un equipo, el número que usan y una edad y genera un jugador con
 * dichos datos.
 *
 * EJEMPLOS
 * creaJugador("Victor Cuesta", "Independiente", 14, 27) --->
 * 		{nombre: "Victor Cuesta", club: "Independiente", numero: 14, edad: 27}
 * creaJugador("Manuel Icardi", "Inter", 9, 23) --->
 * 		{nombre: "Manuel Icardi", club: "Inter", numero: 9, edad: 23}
 */
struct unJugador creaJugador(char* nombre, char* club, int numero, int edad){
	struct unJugador temp;
	temp.nombre = nombre;
        temp.club = club;
        temp.numero = numero;
        temp.edad = edad;
	return temp;
}

/* Dado un Jugador lo muestra por pantalla
 *
 * EJEMPLOS
 *  -- La salida es por pantalla, la función no devuelve nada --
 */
void muestraJugador(struct unJugador jugador) {
    printf("%s %s --- %d --- %d\n", jugador.nombre,
    	jugador.club, jugador.numero, jugador.edad);
}

/* Dado un arreglo de jugadores y los datos de un nuevo Jugador y un índice,
 * agrega un nuevo Jugador con dichos datos en el índice indicado, si el índice
 * es válido, y devuelve 1. Si el índice no es válido, la función devuelve 0
 *
 * EJEMPLOS
 * agregaJugador(jugadores, "Victor Cuesta", "Independiente", 14, 27, 7) -->  1
 * agregaJugador(jugadores, "Manuel Icardi", "Inter", 9, 23, 1) --> 1
 * agregaJugador(jugadores, "Manuel Icardi", "Inter", 9, 23, -4) --> 0
 * agregaJugador(jugadores, "Manuel Icardi", "Inter", 9, 23, 14) --> 0
 *
 */
int agregaJugador(struct unJugador arrayDeJugadores[], char* nombre, char* club, int numero, int edad, int indice) {
    if(indice>0 && indice < CANTIDAD_JUGADORES){
        struct unJugador temp;
        temp = creaJugador(nombre,club,numero,edad);
        arrayDeJugadores[indice] = temp;
        return 1;
    }
    return 0;
}

/* Dado un arreglo de Jugadores lo muestra por pantalla
 *
 * EJEMPLOS
 *  -- La salida es por pantalla, la función no devuelve nada --
 *
 */
void muestraJugadores(struct unJugador arrayDeJugadores[]){
    for(int i=0; i<CANTIDAD_JUGADORES;i++){
        if(arrayDeJugadores[i].numero>0){
            muestraJugador(arrayDeJugadores[i]);
        }
    }
}

/* Dado un arreglo de jugadores y un número, devuelve un nuevo arreglo
 * con aquellos jugadores del original que usen ese número.
 *
 * EJEMPLOS
 * buscaJugadoresNumero([{nombre: "Victor Cuesta", club: "Independiente", numero: 14, edad: 27},
                      {nombre: "Manuel Icardi", club: "Inter", numero: 9, edad: 23},
                      {nombre: "Roman Riquelme", club: "Sin equipo", numero: 10, edad: 38}], 10) ---> [{nombre: "Roman Riquelme", club: "Sin equipo", numero: 10, edad: 38}]
 * buscaJugadoresNumero([{nombre: "Victor Cuesta", club: "Independiente", numero: 14, edad: 27},
                      {nombre: "Manuel Icardi", club: "Inter", numero: 9, edad: 23},
                      {nombre: "Roman Riquelme", club: "Sin equipo", numero: 10, edad: 38}], 3) ---> []
 *
 */
struct unJugador* buscaJugadoresNumero(struct unJugador arrayDeJugadores[], int numero){
	struct unJugador* arrayJugadoresNumero;
	//Creamos un array de 11 jugadores ya que, más de eso, no va a haber
	arrayJugadoresNumero = malloc(sizeof(struct unJugador)*CANTIDAD_JUGADORES);
	//Se debe completar este código
        int j=0;
        for(int i=0; i<CANTIDAD_JUGADORES;i++){
            if(arrayDeJugadores[i].numero == numero){
                arrayJugadoresNumero[j] = arrayDeJugadores[i];
                j++;
            }
        }

	return arrayJugadoresNumero;
}


int main() {
	struct unJugador jugadores[CANTIDAD_JUGADORES];
        for(int i=0; i<CANTIDAD_JUGADORES;i++) jugadores[i].numero = -1;
	assert(agregaJugador(jugadores, "Victor Cuesta", "Independiente", 14, 27, 7) == 1);
	muestraJugador(jugadores[7]);
	assert(agregaJugador(jugadores, "Roman Riquelme", "Sin equipo", 10, 38, 2) == 1);
	assert(agregaJugador(jugadores, "Manuel Icardi", "Inter", 9, 23, -4) == 0);
	assert(agregaJugador(jugadores, "Manuel Icardi", "Inter", 9, 23, 1) == 1);
	assert(agregaJugador(jugadores, "Manuel Icardi", "Inter", 9, 23, 14) == 0);
	muestraJugadores(jugadores);
	struct unJugador* jugadoresNumero;
	jugadoresNumero = buscaJugadoresNumero(jugadores, 10);
	assert(jugadoresNumero[0].numero == 10 &&
		strcmp(jugadoresNumero[0].nombre,"Roman Riquelme")==0);
	return 1;
}
