#include <stdio.h>
#include <stdlib.h>
#include "..\Librerias\pila.c"
// Determinar si un elemento buscado está dentro de una pila. Al encontrarlo, finalizar la búsqueda.

int main()
{
    Pila pilita, buscar, basura;
    inicpila(&pilita);
    inicpila(&buscar);
    inicpila(&basura);

    char continuar;
    continuar = 's';

    while (continuar == 's' || continuar == 'S')
    {
        leer(&pilita);
        printf("Desea continuar? s/n ");
        fflush(stdin);
        scanf("%c", &continuar);
    }

    printf("\t Por teclado, ingrese el elemento a buscar: \n");
    leer(&buscar);

    while (tope(&buscar) != tope(&pilita) && !pilavacia(&pilita))
    // mientras que el tope de buscar no sea igual que el de pilita, y mientras que pilita no esté vacía
    {
        apilar(&basura, desapilar(&pilita));
    }

    if (!pilavacia(&pilita)) // si pilita no está vacía, significa que se encontró el valor en la pila, sino no.
    {
        printf("Encontre tu valor en la pila. \n");
    }
    else
    {
        printf("No encontre tu valor en la pila. \n");
    }

    system("pause");
    return 0;
}