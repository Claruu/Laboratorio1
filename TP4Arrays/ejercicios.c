#include <stdio.h>
#include <stdlib.h>
#include "Librerias\pila.c"

#define TAM_MAX 10
#define DIMENSION 100
// 1- Hacer una función que reciba como parámetro un arreglo de números enteros y permita que el usuario ingrese valores al mismo por teclado. La función debe retornar la cantidad de elementos cargados en el arreglo (o pueden utilizar como puntero válidos).
void cargaYretornoValidos(int[], int *);

// funcion de carga del arreglo, recibe validos
void cargaArreglo(int[], int *);

// 2- Hacer una función que reciba como parámetro un arreglo y la cantidad de elementos (válidos) cargados en él y los muestre por pantalla.
void mostrarArreglo(int[], int *);

// 3- Hacer una función que reciba como parámetro un arreglo y la cantidad de elementos (válidos) cargados en él y calcule la suma de sus elementos.
int sumarElementosArray(int[], int *);

// 4- Hacer una función que reciba como parámetro un arreglo, la cantidad de elementos (válidos) cargados en él y una Pila. La función debe copiar los elementos del arreglo en la pila.
void copiarElemArrayAPila(int[], int *, Pila *);

// 5- Realizar una función que sume los elementos de un arreglo de números reales (float) de dimensión 100. (se recomienda hacer una función para cargar y otra para mostrar para este tipo de dato asociado al arreglo)
int sumarElementosArrayFloat(float[], int *);
void cargarArrayFloat(float[], int *);
void mostrarArrayFloat(float[], int);

int main()
{
    int arreglo[TAM_MAX];
    float flotante[DIMENSION];
    int validos = 0, opcion = 0, suma = 0;
    Pila p;
    inicpila(&p);
    printf("Menu TP ARRAYS: \n");
    printf("Opcion 1: Cargas un array, y te muestra el array y sus elementos validos\n");
    printf("Opcion 2: Carga un array y te muestra sus elementos\n");
    printf("Opcion 3: Luego de cargar un array, se realiza la suma de este\n");
    printf("Opcion 4: Funcion de copia de elementos de array a una pila\n");
    printf("Opcion 5: Carga, muestra y suma los elementos de un array float\n");

    printf("Por favor ingrese que opcion desea del 1 al 10: ");
    scanf("%d", &opcion);

    switch (opcion)
    {
    case 1:
        cargaYretornoValidos(arreglo, &validos);
        printf("\nCantidad de datos que usted ha ingresado al array: %d\n", validos);
        break;
    case 2:
        cargaArreglo(arreglo, &validos);
        mostrarArreglo(arreglo, &validos);
        printf("\nCantidad de datos validos ingresados: %d\n", validos);
        break;
    case 3:
        cargaYretornoValidos(arreglo, &validos);
        printf("Su arreglo: \n");
        suma = sumarElementosArray(arreglo, &validos);
        printf("| \nLa suma de los elementos de su array es: %d \n", suma);
        break;
    case 4:
        cargaYretornoValidos(arreglo, &validos);
        mostrarArreglo(arreglo, &validos);
        copiarElemArrayAPila(arreglo, &validos, &p);
        printf("\n\nSu pila, con los elementos del arreglo:");
        mostrar(&p);
        break;
    case 5:
        cargarArrayFloat(flotante, &validos);

        mostrarArrayFloat(flotante, validos);
        break;
    default:
        break;
    }
    system("pause");
    return 0;
}

void cargaYretornoValidos(int arreglo[TAM_MAX], int *validos)
{
    int indice = 0;
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
    *validos = indice;
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

void mostrarArreglo(int array[TAM_MAX], int *validos)
{
    int indice;
    printf("\nSu arreglo: ");
    for (indice = 0; indice < *validos; indice++)
    {
        printf("| %i", array[indice]);
    }
    printf("|");
}

int sumarElementosArray(int array[TAM_MAX], int *validos)
{
    int suma = 0;
    for (int indice = 0; indice < *validos; indice++)
    {
        printf("| %i ", array[indice]);
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
int sumarElementosArrayFloat(float[], int *)
{
}
