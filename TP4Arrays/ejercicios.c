#include <stdio.h>
#include <stdlib.h>
#include "Librerias\pila.c"

#define TAM_MAX 10
#define DIMENSION 100
// 1- Hacer una función que reciba como parámetro un arreglo de números enteros y permita que el usuario ingrese valores al mismo por teclado. La función debe retornar la cantidad de elementos cargados en el arreglo (o pueden utilizar como puntero válidos).
int muestraValidos(int[]);

// funcion de carga del arreglo, recibe validos
void cargaArreglo(int[], int *);

// 2- Hacer una función que reciba como parámetro un arreglo y la cantidad de elementos (válidos) cargados en él y los muestre por pantalla.
void mostrarArreglo(int[], int);

// 3- Hacer una función que reciba como parámetro un arreglo y la cantidad de elementos (válidos) cargados en él y calcule la suma de sus elementos.
int sumarElementosArray(int[], int *);

// 4- Hacer una función que reciba como parámetro un arreglo, la cantidad de elementos (válidos) cargados en él y una Pila. La función debe copiar los elementos del arreglo en la pila.
void copiarElemArrayAPila(int[], int *, Pila *);

// 5- Realizar una función que sume los elementos de un arreglo de números reales (float) de dimensión 100. (se recomienda hacer una función para cargar y otra para mostrar para este tipo de dato asociado al arreglo)
float sumarElementosArrayFloat(float[], int);
// funciones carga y muestra de array float
void cargarArrayFloat(float[], int *);
void mostrarArrayFloat(float[], int);

// 6- Realizar una función que indique si un elemento dado se encuentra en un arreglo de caracteres.
void cargaArregloChar(char[], int *);
void mostrarArregloChar(char[], int);
int busquedaArrayChar(char[], int, char);

// 7- Realizar una función que inserte un carácter en un arreglo ordenado alfabéticamente, conservando el orden.
void ordenarArregloChar(char[], int);
void ordenar(char[], int);

int main()
{
    int arreglo[TAM_MAX];
    float flotante[DIMENSION];
    char charray[TAM_MAX];
    int validos = 0, opcion = 0, suma = 0, resultado, indice = 0, valor = 0;
    char charBuscado;
    float sumaFlotante = 0;
    Pila p;
    inicpila(&p);
    printf("Menu TP ARRAYS: \n");
    printf("Opcion 1: Carga un array y te muestra la cantidad de elementos validos\n");
    printf("Opcion 2: Carga un array y te muestra sus elementos\n");
    printf("Opcion 3: Carga un array y realiza la suma de sus elementos\n");
    printf("Opcion 4: Funcion de copia de elementos de array a una pila\n");
    printf("Opcion 5: Carga, muestra y suma los elementos de un array float\n");
    printf("Opcion 6: Busca un valor en los elementos de un array char\n");
    printf("Opcion 7: Inserta un char en los elementos de un array char\n");

    printf("Por favor ingrese que opcion desea del 1 al 10: ");
    scanf("%d", &opcion);

    switch (opcion)
    {
    case 1:
        validos = muestraValidos(arreglo);
        printf("\nCantidad de datos que usted ha ingresado al array: %d\n", validos);
        break;
    case 2:
        cargaArreglo(arreglo, &validos);
        mostrarArreglo(arreglo, validos);
        break;
    case 3:
        cargaArreglo(arreglo, &validos);
        mostrarArreglo(arreglo, validos);
        suma = sumarElementosArray(arreglo, &validos);
        printf("\nLa suma de los elementos de su array es: %d \n", suma);
        break;
    case 4:
        printf("\nFuncion de copia de elementos de array a una pila\n");
        cargaArreglo(arreglo, &validos);
        mostrarArreglo(arreglo, validos);
        copiarElemArrayAPila(arreglo, &validos, &p);
        printf("\n\nSu pila, con los elementos del arreglo:");
        mostrar(&p);
        break;
    case 5:
        cargarArrayFloat(flotante, &validos);

        mostrarArrayFloat(flotante, validos);
        sumaFlotante = sumarElementosArrayFloat(flotante, validos);
        printf("\nLa suma de los elementos de su array es: %f \n", sumaFlotante);
        break;
    case 6:
        cargaArregloChar(charray, &validos);
        mostrarArregloChar(charray, validos);
        printf("Por favor ingrese un char a buscar: ");
        fflush(stdin);
        scanf("%c", &charBuscado);
        resultado = busquedaArrayChar(charray, validos, charBuscado);
        if (resultado >= 0)
        {
            printf("El char que me diste se encuentra en la posicion: %d\n", busquedaArrayChar(charray, validos, charBuscado));
        }
        else
        {
            printf("Su char no se encontro en el array.\n");
        }
        break;
    case 7:
        cargaArregloChar(charray, &validos);
        ordenarArregloChar(charray, validos);
        mostrarArregloChar(charray, validos);
        printf("Por favor ingrese un valor al array ordenado: ");
        fflush(stdin);
        scanf("%c", &charray[validos]);
        validos++;
        ordenar(charray, validos);
        mostrarArregloChar(charray, validos);
        break;
    default:
        break;
    }

    system("pause");
    return 0;
}

