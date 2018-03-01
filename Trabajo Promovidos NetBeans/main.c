#include "main.h"

int main() {
    int cantidadeJugadores;
    do {
        system("clear");
        printf("                    Bienvenidos\n");
        imprimeTablero();
        printf("\nInforme la cantidad de jugadores(3-6): ");
        scanf(" %d", &cantidadeJugadores);
    } while (validaCantidadJugadores(cantidadeJugadores) == NO);

    struct jugador *listaJugadores = malloc(cantidadeJugadores * sizeof (struct jugador));
    for (int jugador = 0; jugador < cantidadeJugadores; jugador++) {
        printf(" %s %d %s", "\n¿Jugador", jugador + 1, "cual es su nombre? ");
        scanf(" %s", listaJugadores[jugador].nombre);
        srand(time(NULL));
        listaJugadores[jugador].habitacion = rand() % 9 + 6;
        listaJugadores[jugador].cartas = (int *) calloc(1, sizeof (int));
        listaJugadores[jugador].cantidadeCartas = calculaCantidadCartas(cantidadeJugadores, jugador);
        listaJugadores[jugador].perdio = NO;
    }
    printf("\nJugadores registrados\n");

    int solucionSospechoso, solucionHabitacion, solucionArma;
    int *listaCartasUsadas;
    listaCartasUsadas = (int *) calloc(21, sizeof (int));
    solucionSospechoso = rand() % 6;
    listaCartasUsadas[0] = solucionSospechoso;
    solucionHabitacion = rand() % 9 + 6;
    listaCartasUsadas[1] = solucionHabitacion;
    solucionArma = rand() % 6 + 15;
    listaCartasUsadas[2] = solucionArma;
    printf("\nTres cartas separadas al azar como soluciones\n");

    int cartaUsada, jugador = 0, indiceCarta = 2, contRondas = 0, carta;
    while (indiceCarta < 20) {
        int cartaSaliu = NO;
        carta = rand() % 21;
        for (cartaUsada = 0; cartaUsada <= indiceCarta; cartaUsada++)
            if (listaCartasUsadas[cartaUsada] == carta)
                cartaSaliu = SI;
        if (cartaSaliu == NO) {
            listaJugadores[jugador].cartas = (int *) realloc(listaJugadores[jugador].cartas, (contRondas + 1) * sizeof (int));
            listaJugadores[jugador].cartas[contRondas] = carta;
            indiceCarta++;
            listaCartasUsadas[indiceCarta] = carta;
            jugador++;
            if (jugador >= cantidadeJugadores) {
                jugador = 0;
                contRondas++;
            }
        }
    }
    listaCartasUsadas = NULL;
    free(listaCartasUsadas);
    printf("\nCartas separadas para los jugadores\n");

    getchar();
    for (jugador = 0; jugador < cantidadeJugadores; jugador++) {
        if (listaJugadores[jugador].perdio == NO) {
            int jugadoresAuxPerdieron=SI;
            for(int jugadorAuxiliar=0;jugadorAuxiliar<cantidadeJugadores;jugadorAuxiliar++)
                if((jugadorAuxiliar!=jugador) && (listaJugadores[jugadorAuxiliar].perdio==NO))
                    jugadoresAuxPerdieron = NO;
            if(jugadoresAuxPerdieron==SI)
            {
                printf(" \n%s %s\n", listaJugadores[jugador].nombre, " es el ganador\n");
                listaJugadores = NULL;
                free(listaJugadores);
                
                printf("\nPresiona enter para finalizar..");
                while (getchar() != '\n');
                return 0;
            }
            int respAcusacion;
            printf(" \n%s %s", listaJugadores[jugador].nombre, "presiona enter para continuar..");
            getchar();
            while (getchar() != '\n');
            system("clear");
            printf("\n%s\n", listaJugadores[jugador].nombre);
            imprimeTablero();
            imprimeInformacionesJugador(&listaJugadores[jugador]);
            printf("\n¿Quiere hacer una acusación?(1-Si/0-No)");
            scanf(" %d", &respAcusacion);
            if (respAcusacion == SI) {
                int suspechosoAcusacion, habitacionAcusacion, armaAcusacion;
                preguntaDadosSuposicion(&suspechosoAcusacion, &habitacionAcusacion, &armaAcusacion);
                imprimeCarta(suspechosoAcusacion);
                if ((suspechosoAcusacion == solucionSospechoso) && (habitacionAcusacion == solucionHabitacion) &&
                        (armaAcusacion == solucionArma) && (listaJugadores[jugador].habitacion == solucionHabitacion)) {
                    printf(" \n%s %s\n", listaJugadores[jugador].nombre, " es el ganador\n");
                    listaJugadores = NULL;
                    free(listaJugadores);
                    getchar();
                    printf("\nPresiona enter para finalizar..");
                    while (getchar() != '\n');
                    return 0;
                } else {
                    system("clear");
                    printf("\n No es la respuesta :(\n");
                    printf(" %s %s %s", "Las cartas de", listaJugadores[jugador].nombre, "son:\n");
                    imprimeCartasJugador(&listaJugadores[jugador]);
                    listaJugadores[jugador].perdio = SI;
                }
            } 
            
            if (respAcusacion == NO) {
                int transportoDiagonal = NO;
                if ((listaJugadores[jugador].habitacion == Cocina) || (listaJugadores[jugador].habitacion == Spa) ||
                        (listaJugadores[jugador].habitacion == Observatorio) || (listaJugadores[jugador].habitacion == HabitacionHuespedes)) {
                    printf("\n¿Quiere transportarse a la diagonal opuesta?(1-Si/0-No)\n");
                    int respuestaDiagonal;
                    scanf("%d", &respuestaDiagonal);
                    if (respuestaDiagonal == SI) {
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
                if (transportoDiagonal == NO){
                    int numeroCasas = 0, respuestaDireccion;
                    numeroCasas = rand() % 6 + 1;
                    printf(" %s %d %s", "\n¿Quiere desplazar", numeroCasas, "unidades en que sentido?(0-Horario/1-Antihorario)");
                    scanf("%d", &respuestaDireccion);
                    listaJugadores[jugador].habitacion = calculaNuevaHabitacion(respuestaDireccion,listaJugadores[jugador].habitacion,numeroCasas);
                }
                printf("\n\nNueva habitación: ");
                imprimeCarta(listaJugadores[jugador].habitacion);

                int suposicionSospechoso=0, suposicionHabitacion=0, suposicionArma=0;
                printf("\n\n SUPOSICIÓN\n\n");
                preguntaDadosSuposicion(&suposicionSospechoso,&suposicionHabitacion,&suposicionArma);
                int jugadorRefutador, tieneCartaRefutadora = NO;
                for (jugadorRefutador = 0; jugadorRefutador < cantidadeJugadores; jugadorRefutador++) {
                    if ((jugadorRefutador != jugador) && (listaJugadores[jugadorRefutador].perdio == NO) && (tieneCartaRefutadora == NO)) {
                        system("clear");
                        printf(" \n%s %s", listaJugadores[jugadorRefutador].nombre, "presiona enter para refutar..");
                        getchar();
                        while (getchar() != '\n');
                        system("clear");
                        printf("\n%s\n", listaJugadores[jugadorRefutador].nombre);
                        imprimeTablero();
                        imprimeInformacionesJugador(&listaJugadores[jugadorRefutador]);
                        printf("\nLas cartas son:\n");
                        imprimeCarta(suposicionSospechoso);
                        printf("\n");
                        imprimeCarta(suposicionHabitacion);
                        printf("\n");
                        imprimeCarta(suposicionArma);
                        printf("\n");
                        int respuestaRefutar;
                        printf("\n\n%s %s %s", "¿", listaJugadores[jugadorRefutador].nombre, " puedes refutar?(1-Si/0-No)");
                        scanf("%d", &respuestaRefutar);
                        if (respuestaRefutar == SI){
                            int respuestaCartaRefutadora;
                            printf("\n¿Que quieres refutar?(1-Sospechoso/2-Habitación/3-Arma)");
                            scanf("%d", &respuestaCartaRefutadora);
                            int cartaRefutadora;
                            for (cartaRefutadora=0; cartaRefutadora<listaJugadores[jugadorRefutador].cantidadeCartas; cartaRefutadora++){
                                switch (respuestaCartaRefutadora) {
                                    case SOSPECHOSO:
                                        if (listaJugadores[jugadorRefutador].cartas[cartaRefutadora] == suposicionSospechoso)
                                            tieneCartaRefutadora = SI;
                                        break;
                                    case HABITACION:
                                        if (listaJugadores[jugadorRefutador].cartas[cartaRefutadora] == suposicionHabitacion)
                                            tieneCartaRefutadora = SI;
                                        break;
                                    case ARMA:
                                        if (listaJugadores[jugadorRefutador].cartas[cartaRefutadora] == suposicionArma)
                                            tieneCartaRefutadora = SI;
                                        break;
                                }   
                            }
                            system("clear");
                            if (tieneCartaRefutadora == NO)
                                printf(" \n%s %s", listaJugadores[jugadorRefutador].nombre, "no tiene la carta para refutar\n");
                            if(tieneCartaRefutadora == SI)
                                printf(" \n%s %s", listaJugadores[jugadorRefutador].nombre, "tiene la carta para refutar\n");
                            getchar();
                            while (getchar() != '\n');
                            system("clear");
                        }
                    }
                }
            }
        }
    }
    listaJugadores = NULL;
    free(listaJugadores);
    return 0;
}

int calculaNuevaHabitacion(int direccion,int habitacionAtual, int numeroCasas){
    switch (direccion) 
    {
        int nuevahabitacion=0;
        case HORARIO:
            if ((habitacionAtual + numeroCasas)>14)
                nuevahabitacion = (habitacionAtual + numeroCasas) -9;
            else
                nuevahabitacion = (habitacionAtual + numeroCasas);
            break;
        case ANTIHORARIO:
             if((habitacionAtual - numeroCasas)<6)
                 nuevahabitacion = (habitacionAtual - numeroCasas) +9;
             else
                 nuevahabitacion = (habitacionAtual - numeroCasas);
             break;
      return nuevahabitacion;
    }
}

int validaCantidadJugadores(int cantidadJugadores) {
    if ((cantidadJugadores < 3) || cantidadJugadores > 6)
        return NO;
    return SI;
}

int calculaCantidadCartas(int nrJugadores, int jugador) {
    if (nrJugadores == 3)
        return 6;
    if ((nrJugadores == 4) && ((jugador == 0) || (jugador == 1)))
        return 5;
    if ((nrJugadores == 4) && ((jugador == 2) || (jugador == 3)))
        return 4;
    if ((nrJugadores == 5) && ((jugador == 0) || (jugador == 1) || (jugador == 2)))
        return 4;
    if ((nrJugadores == 5) && ((jugador == 3) || (jugador == 4)))
        return 3;
    if (nrJugadores == 6)
        return 3;
    return 0;
}

void preguntaDadosSuposicion(int *sospechoso, int *habitacion, int *arma) {
    printf("\n¿Quién es el sospechoso? ");
    imprimeCartas(0, 5);
    scanf(" %d", sospechoso);
    printf("\n¿Cual es la habitacion? ");
    imprimeCartas(6, 14);
    scanf(" %d", habitacion);
    printf("\n¿Cual es la arma? ");
    imprimeCartas(15, 20);
    scanf(" %d", arma);
}

void imprimeInformacionesJugador(struct jugador *jugador) {
    printf("\nHabitacion: ");
    imprimeCarta(jugador->habitacion);
    printf("\nCartas:\n");
    imprimeCartasJugador(jugador);
}

void imprimeCartas(int primerIndice, int ultimoIndice) {
    for (int carta = primerIndice; carta <= ultimoIndice; carta++) {
        imprimeCarta(carta);
        printf("\n");
    }

}

void imprimeCartasJugador(struct jugador *jugador) {
    for (int carta = 0; carta < jugador->cantidadeCartas; carta++) {
        imprimeCarta(jugador->cartas[carta]);
        printf("\n");
    }
}

void imprimeCarta(int carta) {
    static char* baraja[21] = {"Senorita Escarlata", "Coronel Mostaza", "Profesor Moradillo", "Senora Azulino", "Senor Verdi",
        "Senora Blanco", "Cocina", "Patio", "Spa", "Teatro", "Salon", "Observatorio", "Vestibulo",
        "Habitacion Huespedes", "Comedor", "Revolver", "Cuchillo", "Lazo", "Candelabro",
        "Llave Inglesa", "Tubo Plomo"};
    printf("%d-%s", carta, baraja[carta]);
}

void imprimeTablero() {
    printf("\n====================================================");
    printf("\n|     6-Cocina    |    7-Patio   |      8-Spa      |");
    printf("\n====================================================");
    printf("\n|                 |    \\   /     |     9-Teatro    |");
    printf("\n|    14-Comedor   |      X       |=================|");
    printf("\n|                 |    /   \\     |     10-Salon    |");
    printf("\n====================================================");
    printf("\n|  13-Habitacion  | 12-Vestibulo | 11-Observatorio |");
    printf("\n|   de huespedes  |              |                 |");
    printf("\n====================================================\n");
}