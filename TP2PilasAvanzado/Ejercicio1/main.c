#include <stdio.h>
#include <stdlib.h>
#include "..\Librerias\pila.c"
// Sumar los elementos de una pila (usar variables enteras)

int main()
{
    Pila pilaUser, aux;
    inicpila(&pilaUser);
    inicpila(&aux);
    int user = 0, sumaUser = 0;
    char continuar;
    continuar = 's';

    do
    {
        leer(&pilaUser);
        printf("Desea seguir agregando elementos? ");
        fflush(stdin);
        scanf("%c", &continuar);
    } while (continuar == 's' || continuar == 'S');

    while (!pilavacia(&pilaUser))
    {
        sumaUser += tope(&pilaUser);
        apilar(&aux, desapilar(&pilaUser));
    }
    while (!pilavacia(&aux))
    {
        apilar(&pilaUser, desapilar(&aux));
    }
    printf("Tu pila se ve asi: ");
    mostrar(&pilaUser);
    printf("Por lo cual, la suma de tus valores seria de %d.\n", sumaUser);

    system("pause");
    return 0;
}