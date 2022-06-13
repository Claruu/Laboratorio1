#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Librerias\pila.c"

#define TAM_MAX 30

typedef struct alumnado
{
    int legajo;
    char nombreYapellido[30];
    int edad;
    int anio;
    // año que cursa, recordar que no podemos utilizar la ñ para definir variables
} stAlumno;

// Trabajo Práctico N° 7: Archivos
// En cada ejercicio, el archivo debe abrirse y cerrarse dentro de cada función. La variable de tipo FILE * debe ser local a la función. Se puede pasar por parámetro una variable de tipo char [30] con el nombre del archivo, ejemplos: “archivo.bin” o "alumnos.dat", o trabajar con una constante declarada.
// Utilizando datos primitivos (int, char, float, etc), elija un tipo de dato y realice las siguientes funciones:

// 0- Hacer una función principal que pruebe el funcionamiento de todos los incisos anteriores, con un menú de opciones para poder ejecutar todas las funciones requeridas. Tengan presente la correcta declaración y el ámbito de variables.
void mostrarOpciones()
{
    char si;

    printf("\tMenu TP 7: Archivos\n");
    printf("Opcion 1: Agrega un elemento al final de un archivo.\n");
    printf("Opcion 2: Muestra por pantalla el contenido de un archivo.\n");
    printf("Opcion 3: Muestra la cantidad de registros que contiene un archivo.\n");
    printf("Opcion 4: Carga un archivo de alumnos con 5 datos.\n");
    printf("Opcion 5: Muestra los registros de un archivo de alumnos.\n");
    printf("Opcion 6: Agrega un elemento al final de un archivo cargado con alumnos.\n");
    printf("Desea ver la siguiente pagina de opciones? s/n: ");
    fflush(stdin);
    scanf("%c", &si);
    if (si == 's' || si == 'S')
    {
        system("cls");
        printf("\t               Pag 2.\n");
        printf("\t           Menu TP 7: Archivos\n");
        printf("Opcion 7: Pasa a una pila los numeros de legajo de los alumnos mayores de edad.\n");
        printf("Opcion 8: Cuenta la cantidad de alumnos mayores a la edad que le pidas.\n");
        printf("Opcion 9: Muestra el nombre de los alumnos en el rango de edad que uno le pida.\n");
        printf("Opcion 10: Muestra los datos del alumno de mayor edad cargado en un archivo de alumnos.\n");
        printf("Opcion 11: Muestra la cantidad de alumnos que cursan el anio que uno le pida.\n");
        printf("Opcion 12: Copia el arreglo de tipo alumno que uno le pasa por parametro a un archivo. Tambien pasa los elementos de ese archivo a un arreglo de alumnos, filtrando los estudiantes de cierto anio.\n");
        // printf("Opcion 13: Muestra la cantidad de registros que tiene un archivo.\n");
        // printf("Opcion 14: Con un archivo de 10 alumnos, muestra el contenido de un registro.\n");
        // printf("Opcion 15: Modifica un registro existente en el archivo de alumnos. Puede modificar uno o todos los campos de la estructura, y puede sobreescribir el registro existente en el archivo.\n");
        // printf("Opcion 16: Invierte los elementos de un archivo de alumnos.\n");
    }
}
void seleccionOpciones(int *);

void checkNum(int *);

// 1- Hacer una función que agregue un elemento al final de un archivo.
void cargarINTySobreescribir();
void cargarINTalFinal();
void cargarVariosElementosAlFinal();

// 2- Hacer una función que muestre por pantalla el contenido de un archivo.
void mostrarArchivoNumeros();

// 3- Hacer una función que retorne la cantidad de registros que contiene un archivo.
int cantRegistrosInt();

// 4- Crear una función que cargue un archivo de alumnos. Abrirlo de manera tal de verificar si el archivo ya está creado previamente. Cargar el archivo con 5 datos. Cerrarlo dentro de la función
void cargarAlumno(stAlumno *); // funciones utiles, carga Alumno
void cargarListaAlumnos();
void mostrarAlumno(stAlumno);
void mostrarListaAlumnos();
void cargarListaAlumnosYsobreesc();

// 5- Crear una función que muestre por pantalla los registros de un archivo de alumnos. Modularizar.
int cantRegistrosStructs();

