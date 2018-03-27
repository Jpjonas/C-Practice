#include <stdio.h>
#include <stdlib.h>

void bubble_sort(float *arreglo, int longitud) {
  for (int iter = 0 ; iter < longitud - 1 ; iter++) {
    for (int i = 0 ; i < longitud - iter - 1; i++) {
      if (arreglo[i] > arreglo[i + 1]) {
        float aux = arreglo[i];
        arreglo[i] = arreglo[i + 1];
        arreglo[i + 1] = aux;
      }
    }
  }
}

float mediana(float *arreglo, int longitud){
  float *temp = arreglo;
  bubble_sort(temp, longitud);
  if(longitud % 2 == 0){//par
    return (arreglo[longitud-1]+arreglo[longitud+1])/2;
  }
  else{//impar
    return arreglo[longitud];
  }
}

int main(){
  float *arreglo[5] = {4,5.1,2,1,3};
  float resultado;
  resultado = mediana(arreglo,5);

  return 0;
}
