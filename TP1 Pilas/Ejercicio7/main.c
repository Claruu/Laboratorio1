#include <stdio.h>
#include <stdlib.h>
#include ".\pila.c"
// 7. Pasar el último elemento (base) de la pila DADA a su primera posición (tope), dejando los restantes elementos en el mismo orden.

int main()
{
    // declaro pilas
    Pila dada, aux1;
    char continuar;
    continuar = 's';
    int user = 0, base = 0;

    // inicializo pilas
    inicpila(&dada);
    inicpila(&aux1);

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

    while (!pilavacia(&dada))
    {
        apilar(&aux1, desapilar(&dada));
    }

    base = desapilar(&aux1);

    while (!pilavacia(&aux1))
    {
        apilar(&dada, desapilar(&aux1));
    }
    apilar(&dada, base);

    printf("\n Al pasar la base de tu pila DADA al tope, se ve asi:\n");
    mostrar(&dada);

    system("pause");
    return 0;
}