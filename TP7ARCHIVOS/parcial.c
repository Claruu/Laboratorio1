#include <stdio.h>
#include <stdlib.h>
#include ".\Librerias\pila.c"
//
void apilarPares(Pila, Pila, Pila *);

int main()
{
    Pila p1;
    Pila p2;
    Pila p3;
    inicpila(&p1);
    inicpila(&p2);
    inicpila(&p3);
    //     p1 base 3 4 6 tope

    // p2 base 1 4 4 4 tope
    apilar(&p1, 3);
    apilar(&p1, 4);
    apilar(&p1, 6);
    apilar(&p2, 1);
    apilar(&p2, 4);
    apilar(&p2, 4);
    apilar(&p2, 4);

    apilarPares(p1, p2, &p3);

    mostrar(&p3);
    system("pause");
    return 0;
}

void apilarPares(Pila p1, Pila p2, Pila *p3)

{

    Pila aux1;

    inicpila(&aux1);

    Pila aux2;

    inicpila(&aux2);

    int suma = 0;

    while ((!pilavacia(&p1)) && (!pilavacia(&p2))) // mientras que ninguna de las dos pilas esté vacía, se va iterando
    {
        suma = tope(&p1) + tope(&p2); // va sumando los topes

        apilar(p3, suma); // la suma se va apilando en la pila a medida que va iterando

        apilar(&aux1, desapilar(&p1));
        apilar(&aux2, desapilar(&p2));
    }

    if ((pilavacia(&p1)) ^ (pilavacia(&p2))) // si uno está vacío pero el otro no, quedan elementos en uno.
    {
        while (!pilavacia(&p1))
        {
            apilar(p3, desapilar(&p1));
        }
        while (!pilavacia(&p2))
        {
            apilar(p3, desapilar(&p2));
        }
    }
}

void eliminarElementosPila(int arreglo[], Pila *p, int validos)
{

    Pila aux;
    inicpila(&aux);

    Pila basura;
    inicpila(&basura);

    for (int i = 0; i < validos; i++)

    {

        while (!pilavacia(p))
        {

            if (tope(p) == arreglo[i])
            {
                apilar(&basura, desapilar(p));
            }
            else
            {
                apilar(&aux, desapilar(p));
            }
        }

        apilar(p, desapilar(&aux));
    }
}