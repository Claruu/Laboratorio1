#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM_MAX 7

typedef struct alumnado
{
    int matricula;
    char nombre[30];
    char genero; // m, f, o
} stAlumno;

// funciones utiles
// carga un array default
void defaultValues(stAlumno[], int *);

// verifica si lo ingresado es un numero o no
void checkNumYcarga(int *);

// ordena un array de structs
void ordenarArrayStruct(stAlumno[], int);

// 0- Hacer una función principal que pruebe el funcionamiento de todos los incisos anteriores, con un menú de opciones para poder ejecutar todas las funciones requeridas. Tengan presente la correcta declaración y el ámbito de variables.
// opciones ejercicios
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

// 1- Hacer una función que cargue un arreglo de alumnos, hasta que el usuario lo decida.
void cargaUnaPersona(stAlumno *);
void insercionOrdenada(stAlumno[], int, stAlumno);
void cargaAlumnadoOrdenado(stAlumno[], int *);

// 2 - Hacer una función que muestre un arreglo de alumnos por pantalla.Modularizar.void mostrarAlumno(stAlumno[TAM_MAX]);
void mostrarAlumno(stAlumno);
void mostrarTodosLosAlumnos(stAlumno[], int);

// 3- Hacer una función que muestre por pantalla los datos de un alumno, conociendo su matrícula. Modularizar.
int busquedaMatricula(stAlumno[], int, int);
void muestraAlumnoSegunMatricula(stAlumno[], int, int);

// 4- Hacer una función que ordene el arreglo de alumnos por medio del método de selección. El criterio de ordenación es el número de matrícula.
int buscarMenor(stAlumno[], int, int);
void ordenarPorSeleccion(stAlumno[], int);

// 5- Hacer una función que muestre por pantalla los datos de los estudiantes de un género determinado (se envía por parámetro). Modularizar.
int buscarPorGenero(stAlumno[], int, char);

// 6- Hacer una función que inserte en un arreglo ordenado por matrícula un nuevo dato, conservando el orden.
void insercionDesordenada(stAlumno[], int *, stAlumno);

// 7- Hacer una función que ordene el arreglo de alumnos por medio del método de inserción. El criterio de ordenación es el nombre.
void insercionOrdenadaPorNombre(stAlumno[], int, stAlumno);

// 8- Hacer una función que cuente y retorne la cantidad de estudiantes de un género determinado (se envía por parámetro) que tiene un arreglo de alumnos.
int contarCantAlumnosGeneroBuscado(stAlumno[], int, char);

