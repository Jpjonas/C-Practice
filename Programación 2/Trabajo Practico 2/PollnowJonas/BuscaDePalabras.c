#include "SopaDeLetras.h"

void imprimeBuscaPalabras(int tamanioUniverso, int numeroFilas, int numeroColumnas, char Universo[tamanioUniverso][MAXPALABRA], char SopaLetras[numeroFilas][numeroColumnas])
{
    int fila,columna,indicePalabra;
    for(indicePalabra=0; indicePalabra<tamanioUniverso;indicePalabra++)
    {
        char palabra[MAXPALABRA];
        strcpy(palabra, Universo[indicePalabra]);
        for(fila=0; fila<numeroFilas; fila++)
        {
            for(columna=0; columna<numeroColumnas; columna++)
            {
                if(buscaPrimeraLetra(fila,columna,numeroFilas,numeroColumnas,SopaLetras,palabra) == PRESENTE)
                {
                    int formaPalabra = buscaPalabra(fila,columna,numeroFilas,numeroColumnas,SopaLetras,palabra);
                    if(formaPalabra != NOPRESENTE)
                    {
                        printf("\n\nPalabra: %s\n",palabra);
                        printf("Fila: %d \nColumna: %d\n", fila+1, columna+1);
                        switch(formaPalabra)
                        {
                            case ARRIBA:
                                printf("Forma: de abajo a arriba\n");
                                break;
                            case ABAJO:
                                printf("Forma: de arriba a abajo\n");
                                break;
                            case DERECHA:
                                printf("Forma: de izquierda a derecha\n");
                                break;
                            case IZQUIERDA:
                                printf("Forma: de derecha a izquierda\n");
                                break;
                            case ARRIBA_DERECHA:
                                printf("Forma: de abajo-izquierda a arriba-derecha\n");
                                break;
                            case ARRIBA_IZQUIERDA:
                                printf("Forma: de abajo-derecha a arriba-izquierda\n");
                                break;
                            case ABAJO_DERECHA:
                                printf("Forma: de arriba-izquierda a abajo-derecha\n");
                                break;
                            case ABAJO_IZQUIERDA:
                                printf("Forma: de arriba-derecha a abajo-izquierda\n");
                                break;
                        }
                    }
                }
            }
        }
    }
    printf("\nPrescione una tecla para continuar...\n");
    getchar();
}

int buscaPrimeraLetra(int fila, int columna, int numeroFilas, int numeroColumnas, char SopaLetras[numeroFilas][numeroColumnas], char palabra[MAXPALABRA])
{
     if(palabra[0] == SopaLetras[fila][columna])
         return PRESENTE;
     else
         return NOPRESENTE;
}