//// 6- Crear una función que permita agregar de a un elemento al final del archivo. O sea, se debe abrir el archivo, se piden los datos (se llena una variable de tipo struct alumno), se escribe en el archivo y se cierra.
void cargaAlumnosNoSobreesc();

// 7- Crear una función que pase a una pila los números de legajo de los alumnos mayores de edad.
void pasarAPilaLegajosMayEdad(char[], Pila *);

// 8- Dado un archivo de alumnos, hacer una función que cuente la cantidad de alumnos mayores a edad específica que se envía por parámetro.
void sumarMayoresAedadBuscada(char[], int);

// 9- Dado un archivo de alumnos, mostrar por pantalla el nombre de todos los alumnos entre un rango de edades específico (por ejemplo, entre 17 y 25 años). Dicho rango debe recibirse por parámetro. Modularizar
void mostrarPorRangoEdad(char[], int, int);

// 10- Dado un archivo de alumnos, mostrar los datos del alumno de mayor edad. Modularizar.
int buscarAlumnoPorEdadYmostrar(char[], int);
void mostrarAluMayorEdad();

// 11- Crear una función que retorne la cantidad de alumnos que cursan un determinado año. El año buscado se pasa por parámetro.
int mostrarCantAlumnosCursandoXanio(char[], int);

// 12- Crear una función que reciba como parámetro un arreglo de tipo alumno y lo copie en el archivo.
// void cargarArrayStructAl(stAlumno[], int *);
// void insercionOrdenada(stAlumno[], int, stAlumno);

// Asimismo, realice otra función que pase los elementos del archivo a un arreglo de alumnos, filtrando los estudiantes de un año en particular.

// 13-Crear una función que retorne la cantidad de registros que tiene el archivo. Usar fseek y ftell. Puede pensar la función para uso genérico, que sirva para averiguar la cantidad de registros de cualquier archivo.
int cantRegGenerico(char[], int);

