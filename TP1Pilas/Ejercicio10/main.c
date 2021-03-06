#include <stdio.h>
#include <stdlib.h>
#include ".\pila.c"
// 10. Comparar las pilas A y B, evaluando si son completamente iguales (en cantidad de elementos, valores que contienen y posición de los mismos). Mostrar por pantalla el resultado.

int main()
{
    // declaro pilas
    Pila pilaA, pilaB;
    int user = 0, flag = 0;
    char continuar;
    continuar = 's';
    // inicializo pilas
    inicpila(&pilaA);
    inicpila(&pilaB);

    printf("Programa de comparacion de valores entre pilas. V 2.0\n");
    do
    {
        printf("Ingrese un valor para la pila A: ");
        fflush(stdin);
        scanf("%d", &user);
        apilar(&pilaA, user);
        printf("Desea seguir ingresando valores? PILA A: ");
        fflush(stdin);
        scanf("%c", &continuar);
    } while (continuar == 's' || continuar == 'S');

    do
    {
        printf("Ingrese un valor para la pila B ");
        fflush(stdin);
        scanf("%d", &user);
        apilar(&pilaB, user);
        printf("Desea seguir ingresando valores? PILA B: ");
        fflush(stdin);
        scanf("%c", &continuar);
    } while (continuar == 's' || continuar == 'S');

    while (!pilavacia(&pilaA) && !pilavacia(&pilaB))
    {
        if (tope(&pilaA) != tope(&pilaB))
        {
            flag = 1;
            break;
        }
        desapilar(&pilaA);
        desapilar(&pilaB);
    }

    if (!pilavacia(&pilaA) || !pilavacia(&pilaB))
    {
        flag = 1;
    }

    if (flag == 1)
    {
        printf("Son distintas.\n");
        mostrar(&pilaA);
        mostrar(&pilaB);
    }
    else
    {
        printf("Son iguales\n");
        mostrar(&pilaA);
        mostrar(&pilaB);
    }

    system("pause");
    return 0;
}
