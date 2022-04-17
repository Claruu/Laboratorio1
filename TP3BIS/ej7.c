#include <stdio.h>
#include <stdlib.h>
// Realizar una función que reciba dos números enteros por parámetro por referencia y cargue sus valores el usuario dentro de la función.

void funcion(int *, int *);

int main()
{
    int numUno = 0, numDos = 0;

    printf("Por favor ingrese dos numeros a continuacion:\n");
    funcion(&numUno, &numDos);
    printf("Su primer numero: %d\n", numUno);
    printf("Su segundo numero: %d\n", numDos);
    system("pause");
    return 0;
}

void funcion(int *numeroUno, int *numeroDos)
{
    int a = 0;
    scanf("%d", &a);
    *numeroUno = a;
    scanf("%d", &a);
    *numeroDos = a;
}