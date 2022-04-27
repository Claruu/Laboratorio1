#include <stdio.h>
#include <stdlib.h>
#define TAM_MAX 10
// 1- Hacer una función que reciba como parámetro un arreglo de números enteros y permita que el usuario ingrese valores al mismo por teclado. La función debe retornar la cantidad de elementos cargados en el arreglo (o pueden utilizar como puntero válidos).
void cargaYretornoValidos(int[], int *);

// funcion de carga del arreglo, recibe validos
void cargaArreglo(int[], int *);

// 2- Hacer una función que reciba como parámetro un arreglo y la cantidad de elementos (válidos) cargados en él y los muestre por pantalla.
void mostrarArregloYvalidos(int[], int *);

// 3- Hacer una función que reciba como parámetro un arreglo y la cantidad de elementos (válidos) cargados en él y calcule la suma de sus elementos.
void sumarElementosArray(int[], int *, int);

int main()
{
    int arreglo[TAM_MAX];
    int validos = 0, opcion = 0;
    printf("Menu TP ARRAYS: \n");
    printf("Opcion 1: Cargas un array, y te muestra el array y sus elementos validos\n");
    printf("Opcion 2: Con un array ya cargado, te muestra sus elementos\n");

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
        mostrarArregloYvalidos(arreglo, &validos);
        printf("\nCantidad de datos validos ingresados: %d\n", validos);
        break;
    case 3:
        cargaYretornoValidos(arreglo, &validos);

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
        printf("El dato #%d de su arreglo es: %i\n", indice, arreglo[indice]);
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

void mostrarArregloYvalidos(int array[TAM_MAX], int *validos)
{
    int indice;
    printf("\nSu arreglo: ");
    for (indice = 0; indice < *validos; indice++)
    {
        printf("| %i", array[indice]);
    }
    printf("|");
}

void sumarElementosArray(int array[TAM_MAX], int *validos, int suma)
{
    
}