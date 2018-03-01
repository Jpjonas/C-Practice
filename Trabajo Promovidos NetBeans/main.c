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
  struct jugador *listaJugadores = malloc(nrJugadores*sizeof(struct jugador));
  //inicialización de los datos
  for(int jugador=0;jugador<nrJugadores;jugador++){
    printf("¿Cual es su nombre?");
    scanf(" %s", listaJugadores[jugador].nombre);
    listaJugadores[jugador].habitacion = rand()%9+6;//habitacion al azar
    listaJugadores[jugador].cartas = (int *) calloc(1,sizeof(int));
    listaJugadores[jugador].cantidadeCartas = calculaCantidadCartas(nrJugadores, jugador);
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
  listaCartasUsadas = NULL;
  free(listaCartasUsadas);
  printf("\nCartas separadas");
  
  //MOSTRAR LAS CARTAS

  
  //Jugadas
  int jugador;
  for(jugador=0;jugador<nrJugadores;jugador++){
      if(listaJugadores[jugador].perdio == NO){
          int respAcusacion;
        printf("\n%s %s", listaJugadores[jugador].nombre, "quiere hacer una acusación?(1-Si/0-No)");
        scanf("%d", &respAcusacion);
        //ACUSACIÓN
        if(respAcusacion == 1){
            if(hacerAcusacion(solSospechoso,solHabitacion,solArma,listaJugadores[jugador].habitacion) == 1){
                printf("%s %s\n", listaJugadores[jugador].nombre, " es el ganador");
                free(listaJugadores);
                getchar();
                return 0;
            }else{
                printf("No es la respuesta\n");
                imprimiCartas(&listaJugadores[jugador]);
                listaJugadores[jugador].perdio = SI;
            }
        }else{
        //RONDA NORMAL
            int transportoDiagonal=NO;
            //DIAGONALES
            if((listaJugadores[jugador].habitacion == Cocina) || (listaJugadores[jugador].habitacion == Spa) ||
            (listaJugadores[jugador].habitacion == Observatorio) || (listaJugadores[jugador].habitacion == HabitacionHuespedes)){
                printf("¿Quiere transportarse a la diagonal opuesta?(1-Si/0-No)\n");
                int respDiagonal;
                scanf("%d", &respDiagonal);
                if(respDiagonal == 1){
                    transportoDiagonal = SI;
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
            if(transportoDiagonal == NO){
                //MOVIMIENTOS NORMALES
                int numeroCasas=0, respDireccion;
                numeroCasas = rand()%6+1;
                printf(" %s %d %s","\n¿Quiere desplazar ",numeroCasas," a la derecha o a la izquierda?(0-Derecha/1-Izquierda)");
                scanf("%d", &respDireccion);
                switch (respDireccion) {
                    case 0:
                        listaJugadores[jugador].habitacion = (listaJugadores[jugador].habitacion + numeroCasas)%9 + 6;
                        break;
                    case 1:
                        listaJugadores[jugador].habitacion = (listaJugadores[jugador].habitacion - numeroCasas)%9 + 6;
                        break;
                }
            }
        
        //SUPOSICION
        int supSospechoso, supHabitacion, supArma;
        printf("\n\n SUPOSICIÓN");
        printf("\n¿Quién es el sospechoso?");
        printf("\nlista suspeitos");
        scanf(" %d", &supSospechoso);
        printf("\n¿Cual es la habitacion?");
        printf("\nLista habitaciones");
        scanf(" %d", &supHabitacion);
        printf("\n¿Cual es la arma?");
        printf("\nLista armas");
        scanf(" %d", &supArma);
        
        //REFUTAR
        int jugadorRefutador,tieneCartaRefutadora=NO;
        for(jugadorRefutador=0;jugadorRefutador<nrJugadores;jugadorRefutador++){
            if((jugadorRefutador != jugador) && (listaJugadores[jugadorRefutador].perdio == NO) && (tieneCartaRefutadora == NO)){
                        int respRefutar;
                        printf("\n%s %s %s", "¿", listaJugadores[jugadorRefutador].nombre, " puedes refutar?(1-Si/0-No)");
                        scanf("%d", &respRefutar);
                        if (respRefutar == 1) {
                            int respCartaRef;
                            printf("\n¿Que quieres refutar?(1-Sospechoso/2-Habitaión/3-Arma)");
                            scanf("%d", &respCartaRef);
                            int cartaRefutadora = 0;
                            switch (respCartaRef) {
                                case 1:
                                    for(cartaRefutadora=0;cartaRefutadora<listaJugadores[jugadorRefutador].cantidadeCartas;cartaRefutadora++){
                                        if(listaJugadores[jugadorRefutador].cartas[cartaRefutadora] == supSospechoso){
                                            printf("\nTiene la carta refutadora");
                                            tieneCartaRefutadora = SI;
                                        }
                                    }
                                    break;
                                case 2:
                                    for(cartaRefutadora=0;cartaRefutadora<listaJugadores[jugadorRefutador].cantidadeCartas;cartaRefutadora++){
                                        if(listaJugadores[jugadorRefutador].cartas[cartaRefutadora] == supHabitacion){
                                            printf("\nTiene la carta refutadora");
                                            tieneCartaRefutadora = SI;
                                        }
                                    }
                                    break;
                                case 3:
                                    for(cartaRefutadora=0;cartaRefutadora<listaJugadores[jugadorRefutador].cantidadeCartas;cartaRefutadora++){
                                        if(listaJugadores[jugadorRefutador].cartas[cartaRefutadora] == supArma){
                                            printf("\nTiene la carta refutadora");
                                            tieneCartaRefutadora = SI;
                                        }
                                    }
                                    break;
                            }
                            if(tieneCartaRefutadora == NO)
                                printf("\nNo tiene la carta refutadora");
                        }
            }
        }
    } 
    }
    }
  free(listaJugadores);
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

  if((sospechoso == solSospechoso) && (habitacion == solHabitacion) && (arma == solArma) && (habitacion == habitacionJugador))
    return 1;
  
  return 0;
}

/*
void removeJugador(struct jugador* listaJugadores, int* nrJugadores, int jugador){
    struct jugador* temp = (struct jugador *) malloc((*nrJugadores - 1) * sizeof(struct jugador));
    memcpy(temp, listaJugadores, (jugador - 1)*sizeof(struct jugador));
    memcpy(&temp+((jugador - 1)*sizeof(struct jugador)),&listaJugadores+(jugador*sizeof(struct jugador)), *nrJugadores - jugador);
    free (listaJugadores);
    listaJugadores = temp;
    *nrJugadores--;
}*/

int calculaCantidadCartas(int nrJugadores,int jugador){
    //son 18 cartas siempre
    if(nrJugadores == 3)
        return 6;
    if((nrJugadores == 4) && ((jugador == 0) || (jugador == 1)))
        return 5;
    if((nrJugadores == 4) && ((jugador == 2) || (jugador == 3)))
        return 4;
    if((nrJugadores == 5) && ((jugador == 0) || (jugador == 1) || (jugador == 2)))
        return 4;
    if((nrJugadores == 5) && ((jugador == 3) || (jugador == 4)))
        return 3;
    if(nrJugadores == 6)
        return 3;
    return 0;
}

void imprimiCartas(struct jugador *jugadorElim){
  int i=0;
  static char* cartas[] = {"Senorita Escarlata", "Coronel Mostaza", "Profesor Moradillo", "Senora Azulino", "Senor Verdi"
                           "Senora Blanco", "Cocina", "Patio", "Spa", "Teatro", "Salon", "Observatorio", "Vestibulo",
                           "Habitacion Huespedes", "Comedor", "Revolver", "Cuchillo", "Lazo", "Candelabro",
                           "Llave Inglesa", "Tubo Plomo"};

 for(int i=0;i<jugadorElim->cantidadeCartas;i++)
   printf("%s\n", cartas[i]);
}
