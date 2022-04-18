#include <stdio.h>
#include <stdlib.h>
#include "Librerias\pila.c"
// NOTA: todas las funciones pedidas deben recibir por parámetro la/s pila/s cargadas con los datos. No se debe usar la función leer() dentro de la función, excepto en la función 1.
// Realizar todas las funciones en un mismo proyecto, para ir probando su correcto funcionamiento deberá desarrollar una función main, donde cree las variables y pilas que necesite, e invoque a las funciones como corresponda en cada caso.

// Funciones utiles:
void vaciarPila(Pila *, Pila *);
int mostrarMenu();

// 1. Hacer una función que permita ingresar varios elementos a una pila, tanto como quiera el usuario.
void cargarPila(Pila *);

// 2. Hacer una función que pase todos los elementos de una pila a otra.
void transferirElementos(Pila *, Pila *);

// 3. Hacer una función que pase todos los elementos de una pila a otra, pero conservando el orden.
void transferirMismoOrden(Pila *, Pila *, Pila *);

// 4. Hacer una función que encuentre el menor elemento de una pila y lo retorna. La misma debe eliminar ese dato de la pila. int buscarMenor(Pila*);
int buscarMenor(Pila *, Pila *, int);

// 5. Hacer una función que pase los elementos de una pila a otra, de manera que se genere una nueva pila ordenada. Usar la función del ejercicio 4. (Ordenamiento por selección)
void ordenarPorSeleccion(Pila *, Pila *);

// 6. Hacer una función que inserta en una pila ordenada un nuevo elemento, conservando el orden de ésta.
void insertarEnOrdenada(Pila *);

// 7. Hacer una función que pase los elementos de una pila a otra, de manera que se genere una nueva pila ordenada. Usar la función del ejercicio 6.  (Ordenamiento por inserción)

int main()
{
    int cargar = 0, opcion = 0;
    char continuar = 's';
    Pila uno, dos, aux, basura;
    inicpila(&uno);
    inicpila(&dos);
    inicpila(&aux);
    inicpila(&basura);

    printf("\tMenu TP3: Funciones \n");

    do
    {
        opcion = mostrarMenu();
        switch (opcion)
        {
        case 1:
            cargarPila(&uno);
            break;
        case 2:
            vaciarPila(&uno, &basura);
            transferirElementos(&uno, &dos);
            break;
        case 3:
            vaciarPila(&uno, &basura);
            transferirMismoOrden(&uno, &dos, &aux);
            break;
        case 4:
            vaciarPila(&uno, &basura);
            printf(" %d \n", buscarMenor(&uno, &aux, 1));
            printf("\nSu pila ORIGINAL sin el elemento menor: ");
            mostrar(&uno);
            break;
        case 5:
            vaciarPila(&uno, &basura);
            vaciarPila(&aux, &basura);
            cargarPila(&uno);
            ordenarPorSeleccion(&uno, &aux);
            break;
        case 6:
            vaciarPila(&uno, &basura);
            insertarEnOrdenada(&uno);
            break;
        default:
            printf("Usted no ha ingresado una opcion valida.\n");
            break;
        }

        fflush(stdin);
        printf("Desea continuar? s/n: ");
        scanf("%c", &continuar);
        fflush(stdin);
    } while (continuar == 's' || continuar == 'S');

    system("pause");
    return 0;
}

int mostrarMenu()
{
    int opcion = 0;
    printf("1-Funcion para cargar una pila.\n");
    printf("2-Transferir elementos de una pila a otra.\n");
    printf("3-Transferir elementos de una pila a otra conservando el orden.\n");
    printf("4-Buscar el menor elemento de una pila y retornarlo.\n");
    printf("5-Ordenar por seleccion una pila.\n");
    printf("6-Insertar en una pila ordenada un elemento, conservando el orden.\n");
    printf("\nIngrese la opcion a elegir (entre 1 y 10): ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

void vaciarPila(Pila *origen, Pila *destinoBasural)
{
    while (!pilavacia(origen))
    {
        apilar(destinoBasural, desapilar(origen));
    }
}

void cargarPila(Pila *destino)
{
    int cargar = 0;
    char seguir = 's';

    do
    {
        printf("Ingrese un numero a la pila: ");
        scanf("%d", &cargar);
        apilar(destino, cargar);
        printf("Desea seguir agregando elementos? s/n: ");
        fflush(stdin);
        scanf("%c", &seguir);
    } while (seguir == 's' || seguir == 'S');
    printf("Su pila al principio: ");
    mostrar(destino);
}

void transferirElementos(Pila *origen, Pila *destino)
{
    cargarPila(origen);

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
    cargarPila(origen);

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

int buscarMenor(Pila *original, Pila *aux, int cargar)
{
    int menor = 0;
    if (cargar == 1)
    {
        cargarPila(original);
    }

    if (!pilavacia(original))
    {
        menor = desapilar(original);
        while (!pilavacia(original))
        {
            if (tope(original) < menor)
            {
                apilar(aux, menor);
                menor = desapilar(original);
                continue;
            }

            apilar(aux, desapilar(original));
        }

        while (!pilavacia(original))
        {
            apilar(original, desapilar(aux));
        }
    }
    else
    {
        printf("La pila esta vacia..\n");
    }
    while (!pilavacia(aux))
    {
        apilar(original, desapilar(aux));
    }

    return menor;
}

void ordenarPorSeleccion(Pila *paraOrdenar, Pila *aux)
{
    int menorElemento;
    Pila b;
    inicpila(&b);

    while (!pilavacia(paraOrdenar))
    {
        menorElemento = buscarMenor(paraOrdenar, aux, 0);
        apilar(&b, menorElemento);
    }
    while (!pilavacia(&b))
    {
        apilar(paraOrdenar, desapilar(&b));
    }
    printf("Su pila ordenada :D");
    mostrar(paraOrdenar);
}

void insertarEnOrdenada(Pila *ordenada)
{
    int user;
    Pila aux;
    inicpila(&aux);
    cargarPila(ordenada);
    ordenarPorSeleccion(ordenada, &aux);
    printf("Ingrese un numero para insertar en la pila ordenada: ");
    fflush(stdin);
    scanf("%d", &user);
    while (!pilavacia(ordenada))
    {
        if (tope(ordenada) < user)
        {
            apilar(&aux, desapilar(ordenada));
            continue;
        }
        apilar(ordenada, user);
        break;
    }

    while (!pilavacia(&aux))
    {
        apilar(ordenada, desapilar(&aux));
    }
    printf("Su pila ordenada, senior :D");
    mostrar(ordenada);
}
