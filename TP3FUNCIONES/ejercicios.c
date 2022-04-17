#include <stdio.h>
#include <stdlib.h>
#include "Librerias\pila.c"
// NOTA: todas las funciones pedidas deben recibir por parámetro la/s pila/s cargadas con los datos. No se debe usar la función leer() dentro de la función, excepto en la función 1.
// Realizar todas las funciones en un mismo proyecto, para ir probando su correcto funcionamiento deberá desarrollar una función main, donde cree las variables y pilas que necesite, e invoque a las funciones como corresponda en cada caso.

// 1. Hacer una función que permita ingresar varios elementos a una pila, tanto como quiera el usuario.
void cargarPila(Pila *);

// 2. Hacer una función que pase todos los elementos de una pila a otra.
void transferirElementos(Pila *, Pila *);

// 3. Hacer una función que pase todos los elementos de una pila a otra, pero conservando el orden.
void transferirMismoOrden(Pila *, Pila *, Pila *);

int main()
{
    int cargar = 0, opcion = 0;
    char continuar = 'n';
    Pila uno, dos, aux;
    inicpila(&uno);
    inicpila(&dos);
    inicpila(&aux);

    printf("\tMenu TP4: Funciones \n");

    do
    {
        printf("1-Funcion para cargar una pila.\n2-Funcion para transferir elementos de una pila a otra.\n3-Funcion para transferir elementos de una pila a otra conservando el orden.\n");
        printf("\nIngrese la opcion a elegir (entre 1 y 10): ");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            cargarPila(&uno);
            break;
        case 2:

            transferirElementos(&uno, &dos);
            break;
        case 3:
            transferirMismoOrden(&uno, &dos, &aux);
            break;
        default:
            printf("Usted no ha ingresado una opcion valida.\n");
            break;
        }

        fflush(stdin);
        printf("Desea continuar? s/n: ");
        scanf("%c", &continuar);
    } while (continuar == 's' || continuar == 'S');

    system("pause");
    return 0;
}

void cargarPila(Pila *pilaUser)
{
    int cargar = 0;
    char seguir = 's';

    do
    {
        printf("Ingrese un numero a la pila: ");
        scanf("%d", &cargar);
        apilar(pilaUser, cargar);
        printf("Desea seguir agregando elementos? ");
        fflush(stdin);
        scanf("%c", &seguir);
    } while (seguir == 's' || seguir == 'S');
    mostrar(pilaUser);
}

void transferirElementos(Pila *origen, Pila *destino)
{
    int cargar = 0;
    char seguir = 's';

    do
    {
        printf("Ingrese un numero a la pila ORIGEN: ");
        scanf("%d", &cargar);
        apilar(origen, cargar);
        printf("Desea seguir cargando elementos? ");
        fflush(stdin);
        scanf("%c", &seguir);

    } while (seguir == 'S' || seguir == 's');
    printf("Esta es su pila ORIGEN originalmente:");
    mostrar(origen);

    while (!pilavacia(origen))
    {
        apilar(destino, desapilar(origen));
    }

    printf("Su pila ORIGEN ya no tiene elementos: ");
    mostrar(origen);
    printf("Su pila DESTINO tiene todos los elementos de la pila ORIGEN:");
    mostrar(destino);
}

void transferirMismoOrden(Pila *origen, Pila *destino, Pila *aux)
{
    int cargar = 0;
    char seguir = 's';

    do
    {
        printf("Ingrese un elemento para la pila ORIGEN:");
        scanf("%d", &cargar);
        apilar(origen, cargar);
        printf("Desea seguir cargando elementos? s/n: ");
        fflush(stdin);
        scanf("%c", &seguir);

    } while (seguir == 's' || seguir == 'S');
    printf("Su pila origen");
    mostrar(origen);
    while (!pilavacia(origen))
    {
        apilar(aux, desapilar(origen));
    }

    while (!pilavacia(aux))
    {
        apilar(destino, desapilar(aux));
    }
    printf("Su pila destino, en el mismo orden");
    mostrar(destino);
}
