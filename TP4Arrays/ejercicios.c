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
void insertarCharEnarreglo(char[], int);
void ordenar(char[], int);

// 8- Realizar una función que obtenga el máximo carácter de un arreglo dado.
char maximoChar(char[], int);

// 9- Realizar una función que determine si un arreglo es capicúa.
int busquedaCapicua(int[], int);

// 10- Realizar una función que invierta los elementos de un arreglo.  (sin utilizar un arreglo auxiliar)
void invertirArreglo(int[], int);

// 11- Ordenar un arreglo según los siguientes métodos:
// a) Selección:
///-> buscaba el menor y lo quitaba
///-> se agregaba el menor a una nueva pila
// a partir de la siguiente posicion j = i+1 busco el
//  menor comparando arreglo[posMenor] con arreglo[j]
// b) Inserción
/// -> por cada dato de la pila que desapilaba
///-> con el dato buscaba el hueco en la nueva de forma ordenada
int buscarMenor(int[], int, int);                   /// recibo el arreglo, la posicion i, y validos
void ordenarArrayporSeleccion(int[], int);          /// recibo el arreglo y los validos
void insercionenArregloOrdenado(int[], int *, int); /// inserta un numero (UNO SOLO) en un arreglo ordenado
void insercionDesordenado(int[], int *, int);
void cargarDatoOrdenado(int[], int *); // CARGA VARIOS DATOS EN UN ARREGLO, DE FORMA ORDENADA

// 12- Dados dos arreglos ordenados alfabéticamente, crear un tercer arreglo con los elementos de los dos primeros intercalados, de manera que quede un arreglo también ordenado alfabéticamente.
void ordenamientoInsercionChar(char[], int *, char);
void ordenarAlfabeticamenteDosArreglos(char[], int, char[], int);

// 13- Dado el vector {1,5,6,7,8} escribir un programa que genere otro vector con la suma del contenido de todo los elementos anteriores al índice actual: {1,6,12,19,27}.

int main()
{
    int arreglo[TAM_MAX];
    int ayuda[TAM_MAX];
    float flotante[DIMENSION];
    char charray[TAM_MAX];
    char arregloUno[TAM_MAX];
    char arregloDos[TAM_MAX];
    char destino[TAM_MAX];
    int validos = 0, opcion = 0, suma = 0, resultado, indice = 0, valor = 0, aux = 0, validosAux = 0;
    char charBuscado, continuar;
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
    printf("Opcion 8: Busca el char mayor en un arreglo de char\n");
    printf("Opcion 9: Busca saber si un numero en un arreglo es capicua\n");
    printf("Opcion 10: Te invierte un arreglo\n");
    printf("Opcion 11: Te ordena un arreglo por seleccion\n");
    printf("Opcion 12: Te carga un numero nuevo en un arreglo ordenado\n");
    printf("Opcion 13: Te ordena un arreglo por insercion\n");

    printf("Por favor ingrese que opcion desea del 1 al 15: ");
    // do
    // {
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
        insertarCharEnarreglo(charray, validos);
        mostrarArregloChar(charray, validos);
        printf("Por favor ingrese un valor al array ordenado: ");
        fflush(stdin);
        scanf("%c", &charray[validos]);
        validos++;
        ordenar(charray, validos);
        mostrarArregloChar(charray, validos);
        break;
    case 8:
        cargaArregloChar(charray, &validos);
        maximoChar(charray, validos);
        charBuscado = maximoChar(charray, validos);
        printf("El mayor es %c", charBuscado);
        break;
    case 9:
        cargaArreglo(arreglo, &validos);
        resultado = busquedaCapicua(arreglo, validos);
        printf("%d", resultado);
        break;
    case 10:
        cargaArreglo(arreglo, &validos);
        invertirArreglo(arreglo, validos);
        mostrarArreglo(arreglo, validos);
        break;
    case 11:
        cargaArreglo(arreglo, &validos);
        printf("Su arreglo antes de ser ordenado por seleccion\n");
        mostrarArreglo(arreglo, validos);
        buscarMenor(arreglo, validos, aux);
        ordenarArrayporSeleccion(arreglo, validos);
        printf("Su arreglo luego de ser ordenado por seleccion\n");
        mostrarArreglo(arreglo, validos);
        break;
    case 12:
        cargaArreglo(arreglo, &validos);
        mostrarArreglo(arreglo, validos);
        // insertarEnArreglo(ayuda, &validosAux);
        cargarDatoOrdenado(arreglo, &validos);
        printf("Su arreglo, con los datos nuevos:\n");
        mostrarArreglo(arreglo, validos);
        break;
    case 13:
        cargaArreglo(arreglo, &validos);
        mostrarArreglo(arreglo, validos);
        cargarDatoOrdenado(arreglo, &validos);
        mostrarArreglo(arreglo, validos);
        break;
    case 14:
        cargaArregloChar(arregloUno, &validos);
        cargaArregloChar(arregloDos, &validosAux);
        ordenarAlfabeticamenteDosArreglos(arregloUno, validos, arregloDos, validosAux);
        break;
    default:
        printf("\n\tError, usted no ha ingresado un numero valido\n");
        break;
    }
    // } while (opcion > 0 && opcion <= 15);

    // system("pause");
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
    for (int i = 0; i < validos; i++)
    {
        printf("| %c ", array[i]);
    }
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

