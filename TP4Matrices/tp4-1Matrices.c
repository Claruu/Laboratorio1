#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define FIL 6
#define COL 4
#define FILSTRING 5
#define COLSTRING 400

// funciones utiles
void cargaMatriz(int[][COL], int *, int *);
int mostrarOpciones();

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

// 7- Hacer una función que cargue un arreglo de palabras (strings). La función debe retornar cuantas palabras se cargaron.  (puede ser a través del parámetro como puntero)
void cargarArrayString(char[][COLSTRING], int *);

// 8- Hacer una función que muestre un arreglo de palabras.
void mostrarStrings(char[][COLSTRING], int);

// 9- Hacer una función que determine si un string se encuentra dentro de un arreglo de strings. La función recibe el arreglo, la cantidad de palabras que contiene y la palabra a buscar. ///devuelve el índice de la fila en que se encuentra, de lo contrario -1
int buscarEnString(char[][COLSTRING], int, char[]);

// 10- Hacer una función que determine si un string se encuentra dentro de un arreglo de strings ordenado alfabéticamente. La función recibe el arreglo, la cantidad de palabras que contiene y el string a buscar.  ///devuelve el índice de la fila en que se encuentra, de lo contrario -1
int buscarEnStringOrdenado(char[][COLSTRING], int, char[]);
// funciones ayuda Ejercicio 10
void insertarOrdenado(char[][COLSTRING], char[], int);
void cargarOrdenado(char[][COLSTRING], char[], int *);

// 11- Hacer una función (o varias) que ordene un arreglo de palabras por orden alfabético. (Por selección o inserción, el que más te guste).

// 12- Hacer una función que retorne el determinante de una matriz de 2x2.

// 13- Función que verifique si una matriz de 2x2 tiene inversa.

// 14- Hacer una función que multiplique una matriz de 2x2 por una matriz de 2x5.

// 15- Hacer una función que calcule la matriz inversa de una matriz de 2x2.

int main()
{
    int matriz[FIL][COL];
    int validosC;
    int validosF;
    int opcion = 0, suma = 0, numero = -1, validos;
    char continuar;
    char arrayStrings[FILSTRING][COLSTRING];
    char buscado[COLSTRING];
    char elemento[COLSTRING];
    float promedio;

    do
    {
        opcion = mostrarOpciones();

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
        case 7:
            cargarArrayString(arrayStrings, &validos);
            mostrarStrings(arrayStrings, validos);
            printf("Usted ha cargado %d strings.\n", validos);
            break;
        case 8:
            cargarArrayString(arrayStrings, &validos);
            mostrarStrings(arrayStrings, validos);
            break;
        case 9:
            cargarArrayString(arrayStrings, &validos);
            printf("Por favor ingrese un string a buscar en el array: ");
            fflush(stdin);
            gets(buscado);
            numero = buscarEnString(arrayStrings, validos, buscado);

            if (numero == -1)
            {
                printf("No se encontro su string en el array.\n");
            }
            else
            {
                printf("Su string se encontro, en la fila %d.\n", numero);
                printf("Su string buscado era: %s\n", arrayStrings[numero]);
            }
            break;
        case 10:
            cargarOrdenado(arrayStrings, elemento, &validos);
            mostrarStrings(arrayStrings, validos);
            printf("Por favor ingrese un string a buscar en el array: ");
            fflush(stdin);
            gets(buscado);
            numero = buscarEnStringOrdenado(arrayStrings, validos, buscado);
            //            numero = buscarEnString(arrayStrings, validos, buscado);
            if (numero == -1)
            {
                printf("No se encontro su string en el array.\n");
            }
            else
            {
                printf("Su string se encontro, en la fila %d.\n", numero);
                printf("Su string buscado era: %s\n", arrayStrings[numero]);
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

        printf("Desea continuar? s/n: ");
        fflush(stdin);
        scanf("%c", &continuar);
        system("cls");
    } while (continuar == 's' || continuar == 'S');

    return 0;
}

int mostrarOpciones()
{
    int opcion = 0;
    printf("\tMenu TP4.1: Matrices \n");
    printf("Opcion 1: Carga de matriz completa.\n");
    printf("Opcion 2: Carga de matriz preguntando al usuario numero de columnas.\n");
    printf("Opcion 3: Carga de matriz completa de forma aleatoria.\n");
    printf("Opcion 4: Suma de los elementos de una matriz.\n");
    printf("Opcion 5: Promedio de los elementos de una matriz.\n");
    printf("Opcion 6: Busqueda de un numero entre los elementos de una matriz.\n");
    printf("Opcion 7: Carga de strings. Como plus, te los muestro.\n");
    printf("Opcion 8: Muestra de strings.\n");
    printf("Opcion 9: Busqueda en un array de strings.\n");
    printf("Opcion 10: Busqueda en un array de strings ordenado.\n");
    printf("Opcion 15: Carga de matriz extra.\n");
    printf("\tIngrese la opcion a elegir (entre 1 y 15): ");
    fflush(stdin);
    scanf("%d", &opcion);
    return opcion;
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
            printf("\t|matriz[%i][%i]: %i|\n ", i, j, numRan);
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
        }
    }
}

