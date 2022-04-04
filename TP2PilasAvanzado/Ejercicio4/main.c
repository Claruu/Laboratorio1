#include <stdio.h>
#include <stdlib.h>
#include "..\Librerias\pila.c"
// Encontrar el menor elemento de una pila y guardarlo en otra. (sin variables enteras, solo pilas)

int main()
{
    Pila pilita, aux, menor;
    inicpila(&pilita);
    inicpila(&aux);
    inicpila(&menor);
    char continuar;
    continuar = 's';
    do
    {
        leer(&pilita);
        printf("Desea seguir?: ");
        fflush(stdin);
        scanf("%c", &continuar);
    } while (continuar == 's' || continuar == 'S');

    printf("Mira tu pilita: ");
    mostrar(&pilita);

    while (!pilavacia(&pilita))
    {
        if (pilavacia(&menor))
        {
            apilar(&menor, desapilar(&pilita));
            continue;
        }

        if (tope(&pilita) < tope(&menor))
        {
            apilar(&aux, desapilar(&menor));
            apilar(&menor, desapilar(&pilita));
        }
        else
        {
            apilar(&aux, desapilar(&pilita));
        }
    }
    printf("Elemento menor:");
    mostrar(&menor);
    system("pause");
    return 0;
}