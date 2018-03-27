#include <stdio.h>
#include <math.h>

struct punto {
    double x;
    double y;
};

double dist(struct punto punto1, struct punto punto2);

int main(){
    struct punto punto1;
    struct punto punto2;
    scanf ("%lf %lf", &punto1.x, &punto1.y);
    scanf ("%lf %lf", &punto2.x, &punto2.y);

    double distancia;
    distancia = dist(punto1,punto2);
    printf("%lf",distancia);

    return 0;
}

//devuelve la distancia entre los puntos recibidos
double dist(struct punto punto1, struct punto punto2){
    return sqrt((punto2.x-punto1.x)*(punto2.x-punto1.x) + (punto2.y-punto1.y)*(punto2.y-punto1.y));
}
