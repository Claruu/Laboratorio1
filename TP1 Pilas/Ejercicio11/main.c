#include <stdio.h>
#include <stdlib.h>
#include ".\pila.c"
// 11. Suponiendo la existencia de una pila MODELO que no esté vacía, eliminar de la pila DADA todos los elementos que sean iguales al tope de la pila MODELO.

int main()
{
    // declaro pilas
    Pila modelo, dada, dAux, mAux;
    int user = 0, flag = 0;
     char continuar;
    continuar = 's';
    // inicializo pilas
    inicpila(&modelo);
    inicpila(&dada);
    inicpila(&dAux);
    inicpila(&mAux);

    printf("\tPrograma de comparacion de valores entre pilas.\t");

    printf("\nPara pasar a ingresar elementos en la DADA, ingrese 0\n Ingrese elementos MODELO:\n");
    do
    {
        scanf("%d", &user);
        if (user != 0)
        {
            apilar(&modelo, user);
        }

    } while (user != 0);

    printf("Esta es su pila MODELO: \n");
    mostrar(&modelo);

    printf("\n Ingrese elementos DADA, para finalizar la carga ingrese 0\n");
    do
    {
        scanf("%d", &user);
        if (user != 0)
        {
            apilar(&dada, user);
        }

    } while (user != 0);

    printf("Esta es su pila DADA: \n");
    mostrar(&dada);

    while (!pilavacia(&dada))
    {
        flag = 0;
        while (!pilavacia(&modelo))
        {
            if (tope(&dada) == tope(&modelo))
            {
                flag = 1;
                break;
            }
            apilar(&mAux, desapilar(&modelo));
        }

        while (!pilavacia(&mAux))
        {
            apilar(&modelo, desapilar(&mAux));
        }

        if (flag == 0)
        {
            apilar(&dAux, desapilar(&dada));
        }
        else
        {
            desapilar(&dada);
        }
    }

    while (!pilavacia(&dAux))
    {
        apilar(&dada, desapilar(&dAux));
    }

    printf("Esta es su pila modelo: \n");
    mostrar(&modelo);

    printf("Esta es su pila DADA: \n");
    mostrar(&dada);

    system("pause");
    return 0;
}
