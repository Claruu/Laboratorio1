#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

int main()
{
    /// usando desde funciones
    int matriz[FIL][COL];
    int validosF;
    int validosC;
    int opcion = 0, suma = 0;
    printf("Menu de opciones:\n");
    printf("Opcion 1: Carga de matriz completa.\n");
    printf("Opcion 2: Carga de matriz completa de forma aleatoria.\n");
    printf("Opcion 3: Suma de los elementos de una matriz.\n");
    printf("Opcion 4: Promedio de los elementos de una matriz.\n");
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
        cargaMatrizConRan(matriz);
        muestraMatrizCompleta(matriz);
        break;
    case 3:
        cargaMatriz(matriz, &validosF, &validosC);
        muestraMatriz(matriz, validosF, validosC);
        suma = sumaMatriz(matriz, validosC, validosF);
        printf("Suma de su matriz: %d\n", suma);
        break;
    case 4:
        cargaMatriz(matriz, &validosF, &validosC);
        suma = promedioMatriz(matriz, validosC, validosF);
        printf("Promedio: %d", suma);
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
        printf("Ingrese cantidad de columnas a cargar\n");
        scanf("%i", validosC);
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
    int sumaValidos = 0, validos = validosC * validosF;

    sumaValidos = sumaMatriz(matrizAPromediar, validosC, validosF);
    printf("sumavalidos: %d\n ", sumaValidos);
    printf("validos: %d\n", validos);
    promedio = (float)sumaValidos / validos;

    return promedio;
}