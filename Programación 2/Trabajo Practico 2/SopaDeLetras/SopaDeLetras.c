#include "SopaDeLetras.h"

int main()
{
  int opcionMenu=0;
  while(opcionMenu!=1 || opcionMenu!=2 || opcionMenu!=3)
  {
    system("clear");//Limpia la pantalla
    printf("Sopa de Letras\n");
    printf("1 - Ingresar Datos\n");
    printf("2 - Testear Funciones\n");
    printf("3 - Salir\n");
    printf("Ingrese la opción deseada: ");
    fflush( stdout );//Mueve los caracteres del bufer a la salida (pantalla)
    scanf("%d",&opcionMenu);
    getchar();//Remove \n del bufer
    switch (opcionMenu) 
    {
      case 1:
        ingresarDatos();
        break;
      case 2:
        testearFunciones();
        break;
      case 3:
        system("clear");
        return EXIT_SUCCESS;
    }
  }
  return EXIT_SUCCESS;
}

void ingresarDatos()
{
    int palabra=0, tamanioUniverso=0, numeroFilas=0, numeroColumnas=0;
    system("clear");
    printf("Universo\n");
    printf("\n¿Cual es el tamaño del universo de palabras? ");
    fflush( stdout );
    scanf("%d",&tamanioUniverso);
    getchar();

    char Universo[tamanioUniverso][MAXPALABRA];
    for(palabra=0; palabra<tamanioUniverso; palabra++)
    {
        printf("\nIngrese la palabra %d del universo: ", palabra+1);
        fflush( stdout );
        scanf("%s",Universo[palabra]);
        getchar();
    }

    system("clear");
    printf("Sopa de Letras\n");
    printf("\n¿Cual es el número de filas de la sopa de letras? ");
    fflush( stdout );
    scanf("%d",&numeroFilas);
    getchar();
    printf("\n¿Cual es el número de columnas de la sopa de letras? ");
    fflush( stdout );
    scanf("%d",&numeroColumnas);
    getchar();

    int fila;
    char SopaLetras[numeroFilas][numeroColumnas];
    printf("\nIngrese la Sopa de Letras:\n");
    for(fila=0; fila<numeroFilas; fila++)
    {
        printf("\nIngresse la fila %d de la Sopa de Letras: ",fila+1);
        fflush( stdout );
        scanf("%s",SopaLetras[fila]);
        getchar();
    }
    system("clear");
    imprimeSopaLetras(numeroFilas,numeroColumnas,SopaLetras);

    imprimeBuscaPalabras(tamanioUniverso,numeroFilas,numeroColumnas,Universo,SopaLetras);
}

void imprimeSopaLetras(int numeroFilas, int numeroColumnas, char SopaLetras[numeroFilas][numeroColumnas])
{
    int fila,columna;
    printf("\nSopa de Letras\n");
    for(fila=0; fila<numeroFilas; fila++)
    {
        printf("\n");
        for(columna=0; columna<numeroColumnas; columna++)
        {
            printf("%c\t", SopaLetras[fila][columna]);
            fflush( stdout );
        }
    }
    printf("\n");
}