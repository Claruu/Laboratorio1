#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM_MAX 20
// Sean los arreglos paralelos, que simbolizan la entidad “alumno de programación”:
// float notasParcial1[20];
// float notasParcial2[20];
// int dnis[20];

// Funciones utiles y necesarias:
int cargarRandomAlumno(int[], float[], float[], int);
void mostrarTodosAlumnos(int[], float[], float[], int);
void mostrarDatosUnaPersona(int[], float[], float[], int);

// 1- Crear una función que los cargue de manera ordenada(por dni), hasta que el usuario lo decida.
void cargarAlumnosNotas(int[], float[], float[], int *, int);
void insercionOrdenada(int[], float[], float[], int, int, float, float);

// 2- Crear una función que los cargue de manera desordenada, hasta que el usuario lo decida.
void insercionDesordenada(int[], float[], float[], int, int, float, float);

// 3- Crear una función que busque dentro del arreglo de dnis un dni determinado y retorne la posición ( Si no se encuentra retornar -1). (considerar que si se hizo una inserción ordenada la búsqueda es con consideración ORDENADA, de lo contrario es una búsqueda en un arreglo DESORDENADO)
void menuYbusquedasEnArreglos(int *, int, int, int[], int, int, float[], float[]);

int busquedaEnArreglodesOrdenado(int[], int, int);
int busquedaEnArregloOrdenado(int[], int, int);

// 4- Hacer una función que muestre las notas del primer y segundo parcial, recibiendo como parámetro la posición.
void mostrarNotasSegunPosicion(float[], float[], int, int);

// 5- Hacer una función que muestre cada dni y un mensaje “DESAPROBADO” para aquellos que desaprobaron solo un parcial (nota menor a 6) y para aquellos que desaprobaron ambos debe mostrar la palabra “RECURSA”.
void mostrarAprobacion(int[], float[], float[], int);

// 6- Hacer una función que muestre la nota promedio de cada dni.
int promedioDnis(int[], float[], float[], int);

// 7- Hacer una función que muestre todos los dni que promocionaron la materia. Se promociona con un promedio de 8 y sin exámenes desaprobados.
void promocionaOno(int[], float[], float[], int);

// 8- Hacer una función que busque la máxima nota obtenida en el primer parcial y retorne la posición, luego en el main informar el dni que obtuvo esa máxima nota.
int maximaNotaPrimerParcial(int[], float[], int);

//9- Hacer una función que retorne la posición del mejor promedio (máximo promedio) de los 2 parciales. Luego en el main informar que dni obtuvo ese promedio.


int main()
{
    float notasParcial1[TAM_MAX];
    float notasParcial2[TAM_MAX];
    int dnis[TAM_MAX];
    int validos = 0, dniBuscado, indice = -1, respuesta = 0, dni, valor, dniConMaxNotaPar1;
    float parcial1, parcial2;
    char continuar;

    printf("Como deseas cargar a los alumnos?\n 1- Ordenado. \n 2- Desordenado. \nIngrese su respuesta: ");
    scanf("%d", &respuesta);

    cargarAlumnosNotas(dnis, notasParcial1, notasParcial2, &validos, respuesta);
    mostrarTodosAlumnos(dnis, notasParcial1, notasParcial2, validos);
    printf("Ingrese la posicion del alumno para ver sus notas: ");
    scanf("%d", &valor);
    mostrarNotasSegunPosicion(notasParcial1, notasParcial2, validos, valor);
    // system("pause");
    // system("cls");
    // printf("Le mostrare a continuacion informacion sobre las notas:\n");
    // mostrarAprobacion(dnis, notasParcial1, notasParcial2, validos);
    // system("pause");
    // system("cls");
    // printf("\n\t\tPromedio:");
    // promedioDnis(dnis, notasParcial1, notasParcial2, validos);
    // system("pause");
    // system("cls");
    // promocionaOno(dnis, notasParcial1, notasParcial2, validos);
    // dniConMaxNotaPar1 = maximaNotaPrimerParcial(dnis, notasParcial1, validos);
    // printf("La maxima nota en el primer parcial fue lograda por el alumno con DNI %d.\n", dnis[dniConMaxNotaPar1]);

    system("pause");
    return 0;
}

