#include <stdio.h>
#include <stdlib.h>
#include "..\Librerias\pila.c"
// Eliminar un elemento de una pila. El eliminarlo, finalizar el recorrido y dejar el resto en el mismo orden.

int main()
{
    Pila pilita, auxpilita, buscar, basura;
    inicpila(&auxpilita);
    inicpila(&pilita);
    inicpila(&buscar);
    inicpila(&basura);
    char continuar;
    continuar = 's';

    printf("\tIngreso de valores para la pila PILITA: \n");

    while (continuar == 's' || continuar == 'S')
    {
        leer(&pilita);
        printf("Desea continuar? s/n ");
        fflush(stdin);
        scanf("%c", &continuar);
    }

    printf("Ingreso de valor a eliminar de la pila PILITA: \n");
    leer(&buscar);

    printf("Hay que sacar tu numero de PILITA. Asi se ve originalmente PILITA");
    mostrar(&pilita);

    while (!pilavacia(&pilita)) // si pilita no está vacia, se ejecuta esto.
    {
        if (tope(&pilita) == tope(&buscar))
        { // si el tope de pilita y el de buscar coinciden, se debe apilar ese valor en basura
            apilar(&basura, desapilar(&pilita));
        }
        else
        { // sino, se apila el valor en una auxiliar, para luego mostrarle al usuario la pila
            apilar(&auxpilita, desapilar(&pilita));
        }
    }

    while (!pilavacia(&auxpilita))
    { // mientras que el auxiliar de pilita no este vacio, se apilan sus valores en pilita
        apilar(&pilita, desapilar(&auxpilita));
    }
    if (!pilavacia(&basura))
    {
        printf("Pilita, sin lo que sacaste: ");
        mostrar(&pilita);
        printf("Aca fue el descarte");
        mostrar(&basura);
    }
    else
    {
        printf("ERROR! No ingreso un numero que se encuentre en la pila.\n");
    }

    system("pause");
    return 0;
}