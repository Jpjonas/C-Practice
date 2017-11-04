#include "SopaDeLetras.h"

void testearFunciones()
{
    system("clear");
    printf("Teste de la Funciones\n\n");
    char palabra1[] = "camello";
    char palabra2[] = "elefante";
    char palabra3[] = "hiena";
    char palabra4[] = "jaguar";
    char palabra5[] = "jirafa";
    char palabra6[] = "leon";
    char palabra7[] = "loro";
    char palabra8[] = "mono";
    char palabra9[] = "oso";
    char palabra10[] = "sapo";
    char palabra11[] = "tigre";
    char palabra12[] = "tucan";   
    char SopaLetras[15][16] = {"vlmtgujpcwzvyhi",
                                "oadeistuaycdvph",
                                "ucxpfgiclnacuta",
                                "uqofbkrjocgcsyk",
                                "hropiujeiwsaxmu",
                                "hfqdafarijmmnfv",
                                "aitfdsglwkcetlh",
                                "zievywujljzlglp",
                                "zcanrtaxhecleya",
                                "qkmsadraorqorbs",
                                "wpqoxlzcqynfofd",
                                "waqnnotytuasrni",
                                "eulorohoqsooknq",
                                "fugwlzetnafeles",
                                "fqlptfsduqiynxv"};
    
    imprimeSopaLetras(15,16,SopaLetras);
    
    //int buscaPrimeraLetra(int fila, int columna, int numeroFilas, int numeroColumnas, char SopaLetras[numeroFilas][numeroColumnas], char palabra[MAXPALABRA])
    assert(buscaPrimeraLetra(0, 8, 15, 16, SopaLetras, palabra1) == PRESENTE);
    assert(buscaPrimeraLetra(1, 3, 15, 16, SopaLetras, palabra2) == PRESENTE);
    assert(buscaPrimeraLetra(5, 0, 15, 16, SopaLetras, palabra3) == PRESENTE);
    assert(buscaPrimeraLetra(10, 12, 15, 16, SopaLetras, palabra4) == NOPRESENTE);
    assert(buscaPrimeraLetra(7, 3, 15, 16, SopaLetras, palabra5) == NOPRESENTE);
    assert(buscaPrimeraLetra(14, 5, 15, 16, SopaLetras, palabra6) == NOPRESENTE);
    printf("buscaPrimeraLetra OK\n");
    
    //int buscaPalabra(int fila, int columna, int numeroFilas, int numeroColumnas, char SopaLetras[numeroFilas][numeroColumnas], char palabra[MAXPALABRA]);
    assert(buscaPalabra(3, 11, 15, 16, SopaLetras, palabra1) == ABAJO);
    assert(buscaPalabra(13, 13, 15, 16, SopaLetras, palabra2) == IZQUIERDA);
    assert(buscaPalabra(5, 0, 15, 16, SopaLetras, palabra3) == ABAJO_DERECHA);
    assert(buscaPalabra(4, 6, 15, 16, SopaLetras, palabra4) == ABAJO);
    assert(buscaPalabra(5, 9, 15, 16, SopaLetras, palabra5) == IZQUIERDA);
    assert(buscaPalabra(7, 13, 15, 16, SopaLetras, palabra6) == ABAJO_IZQUIERDA);
    assert(buscaPalabra(12, 2, 15, 16, SopaLetras, palabra7) == DERECHA);
    assert(buscaPalabra(9, 2, 15, 16, SopaLetras, palabra8) == ABAJO_DERECHA);
    assert(buscaPalabra(10, 12, 15, 16, SopaLetras, palabra9) == ABAJO_IZQUIERDA);
    assert(buscaPalabra(6, 5, 15, 16, SopaLetras, palabra10) == ARRIBA_IZQUIERDA);
    assert(buscaPalabra(0, 3, 15, 16, SopaLetras, palabra11) == ABAJO_DERECHA);
    assert(buscaPalabra(2, 13, 15, 16, SopaLetras, palabra12) == IZQUIERDA);
    assert(buscaPalabra(0, 8, 15, 16, SopaLetras, palabra1) == NOPRESENTE);
    printf("buscaPalabra OK\n");
    
    //int verificaLimiteArriba(int fila, int letra,int formaPalabra)
    assert(verificaLimiteArriba(3, 4, ARRIBA) == NOPRESENTE);
    assert(verificaLimiteArriba(15, 12, ARRIBA) == ARRIBA);
    assert(verificaLimiteArriba(5, 7, ARRIBA_DERECHA) == NOPRESENTE);
    assert(verificaLimiteArriba(4, 2, ARRIBA_DERECHA) == ARRIBA_DERECHA);
    assert(verificaLimiteArriba(8, 10, ARRIBA_IZQUIERDA) == NOPRESENTE);
    assert(verificaLimiteArriba(1, 0, ARRIBA_IZQUIERDA) == ARRIBA_IZQUIERDA);
    printf("verificaLimiteArriba OK\n");
    
    //int verificaLimiteAbajo(int fila, int letra,int formaPalabra,int numeroFilas)
    assert(verificaLimiteAbajo(3, 4, ABAJO, 5) == NOPRESENTE);
    assert(verificaLimiteAbajo(5, 6, ABAJO, 15) == ABAJO);
    assert(verificaLimiteAbajo(6, 8, ABAJO_DERECHA, 3) == NOPRESENTE);
    assert(verificaLimiteAbajo(6, 9, ABAJO_DERECHA, 20) == ABAJO_DERECHA);
    assert(verificaLimiteAbajo(5, 2, ABAJO_IZQUIERDA, 4) == NOPRESENTE);
    assert(verificaLimiteAbajo(4, 4, ABAJO_IZQUIERDA, 10) == ABAJO_IZQUIERDA);          
    printf("verificaLimiteAbajo OK\n");
    
    //int verificaLimiteDerecha(int columna, int letra, int formaPalabra, int numeroColumnas)
    assert(verificaLimiteDerecha(3, 4, DERECHA, 5) == NOPRESENTE);
    assert(verificaLimiteDerecha(5, 6, DERECHA, 15) == DERECHA);
    assert(verificaLimiteDerecha(6, 8, ABAJO_DERECHA, 3) == NOPRESENTE);
    assert(verificaLimiteDerecha(6, 9, ABAJO_DERECHA, 20) == ABAJO_DERECHA);
    assert(verificaLimiteDerecha(5, 2, ARRIBA_DERECHA, 4) == NOPRESENTE);
    assert(verificaLimiteDerecha(4, 4, ARRIBA_DERECHA, 10) == ARRIBA_DERECHA); 
    printf("verificaLimiteDerecha OK\n");
    
    //verificaLimiteIzquierda
    assert(verificaLimiteIzquierda(3, 4, IZQUIERDA) == NOPRESENTE);
    assert(verificaLimiteIzquierda(15, 12, IZQUIERDA) == IZQUIERDA);
    assert(verificaLimiteIzquierda(5, 7, ABAJO_IZQUIERDA) == NOPRESENTE);
    assert(verificaLimiteIzquierda(4, 2, ABAJO_IZQUIERDA) == ABAJO_IZQUIERDA);
    assert(verificaLimiteIzquierda(8, 10, ARRIBA_IZQUIERDA) == NOPRESENTE);
    assert(verificaLimiteIzquierda(1, 0, ARRIBA_IZQUIERDA) == ARRIBA_IZQUIERDA);
    printf("verificaLimiteIzquierda OK\n");
    printf("\nTestes OK\n");
    getchar();
}