int main()
{
    FILE fp;
    char continuar;
    char archInt[TAM_MAX] = {"ejerciciosConInt.bin"};
    char archStruct[TAM_MAX] = {"ejercicios.bin"};
    int opcion = 0, eleccionCarga = 0, num = 0, i = 0, validos = 0, buscado = 0, num2 = 0;
    stAlumno a;
    stAlumno lista[TAM_MAX];
    Pila p;
    inicpila(&p);

    do
    { // 0- Hacer una función principal que pruebe el funcionamiento de todos los incisos anteriores, con un menú de opciones para poder ejecutar todas las funciones requeridas. Tengan presente la correcta declaración y el ámbito de variables.
        mostrarOpciones();
        printf("Ingrese una opcion: ");
        checkNum(&opcion);
        system("cls");
        switch (opcion)
        {
        case 1:
            // 1- Hacer una función que agregue un elemento al final de un archivo.
            while (eleccionCarga != 1 && eleccionCarga != 2)
            {
                printf("Por favor ingrese la opcion que desea.\n1-Cargar y sobreescribir.\n2-Cargar al final.\n");
                checkNum(&eleccionCarga);
            }

            if (eleccionCarga == 1)
            {
                cargarINTySobreescribir(archStruct);
            }
            else if (eleccionCarga == 2)
            {
                cargarINTalFinal(archInt);
            }
            break;
        case 2:
            // 2- Hacer una función que muestre por pantalla el contenido de un archivo.
            mostrarArchivoNumeros(archStruct);
            break;
        case 3:
            // 3- Hacer una función que retorne la cantidad de registros que contiene un archivo.
            i = cantRegistrosInt(num);
            printf("Cantidad de registros en su archivo: %i\n", i);
            break;
        case 4:
            // 4- Crear una función que cargue un archivo de alumnos. Abrirlo de manera tal de verificar si el archivo ya está creado previamente. Cargar el archivo con 5 datos. Cerrarlo dentro de la función
            eleccionCarga = 0;
            while (eleccionCarga != 1 && eleccionCarga != 2)
            {
                system("cls");
                printf("1- Sobreescribir y cargar nuevos alumnos.\n2-Cargar nuevos alumnos al final.\n\tIngrese la opcion: ");
                checkNum(&eleccionCarga);
            }
            if (eleccionCarga == 1)
            {
                cargarListaAlumnosYsobreesc(archStruct);
            }
            else
            {
                mostrarListaAlumnos(archStruct);
                cargaAlumnosNoSobreesc(archStruct);
            }

            mostrarListaAlumnos(archStruct);
            break;
        case 5:
            // 5- Crear una función que muestre por pantalla los registros de un archivo de alumnos. Modularizar.
            mostrarListaAlumnos(archStruct);
            i = cantRegistrosStructs(archStruct);
            printf("Cantidad de alumnos en su archivo: %i\n", i);
            break;
        case 6:
            // 6- Crear una función que permita agregar de a un elemento al final del archivo. O sea, se debe abrir el archivo, se piden los datos (se llena una variable de tipo struct alumno), se escribe en el archivo y se cierra.
            mostrarListaAlumnos(archStruct);
            cargaAlumnosNoSobreesc(archStruct);
            break;
        case 7:
            // 7- Crear una función que pase a una pila los números de legajo de los alumnos mayores de edad.
            mostrarListaAlumnos(archStruct);
            pasarAPilaLegajosMayEdad(archStruct, &p);
            break;
        case 8:
            // 8- Dado un archivo de alumnos, hacer una función que cuente la cantidad de alumnos mayores a edad específica que se envía por parámetro.
            mostrarListaAlumnos(archStruct);
            printf("Ingrese una edad a buscar: ");
            checkNum(&buscado);
            sumarMayoresAedadBuscada(archStruct, buscado);
        case 9:
            // 9- Dado un archivo de alumnos, mostrar por pantalla el nombre de todos los alumnos entre un rango de edades específico (por ejemplo, entre 17 y 25 años). Dicho rango debe recibirse por parámetro. Modularizar
            while (num <= 0)
            {
                printf("Por favor ingrese num 1: ");
                checkNum(&num);
            }

            while (num2 < num)
            {
                printf("Por favor ingrese num 2 (mayor al primero): ");
                checkNum(&num2);
            }
            mostrarPorRangoEdad(archStruct, num, num2);
            break;
        case 10:
            // 10- Dado un archivo de alumnos, mostrar los datos del alumno de mayor edad. Modularizar.
            mostrarAluMayorEdad(archStruct);
            break;
        case 11:
            // 11- Crear una función que retorne la cantidad de alumnos que cursan un determinado año. El año buscado se pasa por parámetro.
            printf("Ingrese anio a buscar: ");
            checkNum(&num);
            num2 = mostrarCantAlumnosCursandoXanio(archStruct, num);
            if (num2 > 0)
            {
                printf("Cantidad de alumnos cursando ese anio: %i", num2);
            }
            break;
        case 12:
            // 12- Crear una función que reciba como parámetro un arreglo de tipo alumno y lo copie en el archivo.
            // cargarArrayStructAl(lista, &validos);
            // Asimismo, realice otra función que pase los elementos del archivo a un arreglo de alumnos, filtrando los estudiantes de un año en particular.

            break;
        case 13:
            // 13-Crear una función que retorne la cantidad de registros que tiene el archivo. Usar fseek y ftell. Puede pensar la función para uso genérico, que sirva para averiguar la cantidad de registros de cualquier archivo.
            printf("Queres saber la cantidad de reg de un archivo de enteros o de struct?\n1-Archivos.\n2-Int\nIngrese la opcion: ");
            fflush(stdin);
            scanf("%d", &opcion);
            if (opcion == 1)
            {
                num = cantRegGenerico(archStruct, sizeof(stAlumno));
            }
            else
            {
                num = cantRegGenerico(archInt, sizeof(int));
            }
            printf("%i", num);
            break;
        case 14:
            // 14- Dado un archivo de alumnos, que tenga al menos 10 registros, hacer una función que muestre el contenido de un registro, cuyo número (entre 0 y 9) se pase por parámetro. Controlar no sobrepasar los límites del archivo.

            break;
        case 15:
            // 15- Realice una (o varias) funciones que permitan modificar un registro existente en el archivo de alumnos. La misma debe permitir modificar uno o todos los campos de la estructura y sobreescribir el registro existente en el archivo.

            break;
        case 16:
            // 16- Dado un archivo de alumnos, hacer una función que invierta los elementos del mismo. No se puede usar otro archivo auxiliar ni un arreglo auxiliar. Debe trabajar sobre el archivo. Puede utilizar variables de tipo alumno auxiliares.

            break;
        default:
            printf("\n\tError, no ha ingresado una opcion valida.\n");
            break;
        }
        printf("\n\tDesea continuar ejecutando el programa? s/n: ");
        fflush(stdin);
        scanf("%c", &continuar);
        system("cls");
    } while (continuar == 's' || continuar == 'S');

    return 0;
}

