#include <stdio.h>
#include <stdlib.h>
#include "..\Librerias\pila.c"
// 12. Suponiendo la existencia de una pila MODELO (vacía o no), eliminar de la pila DADA todos los elementos que existan en MODELO.

int main()
{
    // declaro e inicializo pilas y variables
    Pila modelo, dada, mAux, dAux;
    char continuar;
    continuar = 's';
    int user = 0, flag = 0, basura = 0;
    inicpila(&modelo);
    inicpila(&dada);
    inicpila(&dAux);
    inicpila(&mAux);

    // pido el ingreso de valores para la pila MODELO y DADA
    do
    {
        printf("Ingrese un valor para la pila MODELO: ");
        fflush(stdin);
        scanf("%d", &user);
        apilar(&modelo, user);
        printf("Desea seguir ingresando valores? PILA MODELO: ");
        fflush(stdin);
        scanf("%c", &continuar);
    } while (continuar == 's' || continuar == 'S');

    do
    {
        printf("Ingrese un valor para la pila DADA: ");
        fflush(stdin);
        scanf("%d", &user);
        apilar(&dada, user);
        printf("Desea seguir ingresando valores? PILA DADA: ");
        fflush(stdin);
        scanf("%c", &continuar);
    } while (continuar == 's' || continuar == 'S');

    printf("\nEsta es su pila DADA: \n");
    mostrar(&dada);

    if (!pilavacia(&modelo))
    {
        while (!pilavacia(&dada))
        {
            flag = 0;
            while (!pilavacia(&modelo))
            {
                // mientras que modelo NO este vacia, se compara si los topes de DADA y MODELO son iguales o no. Para esto, se DESAPILA MODELO, y se APILA en MAUX
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
                basura = desapilar(&dada);
            }
        }
        while (!pilavacia(&dAux))
        {
            apilar(&dada, desapilar(&dAux));
        }
        printf("\nEsta es su pila modelo: \n");
        mostrar(&modelo);
        if (pilavacia(&dada))
        {
            printf("Su pila DADA quedo vacia porque coincidia en todos los elementos, es una pila vacia: \n");
            mostrar(&dada);
        }
        else if (!pilavacia(&dada))
        {
            printf("\nLuego de quitar los elementos de MODELO, asi queda su pila DADA: \n");
            mostrar(&dada);
        }
        else
        {
            printf("\nYa que su pila MODELO no dispone de elementos, esta es su pila DADA\n");
            mostrar(&dada);
        }
    }
    system("pause");
    return 0;
}