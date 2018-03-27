#include <stdio.h>
int main()
{
  //Exercicio 7

  //r == 1   repete a operacao
  //r == 0   finaliza a operacao
  int r = 1;
  int n = 0;
  int s = 0;

  //enquanto r e 1, repete a operacao
  do
  {
    //pergunta idade
    int i = 0;
    printf ("Idade: ");
    scanf("%d", &i);

    //soma das idades
    s = s+i;

    //numero de pessoas
    n++;

    //pergunta pra repetir
    printf ("Repetir?: ");
    scanf("%d", &r);

  }while(r == 1);

  //imprime media
  int m=0;
  m=s/n;
  printf ("Media Idade: %d",m);

  return 0;
}
