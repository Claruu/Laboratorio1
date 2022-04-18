#include <stdio.h>
#include <stdlib.h>
#include "Librerias\pila.c"

/**
Buscar el menor elemento de una pila y mostrarlo, la pila debe conservarse
 **/

int main()
{
    int menor, user;
    char continuar;
    continuar = 's';
    Pila pilaUser;
    Pila aux;
    inicpila(&pilaUser);
    inicpila(&aux);

    do
    {
        printf("Ingrese un valor para la pila USER: ");
        fflush(stdin);
        scanf("%d", &user);
        apilar(&pilaUser, user);
        printf("\nDesea seguir ingresando valores? s/n: ");
        fflush(stdin);
        scanf("%c", &continuar);
    } while (continuar == 's' || continuar == 'S');

    mostrar(&pilaUser); // muestro la pila

    if (!pilavacia(&pilaUser)) /// primero verifico que la pila tenga datos
    {
        apilar(&aux, desapilar(&pilaUser)); /// desapilo en aux para que en la comparacion no vuelva a usar el mismo elemento

        menor = tope(&aux); /// inicializo menor con el primer elemento de p (para luego comparar)

        while (!pilavacia(&pilaUser))
        {
            if (tope(&pilaUser) < menor) /// comparo cada elemento de p con menor y actualizo su valor
            {
                menor = tope(&pilaUser);
            }
            apilar(&aux, desapilar(&pilaUser)); /// desapilo en aux, haya o no haya sido menor
        }
        while (!pilavacia(&aux)) /// devuelvo los elementos de aux hacia p (para conservarla)
        {
            apilar(&pilaUser, desapilar(&aux));
        }

        printf("El menor elemento es: %i", menor);
    }
    else
    {
        printf("La pila esta vacia..\n");
    }
    mostrar(&pilaUser);
    system("pause");
    return 0;
}