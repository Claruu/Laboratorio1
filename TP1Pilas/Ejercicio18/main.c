#include <stdio.h>
#include <stdlib.h>
#include "..\Librerias\pila.c"
//
void eliminarElementosPila(int[], Pila *, int);
void apilarPares(Pila, Pila, Pila *);
void cargarPila(Pila *p)
{
    char continuar;
    do
    {
        printf("Ingrese datos a la pila\n");
        leer(p);
        fflush(stdin);
        printf("Desea continuar? s/n: ");
        scanf("%c", &continuar);
    } while (continuar == 's' || continuar == 'S');
    mostrar(p);
}

int main()
{
    int arreglo[] = {2, 3, 5, 1, 9};
    int validos = 5;
    Pila p;
    inicpila(&p);
    Pila p1;
    inicpila(&p1);
    Pila p2;
    inicpila(&p2);
    Pila p3;
    inicpila(&p3);

    // cargarPila(&p);
    // printf("Antes\n\n\n");
    // eliminarElementosPila(arreglo, &p, validos);
    // printf("Despues\n\n\n");
    // mostrar(&p);

    cargarPila(&p1);
    cargarPila(&p2);
    printf("Antes\n\n\n");
    apilarPares(p1, p2, &p3);
    mostrar(&p1);
    mostrar(&p2);
    printf("Despues\n\n\n");
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

    if ((pilavacia(&p1)) * (pilavacia(&p2))) // si uno está vacío pero el otro no, quedan elementos en uno.
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

        while (!pilavacia(&aux))
        {
            apilar(p, desapilar(&aux));
        }
    }
}