// funcion que chequea que se ingrese un numero entero
void checkNum(int *aChequear)
{
    int validacion;
    char str[20];
    do
    {
        fflush(stdin);
        gets(str);
        validacion = atoi(str);
        if (validacion == 0)
        {
            printf("Error. Ingrese nuevamente el numero: ");
        }

    } while (validacion == 0);
    *aChequear = validacion;
}

// funcion para cargar un entero a un archivo, sobreescribiendo si había algo cargado
void cargarINTySobreescribir(char ARCH_INT[])
{
    FILE *fp;
    int num;
    printf("Ingrese numero al archivo: ");
    checkNum(&num);

    fp = fopen(ARCH_INT, "wb");
    if (fp != NULL)
    {
        fwrite(&num, sizeof(int), 1, fp);
        fclose(fp);
    }
    else
    {
        printf("Fallo la apertura del archivo.\n");
    }
}

// carga un entero al final de un archivo
void cargarINTalFinal(char nomArch[])
{
    FILE *fp;
    int num;
    printf("Ingrese numero al archivo: ");
    checkNum(&num);

    fp = fopen(nomArch, "ab");
    if (fp != NULL)
    {
        fwrite(&num, sizeof(int), 1, fp);
        fclose(fp);
    }
    else
    {
        printf("Fallo la apertura del archivo.\n");
    }
}

// muestra un archivo de numeros
void mostrarArchivoNumeros(char archStruct[TAM_MAX])
{
    int num;
    int i = 0;
    FILE *fp;
    fp = fopen(archStruct, "rb");
    if (fp != NULL)
    {
        while ((fread(&num, sizeof(int), 1, fp)) > 0)
        {
            printf("numero #%i: %i\n", i + 1, num);
            i++;
        }
        fclose(fp);
    }
    else
    {
        printf("Fallo la apertura del archivo.\n");
    }
}

// 3- Hacer una función que retorne la cantidad de registros que contiene un archivo.
int cantRegistrosInt(char archInt[TAM_MAX])
{

    int cantidad = 0, num;
    FILE *buffer;
    buffer = fopen(archInt, "rb");
    if (buffer != NULL)
    {
        fseek(buffer, 0, SEEK_END);
        cantidad = ftell(buffer) / sizeof(int);
        fclose(buffer);
    }
    else
    {
        printf("Fallo la apertura del archivo.\n");
    }
    return cantidad;
}

// cargaUNalumno
void cargarAlumno(stAlumno *a)
{
    fflush(stdin);
    printf("Ingrese legajo del alumno: ");
    checkNum(&(a)->legajo);

    printf("Ingrese nombre y apellido del alumno: ");
    fflush(stdin);
    gets(a->nombreYapellido);

    printf("Ingrese edad del alumno: ");
    fflush(stdin);
    checkNum(&(a)->edad);
    while (a->edad <= 10 || a->edad >= 160)
    {
        printf("Ingrese nuevamente (de 10 en adelante): ");
        checkNum(&(a)->edad);
    }

    printf("Ingrese anio del alumno(de 1 a 6): ");
    fflush(stdin);
    checkNum(&(a)->anio);
    while (a->anio > 6 || a->anio <= 0)
    {
        printf("Ingrese nuevamente (de 1 a 6): ");
        checkNum(&(a)->anio);
    }
}

