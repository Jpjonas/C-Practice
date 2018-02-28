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
    printf("%s\n","¿Cual es su nombre?");
    scanf("%s\n", listaJugadores[jugador].nombre);
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

  //Jugadas REVISAR LOOP
  int jugador;
  for(jugador=0;jugador<nrJugadores;jugador++){
    int respAcusacion;
    printf("%s %s\n", listaJugadores[jugador].nombre, "¿Quiere hacer una acusación?(1-Si/0-No)");
    scanf("%d\n", &respAcusacion);
    //Acusación
    if(respAcusacion == 1){
      if(hacerAcusacion(solSospechoso,solHabitacion,solArma,listaJugadores[jugador].habitacion) == 1){
        printf("%s %s\n", listaJugadores[jugador].nombre, " es el ganador");
      }else{
        printf("%s\n", "No es la respuesta");
        listaJugadores[jugador].perdio = SI;
        imprimiCartas(&listaJugadores[jugador]);
        free(listaJugadores[jugador].cartas);
      }
    }
    //RONDA NORMAL
    if(respAcusacion == 0){
      if((listaJugadores[jugador].habitacion == Cocina) || (listaJugadores[jugador].habitacion == Spa) ||
        (listaJugadores[jugador].habitacion == Observatorio) || (listaJugadores[jugador].habitacion == HabitacionHuespedes)){
          printf("%s\n", "¿Quiere transportarse a la diagonal opuesta?(1-Si/0-No)");
          int respDiagonal;
          scanf("%d\n", &respDiagonal);
          if(respDiagonal == 1){
            switch (listaJugadores[jugador].habitacion) {
              case Cocina:
                listaJugadores[jugador].habitacion = Observatorio;
                break;
              case Observatorio:
                listaJugadores[jugador].habitacion = Cocina;
                break;
              case Spa:
                listaJugadores[jugador].habitacion = HabitacionHuespedes;
                break;
              case HabitacionHuespedes:
                listaJugadores[jugador].habitacion = Spa;
                break;
            }
          }
        }
        //MOVIMIENTOS NORMALES
        int numeroCasas=0, respDireccion;
        numeroCasas = rand()%6+1;
        printf("%s\n", "¿Quiere desplazar a derecha o izquierda?(0-Derecha/1-Izquierda)");
        scanf("%d\n", &respDireccion);
        switch (respDireccion) {
          case 0:
            listaJugadores[jugador].habitacion = (listaJugadores[jugador].habitacion + numeroCasas)%9 + 6;
            break;
          case 1:
            listaJugadores[jugador].habitacion = (listaJugadores[jugador].habitacion - numeroCasas)%9 + 6;
            break;
        }
        //SUPOSICION
        int supSospechoso, supHabitacion, supArma;
        printf("%s\n", "¿Quién es el sospechoso?");
        printf("%s\n", "lista suspeitos");
        scanf("%d\n", &supSospechoso);
        printf("%s\n", "¿Cual es la habitacion?");
        printf("%s\n", "Lista habitaciones");
        scanf("%d\n", &supHabitacion);
        printf("%s\n", "¿Cual es la arma?");
        printf("%s\n", "Lista armas");
        scanf("%d\n", &supArma);
        //REFUTAR
        int x;
        for(x=0;x<nrJugadores;x++){
          int respRefutar;
          printf("%s %s %s\n","¿", listaJugadores[jugador].nombre, " puedes refutar?(1-Si/0-No)");
          scanf("%d\n", &respRefutar);
          if(respRefutar == 1){
            int respCartaRef;
            printf("%s\n", "¿Que quieres refutar?(1-Sospechoso/2-Habitaión/3-Arma)");
            scanf("%d\n", &respCartaRef);
            int y=0;
            switch (respCartaRef) {
              case 1:
                //supSospechoso
                while((y<8) && (supSospechoso != listaJugadores[x].cartas[y]))
                  y++;
                if(y == 8)
                  printf("%s\n", "No tiene la carta");
                else
                  printf("%s\n", "Tiene la carta");
                break;
              case 2:
              while((y<8) && (supHabitacion != listaJugadores[x].cartas[y]))
                y++;
              if(y == 8)
                printf("%s\n", "No tiene la carta");
              else
                printf("%s\n", "Tiene la carta");
                break;
              case 3:
              while((y<8) && (supArma != listaJugadores[x].cartas[y]))
                y++;
              if(y == 8)
                printf("%s\n", "No tiene la carta");
              else
                printf("%s\n", "Tiene la carta");
                break;
            }
          }
        }

    }
  }

  return 0;
}

int hacerAcusacion(int solSospechoso, int solHabitacion, int solArma, int habitacionJugador){
  int sospechoso, habitacion, arma;
  printf("%s\n", "¿Quién es el sospechoso?");
  printf("%s\n", "lista suspeitos");
  scanf("%d\n", &sospechoso);
  printf("%s\n", "¿Cual es la habitacion?");
  printf("%s\n", "Lista habitaciones");
  scanf("%d\n", &habitacion);
  printf("%s\n", "¿Cual es la arma?");
  printf("%s\n", "Lista armas");
  scanf("%d\n", &arma);

  if((sospechoso == solSospechoso) && (habitacion == solHabitacion) && (arma == solArma) && (habitacion == habitacionJugador)){
    return 1;
  }
  return 0;
}

void imprimiCartas(struct jugador *jugadorElim){
  int i=0;
  static char* cartas[] = {"Senorita Escarlata", "Coronel Mostaza", "Profesor Moradillo", "Senora Azulino", "Senor Verdi"
                           "Senora Blanco", "Cocina", "Patio", "Spa", "Teatro", "Salon", "Observatorio", "Vestibulo",
                           "Habitacion Huespedes", "Comedor", "Revolver", "Cuchillo", "Lazo", "Candelabro",
                           "Llave Inglesa", "Tubo Plomo"};

  if(jugadorElim->cartas == NULL){
    printf("No hay cartas!");
  }else{
    while(jugadorElim->cartas[i] != NULL){
      printf("%s\n", cartas[i]);
      i++;
    }
  }
}
