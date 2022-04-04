#include <stdio.h>
#include <stdlib.h>
#include "..\Librerias\pila.c"
// Calcular el promedio de los valores de una pila (usar variables)

int main()
{
    Pila pilaUser;
    inicpila(&pilaUser);
    int user = 0, contador = 0, acumulador = 0;
    float promedio = 0;
    char continuar;
    continuar = 's';
    do
    {
        printf("Ingrese un valor entero:", contador);
        fflush(stdin);
        scanf("%d", &user);
        apilar(&pilaUser, user);
        contador++;
        acumulador += user;
        printf("Desea seguir agregando elementos? ");
        fflush(stdin);
        scanf("%c", &continuar);
    } while (continuar == 's' || continuar == 'S');
    printf("%d / %d", acumulador, contador);
    promedio = (float)acumulador / contador;
    printf("\nSu promedio seria de : %.2f\n", promedio);

    system("pause");
    return 0;
}