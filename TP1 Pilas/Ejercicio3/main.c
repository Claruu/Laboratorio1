#include <stdio.h>
#include <stdlib.h>
#include ".\pila.c"
// 3. Cargar desde teclado una pila DADA y pasar a la pila DISTINTOS todos aquellos elementos distintos al valor 8. 
int main()
{
    // declaro pilas
    Pila dada, distintos;
    // inicializo pilas
    inicpila(&dada);
    inicpila(&distintos);


    

    // muestro los valores de la pila DADA
    printf("Al principio, la pila dada es asi: \n");
    mostrar(&dada);

    // paso de dada a aux1 3 valores
    apilar(&distintos, desapilar(&dada));
    apilar(&distintos, desapilar(&dada));
    apilar(&distintos, desapilar(&dada));
    printf("Luego de desapilar 3 valores, DADA se ve asi: \n");
    mostrar(&dada);

    printf("Ahora, aux1 se ve asi: \n");
    mostrar(&distintos);

    

    printf("La pila dada se convirtio en una pila vacia, no tiene valores, se ve asi: \n");
    mostrar(&dada);

    printf("La pila AUX1 se ve asi al finalizar el programa: \n");
    mostrar(&distintos);


    system("pause");
    return 0;
}
