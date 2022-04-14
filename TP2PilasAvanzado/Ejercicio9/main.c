#include <stdio.h>
#include <stdlib.h>
#include "..\Librerias\pila.c"
// Verificar si una pila DADA es capicúa.

int main()
{
    Pila dada, copiaDada, aux, basura;
    inicpila(&dada);
    inicpila(&aux);
    inicpila(&copiaDada);
    inicpila(&basura);
    char continuar = 's';

    while (continuar == 's' || continuar == 'S')
    {
        leer(&dada);
        printf("Desea continuar? s/n ");
        apilar(&copiaDada, tope(&dada));
        fflush(stdin);
        scanf("%c", &continuar);
    }

    while (!pilavacia(&copiaDada))
    {
        apilar(&aux, desapilar(&copiaDada));
    }

    printf("Tu pila se ve asi:\n");
    mostrar(&dada);

    printf("\tEs capicua?\n");

    while (!pilavacia(&dada) && (!pilavacia(&aux)))
    {
        if (tope(&dada) != tope(&aux))
        {
            printf("\nNo, tu pila DADA -NO- es capicua\n");
            break;
        }

        apilar(&basura, desapilar(&dada));
        apilar(&basura, desapilar(&aux));
    }

    if (pilavacia(&dada) && pilavacia(&aux))
    {
        printf("\nSi, tu pila DADA -ES- capicua :D\n");
    }

    system("pause");
    return 0;
}