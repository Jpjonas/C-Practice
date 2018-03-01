#include "main.h"

int main(){
  printf("Inicio del juego\n");

  //Cantidad de jugadores
  int nrJugadores,solSospechoso,solHabitacion,solArma;
  printf("Cuantos jugadores?(3-6)");
  scanf(" %d", &nrJugadores);

  //lista de las cartas sacadas
  int *listaCartasUsadas;
  listaCartasUsadas = (int *) calloc(21,sizeof(int));
  //Cartas al azar para las soluciones
  srand(time(NULL));
  //Solución sospechosos
  solSospechoso = rand()%6;
  listaCartasUsadas[0]=solSospechoso;
  //Solución habitación
  solHabitacion = rand()%9+6;
  listaCartasUsadas[1]=solHabitacion;
  //Solucción arma
  solArma = rand()%6+15;
  listaCartasUsadas[2]=solArma;
  printf("\nTres cartas separadas como soluciones\n");

  //alocación del vector de jugadores
  struct jugador listaJugadores[nrJugadores];
  //inicialización de los datos
  for(int jugador=0;jugador<nrJugadores;jugador++){
    printf("¿Cual es su nombre?");
    scanf(" %s", listaJugadores[jugador].nombre);
    listaJugadores[jugador].habitacion = Cocina;
    listaJugadores[jugador].cartas = (int *) calloc(1,sizeof(int));
    listaJugadores[jugador].perdio = NO;
  }
  printf("\nJugadores registrados");

  //distribucion de las cartas
  int i, proxJugador=0, contCartas=2, contRondas=0, carta;
  
  while(contCartas<20){
      carta = rand()%21;
      
      //verifica si la carta saliu
      int cartaSaliu=0;
      for(i=0;i<=contCartas;i++)
          if(listaCartasUsadas[i] == carta)
              cartaSaliu=1;//carta ya saliu
      
      if(cartaSaliu==0){
          listaJugadores[proxJugador].cartas = (int *) realloc(listaJugadores[proxJugador].cartas, (contRondas+1) * sizeof(int));
          listaJugadores[proxJugador].cartas[contRondas] = carta;
          contCartas++;
          listaCartasUsadas[contCartas] = carta;
          proxJugador++;
          if(proxJugador >= nrJugadores){
            proxJugador = 0;
            contRondas++;
          }
      }
   }
  printf("\nCartas separadas");
  
  //MOSTRAR LAS CARTAS

  
  //Jugadas
  int jugador;
  for(jugador=0;jugador<nrJugadores;jugador++){
      if(listaJugadores[jugador].perdio == NO){
        int respAcusacion;
        printf("\n%s %s", listaJugadores[jugador].nombre, "quiere hacer una acusación?(1-Si/0-No)");
        scanf("%d", &respAcusacion);
        //Acusación
        if(respAcusacion == 1){
            if(hacerAcusacion(solSospechoso,solHabitacion,solArma,listaJugadores[jugador].habitacion) == 1){
                printf("%s %s\n", listaJugadores[jugador].nombre, " es el ganador");
                getchar();
                return 0;
            }else{
            printf("No es la respuesta\n");
            listaJugadores[jugador].perdio = SI;
            imprimiCartas(&listaJugadores[jugador]);
            free(listaJugadores[jugador].cartas);
            }
        }else{
        //RONDA NORMAL
        
            if((listaJugadores[jugador].habitacion == Cocina) || (listaJugadores[jugador].habitacion == Spa) ||
            (listaJugadores[jugador].habitacion == Observatorio) || (listaJugadores[jugador].habitacion == HabitacionHuespedes)){
                printf("¿Quiere transportarse a la diagonal opuesta?(1-Si/0-No)\n");
                int respDiagonal;
                scanf("%d", &respDiagonal);
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
        printf("\n¿Quiere desplazar a derecha o izquierda?(0-Derecha/1-Izquierda)");
        scanf("%d", &respDireccion);
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
        scanf("%d", &supSospechoso);
        printf("%s\n", "¿Cual es la habitacion?");
        printf("%s\n", "Lista habitaciones");
        scanf("%d", &supHabitacion);
        printf("%s\n", "¿Cual es la arma?");
        printf("%s\n", "Lista armas");
        scanf("%d", &supArma);
        //REFUTAR
        int x;
        for(x=0;x<nrJugadores;x++){
          int respRefutar;
          printf("\n%s %s %s","¿", listaJugadores[jugador].nombre, " puedes refutar?(1-Si/0-No)");
          scanf("%d", &respRefutar);
          if(respRefutar == 1){
            int respCartaRef;
            printf("\n¿Que quieres refutar?(1-Sospechoso/2-Habitaión/3-Arma)");
            scanf("%d", &respCartaRef);
            int y=0;
            switch (respCartaRef) {
              case 1:
                //supSospechoso
                while((y<8) && (supSospechoso != listaJugadores[x].cartas[y]))
                  y++;
                if(y == 8)
                  printf("\nNo tiene la carta");
                else
                  printf("\nTiene la carta");
                break;
              case 2:
              while((y<8) && (supHabitacion != listaJugadores[x].cartas[y]))
                y++;
              if(y == 8)
                printf("\nNo tiene la carta");
              else
                printf("\nTiene la carta");
                break;
              case 3:
              while((y<8) && (supArma != listaJugadores[x].cartas[y]))
                y++;
              if(y == 8)
                printf("\nNo tiene la carta");
              else
                printf("\nTiene la carta");
                break;
            }
          }
        
        
        }
        }
        
    }
  }

  return 0;
}

int hacerAcusacion(int solSospechoso, int solHabitacion, int solArma, int habitacionJugador){
  int sospechoso, habitacion, arma;
  printf("\n¿Quién es el sospechoso?");
  printf("\nlista suspeitos");
  scanf("%d", &sospechoso);
  printf("\nCual es la habitacion?");
  printf("\nLista habitaciones");
  scanf("%d", &habitacion);
  printf("\n¿Cual es la arma?");
  printf("\nLista armas\n");
  scanf("%d", &arma);
  //&& (habitacion == habitacionJugador)

  if((sospechoso == solSospechoso) && (habitacion == solHabitacion) && (arma == solArma)){
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
    while(jugadorElim->cartas[i] == 0){
      printf("%s\n", cartas[i]);
      i++;
    }
  }
}