// carga de datos de alumnos. notas random :D pregunta clave, ordenada o no la inserción? chan
void cargarAlumnosNotas(int dnis[TAM_MAX], float notasParcial1[TAM_MAX], float notasParcial2[TAM_MAX], int *validos, int respuesta)
{
    int i = 0, dni, dato;
    float parcial1, parcial2;
    char continuar = 's';

    do
    {
        srand(time(NULL));
        printf("Ingrese el DNI del alumno en la posicion #%d:", i);
        scanf("%d", &dni);
        printf("Carga de notas auto.\n\tPresione n cuando desee dejar de cargarlas\n");
        parcial1 = (rand() % 7) + 4;
        parcial2 = (rand() % 7) + 3;
        switch (respuesta)
        {
        case 1:
            insercionOrdenada(dnis, notasParcial1, notasParcial2, *validos, dni, parcial1, parcial2);
            break;

        case 2:
            insercionDesordenada(dnis, notasParcial1, notasParcial2, *validos, dni, parcial1, parcial2);
            break;
        default:
            printf("Error. Usted no ha ingresado una opcion valida.");
            break;
        }

        printf("\nDesea continuar cargando datos? s/n: ");
        fflush(stdin);
        scanf("%c", &continuar);
        i++;
        (*validos)++;
    } while ((continuar == 's' || continuar == 'S') && ((*validos) < TAM_MAX));
}

// insercion ordenada. al final de esto se va a tener el conjunto de todo esto ordenado, wii
void insercionOrdenada(int dnis[], float notasP1[], float notasP2[], int validos, int dni, float notaP1, float notaP2)
{
    int i = validos - 1;

    while ((i >= 0) && (dnis[i] > dni))
    {
        dnis[i + 1] = dnis[i];
        notasP1[i + 1] = notasP1[i];
        notasP2[i + 1] = notasP2[i];
        i--;
    }
    dnis[i + 1] = dni;
    notasP1[i + 1] = notaP1;
    notasP2[i + 1] = notaP2;
}

// insercion desordenada, da igual como los cargues nomah
void insercionDesordenada(int dnis[], float notasP1[], float notasP2[], int validos, int dni, float parcial1, float parcial2)
{
    int i = validos;

    dnis[i] = dni;
    notasP1[i] = parcial1;
    notasP2[i] = parcial2;
    validos++;
}

