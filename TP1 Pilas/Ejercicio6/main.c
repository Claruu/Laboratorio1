#include <stdio.h>
#include <stdlib.h>
#include ".\pila.c"
// 6. Pasar el primer elemento (tope) de la pila DADA a su última posición (base), dejando los restantes elementos en el mismo orden.

int main()
{
    // declaro pilas
    Pila dada, aux1;

    int user = 0, tope = 0;

    // inicializo pilas
    inicpila(&dada);
    inicpila(&aux1);

    printf("Ingrese los valores para la pila DADA.\n");
    printf("Al ingresar el numero 0, finaliza la carga de valores.\n");
    do
    {
        scanf("%d", &user);
        if (user != 0)
        {
            apilar(&dada, user);
        }

    } while (user != 0);

    printf("Al principio, la pila dada es asi: \n");
    mostrar(&dada);

    tope = desapilar(&dada);

    while (!pilavacia(&dada))
    {
        apilar(&aux1, desapilar(&dada));
    }

    apilar(&dada, tope);

    while (!pilavacia(&aux1))
    {
        apilar(&dada, desapilar(&aux1));
    }

    printf("\n Al pasar el tope de tu pila DADA a la base, se ve asi:\n");
    mostrar(&dada);

    system("pause");
    return 0;
}