// 0- Hacer una función principal que pruebe el funcionamiento de todos los incisos anteriores, con un menú de opciones para poder ejecutar todas las funciones requeridas. Tengan presente la correcta declaración y el ámbito de variables.
int main()
{
    char continuar, generoBuscado;
    int opcion = 0, validos = 0, cargar;
    int matriculaBuscada = -1, buscador = -1;
    stAlumno listaAlumnos[TAM_MAX];
    stAlumno alumno;
    mostrarOpciones();
    printf("\tOpciones de carga:\n\t1- Carga manual.\n\t0-Carga automatica.\n\tIngrese opcion: ");
    scanf("%d", &cargar);
    if (cargar == 1) // carga y muestra general
    {
        cargaAlumnadoOrdenado(listaAlumnos, &validos);
    }
    else
    {
        defaultValues(listaAlumnos, &validos);
        fflush(stdin);
    }

    mostrarTodosLosAlumnos(listaAlumnos, validos);

    do
    {
        mostrarOpciones();

        printf("\tIngrese la opcion a elegir (entre 1 y 8): ");

        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            // 1- Hacer una función que cargue un arreglo de alumnos, hasta que el usuario lo decida.
            system("cls");
            printf("\t1- Carga de alumnos. \n");
            mostrarTodosLosAlumnos(listaAlumnos, validos);
            break;
        case 2:
            // 2- Hacer una función que muestre un arreglo de alumnos por pantalla. Modularizar.
            system("cls");
            printf("\t2- Muestra de alumnos: \n");
            mostrarTodosLosAlumnos(listaAlumnos, validos);
            break;
        case 3:
            // 3- Hacer una función que muestre por pantalla los datos de un alumno, conociendo su matrícula. Modularizar.
            system("cls");
            printf("3- Busqueda de alumno por matricula.\n");
            printf("Por favor ingrese matricula a buscar: ");
            scanf("%i", &matriculaBuscada);
            muestraAlumnoSegunMatricula(listaAlumnos, validos, matriculaBuscada);
            break;
        case 4:
            // 4- Hacer una función que ordene el arreglo de alumnos por medio del método de selección. El criterio de ordenación es el número de matrícula.
            system("cls");
            printf("4- Ordenar por seleccion la estructura, el criterio de ordenacion siendo la matricula.\n");
            printf("Su estructura antes: \n");
            ordenarPorSeleccion(listaAlumnos, validos);
            printf("Su estructura despues de ser ordenada: \n");
            mostrarTodosLosAlumnos(listaAlumnos, validos);
            break;
        case 5:
            // 5- Hacer una función que muestre por pantalla los datos de los estudiantes de un género determinado (se envía por parámetro). Modularizar.
            system("cls");
            printf("Opcion 5: Muestra de alumnos en base a su genero.\n");
            printf("Ingrese el genero de los alumnos que desea ver: ");
            fflush(stdin);
            scanf("%c", &generoBuscado);
            while (generoBuscado != 'f' && generoBuscado != 'm' && generoBuscado != 'o')
            {
                printf("Por favor vuelva a ingresar el genero a buscar: ");
                fflush(stdin);
                scanf("%c", &generoBuscado);
            }
            buscador = buscarPorGenero(listaAlumnos, validos, generoBuscado);
            break;
        case 6:
            // 6- Hacer una función que inserte en un arreglo ordenado por matrícula un nuevo dato, conservando el orden.
            if (cargar != 1)
            {
                ordenarArrayStruct(listaAlumnos, validos);
                printf("\n\nOrdene la estructura antes de trabajar con el ejercicio. \n");
                mostrarTodosLosAlumnos(listaAlumnos, validos);
            }
            printf("\nPor favor ingrese un nuevo alumno al struct:\n");
            cargaUnaPersona(&alumno);
            insercionDesordenada(listaAlumnos, &validos, alumno);
            mostrarTodosLosAlumnos(listaAlumnos, validos);
            break;
        case 7:
            // 7- Hacer una función que ordene el arreglo de alumnos por medio del método de inserción. El criterio de ordenación es el nombre.
            mostrarTodosLosAlumnos(listaAlumnos, validos);
            break;
        case 8:
            // 8- Hacer una función que cuente y retorne la cantidad de estudiantes de un género determinado (se envía por parámetro) que tiene un arreglo de alumnos.
            printf("Ingrese genero a buscar: ");
            fflush(stdin);
            scanf("%c", &generoBuscado);
            while (generoBuscado != 'm' && generoBuscado != 'f' && generoBuscado != 'o')
            {
                printf("ERROR. Usted no ha ingresado un genero valido. Por favor vuelva a ingresar el genero: ");
                scanf("%c", &generoBuscado);
            }
            printf("Buscando... \n");
            buscador = contarCantAlumnosGeneroBuscado(listaAlumnos, validos, generoBuscado);
            if (buscador != 0)
            {
                printf("Se han encontrado %i alumnos de ese genero.\n", buscador);
            }
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
void cargaUnaPersona(stAlumno *alumno)
{
    fflush(stdin);
    printf("Ingrese numero de Matricula: ");
    scanf("%i", &alumno->matricula);
    printf("Ingrese nombre del alumno: ");
    fflush(stdin);
    gets((*alumno).nombre);
    printf("Ingrese genero del alumno: ");
    fflush(stdin);
    gets(&(*alumno).genero);
    while (alumno->genero != 'm' && alumno->genero != 'f' && alumno->genero != 'o')
    {
        printf("Error. Ingrese genero alumno: ");
        fflush(stdin);
        gets(&(*alumno).genero);
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

void cargaAlumnadoOrdenado(stAlumno listaAlumnos[], int *validos) // ejercicio 1
{
    int opcion, checkNoRep = 0;
    char continuar;
    stAlumno alumnoNuevo;
    int i = *validos; /// empiezo desde la ultima posicion NO cargada
    printf("Desea cargar ordenado por:\n1- Matricula\n2-Nombre\nIngrese la opcion: ");
    scanf("%i", &opcion);
    do
    {
        if (opcion == 1)
        {
            cargaUnaPersona(&alumnoNuevo);
            checkNoRep = busquedaMatricula(listaAlumnos, i, alumnoNuevo.matricula);
            while (checkNoRep != -1)
            {
                printf("\nERROR. USTED ESTA INGRESANDO UNA MATRICULA REPETIDA.\n\tVUELVA A INGRESAR LA MATRICULA: ");
                checkNumYcarga(&(alumnoNuevo).matricula);
                checkNoRep = busquedaMatricula(listaAlumnos, i, alumnoNuevo.matricula);
            }
            insercionOrdenada(listaAlumnos, i, alumnoNuevo);
        }
        else
        {
            cargaUnaPersona(&alumnoNuevo);
            checkNoRep = busquedaMatricula(listaAlumnos, i, alumnoNuevo.matricula);
            while (checkNoRep != -1)
            {
                printf("\nERROR. USTED ESTA INGRESANDO UNA MATRICULA REPETIDA.\n\tVUELVA A INGRESAR LA MATRICULA: ");
                checkNumYcarga(&(alumnoNuevo).matricula);
                checkNoRep = busquedaMatricula(listaAlumnos, i, alumnoNuevo.matricula);
            }
            insercionOrdenadaPorNombre(listaAlumnos, i, alumnoNuevo);
        }
        printf("Desea agregar otra persona? s/n: ");
        fflush(stdin);
        scanf("%c", &continuar);
        i++;
    } while (i < TAM_MAX && continuar == 's');

    *validos = i;
}

void mostrarAlumno(stAlumno alumno) // ejercicio 2(1)
{
    printf("                   MATRICULA DEL ESTUDIANTE: %i                     \n", alumno.matricula);
    printf("                   NOMBRE DEL ESTUDIANTE: %s                        \n", alumno.nombre);
    printf("                   GENERO DEL ESTUDIANTE: %c                        \n", alumno.genero);
    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
}

void mostrarTodosLosAlumnos(stAlumno listaAlumnos[], int validos) // ejercicio 2(2)
{
    printf("\n|||||||||||||||||                          |||||||||||||||||\n");
    printf("\n               Lista de alumnos y su informacion:                 \n");
    printf("\n|||||||||||||||||                          |||||||||||||||||\n");

    printf("\n\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n");
    for (int i = 0; i < validos; i++)
    {
        printf("\n                  | |   Alumno #%i:   | |              \n", i);
        mostrarAlumno((listaAlumnos[i]));
    }
}

// funcion que carga un array de structs default
void defaultValues(stAlumno alumno[], int *validos)
{
    alumno[0].matricula = 1;
    strcpy(alumno[0].nombre, "Juan Torres");
    alumno[0].genero = 'm';
    alumno[1].matricula = 5;
    strcpy(alumno[1].nombre, "Damiani Eryn");
    alumno[1].genero = 'o';
    alumno[2].matricula = 2;
    strcpy(alumno[2].nombre, "Paola Lopez");
    alumno[2].genero = 'f';
    *validos = 3;
}

int busquedaMatricula(stAlumno listaAlumnos[TAM_MAX], int validos, int matriculaBuscada) // ejercicio 3(1)
{
    int posicion = -1;

    for (int i = 0; i < validos; i++)
    {
        if (listaAlumnos[i].matricula == matriculaBuscada)
        {
            posicion = i;
            break;
        }
    }
    return posicion;
}

void muestraAlumnoSegunMatricula(stAlumno listaAlumnos[], int validos, int matriculaBuscada) // ejercicio 3(2)
{
    int resultado = busquedaMatricula(listaAlumnos, validos, matriculaBuscada);
    if (resultado != -1)
    {
        printf("Su alumno se ha encontrado, en la posicion %i", resultado);
        mostrarAlumno((listaAlumnos[resultado]));
    }
    else
    {
        printf("No existe un alumno con esa matricula en nuestra base de datos.\n");
    }
}

int buscarMenor(stAlumno listaAlumnos[], int validos, int i) // ejercicio 4
{
    int posMenor = i;
    int indice = i + 1;

    while (indice < validos)
    {
        if (listaAlumnos[posMenor].matricula > listaAlumnos[indice].matricula)
        {
            posMenor = indice;
        }
        indice++;
    }
    return posMenor;
}

void ordenarPorSeleccion(stAlumno listaAlumnos[], int validos) // ejercicio 4
{
    int i, posMenor;
    stAlumno aux[validos];

    for (int i = 0; i < validos; i++)
    {
        posMenor = buscarMenor(listaAlumnos, validos, i);
        aux[i] = listaAlumnos[posMenor];
        listaAlumnos[posMenor] = listaAlumnos[i];
        listaAlumnos[i] = aux[i];
    }
}

int buscarPorGenero(stAlumno listaAlumnos[], int validos, char buscado) // ejercicio 5
{
    int buscador = -1;
    for (int i = 0; i < validos; i++)
    {
        if (listaAlumnos[i].genero == buscado)
        {
            mostrarAlumno(listaAlumnos[i]);
            buscador++;
        }
    }

    if (buscador == -1)
    {
        printf("No se ha encontrado alumnos de ese genero en el alumnado.\n");
    }

    return buscador;
}

void insercionDesordenada(stAlumno listaAlumnos[], int *validos, stAlumno alumnoNuevo) // ejercicio 6
{
    if (*validos < TAM_MAX)
    {
        listaAlumnos[*validos] = alumnoNuevo;
        (*validos)++;
    }
}

void ordenarArrayStruct(stAlumno listaAlumnos[], int validos) // util para ordenar un array de estructuras por matricula
{
    stAlumno aux;
    int j = 0;
    for (int i = 0; i < validos; i++)
    {
        aux = listaAlumnos[i];
        j = i;
        while ((j > 0) && (listaAlumnos[j - 1]).matricula > aux.matricula)
        {
            listaAlumnos[j] = listaAlumnos[j - 1];
            j--;
        }
        listaAlumnos[j] = aux;
    }
}

void insercionOrdenadaPorNombre(stAlumno listaAlumnos[], int validos, stAlumno alumno) // ejercicio 7
{
    int i = validos - 1;

    while (i >= 0 && strcmp(listaAlumnos[i].nombre, alumno.nombre) > 0)
    {
        listaAlumnos[i + 1] = listaAlumnos[i];
        i--;
    }
    validos++;
    listaAlumnos[i + 1] = alumno;
}

int contarCantAlumnosGeneroBuscado(stAlumno listaAlumnos[], int validos, char buscado) // ejercicio 8
{
    int encontrado = 0;
    for (int i = 0; i < validos; i++)
    {
        if (listaAlumnos[i].genero == buscado)
        {
            encontrado++;
        }
    }
    if (encontrado == 0)
    {
        printf("No se han encontrado alumnos de ese genero.");
    }
    return encontrado;
}
