#include <stdio.h>
#include <stdlib.h> // Used for atoi() function
#include <string.h> // Used for strlen() function
#define TAM_MAX 30

typedef struct alumnado
{
    int matricula;
    char nombre[30];
    char genero; // m, f, o
} stAlumno;

// verifica si lo ingresado es un numero o no
void checkNumYcarga(int *);

// 0 - prototipados menu
void seleccionOpciones(stAlumno[TAM_MAX], int *, int);
void mostrarOpciones();

// 1- Hacer una función que cargue un arreglo de alumnos, hasta que el usuario lo decida.
void cargarStructAlumnos(stAlumno[TAM_MAX], int *);

// 2 - Hacer una función que muestre un arreglo de alumnos por pantalla.Modularizar.void mostrarAlumno(stAlumno[TAM_MAX]);
void mostrarAlumno(stAlumno);
void mostrarTodosLosAlumnos(stAlumno[], int);

// 3- Hacer una función que muestre por pantalla los datos de un alumno, conociendo su matrícula. Modularizar.
void buscarPorMatricula(stAlumno[], int, int *);

// 4- Hacer una función que ordene el arreglo de alumnos por medio del método de selección. El criterio de ordenación es el número de matrícula.
int buscarMenor(stAlumno[], int, int);
void ordenarPorSeleccion(stAlumno[], int);

// 5- Hacer una función que muestre por pantalla los datos de los estudiantes de un género determinado (se envía por parámetro). Modularizar.
int buscarPorGenero(stAlumno[], int, char);

// 6- Hacer una función que inserte en un arreglo ordenado por matrícula un nuevo dato, conservando el orden.
void ordenarArrayStruct(stAlumno[], int);
void cargaUnaPersona(stAlumno *);
void insercionOrdenada(stAlumno[], int, stAlumno);
void cargaListaPersonas(stAlumno[], int *);

// 7- Hacer una función que ordene el arreglo de alumnos por medio del método de inserción. El criterio de ordenación es el nombre.

// 8- Hacer una función que cuente y retorne la cantidad de estudiantes de un género determinado (se envía por parámetro) que tiene un arreglo de alumnos.
void ordenacionInsercion(stAlumno[], int);

// void defaultValues(stAlumno[], int *);

