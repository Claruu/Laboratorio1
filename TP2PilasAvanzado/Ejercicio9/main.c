#include <stdio.h>
#include <stdlib.h>
#include "..\Librerias\pila.c"
// Verificar si una pila DADA es capicúa.

int main()
{
    Pila dada, copiaDada, aux, copiaAux;
    inicpila(&copiaDada);
    inicpila(&dada);
    inicpila(&copiaAux);
    inicpila(&aux);
    char continuar = 's';

    while (continuar == 's' || continuar == 'S')
    {
        leer(&dada);
        printf("Desea continuar? s/n ");
        fflush(stdin);
        scanf("%c", &continuar);
        apilar(&copiaDada, tope(&dada));
    }

    while (!pilavacia(&copiaDada))
    {
        apilar(&aux, desapilar(&copiaDada));
    }

    printf("DADA");
    mostrar(&dada);
    printf("copiaDada");
    mostrar(&copiaDada);

    printf("\nAhora verificaremos si tu pila DADA es capicua \n");

    while (!pilavacia(&dada) && (!pilavacia(&aux)))
    {
        if (tope(&dada) != tope(&aux))
        {
            printf("\tTu pila DADA -NO- es capicua\n");
            break;
        }

        apilar(&copiaDada, desapilar(&dada));
        apilar(&copiaAux, desapilar(&aux));
    }

    if (pilavacia(&dada) && pilavacia(&aux))
    {
        printf("Es capicua :D\n");
        printf("COPIA-DADA\n");
        mostrar(&copiaDada);
        printf("COPIA-AUX\n");
        mostrar(&copiaAux);
    }

    system("pause");
    return 0;
}