#include "SopaDeLetras.h"


/*
Representamos el tamaño del universo,
jugar : void
Retorno representa como el el programa fue finalizado
*/
void buscarPalabras(int tamanioUniverso, int numeroFilas, int numeroColumnas, char Universo[tamanioUniverso][MAXPALABRA],
                    char SopaLetras[numeroFilas][numeroColumnas])
{
    int i,j,k,t;

    for(k=0; k<tamanioUniverso;k++)//para las palabras del universo
    {
        char palabra[MAXPALABRA];
        strcpy(palabra, Universo[k]);

        printf("\n%s\n",palabra);

        int situacion=NOPRESENTE;//Indica si la palabra esta en la sopa de letras o no

        for(i=0; i<numeroFilas; i++)
        {
            for(j=0; j<numeroColumnas; j++)
            {
                //Buscar la primera letra
                if (palabra[0] == SopaLetras[i][j])
                {
                    //Busca la segunda letra
                    //Hacia arriba
                    if (palabra[1] == SopaLetras[i-1][j])
                    {
                        situacion = PRESENTE;
                        for (t = 0; t<strlen(palabra); t++)
                            if (palabra[t] != SopaLetras[i-t][j])
                                situacion=NOPRESENTE;

                        if (situacion==PRESENTE)
                            break;
                    }

                    //Hacia abajo
                   if (palabra[1] == SopaLetras[i+1][j])
                    {
                        situacion = PRESENTE;
                        for (t = 0; t<strlen(palabra); t++)
                            if (palabra[t] != SopaLetras[i+t][j])
                                situacion=NOPRESENTE;

                        if (situacion==PRESENTE)
                            break;
                    }

                    //Hacia la derecha
                    if (palabra[1] == SopaLetras[i][j+1])
                    {
                        situacion = PRESENTE;
                        for (t = 0; t<strlen(palabra); t++)
                            if (palabra[t] != SopaLetras[i][j+t])
                                situacion=NOPRESENTE;

                        if (situacion==PRESENTE)
                            break;
                    }

                    //Hacia la izquierda
                    if (palabra[1] == SopaLetras[i][j-1])
                    {
                        situacion = PRESENTE;
                        for (t = 0; t<strlen(palabra); t++)
                            if (palabra[t] != SopaLetras[i][j-t])
                                situacion=NOPRESENTE;

                        if (situacion==PRESENTE)
                            break;
                    }

                    //Hacia arriba-derecha
                    if (palabra[1] == SopaLetras[i-1][j+1])
                    {
                        situacion = PRESENTE;
                        for (t = 0; t<strlen(palabra); t++)
                            if (palabra[t] != SopaLetras[i-t][j+t])
                                situacion=NOPRESENTE;

                        if (situacion==PRESENTE)
                            break;
                    }

                    //Hacia arriba-izquierda
                    if (palabra[1] == SopaLetras[i-1][j-1])
                    {
                        situacion = PRESENTE;
                        for (t = 0; t<strlen(palabra); t++)
                            if (palabra[t] != SopaLetras[i-t][j-t])
                                situacion=NOPRESENTE;

                        if (situacion==PRESENTE)
                            break;
                    }

                    //Hacia abajo-derecha
                    if (palabra[1] == SopaLetras[i+1][j+1])
                    {
                        situacion = PRESENTE;
                        for (t = 0; t < strlen(palabra); t++)
                            if (palabra[t] != SopaLetras[i+t][j+t])
                                situacion=NOPRESENTE;

                        if (situacion==PRESENTE)
                            break;
                    }

                    //Hacia abajo-izquierda
                    if (palabra[1] == SopaLetras[i+1][j-1])
                    {
                        situacion = PRESENTE;
                        for (t = 0; t < strlen(palabra); t++)
                            if (palabra[t] != SopaLetras[i+t][j-1])
                                situacion=NOPRESENTE;

                        if (situacion==PRESENTE)
                            break;
                    }
                }
            }
            if (situacion==PRESENTE)
                break;
        }
    }
    printf("\npress enter to continue...\n");
    getchar();
}
