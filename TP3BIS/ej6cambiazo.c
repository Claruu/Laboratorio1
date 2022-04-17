#include <stdio.h>
#include <stdlib.h>
// Realizar una función que reciba un número positivo entero por parámetro por referencia, y cambie su signo a negativo.

void cambiazo(int *);

int main()
{
    int cambio = 0; // declaro e inicializo cambio

    printf("Por favor ingrese un numero positivo: ");
    scanf("%d", &cambio); // el usuario me ingresa normalmente la variable

    cambiazo(&cambio); // aqui referencio la funcion que cambia los positivos a negativos

    printf("Tu numero como negativo: %d\n", cambio); // muestro el cambio

    system("pause");
    return 0;
}
// aqui, *numero está realizando una referencia a la variable utilizada en el main, que se llama cambio
void cambiazo(int *numero)
{
    *numero = *numero * (-1);
}