int buscaPalabra(int fila, int columna, int numeroFilas, int numeroColumnas, char SopaLetras[numeroFilas][numeroColumnas], char palabra[MAXPALABRA])
{
    int letra, formaPalabra;
     
    if (palabra[1] == SopaLetras[fila-1][columna])//ARRIBA
    {
        formaPalabra = ARRIBA;
        for (letra = 0; letra < strlen(palabra); letra++)
        {
            formaPalabra = verificaLimiteArriba(fila, letra, formaPalabra);
            if (palabra[letra] != SopaLetras[fila-letra][columna])
                formaPalabra = NOPRESENTE;
        }
        if (formaPalabra == ARRIBA) 
            return ARRIBA;
    }
    if (palabra[1] == SopaLetras[fila+1][columna])//ABAJO
    {
        formaPalabra = ABAJO;
        for (letra = 0; letra < strlen(palabra); letra++)
        {
            formaPalabra = verificaLimiteAbajo(fila, letra, formaPalabra, numeroFilas);
            if (palabra[letra] != SopaLetras[fila+letra][columna])
                formaPalabra = NOPRESENTE;
        }
        if (formaPalabra == ABAJO) 
            return ABAJO;
    }
    if (palabra[1] == SopaLetras[fila][columna+1])//DERECHA
    {
        formaPalabra = DERECHA;
        for (letra = 0; letra < strlen(palabra); letra++)
        {
            formaPalabra = verificaLimiteDerecha(columna, letra, formaPalabra, numeroColumnas);
            if (palabra[letra] != SopaLetras[fila][columna+letra])
                formaPalabra = NOPRESENTE;
        }
        if (formaPalabra == DERECHA) 
            return DERECHA;
    }
    if (palabra[1] == SopaLetras[fila][columna-1])//IZQUIERDA
    {
        formaPalabra = IZQUIERDA;
        for (letra = 0; letra < strlen(palabra); letra++)
        {
            formaPalabra = verificaLimiteIzquierda(columna, letra, formaPalabra);
            if (palabra[letra] != SopaLetras[fila][columna-letra])
                formaPalabra = NOPRESENTE;
        }
        if (formaPalabra == IZQUIERDA) 
            return IZQUIERDA;
    }
    if (palabra[1] == SopaLetras[fila-1][columna+1])//ARRIBA_DERECHA
    {
        formaPalabra = ARRIBA_DERECHA;
        for (letra = 0; letra < strlen(palabra); letra++)
        {
            formaPalabra = verificaLimiteDerecha(columna, letra, formaPalabra, numeroColumnas);
            formaPalabra = verificaLimiteArriba(fila, letra, formaPalabra);
            if (palabra[letra] != SopaLetras[fila-letra][columna+letra])
                formaPalabra = NOPRESENTE;
        }
        if (formaPalabra == ARRIBA_DERECHA) 
            return ARRIBA_DERECHA;
    }
    if (palabra[1] == SopaLetras[fila-1][columna-1])//ARRIBA_IZQUIERDA
    {
        formaPalabra = ARRIBA_IZQUIERDA;
        for (letra = 0; letra < strlen(palabra); letra++)
        {
            formaPalabra = verificaLimiteIzquierda(columna, letra, formaPalabra);
            formaPalabra = verificaLimiteArriba(fila, letra, formaPalabra);
            if (palabra[letra] != SopaLetras[fila-letra][columna-letra])
                formaPalabra = NOPRESENTE;
        }
        if (formaPalabra == ARRIBA_IZQUIERDA)
            return ARRIBA_IZQUIERDA;
    }
    if (palabra[1] == SopaLetras[fila+1][columna+1])//ABAJO_DERECHA
    {
        formaPalabra = ABAJO_DERECHA;
        for (letra = 0; letra < strlen(palabra); letra++)
        {
            formaPalabra = verificaLimiteDerecha(columna, letra, formaPalabra, numeroColumnas);
            formaPalabra = verificaLimiteAbajo(fila, letra, formaPalabra, numeroFilas);
            if (palabra[letra] != SopaLetras[fila+letra][columna+letra])
                formaPalabra = NOPRESENTE;
        }
        if (formaPalabra == ABAJO_DERECHA)
            return ABAJO_DERECHA;
    }
    if (palabra[1] == SopaLetras[fila+1][columna-1])//ABAJO_IZQUIERDA
    {
        formaPalabra = ABAJO_IZQUIERDA;
        for (letra = 0; letra < strlen(palabra); letra++)
        {
            formaPalabra = verificaLimiteIzquierda(columna, letra, formaPalabra);
            formaPalabra = verificaLimiteAbajo(fila, letra, formaPalabra, numeroFilas);
            if (palabra[letra] != SopaLetras[fila+letra][columna-letra])
                formaPalabra = NOPRESENTE;
        }
        if (formaPalabra == ABAJO_IZQUIERDA)
            return ABAJO_IZQUIERDA;
    }
    return NOPRESENTE;
}

int verificaLimiteArriba(int fila, int letra,int formaPalabra)
{
    if((fila - letra) < 0) 
        return NOPRESENTE;
    return formaPalabra;
}

int verificaLimiteAbajo(int fila, int letra,int formaPalabra,int numeroFilas)
{
    if((fila + letra) > numeroFilas) 
        return NOPRESENTE;
    return formaPalabra;
}

int verificaLimiteDerecha(int columna, int letra, int formaPalabra, int numeroColumnas)
{
    if((columna + letra) > numeroColumnas) 
        return NOPRESENTE;
    return formaPalabra;
}

int verificaLimiteIzquierda(int columna, int letra,int formaPalabra)
{
    if((columna - letra) < 0) 
        return NOPRESENTE;
    return formaPalabra;
}