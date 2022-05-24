#include <stdio.h>
#include <stdlib.h>
#include "Librerias\pila.c"
/// NOTA: todas las funciones pedidas deben recibir por parámetro la/s pila/s cargadas con los datos. No se debe usar la función leer() dentro de la función, excepto en la función 1.
/// Realizar todas las funciones en un mismo proyecto, para ir probando su correcto funcionamiento deberá desarrollar una función main, donde cree las variables y pilas que necesite, e invoque a las funciones como corresponda en cada caso.

/// Funciones utiles:
int mostrarOpciones();

/// 1. Hacer una función que permita ingresar varios elementos a una pila, tanto como quiera el usuario.
void cargarPila(Pila *);

/// 2. Hacer una función que pase todos los elementos de una pila a otra.
void transferirElementos(Pila *, Pila *);

/// 3. Hacer una función que pase todos los elementos de una pila a otra, pero conservando el orden.
void transferirMismoOrden(Pila *, Pila *, Pila *);

/// 4. Hacer una función que encuentre el menor elemento de una pila y lo retorna. La misma debe eliminar ese dato de la pila. int buscarMenor(Pila*);
int buscarMenor(Pila *, Pila *);

/// 5. Hacer una función que pase los elementos de una pila a otra, de manera que se genere una nueva pila ordenada. Usar la función del ejercicio 4. (Ordenamiento por selección)
void ordenarPorSeleccion(Pila *, Pila *);

/// 6. Hacer una función que inserta en una pila ordenada un nuevo elemento, conservando el orden de ésta.
void ordenarPorInsercion(Pila *, int);

/// 7. Hacer una función que pase los elementos de una pila a otra, de manera que se genere una nueva pila ordenada. Usar la función del ejercicio 6.  (Ordenamiento por inserción)
void pasarOrdenada(Pila *, Pila *);

// 8. Hacer una función que sume y retorne los dos primeros elementos de una pila (tope y anterior), sin alterar su contenido.
int sumaYretornoPrimerosElementos(Pila, int *, int *, int *);
// funcion ayuda para ejercicio 8
void sumaDosPrimerosElementos(Pila, int *, int *, int *);
int verificacionPilaConDosElementos(Pila);

// 9. Hacer una función que calcule el promedio de los elementos de una pila, para ello hacer también una función que calcule la suma, otra para la cuenta y otra que divida. En total son cuatro funciones, y la función que calcula el promedio invoca a las otras 3.

void mirarPila();
int main()
{
    int opcion = 0, primero = 0, segundo = 0, suma = 0;
    char continuar = 's';
    Pila uno, dos, aux;
    inicpila(&uno);
    inicpila(&dos);
    inicpila(&aux);

    printf("\tMenu TP3: Funciones \n");

    do
    {
        opcion = mostrarOpciones();
        inicpila(&uno);
        inicpila(&dos);
        inicpila(&aux);
        switch (opcion)
        {
        case 1:
            printf("\t\n1-Funcion para cargar una pila\t\n");
            cargarPila(&uno);
            printf("Su pila: ");
            mostrar(&uno);
            break;
        case 2:
            printf("\t\n2-Transferir elementos de una pila a otra\t\n");
            transferirElementos(&uno, &dos);
            break;
        case 3:
            printf("\t\n3-Transferir elementos de una pila a otra conservando el orden\n");
            cargarPila(&uno);
            transferirMismoOrden(&uno, &dos, &aux);
            break;
        case 4:
            printf("\t\n4-Buscar el menor elemento de una pila y retornarlo\n");
            cargarPila(&uno);
            mostrar(&uno);
            printf("\nEste era su elemento menor: %d \n", buscarMenor(&uno, &aux));
            printf("\nSu pila ORIGINAL, sin el elemento menor: ");
            mostrar(&uno);
            break;
        case 5:
            printf("\t\n5-Ordenar por seleccion una pila\n");
            cargarPila(&uno);
            ordenarPorSeleccion(&uno, &aux);
            break;
        case 6:
            printf("\t\n6-Insertar en una pila ordenada un elemento, conservando el orden\n");
            cargarPila(&uno);
            ordenarPorSeleccion(&uno, &aux);
            int user = 0;
            printf("Elemento a insertar en la pila: ");
            scanf("%d", &user);
            ordenarPorInsercion(&uno, user);
            printf("\nSu pila, ordenada: \n");
            mostrar(&uno);
            break;
        case 7:
            printf("\t7-Realizar una nueva pila ordenada en base a una ya ordenada.\n");
            cargarPila(&uno);
            ordenarPorSeleccion(&uno, &aux);
            cargarPila(&dos);
            pasarOrdenada(&uno, &dos);
            break;
        case 8:
            printf("\tSumar y retornar los dos primeros elementos de una pila, sin alterar su contenido\n");
            cargarPila(&uno);
            verificacionPilaConDosElementos(uno);
            sumaDosPrimerosElementos(uno, &suma, &primero, &segundo);
            sumaYretornoPrimerosElementos(uno, &suma, &primero, &segundo);
            mostrar(&uno);
            printf("\nSu primer elemento: %d\n", primero);
            printf("Su segundo elemento: %d\n", segundo);
            printf("El resultado de la suma de ambos elementos: %d\n", suma);
            break;
        default:
            printf("\tUsted no ha ingresado una opcion valida.\n");
            break;
        }
        printf("Desea continuar? s/n: ");
        fflush(stdin);
        scanf("%c", &continuar);

    } while (continuar == 's' || continuar == 'S');

    system("pause");
    return 0;
}

