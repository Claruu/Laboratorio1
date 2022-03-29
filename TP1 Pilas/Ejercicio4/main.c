#include <stdio.h>
#include <stdlib.h>
#include ".\pila.c"
// 4. Cargar desde el teclado la pila ORIGEN e inicializar en vacío la pila DESTINO. Pasar los elementos de la pila ORIGEN a la pila DESTINO, pero dejándolos en el mismo orden.

int main()
{
    // declaro pilas
    Pila origen, destino, aux;
    int user = 0;
    char continuar;
    continuar = 's';
    // inicializo pilas
    inicpila(&origen);
    inicpila(&destino);
    inicpila(&aux);

    do
    {
        scanf("%d", &user);
        if (user != 0)
        {
            apilar(&origen, user);
        }

    } while (user != 0);

    printf("Primero te muestro la pila ORIGEN");
    mostrar(&origen);

    printf("Ahora pasaremos de la pila ORIGEN a DESTINO\n");
    while (!pilavacia(&origen))
    {
        apilar(&aux, desapilar(&origen));
    }
    while (!pilavacia(&aux))
    {
        apilar(&destino, desapilar(&aux));
    }

    printf("\n Aqui te muestro la pila DESTINO \n");
    mostrar(&destino);

    system("pause");
    return 0;
}
