#include <stdio.h>
#include <stdlib.h>
#include "..\Librerias\pila.c"
// 12. Suponiendo la existencia de una pila MODELO (vacía o no), eliminar de la pila DADA todos los elementos que existan en MODELO.

int main()
{
    // declaro e inicializo pilas y variables
    Pila modelo, dada, mAux, dAux;
    int user = 0, flag = 0;
    inicpila(&modelo);
    inicpila(&dada);
    inicpila(&dAux);
    inicpila(&mAux);

    // pido el ingreso de valores para la pila MODELO y DADA
    printf("Ingrese valores para la pila MODELO\n");
    do
    {
        scanf("%d", &user);
        if (user != 0) // si el user no ingresa 0, se apila, si ingresa 0, deja de ingresar datos
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
    printf("\nEsta es su pila DADA: \n");
    mostrar(&dada);

    // mientras que modelo NO sea una pila vacia, se ejecuta esto.
    if (!pilavacia(&modelo))
    {
        while (!pilavacia(&dada)) // mientras que dada NO este vacia, pasa esto
        {
            flag = 0; // se inicializa en 0 para el while la flag
            while (!pilavacia(&modelo))
            {
                // mientras que modelo NO este vacia, se compara si los topes de DADA y MODELO son iguales o no. Para esto, se DESAPILA MODELO, y se APILA en MAUX
                if (tope(&dada) == tope(&modelo))
                {
                    flag = 1; // si son iguales los topes, flag es cierto, es 1
                    break;
                }
                apilar(&mAux, desapilar(&modelo));
            }

            // luego de pasar por el while numero 1, pasamos al 2. Si MAUX no es una pila vacia, se lo apila sus valores en MODELO
            while (!pilavacia(&mAux))
            {
                apilar(&modelo, desapilar(&mAux));
            }

            // pero si flag = 0 o sea que sus topes NO fueron iguales, se apila en el AUX desapilando de DADA
            if (flag == 0)
            {
                apilar(&dAux, desapilar(&dada));
            }
            // SI LOS TOPES SON IGUALES SE DESAPILA DADA
            else
            {
                desapilar(&dada);
            }
        }
        // MIENTRAS QUE DAUX NO SEA UNA PILA VACIA SE APILA EN DADA
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