#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define FIL 6
#define COL 4

// funciones utiles
void cargaMatriz(int[][COL], int *, int *);

// 1- Hacer una función que reciba como parámetro una matriz de números enteros y permita que el usuario ingrese valores al mismo por teclado. La función debe cargar la matriz por completo.
void cargaCompletaMatriz(int[][COL]);

// 2- Hacer una función que reciba como parámetro una matriz de números enteros y la muestre por pantalla (en formato matricial).
void muestraMatriz(int[][COL], int, int);
void muestraMatrizCompleta(int[][COL]);

// 3- Hacer una función que reciba como parámetro una matriz de números enteros y que cargue la misma con números aleatorios (sin intervención del usuario). La función debe cargar la matriz por completo.
void cargaMatrizConRan(int[][COL]);

// 4- Hacer una función tipo int que sume el contenido total de una matriz de números enteros.
int sumaMatriz(int[][COL], int, int);

// 5- Hacer una función tipo float que calcule el promedio de una matriz de números enteros.
float promedioMatriz(int[][COL], int, int);

// 6- Hacer una función que determine si un elemento se encuentra dentro de una matriz de números enteros. La función recibe la matriz y el dato a buscar.
void buscarEnMatriz(int[][COL], int *, int, int);

int main()
{
    /// usando desde funciones
    int matriz[FIL][COL];
    int validosF;
    int validosC;
    int opcion = 0, suma = 0, numero = -1;
    float promedio;
    printf("Menu de opciones:\n");
    printf("Opcion 1: Carga de matriz completa.\n");
    printf("Opcion 2: Carga de matriz preguntando al usuario numero de columnas.\n");
    printf("Opcion 3: Carga de matriz completa de forma aleatoria.\n");
    printf("Opcion 4: Suma de los elementos de una matriz.\n");
    printf("Opcion 5: Promedio de los elementos de una matriz.\n");
    printf("Opcion 6: Busqueda de un numero entre los elementos de una matriz.\n");
    printf("Opcion 15: Carga de matriz extra.\n");
    printf("Ingrese un numero del 1 al 15: ");
    scanf("%d", &opcion);
    switch (opcion)
    {
    case 1:
        printf("Ejercicio 1. Carga de matriz completa: \n");
        cargaCompletaMatriz(matriz);
        muestraMatrizCompleta(matriz);
        break;
    case 2:
        cargaMatriz(matriz, &validosF, &validosC);
        break;
    case 3:
        cargaMatrizConRan(matriz);
        muestraMatrizCompleta(matriz);
        break;
    case 4:
        cargaMatriz(matriz, &validosF, &validosC);

        muestraMatriz(matriz, validosF, validosC);
        suma = sumaMatriz(matriz, validosC, validosF);
        printf("Suma de su matriz: %d\n", suma);

        break;
    case 5:

        cargaMatriz(matriz, &validosF, &validosC);

        promedio = promedioMatriz(matriz, validosC, validosF);
        printf("Promedio: %.2f\n", promedio);

        break;
    case 6:

        cargaMatriz(matriz, &validosF, &validosC);

        printf("Ingrese un numero a buscar dentro de la matriz: ");
        scanf("%d", &numero);
        buscarEnMatriz(matriz, &numero, validosF, validosC);

        if (numero == -1)
        {
            printf("No se encontro su numero en la matriz\n");
        }
        break;
    case 15:
        printf("Carga y muestra de matriz comunmente.\n");
        cargaMatriz(matriz, &validosF, &validosC);
        muestraMatriz(matriz, validosF, validosC);
        break;
    default:
        printf("Error, no ha ingresado una opcion valida.\n");
        break;
    }
    system("pause");
    return 0;
}

void cargaMatriz(int matriz[][COL], int *validosF, int *validosC)
{
    int i = 0;
    char continuar;

    do
    {
        printf("Ingrese cantidad de columnas a cargar: ");
        scanf("%i", validosC);
        if (*validosC > COL || *validosC == 0)
        {
            printf("Error. Debe ingresar un numero entre 1 y %d.\nIngrese la cantidad de columnas a cargar: ", COL);
            scanf("%i", validosC);
        }

    } while (*validosC < 1 || *validosC > COL);

    do
    {
        printf("FILA %i\n", i);
        for (int j = 0; j < *validosC; j++)
        {
            printf("matriz[%i][%i]=", i, j);
            scanf("%i", &matriz[i][j]);
        }
        i++;
        printf("Desea cargar otra fila?\n");
        fflush(stdin);
        scanf("%c", &continuar);
    } while (i < FIL && continuar == 's');

    *(validosF) = i;
}

void muestraMatriz(int matriz[][COL], int validosF, int validosC)
{
    for (int i = 0; i < validosF; i++)
    {
        for (int j = 0; j < validosC; j++)
        {
            printf(" [ %i ] ", matriz[i][j]);
        }
        printf("\n");
    }
}

void muestraMatrizCompleta(int matriz[][COL])
{
    for (int i = 0; i < FIL; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            printf(" [ %i ] ", matriz[i][j]);
        }
        printf("\n");
    }
}

void cargaCompletaMatriz(int matriz[][COL])
{
    int i, j;
    for (i = 0; i < FIL; i++)
    {
        for (j = 0; j < COL; j++)
        {
            printf("matriz[%i][%i]: ", i, j);
            scanf("%i", &matriz[i][j]);
        }
    }
}

void cargaMatrizConRan(int matrizRandom[][COL])
{
    int i, j, numRan;

    srand(time(NULL));

    for (i = 0; i < FIL; i++)
    {
        for (j = 0; j < COL; j++)
        {
            numRan = rand() % 90;
            matrizRandom[i][j] = numRan;
            printf("matriz[%i][%i]: %i || ", i, j, numRan);
        }
        printf("\n");
    }
}

int sumaMatriz(int matrizASumar[][COL], int validosC, int validosF)
{
    int suma = 0, validosGeneral = 0;

    for (int i = 0; i < validosF; i++)
    {
        for (int j = 0; j < validosC; j++)
        {
            suma += matrizASumar[i][j];
        }
    }

    return suma;
}

float promedioMatriz(int matrizAPromediar[][COL], int validosC, int validosF)
{
    float promedio = 0;
    int sumaElementos = 0, elementosValidos = validosC * validosF;

    sumaElementos = sumaMatriz(matrizAPromediar, validosC, validosF);
    printf("Promedio: %d / %d \n", sumaElementos, elementosValidos);
    promedio = (float)sumaElementos / elementosValidos;

    return promedio;
}

void buscarEnMatriz(int matrizDondeBuscar[][COL], int *numABuscar, int validosF, int validosC)
{

    for (int i = 0; i < validosF; i++)
    {
        for (int j = 0; j < validosC; j++)
        {

            if (matrizDondeBuscar[i][j] == *numABuscar)
            {
                *numABuscar = 1;
                printf("El valor se encuentra en la fila %d y la columna %d.\n", i, j);
            }
            else
            {
                *numABuscar = -1;
            }
        }
    }
}
