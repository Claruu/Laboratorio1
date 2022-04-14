#include <stdio.h>
#include <stdlib.h>
#include "..\Librerias\pila.c"
// Dadas dos pilas A y B que simulan conjuntos (cada conjunto no tiene elementos repetidos sobre sí mismo), realizar un programa que calcule en la pila C la operación de unión.

int main()
{
    Pila a, b, c, basura, aux;
    inicpila(&a);
    inicpila(&b);
    inicpila(&c);
    inicpila(&basura);
    inicpila(&aux);
    char continuar = 's';

    printf("\tA: \n");
    do
    {
        leer(&a);
        printf("Desea continuar cargando A? s/n ");
        fflush(stdin);
        scanf("%c", &continuar);
    } while (continuar == 's' || continuar == 'S');

    printf("\tB: \n");
    do
    {
        leer(&b);
        printf("Desea continuar cargando B? s/n ");
        fflush(stdin);
        scanf("%c", &continuar);
    } while (continuar == 's' || continuar == 'S');

    mostrar(&a);
    mostrar(&b);

    while (!pilavacia(&a))
    {
        apilar(&c, desapilar(&a));
    }

    while (!pilavacia(&b))
    { // mientras que b tenga algo

        while (!pilavacia(&c))
        { // mientras que c tenga algo
            if (tope(&b) == tope(&c))
            {
                apilar(&basura, desapilar(&b));
                break;
            }
            apilar(&aux, desapilar(&c));
        }

        if (pilavacia(&c))
        {
            apilar(&c, desapilar(&b));
        }

        while (!pilavacia(&aux))
        {
            apilar(&c, desapilar(&aux));
        }
    }
    printf("Su union de pilas, personita");
    mostrar(&c);

    system("pause");
    return 0;
    // Dadas dos pilas A y B que simulan conjuntos (cada conjunto no tiene elementos repetidos sobre sí mismo), realizar un programa que calcule en la pila C la operación de unión.
}