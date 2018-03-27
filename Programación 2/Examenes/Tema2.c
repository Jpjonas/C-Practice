#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define CANTIDAD_INDOCUMENTADOS 17
//Representamos los indocumentados mediante una estructura de la forma (char*, char*, int, int)
//los cuales son un nombre, un domicilio, una edad y la cantidad de años de residencia en ese orden.
struct unIndocumentado {
	char* nombre;
	char* domicilio;
	int edad;
	int aniosResidencia;
};

/* Toma un nombre, un domicilio, una edad y la cantidad de años de residencia y genera un indocumentado con
 * dichos datos.
 *
 * EJEMPLOS
 * creaIndocumentado("José Luis Morales", "1600 Pennsylvania Ave NW", 34, 10) --->
 * 		{nombre: "José Luis Morales", domicilio: "1600 Pennsylvania Ave NW", edad: 34, aniosResidencia: 10}
 * creaIndocumentado("Maria Guadalupe Canseco", "1111 S Figueroa St", 44, 20) --->
 * 		{nombre: "Maria Guadalupe Canseco", domicilio: "1111 S Figueroa St", edad: 44, aniosResidencia: 20}
 */
struct unIndocumentado creaIndocumentado(char* nombre, char* domicilio, int edad, int aniosResidencia){
	struct unIndocumentado temp;
	temp.nombre = nombre;
	temp.domicilio = domicilio;
	temp.edad = edad;
	temp.aniosResidencia = aniosResidencia;
	return temp;
}

/* Dado un indocumentado lo muestra por pantalla
 *
 * EJEMPLOS
 *  -- La salida es por pantalla, la función no devuelve nada --
 */
void muestraIndocumentado(struct unIndocumentado indocumentado) {
    printf("%s %s --- %d --- %d\n", indocumentado.nombre,
    	indocumentado.domicilio, indocumentado.edad, indocumentado.aniosResidencia);
}

/* Dado un arreglo de indocumentados y los datos de un nuevo indocumentado y un índice,
 * agrega un nuevo indocumentado con dichos datos en el índice indicado si el índice
 * es válido y devuelve 1. Si el índice no es válido, la función devuelve 0
 *
 * EJEMPLOS
 * agregaIndocumentado(indocumentados, "José Luis Morales", "1600 Pennsylvania Ave NW", 34, 10, 7) -->  1
 * agregaIndocumentado(indocumentados, "Speedy Gonzalez", "Andale Andale 1121", 61, 35, 1) --> 1
 * agregaIndocumentado(indocumentados, "Speedy Gonzalez", "Andale Andale 1121", 61, 35, -4) --> 0
 * agregaIndocumentado(indocumentados, "Speedy Gonzalez", "Andale Andale 1121", 61, 35, 27) --> 0
 *
 */
int agregaIndocumentado(struct unIndocumentado arrayDeIndocumentados[], char* nombre, char* domicilio, int edad, int aniosResidencia, int indice) {
	//Escriba el código acá
	if(indice < 17 && indice >= 0){
		arrayDeIndocumentados[indice] = creaIndocumentado(nombre, domicilio, edad, aniosResidencia);
		return 1;
	}
	return 0;
}

/* Dado un arreglo de indocumentados lo muestra por pantalla
 *
 * EJEMPLOS
 *  -- La salida es por pantalla, la función no devuelve nada
 */
void muestraIndocumentados(struct unIndocumentado arrayDeIndocumentados[]) {
	for(int i=0; i<17;i++){
		if(arrayDeIndocumentados[i].edad>0 && arrayDeIndocumentados[i].edad < 150)
			muestraIndocumentado(arrayDeIndocumentados[i]);
	}
}

/* Dado un arreglo de indocumentados y una cantidad de años de residencia, devuelve un nuevo arreglo
 * con aquellos indocumentados del original que posean los años de residencia dados.
 *
 * EJEMPLOS
 * buscaIndocumentadosAnios([{nombre: "José Luis Morales", domicilio: "1600 Pennsylvania Ave NW", edad: 34, aniosResidencia: 10},
                      {nombre: "Maria Guadalupe Canseco", domicilio: "1111 S Figueroa St", edad: 44, aniosResidencia: 20},
                      {nombre: "Speedy Gonzalez", domicilio: "Andale Andale 1121", edad: 61, aniosResidencia: 35}], 10) ---> [{nombre: "José Luis Morales", domicilio: "1600 Pennsylvania Ave NW", edad: 34, aniosResidencia: 10}]
 * buscaIndocumentadosAnios([{nombre: "José Luis Morales", domicilio: "1600 Pennsylvania Ave NW", edad: 34, aniosResidencia: 10},
                      {nombre: "Maria Guadalupe Canseco", domicilio: "1111 S Figueroa St", edad: 44, aniosResidencia: 20},
                      {nombre: "Speedy Gonzalez", domicilio: "Andale Andale 1121", edad: 61, aniosResidencia: 35}], 21) ---> []
 *
 */
struct unIndocumentado* buscaIndocumentadosAnios(struct unIndocumentado arrayDeIndocumentados[], int aniosResidencia){
	struct unIndocumentado* arrayIndocumentadoAnios;
	//Creamos un array de 17 indocumentados ya que, más de eso, no va a haber
	arrayIndocumentadoAnios = malloc(sizeof(struct unIndocumentado)*CANTIDAD_INDOCUMENTADOS);

	int j=0;
	for(int i=0;i<17;i++){
		if(arrayDeIndocumentados[i].aniosResidencia >= aniosResidencia && arrayDeIndocumentados[i].aniosResidencia <= 100){
			arrayIndocumentadoAnios[j] = arrayDeIndocumentados[i];
			j++;
		}
	}
	return arrayIndocumentadoAnios;
}


int main() {
	struct unIndocumentado indocumentados[CANTIDAD_INDOCUMENTADOS];
	assert(agregaIndocumentado(indocumentados, "José Luis Morales", "1600 Pennsylvania Ave NW", 34, 10, 7) == 1);
	muestraIndocumentado(indocumentados[7]);
	assert(agregaIndocumentado(indocumentados, "Speedy Gonzalez", "Andale Andale 1121", 61, 35, -4) == 0);
	assert(agregaIndocumentado(indocumentados, "Speedy Gonzalez", "Andale Andale 1121", 61, 35, 1) == 1);
	assert(agregaIndocumentado(indocumentados, "Speedy Gonzalez", "Andale Andale 1121", 61, 35, 27) == 0);
	assert(agregaIndocumentado(indocumentados, "Gallo Claudio", "Lanza la bola 778", 70, 57,2) == 1);
	muestraIndocumentados(indocumentados);

	struct unIndocumentado* indocumentadosAnios;
	indocumentadosAnios = buscaIndocumentadosAnios(indocumentados, 10);
	assert(indocumentadosAnios[2].aniosResidencia == 10 && strcmp(indocumentadosAnios[2].nombre,"José Luis Morales")==0);
	return 1;
}
