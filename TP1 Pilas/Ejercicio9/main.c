#include <stdio.h>
#include <stdlib.h>
#include ".\pila.c"
// 9. Comparar la cantidad de elementos de las pilas A y B. Mostrar por pantalla el resultado.

int main()
{
    // declaro pilas
    Pila pilaA, pilaB;
    int user = 0, valor = 0;
    // inicializo pilas
    inicpila(&pilaA);
    inicpila(&pilaB);

    printf("\tPrograma de comparacion de valores entre pilas.\t");

    printf("\nPara pasar a ingresar elementos en la pila B, ingrese 0\n Ingrese elementos Pila A:\n");
    do
    {
        scanf("%d", &user);
        if (user != 0)
        {
            apilar(&pilaA, user);
        }

    } while (user != 0);

    printf("\n Ingrese elementos Pila B, para finalizar la carga ingrese 0");
    do
    {
        scanf("%d", &user);
        if (user != 0)
        {
            apilar(&pilaB, user);
        }

    } while (user != 0);

    while (!pilavacia(&pilaA) && !pilavacia(&pilaB))
    {
        valor = desapilar(&pilaA);
        valor = desapilar(&pilaB);
    }

    if (pilavacia(&pilaA) ^ /*(xor)*/ pilavacia(&pilaB))
    {
        printf("No tienen la misma cantidad de elementos.\n");
    }
    else
    {
        printf("Tienen la misma cantidad de elementos :D\n");
    }

    system("pause");
    return 0;
}