int mostrarOpciones()
{
    int opcion = 0;
    printf("\n1-Funcion para cargar una pila.\n");
    printf("2-Transferir elementos de una pila a otra.\n");
    printf("3-Transferir elementos de una pila a otra conservando el orden.\n");
    printf("4-Buscar el menor elemento de una pila y retornarlo.\n");
    printf("5-Ordenar por seleccion una pila.\n");
    printf("6-Insertar en una pila ordenada un elemento, conservando el orden.\n");
    printf("7-Realizar una nueva pila ordenada en base a una ya ordenada.\n");
    printf("8-Sumar y retornar los dos primeros elementos de una pila, sin alterar su contenido\n");
    printf("\tIngrese la opcion a elegir (entre 1 y 10): ");
    fflush(stdin);
    scanf("%d", &opcion);
    return opcion;
}

void cargarPila(Pila *destino)
{
    int cargar = 0;
    char seguir = 's';

    do
    {
        printf("Ingrese un numero a la pila: ");
        fflush(stdin);
        scanf("%d", &cargar);
        apilar(destino, cargar);
        printf("Desea seguir agregando elementos? s/n: ");
        fflush(stdin);
        scanf("%c", &seguir);
    } while (seguir == 's' || seguir == 'S');
}

void transferirElementos(Pila *origen, Pila *destino)
{
    cargarPila(origen);

    while (!pilavacia(origen))
    {
        apilar(destino, desapilar(origen));
    }

    printf("Su pila origen ya no tiene elementos: ");
    mostrar(origen);
    printf("Su pila destino tiene todos los elementos de la pila origen:");
    mostrar(destino);
}

void transferirMismoOrden(Pila *origen, Pila *destino, Pila *aux)
{
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

int buscarMenor(Pila *original, Pila *aux)
{
    int menor = 0;

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
        menorElemento = buscarMenor(paraOrdenar, aux);
        apilar(&b, menorElemento);
    }
    while (!pilavacia(&b))
    {
        apilar(paraOrdenar, desapilar(&b));
    }
    printf("Su pila, ordenada:");
    mostrar(paraOrdenar);
}

void ordenarPorInsercion(Pila *paraOrdenar, int valor)
{
    Pila aux;
    inicpila(&aux);

    while (!pilavacia(paraOrdenar))
    {
        if (tope(paraOrdenar) < valor)
        {
            apilar(&aux, desapilar(paraOrdenar));
            continue;
        }
        apilar(paraOrdenar, valor);
        break;
    }

    while (!pilavacia(&aux))
    {
        apilar(paraOrdenar, desapilar(&aux));
    }
}

/// 7. Hacer una función que pase los elementos de una pila a otra, de manera que se genere una nueva pila ordenada. Usar la función del ejercicio 6.  (Ordenamiento por inserción)
void pasarOrdenada(Pila *ordenada, Pila *nuevosDatos)
{
    Pila aux;
    inicpila(&aux);

    while (!pilavacia(nuevosDatos))
    {

        ordenarPorInsercion(ordenada, desapilar(nuevosDatos));
    }

    mostrar(ordenada);
}

int verificacionPilaConDosElementos(Pila uno)
{
    int validacion = 0, basura = 0;
    if (!pilavacia(&uno))
    {
        basura = desapilar(&uno);
    }
    else if (!pilavacia(&uno))
    {
        validacion == 1;
    }
    return validacion;
}
void sumaDosPrimerosElementos(Pila uno, int *suma, int *primero, int *segundo)
{
    *primero = desapilar(&uno);
    *segundo = desapilar(&uno);

    *suma = (*primero) + (*segundo);
}

int sumaYretornoPrimerosElementos(Pila uno, int *suma, int *primero, int *segundo)
{
    if (!verificacionPilaConDosElementos(uno))
    {
        sumaDosPrimerosElementos(uno, suma, primero, segundo);
    }
}
