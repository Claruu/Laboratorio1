#include <stdio.h>
#include <stdlib.h>
#define TAM_MAX 5

/// DOMINGUEZ CLARA MARTHA INES

// Exploracion
// Se tienen 2 matrices, una matriz de parcelas que representa una tabla donde figuran las parcelas a explorar, y una matriz de km que representa los km2 de recorrido que significa cada parcela. Cada fila de la matriz de parcelas representa una ZONA de parcelas.
// Se lee desde un archivo binario “parcelas.bin” un número entero N que representará el formato NxN de dos matrices que representan parcelas y sus recorridos en km2, luego se leerán a continuación Matriz 1 en su totalidad (secuencial), y Matriz 2 en su totalidad (secuencial).
// La primera Matriz contiene caracteres que representan “X” “Explorado”  y “O” “No explorado”, y la segunda numeros enteros (cantidad km2 en cada parcela).

// Calcular a través de funciones e informar por pantalla:
// Cuántas parcelas quedan aún sin explorar
// Cuántas zonas se exploraron enteras
// Cantidad total de km explorados.

// Funciones utiles:
void lecturaArchivo(int *, char[][TAM_MAX], int[][TAM_MAX], char[]);
void muestraMatrices(int, char[][TAM_MAX], int[][TAM_MAX]);

// 1- Cuántas parcelas quedan aún sin explorar
void parcelasSinExplorar(int, char[][TAM_MAX], int[][TAM_MAX]);

// 2- Cuántas zonas se exploraron enteras
void cantZonasExploradasTotalmente(int, char[][TAM_MAX], int[][TAM_MAX]);

// 3- Cantidad total de km explorados.
void cantTotalKmExplorados(int, char[][TAM_MAX], int[][TAM_MAX]);

int main()
{
    char nombArch[] = {"parcelas.bin"};
    int rango = 0, opcion = 0;
    char continuar;
    char estadoExpl[TAM_MAX][TAM_MAX];
    int kmRecorridos[TAM_MAX][TAM_MAX];

    printf("\tParcial 2 LAB 1: \n");

    printf("Primero, se realiza la lectura del archivo con las matrices.\n");
    lecturaArchivo(&rango, estadoExpl, kmRecorridos, nombArch);

    printf("Aqui le muestro informacion sobre las matrices: \n");
    muestraMatrices(rango, estadoExpl, kmRecorridos);

    printf("\n\tMenu Parcial 2 LAB 1: Exploracion \n");
    printf("\n1- Funcion que calcula la cantidad de parcelas SIN explorar\n");
    printf("\n2- Funcion que calcula la cantidad de zonas exploradas en su totalidad\n");
    printf("\n3- Funcion que calcula el total de km explorados\n ");
    printf("\nIngrese una opcion: ");
    scanf("%d", &opcion);

    switch (opcion)
    {
    case 1:
        parcelasSinExplorar(rango, estadoExpl, kmRecorridos);
        break;
    case 2:
        cantZonasExploradasTotalmente(rango, estadoExpl, kmRecorridos);
        break;
    case 3:
        cantTotalKmExplorados(rango, estadoExpl, kmRecorridos);
        break;
    default:
        printf("\n\tError, no ha ingresado una opcion valida. \n");
        break;
    }

    system("pause");
    return 0;
}

void lecturaArchivo(int *rango, char estadoExploracion[][TAM_MAX], int kmRecorridos[][TAM_MAX], char nombArch[])
{
    FILE *fp;
    fp = fopen(nombArch, "rb");

    if (fp != NULL)
    {
        fread(rango, sizeof(int), 1, fp);

        for (int i = 0; i < *rango; i++)
        {
            for (int j = 0; j < *rango; j++)
            {
                fread(&estadoExploracion[i][j], sizeof(char), 1, fp);
            }
        }

        for (int i = 0; i < *rango; i++)
        {
            for (int j = 0; j < *rango; j++)
            {
                fread(&kmRecorridos[i][j], sizeof(int), 1, fp);
            }
        }

        fclose(fp);
    }
    else
    {
        printf("No se ha podido abrir el archivo.\n");
    }
}

void muestraMatrices(int rango, char estadoExploracion[][TAM_MAX], int kmRecorridos[][TAM_MAX])
{
    printf("Estado exploracion (X: explorado, O: sin explorar): \n");
    for (int i = 0; i < rango; i++)
    {

        for (int j = 0; j < rango; j++)
        {
            printf(" [%c] ", estadoExploracion[i][j]);
        }
        printf("\n");
    }

    printf("Km recorridos: \n");
    for (int i = 0; i < rango; i++)
    {
        for (int j = 0; j < rango; j++)
        {
            printf(" [%i] ", kmRecorridos[i][j]);
        }
        printf("\n");
    }
}

// 1- Cuántas parcelas quedan aún sin explorar
void parcelasSinExplorar(int rango, char estadoExpl[][TAM_MAX], int kmRecorridos[][TAM_MAX])
{
    int cantNoExpl = 0, cantExpl = 0;

    for (int i = 0; i < rango; i++)
    {
        for (int j = 0; j < rango; j++)
        {
            if (estadoExpl[i][j] == 'O')
            {
                cantNoExpl++;
            }
            else
            {
                cantExpl++;
            }
        }
    }

    printf("Cantidad Parcelas NO Exploradas: %i\n", cantNoExpl);
    printf("\nCantidad Parcelas exploradas: %i\n", cantExpl);
}

// 2- Cuántas zonas se exploraron enteras
void cantZonasExploradasTotalmente(int rango, char estadoExpl[][TAM_MAX], int kmRecorridos[][TAM_MAX])
{
    int cantZonasExplTotal = 0, j = 0;
    char letraExpl = 'X';

    for (int i = 0; i < rango; i++)
    {
        j = 0;

        while (j < rango && letraExpl == estadoExpl[i][j])
        {
            j++;
        }

        if (j == rango)
        {
            cantZonasExplTotal++;
        }
    }

    printf("\nCantidad de Zonas exploradas totalmente: %i\n", cantZonasExplTotal);
}

// 3- Cantidad total de km explorados.
void cantTotalKmExplorados(int rango, char estadoExpl[][TAM_MAX], int kmRecorridos[][TAM_MAX])
{
    int explorado = 0;

    for (int i = 0; i < rango; i++)
    {

        for (int j = 0; j < rango; j++)
        {
            if (estadoExpl[i][j] == 'X')
            {
                explorado += kmRecorridos[i][j];
            }
        }
    }

    printf("\nCantidad total de Km explorados: %i\n", explorado);
}