void mostrarTodosAlumnos(int dnis[TAM_MAX], float notaParcial1[TAM_MAX], float notaParcial2[TAM_MAX], int validos)
{
    int i;
    printf("\n - - - - - - - - - MOSTRANDO TODOS LOS ALUMNOS - - - - - - -");
    for (i = 0; i < validos; i++)
    {
        mostrarDatosUnaPersona(dnis, notaParcial1, notaParcial2, i);
    }
    printf("\n - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
}

void mostrarDatosUnaPersona(int dnis[TAM_MAX], float notasParcial1[TAM_MAX], float notasParcial2[TAM_MAX], int i)
{
    printf("\n\t               ------ DNI: %d ------\n", dnis[i]);
    printf("\t               Nota Parcial 1: %.2f\n", notasParcial1[i]);
    printf("\t               Nota Parcial 2: %.2f\n", notasParcial2[i]);
}

void menuYbusquedasEnArreglos(int *dniBuscado, int respuesta, int indice, int dnis[], int dni, int validos, float notasParcial1[], float notasParcial2[])
{
    printf("\nIngrese DNI a buscar: ");
    scanf("%d", &dniBuscado);
    if (respuesta == 1)
    {
        indice = busquedaEnArreglodesOrdenado(dnis, validos, *dniBuscado);
    }
    else if (respuesta == 2)
    {
        indice = busquedaEnArreglodesOrdenado(dnis, validos, *dniBuscado);
    }

    if (indice != -1)
    {
        printf("\n\t             Se encontro a la persona: \n");
        mostrarDatosUnaPersona(dnis, notasParcial1, notasParcial2, indice);
    }
    else
    {
        printf("No se ha encontrado a la persona que buscaba.\n");
    }
}

int busquedaEnArreglodesOrdenado(int dnis[], int validos, int dni)
{
    int i = 0;
    int indice;
    if (validos != 0)
    {
        while ((i < validos) && (dni != dnis[i]))
        {
            i++;
        }

        if (i < validos)
        {
            indice = i;
        }
        else
        {
            indice = -1;
        }

        return indice;
    }
    else
    {
        printf("\nError, su arreglo esta vacio.");
    }
    return indice;
}

int busquedaEnArregloOrdenado(int dnis[], int validos, int dni)
{
    int medio = (validos / 2);
    int resultado = -1;
    if (validos != 0)
    {
        if (dnis[medio] > dni)
        {
            while (medio >= 0 && dnis[medio] != dni)
            {
                medio--;
            }
        }
        else
        {
            while (medio < validos && dnis[medio] != dni)
            {
                medio++;
            }
        }

        if (medio > -1 && medio > validos)
        {
            resultado = medio;
        }

        return resultado;
    }

    else
    {
        printf("Error, su arreglo esta vacio.");
    }

    return resultado;
}

void mostrarNotasSegunPosicion(float parcial1[], float parcial2[], int validos, int posicion)
{
    int i;

    for (i = 0; i < validos; i++)
    {
        if (i == posicion)
        {
            printf("\n\t - - - - - MOSTRAND0 NOTAS PARCIALES - - - - - \n");
            printf("\n                    - - - Parcial 1: %.2f - - -\n", parcial1[i]);
            printf("\n                    - - - Parcial 2: %.2f - - -\n", parcial2[i]);
            printf("\n - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
        }
    }
}

void mostrarAprobacion(int dnis[], float parcial1[], float parcial2[], int validos)
{
    int i;
    printf("\n|||||||||||||||||                          |||||||||||||||||\n");
    printf("\n               Lista de alumnos y sus notas:                 \n");
    printf("\n|||||||||||||||||                          |||||||||||||||||\n");
    for (i = 0; i < validos; i++)
    {
        if (parcial1[i] >= 6 && parcial2[i] >= 6)
        {
            printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
            printf("\n\t               DNI N %d : APROBADO\n", dnis[i]);
            mostrarDatosUnaPersona(dnis, parcial1, parcial2, i);
        }
        else if ((parcial1[i] < 6) ^ /*xor*/ (parcial2[i] < 6))
        {
            printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
            printf("\n\t               DNI N %d: DESAPROBADO\n", dnis[i]);
            mostrarDatosUnaPersona(dnis, parcial1, parcial2, i);
        }
        else
        {
            printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
            printf("\n\t                DNI N %d:RECURSA\n", dnis[i]);
            mostrarDatosUnaPersona(dnis, parcial1, parcial2, i);
        }
    }
    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
}

int promedioDnis(int dnis[], float parcial1[], float parcial2[], int validos)
{
    int i;
    float promedio;

    for (i = 0; i < validos; i++)
    {
        promedio = 0;
        promedio = (parcial1[i] + parcial2[i]) / 2;
        printf("\n\t    DNI: %d", dnis[i]);
        printf("\n\tPARCIAL 1: %.2f", parcial1[i]);
        printf("\n\tPARCIAL 2: %.2f", parcial2[i]);
        printf("\n\tPROMEDIO: %.2f\n", promedio);
    }
    return promedio;
}

void promocionaOno(int dnis[], float parcial1[], float parcial2[], int validos)
{
    int aprobados = 0;
    int promedio;
    int i;

    promedio = promedioDnis(dnis, parcial1, parcial2, validos);

    for (i = 0; i < validos; i++)
    {
        if ((parcial1[i] > 6 && parcial1[i] < 8) && (parcial2[i] > 6 && parcial2[i] < 8))
        {
            printf("Usted aprobo ambos parciales, pero con nota insuficiente para promocionar, estudiante %d.\n", dnis[i]);
        }
        else if ((parcial1[i] < 6) || (parcial2[i] < 6))
        {
            printf("\n\tPARCIAL DESAPROBADO, USTED PIERDE LA CHANCE DE PROMOCIONAR: %d\n", dnis[i]);
        }

        if ((parcial1[i] >= 8) && (parcial2[i] >= 8))
        {
            printf("\nTIENE AMBOS PARCIALES APROBADOS: %d", dnis[i]);
            printf("\n\tUsted ha promocionado la materia. Felicidades %d!\t\n", dnis[i]);
        }
    }
}

int maximaNotaPrimerParcial(int dnis[], float parcial1[], int validos)
{
    int i, maximaNota = 0, posicion = 0;

    for (i = 0; i < validos; i++)
    {
        if (i == 0)
        {
            maximaNota = parcial1[i];
        }
        if (parcial1[i] > maximaNota)
        {
            maximaNota = parcial1[i];
            posicion = i;
        }
    }
    printf("El DNI con la mejor nota se encuentra en la posicion %d\n", posicion);
    return posicion;
}