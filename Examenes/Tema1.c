#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define CANTIDAD_PEDIDOS 10
//Representamos los pedidos mediante una estructura de la forma (int, char*, int, double)
//los cuales son un código, una descripcion, un número de unidades y el precio en ese orden.
struct unPedido {
	int codigo;
	char* descripcion;
	int numeroUnidades;
	double precio;
};

/* Toma un codigo de producto, una descripción del mismo, un número de unidades y un precio
 * y genera un pedido con dichos datos.
 *
 * EJEMPLOS
 * creaPedido(11, "Sandwich de Pollo", 1, 123.0) ---> {codigo: 11, descripcion: "Sandwich de Pollo", numeroUnidades: 1, precio: 123.0}
 * creaPedido(10, "Sandwich de Carne", 2, 245.0) ---> {codigo: 10, descripcion: "Sandwich de Pollo", numeroUnidades: 1, precio: 245.0}
 */
struct unPedido creaPedido(int codigo, char* descripcion, int numeroUnidades, double precio){
	struct unPedido temp;
	temp.codigo = codigo;

	return temp;
}

/* Dado un pedido lo muestra por pantalla
 *
 * EJEMPLOS
 *  -- La salida es por pantalla, la función no devuelve nada --
 */
void muestraPedido(struct unPedido pedido) {
    printf("[%d] %s x %d --- %.2lf\n", pedido.codigo, pedido.descripcion, pedido.numeroUnidades, pedido.precio);
}

/* Dado un arreglo de pedidos y los datos de un nuevo pedido y un índice, agrega un nuevo pedido
 * con dichos datos en el índice indicado si el índice es válido y devuelve 1.
 * Si el índice no es válido, la función devuelve 0
 *
 * EJEMPLOS
 * agregaPedido(pedidos, 11, "Sandwich de Pollo", 1, 123.0,7) -->  1
 * agregaPedido(pedidos, 57, "Bebidas", 4, 165.25, 1) --> 1
 * agregaPedido(pedidos, 57, "Bebidas", 4, 165.25, -1) --> 0
 * agregaPedido(pedidos, 57, "Bebidas", 4, 165.25, 11) --> 0
 *
 */
int agregaPedido(struct unPedido arrayDePedidos[], int codigo, char* descripcion, int numeroUnidades, double precio, int indice) {
	//Escriba el código acá

	if(indice < 10 && indice >= 0){
		//struct unPedido temp = creaPedido(codigo,descripcion,numeroUnidades,precio);
		//arrayDePedidos[indice] = temp;

		return 1;
	}
	return 0;
}

/* Dado un arreglo de pedidos lo muestra por pantalla
 *
 * EJEMPLOS
 *  -- La salida es por pantalla, la función no devuelve nada --
 *
 */
void muestraPedidos(struct unPedido arrayDePedidos[]) {
	//Escriba el código acá
}

/* Dado un arreglo de pedidos y un código, devuelve un nuevo arreglo con aquellos
 * pedidos del original que posean el código dado.
 *
 * EJEMPLOS
 * buscaPedidoCodigo([{codigo: 10, descripcion: "Sandwich de Carne", numeroUnidades: 2, precio: 246.0},
                      {codigo: 11, descripcion: "Sandwich de Pollo", numeroUnidades: 1, precio: 123.0},
                      {codigo: 11, descripcion: "Sandwich de Pollo", numeroUnidades: 3, precio: 369.0}], 11) ---> [{codigo: 11, descripcion: "Sandwich de Pollo", numeroUnidades: 1, precio: 123.0},
                                                                                                                   {codigo: 11, descripcion: "Sandwich de Pollo", numeroUnidades: 3, precio: 369.0}]
 * buscaPedidoCodigo([{codigo: 10, descripcion: "Sandwich de Carne", numeroUnidades: 2, precio: 246.0},
                      {codigo: 11, descripcion: "Sandwich de Pollo", numeroUnidades: 1, precio: 123.0},
                      {codigo: 11, descripcion: "Sandwich de Pollo", numeroUnidades: 3, precio: 369.0}], 10) ---> [{codigo: 10, descripcion: "Sandwich de Carne", numeroUnidades: 2, precio: 246.0}]
 *
 */
struct unPedido* buscaPedidoCodigo(struct unPedido arrayDePedidos[], int codigo){
	struct unPedido* arrayPedidosCodigo;
	//Creamos un array de 10 pedidos ya que, más de eso, no va a haber
	arrayPedidosCodigo = malloc(sizeof(struct unPedido)*CANTIDAD_PEDIDOS);
	//Se debe completar este código
	return arrayPedidosCodigo;
}


int main() {
	struct unPedido pedidos[CANTIDAD_PEDIDOS];
	assert(agregaPedido(pedidos, 11, "Sandwich de Pollo", 1, 123.0,7) == 1);
	muestraPedido(pedidos[7]);
	assert(agregaPedido(pedidos, 57, "Bebidas", 4, 165.25, -1) == 0);
	assert(agregaPedido(pedidos, 57, "Bebidas", 4, 165.25, 1) == 1);
	assert(agregaPedido(pedidos, 57, "Bebidas", 4, 165.25, 11) == 0);
	assert(agregaPedido(pedidos, 123, "Papas y Complementos", 3, 210.5,2) == 1);
	muestraPedidos(pedidos);
	struct unPedido* pedidosCodigo;
	pedidosCodigo = buscaPedidoCodigo(pedidos, 11);
	assert(pedidosCodigo[0].codigo == 11 &&
		strcmp(pedidosCodigo[0].descripcion,"Sandwich de Pollo")==0);
	return 1;
}
