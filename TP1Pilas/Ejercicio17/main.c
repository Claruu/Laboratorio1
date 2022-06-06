#include <stdio.h>
#include <stdlib.h>
#include "..\Librerias\pila.c"
// resuelto en word

int main()
{
    Pila Origen, Distinto;
    char continuar;
    continuar = 's';
    int user;
    inicpila(&Origen);
    inicpila(&Distinto);
    do
    {
        printf("\tIngrese un valor para la pila ORIGEN\t\n");
        fflush(stdin);
        scanf("%d", &user);
        apilar(&Origen, user);
        printf("\nDesea seguir ingresando valores? PILA ORIGEN\n");
        fflush(stdin);
        scanf("%c", &continuar);
    } while (continuar == 's' || continuar == 'S');
    if (!pilavacia(&Origen))
    {
        while (tope(&Origen) != 5)
        {
            apilar(&Distinto, desapilar(&Origen));
        }
    }
    mostrar(&Distinto);
    mostrar(&Origen);
    system("pause");
    return 0;
}
