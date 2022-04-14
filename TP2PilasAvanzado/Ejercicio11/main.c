#include <stdio.h>
#include <stdlib.h>
#include "..\Librerias\pila.c"
// Intercalar dos pilas ordenadas en forma creciente (ORDENADA1 y ORDENADA2) dejando el resultado en una pila también ordenada en forma creciente (ORDENADAFINAL).

int main()
{
    Pila ordenadaUno, ordenadaDos, destino, ordenadaFinal;
    inicpila(&ordenadaUno);
    inicpila(&ordenadaDos);
    inicpila(&destino);
    inicpila(&ordenadaFinal);

    apilar(&ordenadaUno, 1);
    apilar(&ordenadaUno, 3);
    apilar(&ordenadaUno, 7);

    apilar(&ordenadaDos, 2);
    apilar(&ordenadaDos, 4);
    apilar(&ordenadaDos, 6);

    printf("\nOrdena 1");
    mostrar(&ordenadaUno);
    printf("\nOrdena 2");
    mostrar(&ordenadaDos);

    while (!pilavacia(&ordenadaUno) && !pilavacia(&ordenadaDos))
    {
        if (tope(&ordenadaUno) > tope(&ordenadaDos))
        {
            apilar(&destino, desapilar(&ordenadaUno));
        }
        else
        {
            apilar(&destino, desapilar(&ordenadaDos));
        }
    }
    if (!pilavacia(&ordenadaUno))
    {
        while (!pilavacia(&ordenadaUno))
        {
            apilar(&destino, desapilar(&ordenadaUno));
        }
    }
    else
    {
        while (!pilavacia(&ordenadaDos))
        {
            apilar(&destino, desapilar(&ordenadaDos));
        }
    }
    while (!pilavacia(&destino))
    {
        apilar(&ordenadaFinal, desapilar(&destino));
    }
    printf("\nOrdena final queda con las pilas intercalas");
    mostrar(&ordenadaFinal);

    return 0;
}
// Intercalar dos pilas ordenadas en forma creciente (ORDENADA1 y ORDENADA2) dejando el resultado en una pila también ordenada en forma creciente (ORDENADAFINAL).
// do
// {
//     leer(&ordenadaUno);
//     printf("Desea continuar? Ordenada 1 s/n ");
//     fflush(stdin);
//     scanf("%c", &continuar);
// } while (continuar == 's' || continuar == 'S');

// do
// {
//     leer(&ordenadaDos);
//     printf("Desea continuar? Ordenada 2 s/n ");
//     fflush(stdin);
//     scanf("%c", &continuar);
// } while (continuar == 's' || continuar == 'S');
