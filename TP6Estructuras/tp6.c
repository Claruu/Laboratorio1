#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM_MAX 30

typedef struct alumnado
{
    int matricula;
    char nombre[30];
    char genero; // m, f, o
} stAlumno;

// funciones utiles
void defaultValues(stAlumno[], int *);    // carga un array default
void checkNumYcarga(int *);               // verifica si lo ingresado es un numero o no
void ordenarArrayStruct(stAlumno[], int); // ordena un array de structs

// 0 - prototipados menu
void mostrarOpciones();

// 1- Hacer una función que cargue un arreglo de alumnos, hasta que el usuario lo decida.
void cargaUnaPersona(stAlumno *);
void insercionOrdenada(stAlumno[], int, stAlumno);
void cargaAlumnadoOrdenado(stAlumno[], int *);

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
void insercionDesordenada(stAlumno[], int *, stAlumno);

// 7- Hacer una función que ordene el arreglo de alumnos por medio del método de inserción. El criterio de ordenación es el nombre.

// 8- Hacer una función que cuente y retorne la cantidad de estudiantes de un género determinado (se envía por parámetro) que tiene un arreglo de alumnos.

int main()
{
    char continuar, buscado;
    int opcion = 0, validos = 0, cargar;
    int matriculaBuscada = -1, buscador = -1;
    stAlumno p[TAM_MAX];
    stAlumno alumno;

    printf("\tOpciones de carga:\n\t1- Carga manual.\n\t0-Carga automatica.\n\tIngrese opcion: ");
    scanf("%d", &cargar);
    if (cargar == 1) // carga y muestra general
    {
        cargaAlumnadoOrdenado(p, &validos);
    }
    else
    {
        defaultValues(p, &validos);
        fflush(stdin);
    }

    mostrarTodosLosAlumnos(p, validos);

    do
    { // 0- Hacer una función principal que pruebe el funcionamiento de todos los incisos anteriores, con un menú de opciones para poder ejecutar todas las funciones requeridas. Tengan presente la correcta declaración y el ámbito de variables.

        mostrarOpciones();

        printf("\tIngrese la opcion a elegir (entre 1 y 8): ");

        scanf("%d", &opcion);
        switch (opcion)
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
            if (cargar != 1)
            {
                ordenarArrayStruct(p, validos);
                printf("Ordene la estructura antes de trabajar con el ejercicio. \n");
                mostrarTodosLosAlumnos(p, validos);
            }
            printf("\nPor favor ingrese un nuevo alumno al struct:\n");
            cargaUnaPersona(&alumno);
            insercionDesordenada(p, &validos, alumno);
            mostrarTodosLosAlumnos(p, validos);
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

// funcion no pedida pero util para verificaciones.
//  Funcion para chequear que lo ingresado sea un numero entero
void checkNumYcarga(int *aVerificar)
{
    int validacion;
    char str[20];
    do
    {
        gets(str);
        validacion = atoi(str);
        if (validacion == 0) // si atoi devuelve 0, se introdujo un string.
        {
            printf("Error. Ingrese nuevamente el numero: ");
        }
    } while (validacion == 0);
    *aVerificar = validacion;
}

// carga 1 alumno
void cargaUnaPersona(stAlumno *p)
{
    fflush(stdin);
    printf("Ingrese numero de Matricula: ");
    checkNumYcarga(&(p)->matricula);
    printf("Ingrese nombre del alumno: ");
    fflush(stdin);
    gets((*p).nombre);
    printf("Ingrese genero del alumno: ");
    fflush(stdin);
    gets(&(*p).genero);
    while (p->genero != 'm' && p->genero != 'f' && p->genero != 'o')
    {
        printf("Error. Ingrese genero alumno: ");
        fflush(stdin);
        gets(&(*p).genero);
    }
}

// para la carga ordenada de alumnos
void insercionOrdenada(stAlumno listaAlumnos[], int validos, stAlumno alumno)
{
    int i = validos - 1;
    while (i >= 0 && (listaAlumnos[i].matricula > alumno.matricula))
    {
        listaAlumnos[i + 1] = listaAlumnos[i];
        i--;
    }
    validos++;
    listaAlumnos[i + 1] = alumno;
}

// ejercicio 1
void cargaAlumnadoOrdenado(stAlumno listaAlumnos[], int *validos)
{
    char continuar;
    stAlumno alumnoNuevo;
    int i = *validos; /// empiezo desde la ultima posicion NO cargada
    do
    {
        cargaUnaPersona(&alumnoNuevo);
        insercionOrdenada(listaAlumnos, i, alumnoNuevo);
        printf("Desea agregar otra persona? s/n: ");
        fflush(stdin);
        scanf("%c", &continuar);
        i++;
    } while (i < TAM_MAX && continuar == 's');

    *validos = i;
}

void mostrarAlumno(stAlumno p) // ejercicio 2
{
    printf("                   MATRICULA DEL ESTUDIANTE: %i                     \n", p.matricula);
    printf("                   NOMBRE DEL ESTUDIANTE: %s                        \n", p.nombre);
    printf("                   GENERO DEL ESTUDIANTE: %c                        \n", p.genero);
    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
}

void mostrarTodosLosAlumnos(stAlumno p[], int validos) // ejercicio 2
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

// funcion que carga un array de structs default
void defaultValues(stAlumno p[], int *validos)
{
    p[0].matricula = 1;
    strcpy(p[0].nombre, "Tobias Torres");
    p[0].genero = 'm';
    p[1].matricula = 5;
    strcpy(p[1].nombre, "Manuel Vasquez");
    p[1].genero = 'o';
    p[2].matricula = 2;
    strcpy(p[2].nombre, "Penelope Martinez");
    p[2].genero = 'f';
    *validos = 3;
}

void buscarPorMatricula(stAlumno p[TAM_MAX], int validos, int *matriculaBuscada) // ejercicio 3
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

int buscarMenor(stAlumno p[], int validos, int i) // ejercicio 4
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

void ordenarPorSeleccion(stAlumno p[], int validos) // ejercicio 4
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

int buscarPorGenero(stAlumno p[], int validos, char buscado) // ejercicio 5
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

void insercionDesordenada(stAlumno p[], int *validos, stAlumno alumnoNuevo) // ejercicio 6
{
    if (*validos < TAM_MAX)
    {
        p[*validos] = alumnoNuevo;
        (*validos)++;
    }
}

// ordena un array de estructuras
void ordenarArrayStruct(stAlumno alumnos[], int validos)
{
    stAlumno aux;
    int j = 0;
    for (int i = 0; i < validos; i++)
    {
        aux = alumnos[i];
        j = i;
        while ((j > 0) && (alumnos[j - 1]).matricula > aux.matricula)
        {
            alumnos[j] = alumnos[j - 1];
            j--;
        }
        alumnos[j] = aux;
    }
}