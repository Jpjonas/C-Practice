#include "main.h"

int main(){
  printf("%s\n","Inicio del juego");

  //Cantidad de jugadores
  int nrJugadores,i=0;
  do{
    printf("%s\n","Cuantos jugadores?");
    scanf("%d\n", &nrJugadores);
  }while((nrJugadores<3) && (nrJugadores>6));

  //Cartas al azar
  srand(time(NULL));
  //Solución sospechosos
  int solSospechoso = rand()%6;
  //Solución habitación
  int solHabitacion = rand()%9;
  //Solucción arma
  int solArma = rand()%6;

  //alocación vector de nrJugadores
  int **jugadores;
  jugadores = (int **) malloc(nrJugadores * sizeof(int  *));

  for(i=0;i<3;i++){
    jugadores[i] = (int *) malloc()
  }



  return 0;
}
