#include "main.h"

int main(){
  printf("%s\n","Inicio del juego");

  //Cantidad de jugadores
  int nrJugadores;;
  printf("%s\n","Cuantos jugadores?(3-6)");
  scanf("%d\n", &nrJugadores);

  //lista de las cartas sacadas
  int listaCartas[21];
  //Cartas al azar para las soluciones
  srand(time(NULL));
  //Solución sospechosos
  int solSospechoso = rand()%6;
  listaCartas[0]=solSospechoso;
  //Solución habitación
  int solHabitacion = rand()%9+5;
  listaCartas[1]=solHabitacion;
  //Solucción arma
  int solArma = rand()%6+14;
  listaCartas[2]=solArma;
  printf("%s\n", "Tres cartas separadas como soluciones");

  //alocación del vector de jugadores
  struct jugador listaJugadores[nrJugadores];
  //inicialización de los datos
  for(int jugador=0;jugador<nrJugadores;jugador++){
    printf("%s\n","Cual es su nombre?");
    scanf("%s\n", listaJugadores[jugador].nome);
    listaJugadores[jugador].habitacion = Cocina;
    listaJugadores[jugador].cartas = (int *) malloc(sizeof(int));
    listaJugadores[jugador].perdio = NO;
  }
  printf("%s\n", "Jugadores registrados");

  //distribucion de las cartas
  int proxJugador=0, proxCarta=3, contRondas=1;
  for(int carta=0;carta<18;carta++){//Loop por todas las cartas
    for(int cartaSol=0;cartaSol<3;cartaSol++){//Loop por las cartas ya sacadas
      if(carta=!listaCartas[cartaSol]){//Verifica si la carta actual ya fue sacada
        listaJugadores[proxJugador].cartas = (int *) realloc(listaJugadores[proxJugador].cartas, contRondas * sizeof(int));
        listaJugadores[proxJugador].cartas[proxCarta] = carta;
        proxJugador++;
        proxCarta++;
        if(proxJugador >= nrJugadores){
          proxJugador = 0;
          contRondas++;
        }
      }
    }
  }
  printf("%s\n", "Cartas separadas");

  //Jugadas
  for(int jugador=0;jugador<nrJugadores;jugador++){
      printf("%s %s\n", listaJugadores[jugador].nome, " queres hacer una acusación?(1-Si/0-No)");
      int respuesta;
      scanf("%d\n", &respuesta);
      if(respuesta == 1){
        if(hacerAcusacion(solSospechoso,solHabitacion,solArma,listaJugadores[jugador].habitacion) == 1){
          printf("%s %s\n", listaJugadores[jugador].nome, " es el ganador");
        }else{
          printf("%s\n", "No es la respuesta");
          listaJugadores[jugador].perdio = SI;
        }
      }
      if(respuesta == 0){

      }
  }
  return 0;
}

int hacerAcusacion(int solSospechoso, int solHabitacion, int solArma, int habitacionJugador){
  int sospechoso, habitacion, arma;
  printf("%s\n", "Quién es el sospechoso?");
  printf("%s\n", "lista suspeitos");
  scanf("%d\n", &sospechoso);
  printf("%s\n", "Cual es la habitacion?");
  printf("%s\n", "Lista habitaciones");
  scanf("%d\n", &habitacion);
  printf("%s\n", "Cual es la arma?");
  printf("%s\n", "Lista armas");
  scanf("%d\n", &arma);

  if((sospechoso == solSospechoso) && (habitacion == solHabitacion) && (arma == solArma) && (habitacion == habitacionJugador)){
    return 1;
  }
  return 0;
}
