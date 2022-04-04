#include <stdio.h>
#include <stdlib.h>
#include "..\Librerias\pila.c"
// Contar los elementos de una pila (usar variables enteras)

int main()
{
    Pila pilaUser;
    inicpila(&pilaUser);
    int contador = 0;
    char continuar;
    continuar = 's';

    while (continuar == 's' || continuar == 'S')
    {
        leer(&pilaUser);
        contador++;
        printf("Desea seguir ingresando valores?: ");
        fflush(stdin);
        scanf("%c", &continuar);
    }
    printf("Usted ha ingresado %d elementos a la pila. \n", contador);

    system("pause");
    return 0;
}