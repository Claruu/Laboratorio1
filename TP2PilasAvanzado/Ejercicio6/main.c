#include <stdio.h>
#include <stdlib.h>
#include "..\Librerias\pila.c"
// Usando lo resuelto en el ejercicio 4, pasar los elementos de una pila a otra de forma tal que la segunda pila quede ordenada de mayor (tope) a menor (base). Esto se llama método de ordenación por selección.

int main()
{
    Pila dada, auxgeneral, auxdada;
    inicpila(&dada);
    inicpila(&auxgeneral);
    inicpila(&auxdada);
    char continuar;
    continuar = 's';

    while (continuar == 's' || continuar == 'S')
    {
        leer(&dada);
        printf("Desea seguir? ");
        fflush(stdin);
        scanf("%c", &continuar);
    }

    while (!pilavacia(&dada))
    {
        apilar(&auxdada, desapilar(&dada));

        while (!pilavacia(&dada))
        {
            if (tope(&auxdada) > tope(&dada))
            {
                apilar(&auxgeneral, desapilar(&auxdada));
                apilar(&auxdada, desapilar(&dada));
            }
            else
            {
                apilar(&auxgeneral, desapilar(&dada));
            }
        }
        while (!pilavacia(&auxgeneral))
        {
            apilar(&dada, desapilar(&auxgeneral));
        }
    }
    printf("Tu pila se ve muy linda ordenada:");
    mostrar(&auxdada);

    system("pause");
    return 0;
}
// Usando lo resuelto en el ejercicio 4, pasar los elementos de una pila a otra de forma tal que la segunda pila quede ordenada de mayor (tope) a menor (base). Esto se llama método de ordenación por selección.
