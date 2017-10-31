#include "SopaDeLetras.h"

/*
Representamos opciones del menu mediante números enteros,
Apresenta las opciones y espera la opción deseada por el usuário.
main : -> int
Retorno representa como el el programa fue finalizado
*/
int main()
{
  int m=0;
  while(m!=1 || m!=2 || m!=3)
  {
    system("clear");
    printf("Sopa de Letras\n");
    printf("1 - Jugar\n");
    printf("2 - Testear Funciones\n");
    printf("3 - Salir\n");
    printf("Ingrese la opción deseada: ");
    fflush( stdout );// mover los caracteres del bufer a la salida estandar sea esta la pantalla
    scanf("%d",&m);
    getchar();//Remove \n del scanf
    switch (m) {
      case 1:
        jugar();
        break;
      case 2:
        //testearFunciones();
        break;
      case 3:
        system("clear");
        return 0;
    }
  }
  return 0;
}

/*
Representamos el tamaño del universo,
jugar : void
Retorno representa como el el programa fue finalizado
*/
void jugar()
{
    //Variables
    int i=0, tamanioUniverso=0, numeroFilas=0, numeroColumnas=0;

    //Definición del Universo
    system("clear");
    printf("Universo\n");
    printf("\n¿Cual es el tamaño del universo de palabras? ");
    fflush( stdout );// mover los caracteres del bufer a la salida estandar sea esta la pantalla
    scanf("%d",&tamanioUniverso);
    getchar();//Remove \n del scanf
    
  
    char Universo[tamanioUniverso][MAXPALABRA];
    for(i=0; i<tamanioUniverso; i++)
    {
        printf("\nIngrese la %d palabra del universo: ", i+1);
        fflush( stdout );// mover los caracteres del bufer a la salida estandar sea esta la pantalla
        scanf("%s",Universo[i]);
        getchar();//Remove \n del scanf
    }

    //Definición de la Sopa de Letras
    system("clear");
    printf("Sopa de Letras\n");
    printf("\n¿Cual es el número de filas de la sopa de letras? ");
    fflush( stdout );// mover los caracteres del bufer a la salida estandar sea esta la pantalla
    scanf("%d",&numeroFilas);
    getchar();//Remove \n del scanf
    printf("\n¿Cual es el número de columnas de la sopa de letras? ");
    fflush( stdout );// mover los caracteres del bufer a la salida estandar sea esta la pantalla
    scanf("%d",&numeroColumnas);
    getchar();//Remove \n del scanf

    char SopaLetras[numeroFilas][numeroColumnas];
    printf("\nIngrese la Sopa de Letras:\n");
  
    for(i=0; i<numeroFilas; i++)
    {
        printf("\nIngresse la primera fila de la Sopa de Letras: ");
        fflush( stdout );// mover los caracteres del bufer a la salida estandar sea esta la pantalla
        scanf("%s",SopaLetras[i]);
        getchar();//Remove \n del scanf
    }
    system("clear");
    imprimeSopaLetras(numeroFilas,numeroColumnas,SopaLetras);
 
    buscarPalabras(tamanioUniverso,numeroFilas,numeroColumnas,Universo,SopaLetras);
}

/*
Representamos el tamaño del universo,
jugar : void
Retorno representa como el el programa fue finalizado
*/
void imprimeSopaLetras(int numeroFilas, int numeroColumnas, char SopaLetras[numeroFilas][numeroColumnas])
{
    int i,j;
    for(i=0; i<numeroFilas; i++)
    {
        printf("\n");
        for(j=0; j<numeroColumnas; j++)
        {
            printf("%c\t", SopaLetras[i][j]);
            fflush( stdout );// mover los caracteres del bufer a la salida estandar sea esta la pantalla
        }
    } 
    printf("\npress enter to continue...\n");
    getchar();
}

/*
Representamos el tamaño del universo,
jugar : void
Retorno representa como el el programa fue finalizado
*/
void buscarPalabras(int tamanioUniverso, int numeroFilas, int numeroColumnas, char Universo[tamanioUniverso][MAXPALABRA], 
                    char SopaLetras[numeroFilas][numeroColumnas])
{
    int i,j,k,t;
    
    for(k=0; k<tamanioUniverso;k++)//para las palabras del universo
    {
        char palabra[MAXPALABRA];
        strcpy(palabra, Universo[k]);
        
        printf("\n%s\n",palabra);
        fflush( stdout );
        
        int situacion=NOPRESENTE;//Indica si la palabra esta en la sopa de letras o no
        
        for(i=0; i<numeroFilas; i++)
        {
            for(j=0; j<numeroColumnas; j++)
            {
                //Buscar la primera letra
                if (palabra[0] == SopaLetras[i][j]) 
                {
                    //Busca la segunda letra
                    //Hacia arriba
                    if (palabra[1] == SopaLetras[i - 1][j]) 
                    {
                        situacion = PRESENTE;
                        for (t = 0; t < strlen(palabra); t++)
                            if (palabra[t] != SopaLetras[i - t][j])
                                situacion=NOPRESENTE;
 
                        if (situacion==PRESENTE)
                            break;
                    }
                    
                    //Hacia abajo
                   
                    //Hacia la derecha
                    
                    //Hacia la izquierda
                    
                    //Hacia arriba-izquierda
                    
                    //Hacia arriba-derecha
                    
                    //Hacia abajo-izquierda
                    
                    //Hacia abajo-derecha
                    

                    if (situacion==PRESENTE)
                        break;
                }
            }
        }
    }
    printf("\npress enter to continue...\n");
    getchar();
}



























//fim
