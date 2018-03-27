#include <stdio.h>
int main()
{
  printf("Habitación   Camas     Planta\n");
  printf("1. Azul        2       Primera\n");
  printf("2. Roja        1       Primera\n");
  printf("3. Verde       3       Segunda\n");
  printf("4. Rosa        2       Segunda\n");
  printf("5. Gris        1       Tercera\n");

  int n=0;
  printf("Ingrese el numero de una habitacion: ");
  scanf("%d",&n);
  printf("\n");

  switch(n)
  {
    case 1:
      printf("Habitacion Azul con 2 camas en la planta 1\n");
      break;
    case 2:
      printf("Habitacion Roja con 1 cama en la planta 1\n");
      break;
    case 3:
      printf("Habitacion Verde con 3 camas en la planta 2\n");
      break;
    case 4:
      printf("Habitacion Rosa con 2 camas en la planta 2\n");
      break;
    case 5:
      printf("Habitacion Gris con 1 cama en la planta 3\n");
      break;
    default:
      printf("Número no asociado a habitación\n");
  }
  return 0;
}
