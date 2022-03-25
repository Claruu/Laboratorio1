#include <stdio.h>
#include <stdlib.h>
#include "..\Librerias\pila.c"
// 12. Suponiendo la existencia de una pila MODELO (vacía o no), eliminar de la pila DADA todos los elementos que existan en MODELO.

int main()
{
    Pila modelo, dada, mAux, dAux;
    int user = 0, flag = 0;
    inicpila(&modelo);
    inicpila(&dada);
    inicpila(&dAux);
    inicpila(&mAux);

    printf("Ingrese valores para la pila MODELO\n");
    do
    {
        scanf("%d", &user);
        if (user != 0)
        {
            apilar(&modelo, user);
        }

    } while (user != 0);

    printf("Ingrese valores para la pila DADA\n");
    do
    {
        scanf("%d", &user);
        if (user != 0)
        {
            apilar(&dada, user);
        }
    } while (user != 0);

    if (!pilavacia(&modelo))
    {
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
        printf("\nEsta es su pila modelo: \n");
        mostrar(&modelo);

        printf("\nLuego de quitar los elementos de MODELO, asi queda su pila DADA: \n");
        mostrar(&dada);
    }
    else
    {
        printf("\nYa que su pila MODELO no dispone de elementos, esta es su pila DADA\n");
        mostrar(&dada);
    }

    system("pause");
    return 0;
}