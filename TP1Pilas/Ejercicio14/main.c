#include <stdio.h>
#include <stdlib.h>
#include "..\Librerias\pila.c"
// 14. Determinar si la cantidad de elementos de la pila DADA es par. Si es par, pasar el elemento del tope de la pila AUX a la pila PAR y si es impar pasar el tope a la pila IMPAR.

int main()
{
    Pila dada, par, impar, aux;
    int user = 0, flag = 0;
    char continuar;
    continuar = 's';
    inicpila(&dada);
    inicpila(&par);
    inicpila(&impar);
    inicpila(&aux);
    printf("\tPrograma de comparacion de pilas:\n");
    do
    {
        printf("Ingrese valor, pila DADA: ");
        scanf("%d", &user);
        apilar(&dada, user);
        printf("\tDesea seguir ingresando valores? Pila DADA: ");
        fflush(stdin);
        scanf("%c", &continuar);
    } while (continuar == 's' || continuar == 'S');

    mostrar(&dada);

    while (!pilavacia(&dada))
    {
        apilar(&aux, desapilar(&dada));
        if (!pilavacia(&dada))
        {
            apilar(&aux, desapilar(&dada));
        }
        else
        {
            flag = 1;
        }
    }
    if (flag == 1)
    {
        printf("Tu pila DADA es impar");
        apilar(&impar, desapilar(&aux));
        mostrar(&impar);
    }
    else
    {
        apilar(&par, desapilar(&aux));
        printf("Tu pila es par");
        mostrar(&par);
    }

    system("pause");
    return 0;
}

// 14. Determinar si la cantidad de elementos de la pila DADA es par. Si es par, pasar el elemento del tope de la pila AUX a la pila PAR y si es impar pasar el tope a la pila IMPAR.
