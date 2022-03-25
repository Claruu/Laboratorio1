#include <stdio.h>
#include <stdlib.h>
#include ".\pila.c"
// 3. Cargar desde teclado una pila DADA y pasar a la pila
// DISTINTOS todos aquellos elementos distintos al valor 8.
int main()
{
    // declaro pilas
    Pila dada, distintos, aux;
    int user = 0;
    // inicializo pilas
    inicpila(&dada);
    inicpila(&distintos);
    inicpila(&aux);

    printf("Por favor ingrese los valores para la pila DADA.\n");
    printf("Al ingresar el numero 0, finaliza la carga de valores.\n");
    do
    {
        scanf("%d", &user);
        if (user != 0)
        {
            apilar(&dada, user);
        }

    } while (user != 0);

    // muestro los valores de la pila DADA
    printf("Al principio, tu pila dada es asi: \n");
    mostrar(&dada);

    // paso de dada a DISTINTOS los valores distintos a 8
    printf("Ahora pasaremos todos los valores distintos a 8 a DISTINTOS");
    while (!pilavacia(&dada))
    {
        if (tope(&dada) != 8)
        {
            apilar(&distintos, desapilar(&dada));
        }
        else
        {
            apilar(&aux, desapilar(&dada));
        }
    }
    while (!pilavacia(&aux))
    {
        apilar(&dada, desapilar(&aux));
    }

    printf("Por lo cual, DISTINTOS se ve asi: \n");
    mostrar(&distintos);

    printf("La pila DADA tiene todos los elementos que sean 8, se ve asi: \n");
    mostrar(&dada);

    printf("La pila DISTINTOS se ve asi al finalizar el programa: \n");
    mostrar(&distintos);

    system("pause");
    return 0;
}
