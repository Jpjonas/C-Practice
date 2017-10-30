#include "SopaDeLetras.h"

/*
Representamos opciones del menu mediante números enteros,
Apresenta las opciones y espera la opción deseada por el usuário.
main : -> int
Retorno representa como el el programa fue finalizado
*/
int main()
{
  system("clear");
  int m=0;
  while(m!=3)
  {
    printf("Sopa de Letras\n");
    printf("1 - Jugar\n");
    printf("2 - Testear Funciones\n");
    printf("3 - Salir\n");
    printf("Ingrese la opción deseada: ");
    scanf("%d",&m);
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
  int i, j, tamanioUniverso, numeroFilas, numeroColumnas;
  char Universo[tamanioUniverso][100];

  //Definición del Universo
  system("clear");
  printf("Universo\n");
  printf("\n¿Cual es el tamaño del universo de palabras? ");
  scanf("%d",&tamanioUniverso);
  for(i=0;i<tamanioUniverso;i++)
  {
    printf("\nIngrese la %d palabra del universo: ", i+1);
    scanf("%s",Universo[i]);
  }

  //Definición de la Sopa de Letras
  system("clear");
  printf("Sopa de Letras\n");
  printf("\n¿Cual es el número de filas de la sopa de letras? ");
  scanf("%d",&numeroFilas);
  printf("\n¿Cual es el número de columnas de la sopa de letras? ");
  scanf("%d",&numeroColumnas);

  char SopaLetras[numeroFilas][numeroColumnas];
  printf("\nIngrese la Sopa de Letras:\n");

  for(i = 0; i < numeroFilas; ++i)
  {
     for(j = 0; j < numeroColumnas ; ++j)
     {
        printf("%c\t",SopaLetras[i][j]);
     }
  printf("\n");
  }


}





























//fim
