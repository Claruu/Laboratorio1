#include <stdio.h>
#include <stdlib.h> // Used for atoi() function
#include <string.h> // Used for strlen() function
#define TAM_MAX 30
#define TRUE 1
#define FALSE 0

typedef struct
{
    int matricula;
    char nombre[30];
    char genero; // m, f, o
} stAlumno;

// verifica si lo ingresado es un numero o no
int checkNum(int);

// 0 - prototipados menu
void seleccionOpciones(stAlumno[TAM_MAX], int *, int);
void mostrarOpciones();

// 1- Hacer una función que cargue un arreglo de alumnos, hasta que el usuario lo decida.
void cargarStructAlumnos(stAlumno[TAM_MAX], int *);

// 2 - Hacer una función que muestre un arreglo de alumnos por pantalla.Modularizar.void mostrarAlumno(stAlumno[TAM_MAX]);
void mostrarAlumnado(stAlumno[], int);

// 3- Hacer una función que muestre por pantalla los datos de un alumno, conociendo su matrícula. Modularizar.

// 4- Hacer una función que ordene el arreglo de alumnos por medio del método de selección. El criterio de ordenación es el número de matrícula.

// 5- Hacer una función que muestre por pantalla los datos de los estudiantes de un género determinado (se envía por parámetro). Modularizar.

// 6- Hacer una función que inserte en un arreglo ordenado por matrícula un nuevo dato, conservando el orden.

// 7- Hacer una función que ordene el arreglo de alumnos por medio del método de inserción. El criterio de ordenación es el nombre.

// 8- Hacer una función que cuente y retorne la cantidad de estudiantes de un género determinado (se envía por parámetro) que tiene un arreglo de alumnos.

int main()
{
    char continuar;
    int opcion = 0, validos = 0;

    stAlumno a;

    do
    { // 0- Hacer una función principal que pruebe el funcionamiento de todos los incisos anteriores, con un menú de opciones para poder ejecutar todas las funciones requeridas. Tengan presente la correcta declaración y el ámbito de variables.
        mostrarOpciones();
        seleccionOpciones(&a, &opcion, validos);
        printf("Desea continuar? s/n: ");
        fflush(stdin);
        scanf("%c", &continuar);
        system("cls");
    } while (continuar == 's' || continuar == 'S');

    return 0;
}

void mostrarOpciones()
{
    printf("\tMenu TP 6: Estructuras\n");
    printf("Opcion 1: Carga de arreglo de alumnos.\n");
    printf("Opcion 2: Muestra de arreglo de alumnos.\n");
    printf("Opcion 3: Muestra de alumno particular con su matricula.\n");
    printf("Opcion 4: Ordenacion por seleccion de alumnos en base a su matricula.\n");
    printf("Opcion 5: Muestra de alumnos en base a su genero.\n");
    printf("Opcion 6: Insercion de un dato en un arreglo ordenado, conservando el orden.\n");
    printf("Opcion 7: Ordenacion por insercion de alumnos en base a su nombre.\n");
    printf("Opcion 8: Contador de cantidad de estudiantes de un genero determinado.\n");
    printf("\tIngrese la opcion a elegir (entre 1 y 8): ");
}
void seleccionOpciones(stAlumno p[], int *opcion, int validos)
{
    scanf("%d", opcion);
    switch (*opcion)
    {
    case 1:
        // 1- Hacer una función que cargue un arreglo de alumnos, hasta que el usuario lo decida.
        system("cls");
        printf("\t1- Carga de alumnos: \n");
        cargarStructAlumnos(p, &validos);
        mostrarAlumno(p);
        mostrarAlumnado(p, validos);
        break;
    case 2:
        // 2- Hacer una función que muestre un arreglo de alumnos por pantalla. Modularizar.
        system("cls");
        printf("\t2- Muestra de alumnos: \n");
        cargarStructAlumnos(p, &validos);
        mostrarAlumno(p);
        mostrarAlumnado(p, validos);
        break;
    case 3:
        // 3- Hacer una función que muestre por pantalla los datos de un alumno, conociendo su matrícula. Modularizar.
        break;
    case 4:
        // 4- Hacer una función que ordene el arreglo de alumnos por medio del método de selección. El criterio de ordenación es el número de matrícula.
        break;
    case 5:
        // 5- Hacer una función que muestre por pantalla los datos de los estudiantes de un género determinado (se envía por parámetro). Modularizar.
        break;
    case 6:
        // 6- Hacer una función que inserte en un arreglo ordenado por matrícula un nuevo dato, conservando el orden.
        break;
    case 7:
        // 7- Hacer una función que ordene el arreglo de alumnos por medio del método de inserción. El criterio de ordenación es el nombre.
        break;
    case 8:
        // 8- Hacer una función que cuente y retorne la cantidad de estudiantes de un género determinado (se envía por parámetro) que tiene un arreglo de alumnos.
        break;
    default:
        printf("Error, no ha ingresado una opcion valida.\n");
        break;
    }
}

