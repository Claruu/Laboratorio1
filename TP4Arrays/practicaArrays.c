#include <stdio.h>
#include <stdlib.h>
#define TAM_MAX 10
// recibe el arreglo y los validos para modificar
void cargaArreglo(int[], int *);

// muestra el arreglo en su totalidad
void muestraArreglo(int[], int *);

// busca en el array un valor que ingresa el usuario
int busquedaArreglo(int[], int, int *);

int main()
{
    int arreglo[TAM_MAX];
    int validos, resultado;
    int *valor = 0;
    cargaArreglo(arreglo, &validos);
    muestraArreglo(arreglo, &validos);
    printf("\nPor favor ingrese el valor a buscar: ");
    fflush(stdin);
    scanf("%d", &valor);

    resultado = busquedaArreglo(arreglo, validos, valor);
    if (resultado >= 0)
    {
        printf("El elemento se encuentra en la posicion %d \n", resultado);
    }
    else
    {
        printf("No se encuentra en el arreglo.\n");
    }

    system("pause");
    return 0;
}

void cargaArreglo(int arreglo[TAM_MAX], int *validos)
{
    int i = 0;
    char continuar = 's';

    do
    {
        printf("Ingrese un dato al array numerico:");
        fflush(stdin);
        scanf("%i", &arreglo[i]);
        printf("El dato #%d de su arreglo es: %i", i, arreglo[i]);
        printf("\nDesea continuar? s/n: ");
        fflush(stdin);
        scanf("%c", &continuar);
        i++;
    } while ((continuar == 's' || continuar == 'S') && (i < TAM_MAX));
    *validos = i;
    printf("\nCantidad de datos que ha ingresado al array: %d\n", *validos);
}
void muestraArreglo(int arreglo[TAM_MAX], int *validos)
{
    int i;
    printf("Su arreglo: ");
    for (i = 0; i < *validos; i++)
    {
        printf("| %i ", arreglo[i]);
    }
    printf("|\n");
}

int busquedaArreglo(int arreglo[TAM_MAX], int validos, int *valor)
{
    int i = 0, resultado = -1;
    while ((i < validos) && (arreglo[i] != *valor))
    {
        i++;
    }

    if (i < validos)
    {
        resultado = i;
    }

    return resultado;
}

// PRACTICA RANDOM STRING:
//  #define MAXIMA_LONGITUD_CADENA 50 // para practica string
//  char nombre[MAXIMA_LONGITUD_CADENA]; // para el string
//  printf("Ingrese su nombre: ");
//  scanf("%s", &nombre); //%s por string, prueba string
//  fflush(stdin);
//  printf("Su nombre es %s.\n", nombre);
