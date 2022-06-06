#include <stdio.h>
#include <stdlib.h>
#include ".\pila.c"
// 8. Repartir los elementos de la pila MAZO en las pilas JUGADOR1 y JUGADOR2 en forma alternativa.
int main()
{
    // declaro pilas
    Pila mazo, jugador1, jugador2;
    int user = 0;
    char continuar;
    continuar = 's';
    // inicializo pilas
    inicpila(&mazo);
    inicpila(&jugador1);
    inicpila(&jugador2);

    do
    {
        printf("\tIngrese un valor para la pila MAZO\t\n");
        fflush(stdin);
        scanf("%d", &user);
        apilar(&mazo, user);
        printf("\nDesea seguir ingresando valores? PILA MAZO\n");
        fflush(stdin);
        scanf("%c", &continuar);
    } while (continuar == 's' || continuar == 'S');

    while (!pilavacia(&mazo))
    {
        apilar(&jugador1, desapilar(&mazo));
        if (!pilavacia(&mazo))
        {
            apilar(&jugador2, desapilar(&mazo));
        }
    }
    mostrar(&jugador1);
    mostrar(&jugador2);

    system("pause");
    return 0;
}