void cargarArrayString(char arrayStrings[FILSTRING][COLSTRING], int *validos)
{
    int i = 0;
    char continuar;

    do
    {
        printf("Ingrese un string: ");
        fflush(stdin);
        gets(arrayStrings[i]);
        printf("Desea continuar? s/n ");
        fflush(stdin);
        scanf("%c", &continuar);
        i++;
    } while ((continuar == 's' || continuar == 'S') && i < FIL);

    (*validos) = i;
}

void mostrarStrings(char strings[][COLSTRING], int validos)
{

    for (int i = 0; i < validos; i++)
    {
        puts(strings[i]);
    }
    printf("\n");
}

int buscarEnString(char arrayStrings[][COLSTRING], int validos, char stringBuscado[COLSTRING])
{
    int buscador = -1, i = 0;

    for (i = 0; i < validos; i++)
    {
        if (strcmpi(arrayStrings[i], stringBuscado) == 0)
        {
            buscador = i;
        }
    }

    return buscador;
}

void insertarOrdenado(char arrayStrings[][COLSTRING], char elemento[], int validos)
{
    int i = validos - 1;

    while (i >= 0 && strcmp(arrayStrings[i], elemento) > 0)
    {
        strcpy(arrayStrings[i + 1], arrayStrings[i]);
        i--;
    }

    strcpy(arrayStrings[i + 1], elemento);
}

void cargarOrdenado(char arrayStrings[][COLSTRING], char elemento[], int *validos)
{
    char continuar;
    int i = 0;
    do
    {
        printf("Ingrese un string: ");
        fflush(stdin);
        gets(elemento);
        insertarOrdenado(arrayStrings, elemento, i);
        printf("Desea continuar? s/n: ");
        fflush(stdin);
        scanf("%c", &continuar);
        i++;
    } while (i < FILSTRING && (continuar == 's' || continuar == 'S'));

    (*validos) = i;
}

//          Logica general de buscar en un array ordenado:
// if (array[validos / 2] > buscar) tengo que buscar desde 0 a validos / 2
// else busco desde validos / 2 hasta validos

int buscarEnStringOrdenado(char arrayStrings[][COLSTRING], int validos, char buscado[])
{
    int medio = validos / 2, buscador = -1;

    int comparador = strcmpi(arrayStrings[medio], buscado);
    if (comparador == 0)
    {
        // encontrado en en el medio
        buscador = medio;
    }
    else if (comparador > 0)
    { // si es positivo, significa que esta desde el medio hasta validos
        for (int i = medio; i >= 0; i--)
        {
            if (strcmpi(arrayStrings[i], buscado) == 0)
            {
                buscador = i;
            }
        }
    }
    else if (comparador < 0)
    { // si es negativo, la posición J es más grande que lo que busco
      //  entonces, tengo que buscar desde J a 0 (j--)
        for (int i = medio; i < validos; i++)
        {
            if (strcmpi(arrayStrings[i], buscado) == 0)
            {
                buscador = i;
            }
        }
    }

    return buscador;
}