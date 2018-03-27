/* Jonas Pollnow 
 * Programación 2
 * 
 * Sopa de Letras
 * 
 * Comandos de compilación y ejecución(compila con la versión C99):
 * gcc -std=c99 -Wall -c SopaDeLetras.h SopaDeLetras.c BuscaDePalabras.c TesteFunciones.c
 * gcc -o sopadeletras SopaDeLetras.o BuscaDePalabras.o TesteFunciones.o
 * ./sopadeletras
 */


//BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>//testes
#include <string.h>//manipulación de strings

//DEFINICIONES 
//Representa el tamaño máximo de una palabra en el universo
#define MAXPALABRA 100

//Representaciones de las formas de las palabras en la sopa de letras o de las letras en las palabras
#define PRESENTE 0
#define NOPRESENTE 1
#define ARRIBA 2
#define ABAJO 3
#define DERECHA 4
#define IZQUIERDA 5
#define ARRIBA_DERECHA 6
#define ARRIBA_IZQUIERDA 7
#define ABAJO_DERECHA 8
#define ABAJO_IZQUIERDA 9

//PROTOTIPOS Y DOCUMENTACIÓN DE LAS FUNCIONES

/* Representamos opciones del menu mediante números enteros,
 * Apresenta las opciones y espera la opción deseada por el usuário.
 * main : int
 * El retorno representa como el programa fue finalizado.
 */
int main();


/* Representamos el numero de la palabra, de la fila y de la columnas con enteros, así como el tamaño del universo, 
 * la cantidad total de filas y columnas de la sopa de letras.
 * Representamos el universo de palabras posibles como un arreglo de caractéres de dos dimensiones, siendo la primera 
 * dimensión el número de la palabra y la segunda el número de la letra de la palabra.
 * Representamos la sopa de letras como un arreglo de caractéres de dos dimensiones, siendo la primera el número de la fila 
 * y la segunda el número de la columna de la sopa de letras.
 * ingresarDatos
 */
void ingresarDatos();


/* Representamos el número de la fila y de la columna con enteros.
 * Imprime la sopa de letras en la pantalla.
 * imprimeSopaLetras*/
void imprimeSopaLetras(int numeroFilas, int numeroColumnas, char SopaLetras[numeroFilas][numeroColumnas]);


/* Representamos las filas y las columnas de la sopa de letras y el indice de las letras como enteros.
 * Imprime las palabras que estan presentes en la sopa de letras con su posición y forma.
 * imprimeBuscaPalabras: int -> int -> int -> char[][] -> char[][]
 */
void imprimeBuscaPalabras(int tamanioUniverso, int numeroFilas, int numeroColumnas, char Universo[tamanioUniverso][MAXPALABRA], char SopaLetras[numeroFilas][numeroColumnas]);


/* Representamos la palabra como un arreglo de caratéres unidimensional y la sopa de letras como un arreglo de caractéres de dos dimensiones.
 * Compara la primera letras de la palabra con las letras de la sopa de letras. 
 * buscaPrimeraLetra : -> int -> int -> int -> int -> char[][] -> char[][] -> int
 * Retorna 0 si la letra es igual, sino retorna 1
 */
int buscaPrimeraLetra(int fila, int columna, int numeroFilas, int numeroColumnas, char SopaLetras[numeroFilas][numeroColumnas], char palabra[MAXPALABRA]);


/* Representamos la palabra como un arreglo de caratéres unidimensional y la sopa de letras como un arreglo de caractéres de dos dimensiones.
 * Busca la segunda en la ocho direcciones, entonces verifica si la palara entera esta contenida.
 * buscaPalabra : int -> int -> int -> int -> char[][] -> char[][] -> int
 * Retorna 1 si la palabra no esta presente, o retorna la forma de la palabra(2,3,4,5,6,7,8,9)
*/
int buscaPalabra(int fila, int columna, int numeroFilas, int numeroColumnas, char SopaLetras[numeroFilas][numeroColumnas], char palabra[MAXPALABRA]);


/* Representamos la fila, el indice de la letra y la forma de la palabra en la sopa de letras como enteros.
 * Verifica si los indices de la palabra estan dentro de los indices de la sopa de letras hacia arriba.
 * verificaLimiteArriba : int -> int -> int -> int
 * Retorna 1 si la palabra no esta en la sopa de letras, sino retorna la forma de la palabra. 
*/
int verificaLimiteArriba(int fila, int letra,int formaPalabra);


/* Representamos la fila, el indice de la letra, el número de filas y la forma de la palabra en la sopa de letras como enteros.
 * Verifica si los indices de la palabra estan dentro de los indices de la sopa de letras hacia abajo.
 * verificaLimiteAbajo : int -> int -> int -> int -> int
 * Retorna 1 si la palabra no esta en la sopa de letras, sino retorna la forma de la palabra. 
*/
int verificaLimiteAbajo(int fila, int letra, int formaPalabra, int numeroFilas);


/* Representamos la columna, el indice de la letra, el número de columnas y la forma de la palabra en la sopa de letras como enteros.
 * Verifica si los indices de la palabra estan dentro de los indices de la sopa de letras hacia la derecha.
 * verificaLimiteDerecha : int -> int -> int -> int -> int
 * Retorna 1 si la palabra no esta en la sopa de letras, sino retorna la forma de la palabra. 
*/
int verificaLimiteDerecha(int columna, int letra, int formaPalabra, int numeroColumnas);


/* Representamos la columna, el indice de la letra y la forma de la palabra en la sopa de letras como enteros.
 * Verifica si los indices de la palabra estan dentro de los indices de la sopa de letras hacia la izquierda.
 * verificaLimiteIzquierda : int -> int -> int -> int
 * Retorna 1 si la palabra no esta en la sopa de letras, sino retorna la forma de la palabra. 
*/
int verificaLimiteIzquierda(int columna, int letra,int formaPalabra);

/* Representamos la palabra como un arreglo de caratéres unidimensional y la sopa de letras como un arreglo de caractéres de dos dimensiones.
 * Testea las funciones con el comando assert
 * testearFunciones
*/
void testearFunciones();
