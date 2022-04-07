#include <stdio.h>
#include <stdlib.h>
#include "..\Librerias\pila.c"
// Insertar un elemento en una pila ordenada de menor (tope) a mayor (base) de forma tal que se conserve el orden. (sin variables, solo pilas)

int main()
{
    Pila ordenada, mayOmen, aux;
    inicpila(&ordenada);
    inicpila(&mayOmen);
    inicpila(&aux);
    char continuar;
    continuar = 's';

    apilar(&ordenada, 5);
    apilar(&ordenada, 4);
    apilar(&ordenada, 3);
    apilar(&ordenada, 2);
    apilar(&ordenada, 1);
    mostrar(&ordenada);
    leer(&aux);

    if (tope(&aux) > tope(&ordenada))
    {
        while (tope(&aux) > tope(&ordenada))
        {
            apilar(&mayOmen, desapilar(&ordenada));
        }

        apilar(&ordenada, desapilar(&aux));

        while (!pilavacia(&mayOmen))
        {
            apilar(&ordenada, desapilar(&mayOmen));
        }
        printf("Tu pila quedo asi, con el valor mayor que insertaste: ");

        mostrar(&ordenada);
    }
    else
    {
        apilar(&mayOmen, desapilar(&aux));
    }

    if (tope(&mayOmen) < tope(&ordenada))
    { // si el tope de menor es menor al de pilita se desapila pilita en menor
        while (!pilavacia(&ordenada))
        {
            apilar(&mayOmen, desapilar(&ordenada));
        }
        while (!pilavacia(&mayOmen))
        {
            apilar(&ordenada, desapilar(&mayOmen));
        }
        printf("Tu pila quedo asi, con el valor menor que insertaste: ");
        mostrar(&ordenada);
    }

    system("pause");
    return 0;
}