// carga una lista de alumnos y sobreescribe
void cargarListaAlumnosYsobreesc(char archStruct[TAM_MAX])
{
    FILE *fp;
    char continuar;
    int validos = 0;
    stAlumno alumnoNuevo;
    fp = fopen(archStruct, "wb");
    if (fp != NULL)
    {

        do
        {
            fflush(stdin);
            printf("- - - - - - - - - - - - Alumno #%i- - - - - - - - - - - - - -\n ", validos + 1);
            cargarAlumno(&alumnoNuevo);
            fwrite(&alumnoNuevo, sizeof(stAlumno), 1, fp);
            printf("Desea agregar otro alumno? s/n: ");
            fflush(stdin);
            scanf("%c", &continuar);
            printf("\n");
            validos++;
        } while ((validos < TAM_MAX) && (continuar == 's' || continuar == 'S'));
        fclose(fp);
    }
    else
    {
        printf("Fallo la apertura del archivo.\n");
    }
}

// carga una lista de alumnos sin sobreescribir
void cargarListaAlumnos(char archStruct[TAM_MAX])
{
    FILE *fp;
    char continuar;
    int validos = 0;
    stAlumno alumnoNuevo;
    fp = fopen(archStruct, "ab");

    if (fp != NULL)
    {
        do
        {
            fflush(stdin);
            printf("Alumno #%i: ", validos);
            cargarAlumno(&alumnoNuevo);
            fwrite(&alumnoNuevo, sizeof(stAlumno), 1, fp);
            printf("Desea agregar otro alumno? s/n: ");
            fflush(stdin);
            scanf("%c", &continuar);
            validos++;
        } while ((validos < TAM_MAX) && (continuar == 's' || continuar == 'S'));

        fclose(fp);
    }
}

// muestra UN alumno
void mostrarAlumno(stAlumno a)
{
    printf("\nLegajo del alumno: %i\n", a.legajo);
    printf("Nombre y apellido del alumno: %s\n", a.nombreYapellido);
    printf("Edad del alumno: %i\n", a.edad);
    printf("Anio del alumno: %i\n", a.anio);
}

// muestra la lista de alumnosS
void mostrarListaAlumnos(char archStruct[TAM_MAX])
{
    FILE *fp;
    stAlumno al;

    fp = fopen(archStruct, "rb");
    if (fp != NULL)
    {
        while ((fread(&al, sizeof(stAlumno), 1, fp)) > 0)
        {
            mostrarAlumno(al);
        }

        fclose(fp);
    }
}

// carga alumnos a un archivo sin sobreescribir
void cargaAlumnosNoSobreesc(char archStruct[TAM_MAX])
{
    FILE *fp;
    stAlumno al;
    fp = fopen(archStruct, "ab");
    if (fp != NULL)
    {
        cargarAlumno(&al);
        fwrite(&al, sizeof(stAlumno), 1, fp);
        fclose(fp);
    }
    else
    {
        printf("Fallo la apertura del archivo.\n");
    }
}

// devuelve la cantidad de structs dentro de un archivo
int cantRegistrosStructs(char archStruct[TAM_MAX])
{
    int cantidad = 0;
    FILE *buffer;
    buffer = fopen(archStruct, "rb");
    if (buffer != NULL)
    {
        fseek(buffer, 0, SEEK_END);
        cantidad = ftell(buffer) / sizeof(stAlumno);
        fclose(buffer);
    }
    else
    {
        printf("Fallo la apertura del archivo.\n");
    }
    return cantidad;
}

void pasarAPilaLegajosMayEdad(char archStruct[TAM_MAX], Pila *p)
{
    FILE *fp;
    fp = fopen(archStruct, "rb");
    stAlumno al;
    if (fp != NULL)
    {
        while ((fread(&al, sizeof(stAlumno), 1, fp)) > 0)
        {
            if (al.edad >= 18)
            {
                apilar(p, al.legajo);
            }
        }

        if (!pilavacia(p))
        {
            mostrar(p);
        }

        fclose(fp);
    }
    else
    {
        printf("Fallo la apertura del archivo.\n");
    }
}

void sumarMayoresAedadBuscada(char archStruct[], int buscado)
{
    int suma = 0;
    FILE *fp;
    fp = fopen(archStruct, "rb");
    stAlumno al;

    if (fp != NULL)
    {
        while (((fread(&al, sizeof(stAlumno), 1, fp)) > 0))
        {
            if (al.edad > buscado)
            {
                suma++;
            }
        }

        printf("Suma: %i", suma);
        fclose(fp);
    }
}

