#include <stdio.h>
#include <stdlib.h>
#include ".\pila.c"
// 10. Comparar las pilas A y B, evaluando si son completamente iguales (en cantidad de elementos, valores que contienen y posición de los mismos). Mostrar por pantalla el resultado.

int main()
{
    // declaro pilas
    Pila pilaA, pilaB;
    int user = 0, flag = 0;
    // inicializo pilas
    inicpila(&pilaA);
    inicpila(&pilaB);

    printf("\tPrograma de comparacion de valores entre pilas. V 2.0\t");

    printf("\nPara pasar a ingresar elementos en la pila B, ingrese 0\n Ingrese elementos Pila A:\n");
    do
    {
        scanf("%d", &user);
        if (user != 0)
        {
            apilar(&pilaA, user);
        }

    } while (user != 0);

    printf("\n Ingrese elementos Pila B, para finalizar la carga ingrese 0\n");
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
    }
    else
    {
        printf("Son iguales\n");
    }

    system("pause");
    return 0;
}
