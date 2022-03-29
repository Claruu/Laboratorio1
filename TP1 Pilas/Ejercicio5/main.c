#include <stdio.h>
#include <stdlib.h>
#include ".\pila.c"
// 5. Cargar desde el teclado la pila DADA. Invertir la pila de manera que DADA contenga los elementos cargados originalmente en ella, pero en orden inverso.

int main()
{
    // declaro pilas
    Pila dada, aux, aux2;
    int user = 0;
    char continuar;
    continuar = 's';
    // inicializo pilas
    inicpila(&dada);
    inicpila(&aux);
    inicpila(&aux2);

    printf("Por favor ingrese los valores para la pila DADA.\n");
    printf("Al ingresar el numero 0, finaliza la carga de valores.\n");
    do
    {
        printf("\tIngrese un valor para la pila DADA\t\n");
        fflush(stdin);
        scanf("%d", &user);
        apilar(&dada, user);
        printf("\nDesea seguir ingresando valores? PILA DADA\n");
        fflush(stdin);
        scanf("%c", &continuar);
    } while (continuar == 's' || continuar == 'S');

    // muestro los valores de la pila DADA
    printf("Al principio, la pila dada es asi: \n");
    mostrar(&dada);

    while (!pilavacia(&dada))
    {
        apilar(&aux, desapilar(&dada));
    }
    while (!pilavacia(&aux))
    {
        apilar(&aux2, desapilar(&aux));
    }
    while (!pilavacia(&aux2))
    {
        apilar(&dada, desapilar(&aux2));
    }

    printf("Al invertir los valores, la pila DADA se ve asi: \n");
    mostrar(&dada);

    system("pause");
    return 0;
}
