#include <stdio.h>
#include <stdlib.h>
#include ".\pila.c"
// 1. Cargar desde el teclado una pila DADA con 5 elementos.
// Pasar los tres primeros elementos que se encuentren en el tope a la pila AUX1
// y los restantes a la pila AUX2, ambas pilas inicializadas.
int main()
{
    // declaro pilas
    Pila dada, aux1, aux2;
    // inicializo pilas
    inicpila(&dada);
    inicpila(&aux1);
    inicpila(&aux2);

    // apilo valores -SI O SI- es así
    apilar(&dada, 5);
    apilar(&dada, 4);
    apilar(&dada, 3);
    apilar(&dada, 2);
    apilar(&dada, 1);

    // muestro los valores de la pila DADA
    printf("Al principio, la pila dada es asi: \n");
    mostrar(&dada);

    // paso de dada a aux1 3 valores
    apilar(&aux1, desapilar(&dada));
    apilar(&aux1, desapilar(&dada));
    apilar(&aux1, desapilar(&dada));
    printf("Luego de desapilar 3 valores, DADA se ve asi: \n");
    mostrar(&dada);

    printf("Ahora, aux1 se ve asi: \n");
    mostrar(&aux1);

    apilar(&aux2, desapilar(&dada));
    apilar(&aux2, desapilar(&dada));

    printf("La pila dada se convirtio en una pila vacia, no tiene valores, se ve asi: \n");
    mostrar(&dada);

    printf("La pila AUX1 se ve asi al finalizar el programa: \n");
    mostrar(&aux1);

    printf("La pila AUX2 se ve asi al finalizar el programa: \n");
    mostrar(&aux2);

    system("pause");
    return 0;
}