void insertarCharEnarreglo(char arreglo[TAM_MAX], int validos)
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
// 8- Realizar una función que obtenga el máximo carácter de un arreglo dado.
char maximoChar(char array[TAM_MAX], int validos)
{
    char mayor;
    fflush(stdin);
    mayor = array[0];
    // menor = array[0];
    for (int i = 1; i < validos; i++)
    {
        if (array[i] > mayor)
        {
            mayor = array[i];
        }
        // if (array[i] < menor)
        // {
        //     menor = array[i];
        // }
    }
    return mayor;
}

int busquedaCapicua(int array[TAM_MAX], int validos)
{
    int resultado = 1;
    int j = validos - 1;
    for (int i = 0; i < validos; i++)
    {
        if (array[i] != array[j])
        {
            resultado = 0;
        }
        j--;
    }

    if (resultado == 0)
    {
        printf("No es capicua. \n");
    }
    else
    {
        printf("Si es capicua. \n");
    }

    return resultado;
}

// 10- Realizar una función que invierta los elementos de un arreglo.  (sin utilizar un arreglo auxiliar)
void invertirArreglo(int array[TAM_MAX], int validos)
{
    int auxiliar;
    int j = validos - 1;
    for (int i = 0; i < (validos / 2); i++)
    {
        auxiliar = array[i];
        array[i] = array[j];
        array[j] = auxiliar;
        j--;
    }
}

int buscarMenor(int array[], int validos, int pos)
{
    int posmenor = pos;
    int indice = pos + 1;
    while (indice < validos)
    {
        if (array[posmenor] > array[indice])
        {
            posmenor = indice;
        }
        indice++;
    }
    return posmenor;
}
void ordenarArrayporSeleccion(int array[], int validos)
{
    int i, posmenor, aux;
    for (i = 0; i < validos; i++)
    {
        posmenor = buscarMenor(array, validos, i);
        aux = array[posmenor];
        array[posmenor] = array[i];
        array[i] = aux;
    }
}

void insercionenArregloOrdenado(int array[], int *validos, int numero)
{
    int posActual = (*validos) - 1;

    while ((posActual >= 0) && (numero < array[posActual]))
    {
        // asume que uno le paso valores ordenados de menor a mayor
        array[posActual + 1] = array[posActual];
        posActual--;
    }

    array[posActual + 1] = numero;
    (*validos)++;
}

void insercionDesordenado(int array[], int *validos, int nuevoD)
{
    if (*validos < TAM_MAX)
    {
        array[*validos] = nuevoD;
        (*validos)++;
    }
}

void cargarDatoOrdenado(int arreglo[], int *validos)
{
    int ayudante[TAM_MAX];
    int i = 0, validosAyudante = 0;
    cargaArreglo(ayudante, &validosAyudante);
    for (i = 0; i < validosAyudante; i++)
    {
        insercionenArregloOrdenado(arreglo, validos, ayudante[i]);
    }
}

void ordenamientoInsercionChar(char array[], int *validos, char letra)
{
    int posActual = (*validos) - 1;

    while ((posActual >= 0) && (letra < array[posActual]))
    {
        array[posActual + 1] = array[posActual];
        posActual--;
    }
    array[posActual + 1] = letra;
    (*validos)++; // esto incrementa cuantos validos hay disponibles porque sino cagamos
}

void ordenarAlfabeticamenteDosArreglos(char array[], int validosArray, char arregloDos[], int validosDos)
{
    char arrayGeneral[TAM_MAX];
    int validosGeneral = 0;

    for (int i = 0; i < validosArray; i++)
    {
        arrayGeneral[i] = array[i]; // aca va pasando valores al arraygeneral de array como un apilar(arraygeneral, desapilar array)
        validosGeneral++;
    }

    for (int i = 0; i < validosDos; i++)
    {
        ordenamientoInsercionChar(arrayGeneral, &validosGeneral, arregloDos[i]);
    }
    mostrarArregloChar(arrayGeneral, validosGeneral);
}