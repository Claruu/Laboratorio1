#include <stdio.h>
#include <stdlib.h>
#include "..\Librerias\pila.c"
// Sumar los elementos de una pila (usar variables enteras)

int main()
{
    Pila pilaUser;
    inicpila(&pilaUser);
    int user = 0, sumaUser = 0;
    char continuar;
    continuar = 's';

    do
    {
        printf("Ingrese elementos a la pila: ");
        fflush(stdin);
        scanf("%d", &user);
        printf("Desea seguir agregando elementos? ");
        fflush(stdin);
        scanf("%c", &continuar);
        sumaUser += user;
        apilar(&pilaUser, user);
    } while (continuar == 's' || continuar == 'S');

    printf("Tu pila se ve asi: ");
    mostrar(&pilaUser);
    printf("Por lo cual, la suma de tus valores seria de %d.\n", sumaUser);

    system("pause");
    return 0;
}