int main()
{
    char continuar;
    int opcion = 0, validos = 0, num, cargar;

    stAlumno p[TAM_MAX];
    stAlumno alumno;
    // printf("Carga manual: ");
    // // scanf("%d", &cargar);

    // // carga y muestra general
    // if (cargar == 1)
    // {
    //     cargarStructAlumnos(p, &validos);
    // }
    // else
    // {
    //     // defaultValues(p, &validos);
    //     fflush(stdin);
    // }
    cargaListaPersonas(p, &validos);
    mostrarTodosLosAlumnos(p, validos);

    do
    { // 0- Hacer una función principal que pruebe el funcionamiento de todos los incisos anteriores, con un menú de opciones para poder ejecutar todas las funciones requeridas. Tengan presente la correcta declaración y el ámbito de variables.

        mostrarOpciones();
        seleccionOpciones(p, &opcion, validos);

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
}
void seleccionOpciones(stAlumno p[], int *opcion, int validos)
{
    int matriculaBuscada = -1, buscador = -1;
    char buscado;
    stAlumno alumno;

    printf("\tIngrese la opcion a elegir (entre 1 y 8): ");

    scanf("%d", opcion);
    switch (*opcion)
    {
    case 1:
        // 1- Hacer una función que cargue un arreglo de alumnos, hasta que el usuario lo decida.
        system("cls");
        printf("\t1- Carga de alumnos: \n");
        // cargarStructAlumnos(p, &validos);
        mostrarAlumno(*p);
        break;
    case 2:
        // 2- Hacer una función que muestre un arreglo de alumnos por pantalla. Modularizar.
        system("cls");
        printf("\t2- Muestra de alumnos: \n");
        mostrarTodosLosAlumnos(p, validos);
        break;
    case 3:
        // 3- Hacer una función que muestre por pantalla los datos de un alumno, conociendo su matrícula. Modularizar.
        system("cls");
        printf("3- Busqueda de alumno por matricula.\n");
        printf("Por favor ingrese matricula a buscar: ");
        scanf("%i", &matriculaBuscada);
        buscarPorMatricula(p, validos, &matriculaBuscada);
        break;
    case 4:
        // 4- Hacer una función que ordene el arreglo de alumnos por medio del método de selección. El criterio de ordenación es el número de matrícula.
        system("cls");
        printf("4- Ordenar por seleccion la estructura, el criterio de ordenacion siendo la matricula.\n");
        printf("Su estructura antes: \n");
        ordenarPorSeleccion(p, validos);
        printf("Su estructura despues de ser ordenada: \n");
        mostrarTodosLosAlumnos(p, validos);
        break;
    case 5:
        // 5- Hacer una función que muestre por pantalla los datos de los estudiantes de un género determinado (se envía por parámetro). Modularizar.
        system("cls");
        printf("Opcion 5: Muestra de alumnos en base a su genero.\n");
        printf("Por favor ingrese el genero de los alumnos que desea buscar: ");
        fflush(stdin);
        scanf("%c", &buscado);
        if (buscado != 'f' && buscado != 'm' && buscado != 'o')
        {
            printf("Por favor vuelva a ingresar el genero a buscar: ");
            fflush(stdin);
            scanf("%c", &buscado);
        }

        buscador = buscarPorGenero(p, validos, buscado);
        if (buscador == -1)
        {
            printf("No hay alumnos de ese genero matriculados.\n");
        }
        break;
    case 6:
        // 6- Hacer una función que inserte en un arreglo ordenado por matrícula un nuevo dato, conservando el orden.
        mostrarTodosLosAlumnos(p, validos);
        printf("Por favor ingrese un nuevo alumno al struct");
        cargaUnaPersona(&alumno);
        mostrarTodosLosAlumnos(p, validos);
        validos = validos + 1;
        insercionOrdenada(p, validos, alumno);
        mostrarTodosLosAlumnos(p, validos);
        system("pause");
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

void cargaUnaPersona(stAlumno *p)
{
    fflush(stdin);
    printf("MATRICULA: ");
    fflush(stdin);
    checkNumYcarga(&(p)->matricula);
    printf("NOMBRE: ");
    fflush(stdin);
    gets((*p).nombre);
    printf("Ingrese genero alumno: ");
    fflush(stdin);
    gets(&(*p).genero);
    while (p->genero != 'm' && p->genero != 'f' && p->genero != 'o')
    {
        printf("Error. Ingrese genero alumno: ");
        fflush(stdin);
        gets(&(*p).genero);
    }
}

void cargaListaPersonas(stAlumno alumnos[], int *validos)
{
    char continuar;
    stAlumno p;
    int i = *validos; /// empiezo desde la ultima posicion NO cargada
    do
    {
        cargaUnaPersona(&p);
        insercionOrdenada(alumnos, i, p);
        printf("Desea agregar otra persona? s/n: ");
        fflush(stdin);
        scanf("%c", &continuar);
        i++;
    } while (i < TAM_MAX && continuar == 's');

    *validos = i;
}

//             Funcion para chequear que lo ingresado sea un numero entero
void checkNumYcarga(int *aVerificar)
{
    int valido;
    char str[20];

    do
    {
        gets(str);
        valido = atoi(str);
        if (valido == 0) // si atoi devuelve 0, se introdujo un string.
        {
            printf("Error. Ingrese nuevamente el numero: ");
        }

    } while (valido == 0);

    *aVerificar = valido;
}

void cargarStructAlumnos(stAlumno p[TAM_MAX], int *validos)
{
    char continuar;
    int i = 0;

    do
    {
        printf("Ingrese matricula alumno #%i: ", i);
        checkNumYcarga(&(p[i]).matricula); // mientras que se va cargando la matricula se chequea que sea un numero, entero.

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
        fflush(stdin);
    } while ((continuar == 's' || continuar == 'S') && i < TAM_MAX);

    (*validos) = i;
}
//    int matricula;
//   char nombre[30];
//   char genero; // m, f, o
void mostrarAlumno(stAlumno p)
{
    printf("                   MATRICULA DEL ESTUDIANTE: %i                     \n", p.matricula);
    printf("                   NOMBRE DEL ESTUDIANTE: %s                        \n", p.nombre);
    printf("                   GENERO DEL ESTUDIANTE: %c                        \n", p.genero);
    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
}

void mostrarTodosLosAlumnos(stAlumno p[], int validos)
{
    printf("\n|||||||||||||||||                          |||||||||||||||||\n");
    printf("\n               Lista de alumnos y su informacion:                 \n");
    printf("\n|||||||||||||||||                          |||||||||||||||||\n");

    printf("\n\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n");
    for (int i = 0; i < validos; i++)
    {
        printf("\n                  | |   Alumno #%i:   | |              \n", i);
        mostrarAlumno((p[i]));
    }
}

void buscarPorMatricula(stAlumno p[TAM_MAX], int validos, int *matriculaBuscada)
{
    for (int i = 0; i < validos; i++)
    {
        if (p[i].matricula == (*matriculaBuscada))
        {
            printf("Su alumno buscado se ha encontrado. Sus datos:\n");
            mostrarAlumno((p[i]));
        }
        else
        {
            (*matriculaBuscada) = -1;
        }
    }

    if ((*matriculaBuscada) == -1)
    {
        printf("No se encontro la matricula buscada");
    }
}

int buscarMenor(stAlumno p[], int validos, int i)
{
    int posMenor = i;
    int indice = i + 1;

    while (indice < validos)
    {
        if (p[posMenor].matricula > p[indice].matricula)
        {
            posMenor = indice;
        }
        indice++;
    }
    return posMenor;
}

void ordenarPorSeleccion(stAlumno p[], int validos)
{
    int i, posMenor;
    stAlumno aux[validos];

    for (int i = 0; i < validos; i++)
    {
        posMenor = buscarMenor(p, validos, i);
        aux[i] = p[posMenor];
        p[posMenor] = p[i];
        p[i] = aux[i];
    }
}

int buscarPorGenero(stAlumno p[], int validos, char buscado)
{
    int buscador = -1;

    for (int i = 0; i < validos; i++)
    {
        if (p[i].genero == buscado)
        {
            mostrarAlumno(p[i]);
            buscador++;
        }
    }

    return buscador;
}

void ordenarArrayStruct(stAlumno p[], int validos)
{
    stAlumno aux;
    int j = 0;
    for (int i = 0; i < validos; i++)
    {
        aux = p[i];
        j = i;
        while ((j > 0) && (p[j - 1]).matricula > aux.matricula)
        {
            p[j] = p[j - 1];
            j--;
        }
        p[j] = aux;
    }
}

void insercionOrdenada(stAlumno alumnos[], int validos, stAlumno p) /// insercion ordenada de una persona por el criterio de nombre alfabeticamente
{
    int i = validos - 1;
    while (i >= 0 && (alumnos[i].matricula > p.matricula))
    {
        alumnos[i + 1] = alumnos[i];
        i--;
    }
    validos++;
    alumnos[i + 1] = p;
}

// void cargarAlumno(stAlumno *a)
// {
//     a->matricula = 2;
//     strcpy(a->nombre, "Faa");
//     a->genero = 'f';

//     mostrarAlumno(*a);
// }

// void defaultValues(stAlumno p[], int *validos)
// {
//     p[0].matricula = 123;
//     strcpy(p[0].nombre, "Foo");
//     p[0].genero = 'm';
//     p[1].matricula = 456;
//     strcpy(p[1].nombre, "Bar");
//     p[1].genero = 'f';
//     p[2].matricula = 789;
//     strcpy(p[2].nombre, "Let");
//     p[2].genero = 'f';

//     *validos = 4;
// }

//
//
//
//
//
//
//
//
//
//
//
//
//