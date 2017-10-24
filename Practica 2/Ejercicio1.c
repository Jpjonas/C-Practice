#include <stdio.h>
int main()
{
  int l=0;
  printf("Ingrese el resultado del dado: ");
  scanf("%d",&l);
  switch (l)
  {
    case 1:
      printf("Seis");
      break;
    case 2:
      printf("Cinco");
      break;
    case 3:
      printf("Cuatro");
      break;
    case 4:
      printf("Tres");
      break;
    case 5:
      printf("Dos");
      break;
    case 6:
      printf("Uno");
      break;
    default:
      printf("Número Incorrecto");
      break;
  }
  printf("\n");
  return 0;
}
