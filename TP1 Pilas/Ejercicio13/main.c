#include <stdio.h>
#include <stdlib.h>
#include "..\Librerias\pila.c"
// 13. Suponiendo la existencia de una pila LÍMITE, pasar los elementos de la pila DADA que sean mayores o iguales que el tope de LIMITE a la pila MAYORES, y los elementos que sean menores a la pila MENORES.

int main()
{
    Pila limite, dada, mayores, menores;
    int user = 0;
    char continuar;
    continuar = 's';
    inicpila(&limite);
    inicpila(&dada);
    inicpila(&mayores);
    inicpila(&menores);

    printf("\tIngrese valores para la pila LIMITE\t\n");
    do
    {
        scanf("%d", &user);
        apilar(&limite, user);
        fflush(stdin);
        printf("\nDesea seguir ingresando valores? PILA LIMITE\n");
        scanf("%c", &continuar);
        fflush(stdin);
    } while (continuar == 's' || continuar == 'S');

    printf("\n\tIngrese valores para la pila DADA\t\n");
    do
    {
        scanf("%d", &user);
        apilar(&dada, user);
        fflush(stdin);
        printf("\nDesea seguir ingresando valores? PILA DADA\n");
        scanf("%c", &continuar);
        fflush(stdin);
    } while (continuar == 's' || continuar == 'S');

    printf("PILA LIMITE\n");
    mostrar(&limite);
    printf("PILA DADA\n");
    mostrar(&dada);

    while (!pilavacia(&dada))
    {
        if (tope(&dada) >= tope(&limite))
        {
            apilar(&mayores, desapilar(&dada));
        }
        else
        {
            apilar(&menores, desapilar(&dada));
        }
    }
    printf("Mayorcitos");
    mostrar(&mayores);
    printf("Menorcitos\n");
    mostrar(&menores);

    // 13. Suponiendo la existencia de una pila LÍMITE, pasar los elementos de la pila DADA que sean mayores o iguales que el tope de LIMITE a la pila MAYORES, y los elementos que sean menores a la pila MENORES.
    system("pause");
    return 0;
}