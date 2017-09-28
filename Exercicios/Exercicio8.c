#include <stdio.h>
int main()
{
  //Exercicio 8

  int n=0;//numero de eleitores

  //pergunta numero de eleitores
  printf ("Numero total de eleitores: ");
  scanf("%d", &n);

  //inicializanto total de votos de cada candidato
  int l=0;//Lula
  int a=0;//Alkimim
  int h=0;//Luisa Helena

  int i = 0;//contador

  while(i<n)
  {
    //pergunta voto
    int v;
    printf("Vote: \n(1)-Lula  \n(2)-Alkimim  \n(3)-Luisa Helena \n-> ");
    scanf("%d",&v);

    //Soma voto para candidato
    if(v==1)
      l++;
    if(v==2)
      a++;
    if(v==3)
      h++;

    i++;
  }

  //imprime voto de cada candidato
  printf("\nResultado Votacao:");

  printf("\nLula: %d votos",l);
  double p1 = (l/n);
  printf("\n%f",p1);

  printf("\nAlkimim: %d votos",a);
  double p2 = (a/n);
  printf("\n%f",p2);

  printf("\nLuisa Helena: %d votos",h);
  double p3 = (h/n);
  printf("\n%f",p3);

  return 0;
}
