#include <stdio.h>
#include <stdlib.h>
#include ".\pila.c"
// 9. Comparar la cantidad de elementos de las pilas A y B. Mostrar por pantalla el resultado.

int main()
{
    // declaro pilas
    Pila pilaA, pilaB;
    int user = 0, valor = 0;
    char continuar;
    continuar = 's';
    // inicializo pilas
    inicpila(&pilaA);
    inicpila(&pilaB);

    printf("\tPrograma de comparacion de valores entre pilas.\t");

    do
    {
        printf("\tIngrese un valor para la pila PILA A\t\n");
        fflush(stdin);
        scanf("%d", &user);
        apilar(&pilaA, user);
        printf("\nDesea seguir ingresando valores? PILA A\n");
        fflush(stdin);
        scanf("%c", &continuar);
    } while (continuar == 's' || continuar == 'S');

    do
    {
        printf("\tIngrese un valor para la pila B\t\n");
        fflush(stdin);
        scanf("%d", &user);
        apilar(&pilaB, user);
        printf("\nDesea seguir ingresando valores? PILA B\n");
        fflush(stdin);
        scanf("%c", &continuar);
    } while (continuar == 's' || continuar == 'S');

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