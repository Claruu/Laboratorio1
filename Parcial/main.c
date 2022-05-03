#include <stdio.h>
#include <stdlib.h>
#include "Librerias\pila.c"
//

int nombre(Pila p);

int main()
{
    int a = 0, b, teMuestro = 0;
    Pila wii;
    inicpila(&wii);
    apilar(&wii, 4);
    apilar(&wii, 6);
    apilar(&wii, 7);
    apilar(&wii, 8);
    apilar(&wii, 9);
    apilar(&wii, 0);
    apilar(&wii, 5);
    printf("%i", a);
    mostrar(&wii);

    teMuestro = printf("Resultado final: %d\n", nombre(wii));
    printf("Resultado del resto de la division de 0 / 2 equivale a 0: %d", (0 % 2) == 0);
    printf("\nTu pila:");
    mostrar(&wii);
    system("pause");
    return 0;
}

int nombre(Pila p)
{
    int a = 0;
    int b;
    while (!pilavacia(&p))
    {
        a = a + (tope(&p) % 2 == 0);
        b = desapilar(&p);
    }
    return a;
}