void mostrarPorRangoEdad(char archStruct[TAM_MAX], int num1, int num2)
{
    FILE *fp;
    fp = fopen(archStruct, "rb");
    stAlumno al;
    int i = 0;

    if (fp != NULL)
    {
        while (((fread(&al, sizeof(stAlumno), 1, fp)) > 0))
        {
            if ((al.edad >= num1) && (al.edad <= num2))
            {
                printf("\n\n- - - - - - - - - - - - Alumno #%i- - - - - - - - - - - - - -\n ", i + 1);
                printf("\tNombre del alumno: %s", al.nombreYapellido);
                i++;
                printf("\n");
            }
        }
        fclose(fp);
    }
    else
    {
        printf("Fallo la apertura del archivo.\n");
    }
}

int buscarAlumnoPorEdadYmostrar(char archStruct[TAM_MAX], int edad)
{
    FILE *fp;
    stAlumno al;
    int encontrado = -1, i = 0;

    fp = fopen(archStruct, "rb");
    if (fp != NULL)
    {
        while ((fread(&al, sizeof(stAlumno), 1, fp)) > 0)
        {
            if (al.edad == edad)
            {
                encontrado = i;
                mostrarAlumno(al);
            }
            i++;
        }
        fclose(fp);
    }

    return encontrado;
}

void mostrarAluMayorEdad(char archStruct[TAM_MAX])
{
    FILE *fp;
    stAlumno al;
    fp = fopen(archStruct, "rb");
    int i = 0, mayorEdad = 0;

    if (fp != NULL)
    {
        while ((fread(&al, sizeof(stAlumno), 1, fp)) > 0)
        {
            if (i == 0)
            {
                mayorEdad = i;
            }
            if (al.edad > mayorEdad)
            {
                mayorEdad = al.edad;
            }

            i++;
        }

        printf("Alumno con la mayor edad: ");
        buscarAlumnoPorEdadYmostrar(archStruct, mayorEdad);

        fclose(fp);
    }
}

int mostrarCantAlumnosCursandoXanio(char archStruct[TAM_MAX], int anioBuscado)
{
    FILE *fp;
    stAlumno al;
    int i = 0;

    fp = fopen(archStruct, "rb ");
    if (fp != NULL)
    {
        while ((fread(&al, sizeof(stAlumno), 1, fp)) > 0)
        {
            if (al.anio == anioBuscado)
            {
                i++;
            }
        }
        fclose(fp);
    }
    if (i > 0)
    {
        return i;
    }
    else
    {
        printf("No se han encontrado alumnos cursando ese anio. \n");
    }
}

// void cargarArrayStructAl(stAlumno li[TAM_MAX], int *validos)
// {
//     char continuar;
//     stAlumno nuevo;
//     int i = *validos;

//     do
//     {
//         cargarAlumno(&nuevo);
//         insercionOrdenada(li, i, nuevo);
//         printf("Desea agregar otra persona? s/n: ");
//         fflush(stdin);
//         scanf("%c", &continuar);
//         i++;
//     } while ((i < TAM_MAX) && (continuar == 's' || continuar == 'S'));

//     *validos = i;
// }

// void insercionOrdenada(stAlumno listaAlumnos[], int validos, stAlumno alumno)
// {
//     int i = validos - 1;
//     while (i >= 0 && (listaAlumnos[i].legajo > alumno.legajo))
//     {
//         listaAlumnos[i + 1] = listaAlumnos[i];
//         i--;
//     }
//     validos++;
//     listaAlumnos[i + 1] = alumno;
// }

// void mostrarListaArray()
// {

// }

int cantRegGenerico(char nombreArch[TAM_MAX], int tamanio)
{
    int cantidad = 0;
    FILE *buffer;
    buffer = fopen(nombreArch, "rb");
    if (buffer != NULL)
    {
        fseek(buffer, 0, SEEK_END);
        cantidad = ftell(buffer) / tamanio;
        fclose(buffer);
    }
    else
    {
        printf("Fallo la apertura del archivo.\n");
    }
    return cantidad;
}
