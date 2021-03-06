#include <stdio.h>
#include <stdlib.h>
#include ".\pila.c"
// 6. Pasar el primer elemento (tope) de la pila DADA a su última posición (base), dejando los restantes elementos en el mismo orden.

int main()
{
    // declaro pilas
    Pila dada, aux;
    char continuar;
    continuar = 's';
    int user = 0, tope = 0;

    // inicializo pilas
    inicpila(&dada);
    inicpila(&aux);

    do
    {
        printf("\tIngrese un valor para la pila DADA\t\n");
        fflush(stdin);
        scanf("%d", &user);
        apilar(&dada, user);
        printf("\nDesea seguir ingresando valores? PILA DADA\n");
        fflush(stdin);
        scanf("%c", &continuar);
    } while (continuar == 's' || continuar == 'S');

    printf("Al principio, la pila dada es asi: \n");
    mostrar(&dada);

    tope = desapilar(&dada);

    while (!pilavacia(&dada))
    {
        apilar(&aux, desapilar(&dada));
    }

    apilar(&dada, tope);

    while (!pilavacia(&aux))
    {
        apilar(&dada, desapilar(&aux));
    }

    printf("\n Al pasar el tope de tu pila DADA a la base, se ve asi:\n");
    mostrar(&dada);

    system("pause");
    return 0;
}