int muestraValidos(int arreglo[TAM_MAX])
{
    int indice = 0, validos = 0;
    char continuar = 's';
    do
    {
        printf("Ingrese un dato al array numerico: ");
        scanf("%d", &arreglo[indice]);
        printf("Desea continuar? s/n: ");
        fflush(stdin);
        scanf("%c", &continuar);
        indice++;
    } while ((continuar == 's' || continuar == 'S') && (indice < TAM_MAX));
    validos = indice;
    return validos;
}

void cargaArreglo(int array[], int *validos)
{
    int indice = 0;
    char continuar = 's';

    do
    {
        printf("Ingrese un dato para el array: ");
        scanf("%d", &array[indice]);
        printf("Desea continuar? s/n: ");
        fflush(stdin);
        scanf("%c", &continuar);
        indice++;
    } while ((continuar == 's' || continuar == 'S') && (indice < TAM_MAX));
    *validos = indice;
}

void mostrarArreglo(int array[TAM_MAX], int validos)
{
    int indice;
    printf("\nSu arreglo: ");
    for (indice = 0; indice < validos; indice++)
    {
        printf("| %i", array[indice]);
    }
    printf("\nIngreso %d elementos validos.\n", validos);
}

int sumarElementosArray(int array[TAM_MAX], int *validos)
{
    int suma = 0;
    for (int indice = 0; indice < *validos; indice++)
    {
        suma += array[indice];
    }
    return suma;
}

void copiarElemArrayAPila(int arreglo[TAM_MAX], int *validos, Pila *p)
{
    for (int i = 0; i < *validos; i++)
    {
        apilar(p, arreglo[i]);
    }
}
void cargarArrayFloat(float array[DIMENSION], int *validos)
{
    char continuar = 's';
    int indice = 0;

    do
    {
        printf("Ingrese un numero real: ");
        scanf("%f", &array[indice]); // array lleva ampersand porque guarda el dato que ingresa el usuario en una posicion de memoria
        printf("Desea continuar? s/n: ");
        fflush(stdin);
        scanf("%c", &continuar);
        indice++;
    } while ((continuar == 's' || continuar == 'S') && (indice < DIMENSION));
    *validos = indice;
}

void mostrarArrayFloat(float array[DIMENSION], int validos)
{
    int indice;
    printf("Su arreglo con numeros reales:");
    for (indice = 0; indice < validos; indice++)
    {
        printf("| %.2f ", array[indice]);
    }
    printf("|\n");
}
float sumarElementosArrayFloat(float array[], int validos)
{
    float suma = 0;
    for (int i = 0; i < validos; i++)
    {
        suma += array[i];
    }
    return suma;
}

void cargaArregloChar(char array[TAM_MAX], int *validos)
{
    char continuar = 's';
    int i = 0;
    do
    {
        printf("Ingrese un caracter al array: ");
        fflush(stdin);
        scanf("%c", &array[i]);
        printf("Desea continuar? s/n: ");
        fflush(stdin);
        scanf("%c", &continuar);
        i++;
    } while ((continuar == 's' || continuar == 'S') && (i < TAM_MAX));
    *validos = i;
}

void mostrarArregloChar(char array[TAM_MAX], int validos)
{
    int indice;
}

int busquedaArrayChar(char array[TAM_MAX], int validos, char charBuscado)
{
    int i = 0, resultado = -1;

    while ((i < validos) && (array[i] != charBuscado))
    {
        i++;
    }

    if (i < validos)
    {
        resultado = i;
    }

    return resultado;
}

void ordenarArregloChar(char arreglo[TAM_MAX], int validos)
{
    char aux;
    int j = 0;
    for (int i = 0; i < validos; i++)
    {
        aux = arreglo[i];
        j = i;
        while (j > 0 && arreglo[j - 1] > aux)
        {                                /// mientras j sea mayor a 0 y arreglo[j-1] (el anterior) sea mayor al elemento
            arreglo[j] = arreglo[j - 1]; /// corro los elementos
            j--;
        }                 /// cuando termina tengo el hueco
        arreglo[j] = aux; /// inserto en el hueco
    }
}

void insertarOrdenado(char arreglo[TAM_MAX], int indiceActual, char letra)
{
    int i = 0;
    i = indiceActual - 1;
    while (i >= 0 && (arreglo[i] > letra))
    {
        arreglo[i + 1] = arreglo[i];
        i--;
    }
    arreglo[i + 1] = letra;

    // validos++;
}

void ordenar(char array[TAM_MAX], int validos)
{
    char letra;
    for (int i = 1; i < validos; i++)
    {
        letra = array[i];
        insertarOrdenado(array, i, letra);
    }
}
// 7- Realizar una función que inserte un carácter en un arreglo ordenado alfabéticamente, conservando el orden.n