void cargarStructAlumnos(stAlumno p[TAM_MAX], int *validos)
{
    char continuar;
    int nombresCargados = 0, aux, i = 0;

    do
    {
        printf("Ingrese matricula alumno #%i: ", i);
        (p[i]).matricula = checkNum((p[i]).matricula); // mientras que se va cargando la matricula se chequea que sea un numero, entero.

        printf("Ingrese nombre alumno #%i: ", i);
        fflush(stdin);
        gets((p[i]).nombre);

        printf("Ingrese genero alumno #%i: ", i);
        fflush(stdin);
        gets(&(p[i]).genero);
        while (((p[i]).genero != 'm') && ((p[i]).genero != 'f') && ((p[i]).genero != 'o'))
        {
            printf("Error. Ingrese genero alumno #%i: ", i);
            fflush(stdin);
            gets(&(p[i]).genero);
        }

        printf("Desea continuar cargando alumnos? s/n: ");
        fflush(stdin);
        scanf("%c", &continuar);
        i++;
    } while ((continuar == 's' || continuar == 'S') && i < TAM_MAX);

    (*validos) = i;
}
//    int matricula;
//   char nombre[30];
//   char genero; // m, f, o
void mostrarAlumno(stAlumno p[])
{
    printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
    printf("                   MATRICULA DEL ESTUDIANTE: %i                     \n", p->matricula);
    printf("                   NOMBRE DEL ESTUDIANTE: %s                        \n", &p->nombre);
    printf("                   GENERO DEL ESTUDIANTE: %c                        \n", p->genero);
    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
}

void mostrarAlumnado(stAlumno p[], int validos)
{
    printf("\n|||||||||||||||||                          |||||||||||||||||\n");
    printf("\n               Lista de alumnos y su informacion:                 \n");
    printf("\n|||||||||||||||||                          |||||||||||||||||\n");
    for (int i = 0; i < validos; i++)
    {
        printf("\n                  | |   Alumno #%i:   | |              \n", i);
        mostrarAlumno(p);
    }
}

//                   Funcion para chequear que lo ingresado sea un numero entero
//                   Not my code, don't judge me (?)
int checkNum(int aVerificar)
{
    char n[10]; // Limits characters to the equivalent of the 32 bits integers limit (10 digits)

    do
    {
        scanf(" %s", n);

        aVerificar = TRUE; // Sets the default for the integer test variable to TRUE

        int i = 0, l = strlen(n);
        if (n[0] == '-') // Tests for the negative sign to correctly handle negative integer values
            i++;
        while (i < l)
        {
            if (n[i] < '0' || n[i] > '9') // Tests the string characters for non-integer values
            {
                aVerificar = FALSE; // Changes intTest variable from TRUE to FALSE and breaks the loop early
                break;
            }
            i++;
        }
        if (aVerificar == TRUE)
        {
            aVerificar = atoi(n);
        } // Converts the string to an integer and prints the integer value
        else
        {
            printf("Error. Vuelva a ingresar el # matricula: "); // Prints "Retry:" if tested FALSE
            if (aVerificar == TRUE)
            {
                aVerificar = atoi(n);
            }
        }

    } while (aVerificar == FALSE); // Continues to ask the user to input a valid integer value

    return aVerificar;
}
