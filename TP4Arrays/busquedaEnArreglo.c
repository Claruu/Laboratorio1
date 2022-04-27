#include <stdio.h>
#include <stdlib.h>
#define TAM_MAX 10
// recibe el arreglo y los validos para modificar
void cargaArreglo(int[], int *);

// muestra el arreglo en su totalidad
void muestraArreglo(int[], int *);

// busca en el array un valor que ingresa el usuario
int busquedaArreglo(int[], int, int);

int main()
{
    int arreglo[TAM_MAX];
    int validos, resultado;
    int valor = 0;
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
    int indice = 0;
    char continuar = 's';

    do
    {
        printf("Ingrese un dato al array numerico:");
        fflush(stdin);
        scanf("%i", &arreglo[indice]);
        printf("El dato #%d de su arreglo es: %i", indice, arreglo[indice]);
        printf("\nDesea continuar? s/n: ");
        fflush(stdin);
        scanf("%c", &continuar);
        indice++;
    } while ((continuar == 's' || continuar == 'S') && (indice < TAM_MAX));
    *validos = indice;
    printf("\nCantidad de datos que ha ingresado al array: %d\n", *validos);
}
void muestraArreglo(int arreglo[TAM_MAX], int *validos)
{
    int indice;

    printf("Su arreglo: ");
    for (indice = 0; indice < *validos; indice++)
    {
        printf("| %i ", arreglo[indice]);
    }
    printf("|\n");
}

int busquedaArreglo(int arreglo[TAM_MAX], int validos, int valorAbuscar)
{
    int i = 0, resultado = -1;
    while ((i < validos) && (arreglo[i] != valorAbuscar))
    { // como ejemplo: hay 5 valores, si cant datos ingresados es 5, pero cuando estas en el 2 encontras el valor deja de cumplirse la segunda regla del while, por lo cual el indice deja de sumarse, queda en la posicion esa, luego verifica en el while el indice contra la cantidad de datos ingresados, si es menor, es igual al indice
        i++;
    }

    if (i < validos) // si indice es menor a 5 encontaste el numero, y resultado toma el valor del indice
    {                                 // si la posicion del array es menor a validos, el resultado es igual a la posicion del array, que era 0
        resultado = i;
    }
    // en cambio, si no lo encontró en el array, devuelve -1, que no es un valor valido de una posicion del array, ya que comienzan en 0
    return resultado;
}

// PRACTICA RANDOM STRING:
//  #define MAXIMA_LONGITUD_CADENA 50 // para practica string
//  char nombre[MAXIMA_LONGITUD_CADENA]; // para el string
//  printf("Ingrese su nombre: ");
//  scanf("%s", &nombre); //%s por string, prueba string
//  fflush(stdin);
//  printf("Su nombre es %s.\n", nombre);
