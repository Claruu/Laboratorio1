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