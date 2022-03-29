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

    printf("Ingrese los elementos del mazo\n");
    do
    {
        scanf("%d", &user);
        if (user != 0)
        {
            apilar(&mazo, user);
        }
    } while (user != 0);

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
