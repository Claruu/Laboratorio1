#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM_MAX 30
#define NOM_ARCH "ejercicios.bin"

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
    printf("\tMenu TP 7: Archivos\n");
    printf("Opcion 1: Agrega un elemento al final de un archivo.\n");
    printf("Opcion 2: Muestra por pantalla el contenido de un archivo.\n");
    printf("Opcion 3: Muestra la cantidad de registros que contiene un archivo.\n");
    printf("Opcion 4: Carga un archivo de alumnos con 5 datos.\n");
    printf("Opcion 5: Muestra los registros de un archivo de alumnos.\n");
    printf("Opcion 6: Agrega un elemento al final de un archivo cargado con alumnos.\n");
    // printf("Opcion 7: Pasa a una pila los numeros de legajo de los alumnos mayores de edad.\n");
    // printf("Opcion 8: Cuenta la cantidad de alumnos mayores a la edad que le pidas.\n");
    // printf("Opcion 9: Muestra el nombre de los alumnos en el rango de edad que uno le pida.\n");
    // printf("Opcion 10: Muestra los datos del alumno de mayor edad cargado en un archivo de alumnos.\n");
    // printf("Opcion 11: Muestra la cantidad de alumnos que cursan el anio que uno le pida.\n");
    // printf("Opcion 12: Copia el arreglo de tipo alumno que uno le pasa por parametro a un archivo. Tambien pasa los elementos de ese archivo a un arreglo de alumnos, filtrando los estudiantes de cierto anio.\n");
    // printf("Opcion 13: Muestra la cantidad de registros que tiene un archivo.\n");
    // printf("Opcion 14: Con un archivo de 10 alumnos, muestra el contenido de un registro.\n");
    // printf("Opcion 15: Modifica un registro existente en el archivo de alumnos. Puede modificar uno o todos los campos de la estructura, y puede sobreescribir el registro existente en el archivo.\n");
    // printf("Opcion 16: Invierte los elementos de un archivo de alumnos.\n");
}
void seleccionOpciones(int *);

void checkNum(int *);

// 1- Hacer una función que agregue un elemento al final de un archivo.
void cargarElementoYsobreescribir();
void cargarElementoAlFinal();
void cargarVariosElementosAlFinal();

// 2- Hacer una función que muestre por pantalla el contenido de un archivo.
void mostrarArchivoNumeros(int);

// 3- Hacer una función que retorne la cantidad de registros que contiene un archivo.
int cantidadRegistrosEnArchivo();

// carga Alumno
void cargarAlumno(stAlumno *);
void cargarListaAlumnos(stAlumno *, int *);
void mostrarAlumno(stAlumno);

int main()
{
    FILE fp;
    char continuar;
    int opcion = 0, eleccionCarga = 0, num, i = 0, validos;
    stAlumno a;

    do
    {
        printf("\tMenu 1 TP Archivos\n");

        while (opcion != 1 && opcion != 2)
        {
            printf("Desea cargar: \n1-Numero Entero.\n2-Estructura de alumnos.\nIngrese la opcion que desee a continuacion: ");
            checkNum(&opcion);
            system("cls");
        }

        if (opcion == 1) // se cargan numeros enteros
        {
            while (eleccionCarga != 1 && eleccionCarga != 2)
            {
                system("cls");
                printf("Por favor ingrese la opcion que desea.\n1-Cargar y sobreescribir.\n2-Cargar al final.\n");
                checkNum(&eleccionCarga);
            }

            if (eleccionCarga == 1)
            {
                cargarElementoYsobreescribir();
            }
            else if (eleccionCarga == 2)
            {

                cargarElementoAlFinal();
            }
        }
        else
        { // se carga struct alumnos
            system("cls");
            cargarAlumno(&a);
            mostrarAlumno(a);
        }

        printf("Desea ir al segundo menu y a los ejercicios? s/n: ");
        fflush(stdin);
        scanf("%c", &continuar);
    } while (continuar == 'n' || continuar == 'N');

    fflush(stdin);

    do
    { // 0- Hacer una función principal que pruebe el funcionamiento de todos los incisos anteriores, con un menú de opciones para poder ejecutar todas las funciones requeridas. Tengan presente la correcta declaración y el ámbito de variables.
        mostrarOpciones();
        printf("Ingrese una opcion: ");
        checkNum(&opcion);
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
                cargarElementoYsobreescribir();
            }
            else if (eleccionCarga == 2)
            {

                cargarElementoAlFinal();
            }
            break;
        case 2:
            // 2- Hacer una función que muestre por pantalla el contenido de un archivo.
            mostrarArchivoNumeros(num);
            break;
        case 3:
            // 3- Hacer una función que retorne la cantidad de registros que contiene un archivo.
            i = cantidadRegistrosEnArchivo(num);
            printf("Cantidad de registros en su archivo: %i\n", i);
            break;
        case 4:
            // 4- Crear una función que cargue un archivo de alumnos. Abrirlo de manera tal de verificar si el archivo ya está creado previamente. Cargar el archivo con 5 datos. Cerrarlo dentro de la función

            break;
        case 5:
            // 5- Crear una función que muestre por pantalla los registros de un archivo de alumnos. Modularizar.

            break;
        case 6:
            // 6- Crear una función que permita agregar de a un elemento al final del archivo. O sea, se debe abrir el archivo, se piden los datos (se llena una variable de tipo struct alumno), se escribe en el archivo y se cierra.

            break;
        case 7:
            // 7- Crear una función que pase a una pila los números de legajo de los alumnos mayores de edad.

            break;
        case 8:
            // 8- Dado un archivo de alumnos, hacer una función que cuente la cantidad de alumnos mayores a edad específica que se envía por parámetro.
        case 9:
            // 9- Dado un archivo de alumnos, mostrar por pantalla el nombre de todos los alumnos entre un rango de edades específico (por ejemplo, entre 17 y 25 años). Dicho rango debe recibirse por parámetro. Modularizar

            break;
        case 10:
            // 10- Dado un archivo de alumnos, mostrar los datos del alumno de mayor edad. Modularizar.

            break;
        case 11:
            // 11- Crear una función que retorne la cantidad de alumnos que cursan un determinado año. El año buscado se pasa por parámetro.

            break;
        case 12:
            // 12- Crear una función que reciba como parámetro un arreglo de tipo alumno y lo copie en el archivo. Asimismo, realice otra función que pase los elementos del archivo a un arreglo de alumnos, filtrando los estudiantes de un año en particular.

            break;
        case 13:
            // 13-Crear una función que retorne la cantidad de registros que tiene el archivo. Usar fseek y ftell. Puede pensar la función para uso genérico, que sirva para averiguar la cantidad de registros de cualquier archivo.

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
        printf("Desea continuar? s/n: ");
        fflush(stdin);
        scanf("%c", &continuar);
        system("cls");
    } while (continuar == 's' || continuar == 'S');

    return 0;
}

void checkNum(int *aChequear)
{
    int validacion;
    char str[20];
    do
    {
        gets(str);
        validacion = atoi(str);
        if (validacion == 0)
        {
            printf("Error. Ingrese nuevamente el numero: ");
        }

    } while (validacion == 0);
    *aChequear = validacion;
}

void cargarElementoYsobreescribir()
{
    FILE *fp;
    int num;
    printf("Ingrese numero al archivo: ");
    checkNum(&num);

    fp = fopen(NOM_ARCH, "wb");
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

void cargarElementoAlFinal()
{
    FILE *fp;
    int num;
    printf("Ingrese numero al archivo: ");
    checkNum(&num);

    fp = fopen(NOM_ARCH, "ab");
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
void mostrarArchivoNumeros(int num)
{
    int i = 0;
    FILE *fp;
    fp = fopen(NOM_ARCH, "rb");
    if (fp != NULL)
    {
        while ((fread(&num, sizeof(int), 1, fp)) > 0)
        {
            printf("numero #%i: %i\n", i + 1, num);
            i++;
        }
        fclose(fp);
    }
}

// 3- Hacer una función que retorne la cantidad de registros que contiene un archivo.
int cantidadRegistrosEnArchivo()
{
    int cantidad = 0, num;
    FILE *buffer;
    buffer = fopen(NOM_ARCH, "rb");
    if (buffer != NULL)
    {
        fseek(buffer, 0, SEEK_END);
        cantidad = ftell(buffer) / sizeof(int);
        fclose(buffer);
    }
    return cantidad;
}

void cargarAlumno(stAlumno *a)
{
    fflush(stdin);
    printf("Ingrese legajo del alumno: ");
    checkNum(&(a)->legajo);

    printf("Ingrese nombre y apellido del alumno: ");
    fflush(stdin);
    gets(a->nombreYapellido);

    printf("Ingrese edad del alumno: ");
    checkNum(&(a)->edad);

    printf("Ingrese anio del alumno: ");
    checkNum(&(a)->anio);
}

void mostrarAlumno(stAlumno a)
{
    printf("\nLegajo del alumno: %i\n", a.legajo);
    printf("Nombre y apellido del alumno: %s\n", a.nombreYapellido);
    printf("Edad del alumno: %i\n", a.edad);
    printf("Anio del alumno: %i\n", a.anio);
}

// int busquedaBinaria(int arreglo[], int validos, int X)
// {
//     int medio, pri, ult, enc;
//     enc = 0;           /// Asumo que no lo encontré
//     pri = 0;           /// primer índice será el 0
//     ult = validos - 1; /// inicializo con el último índice válido de mi arreglo
//     medio = (pri + ult) / 2;
//     /// Partimos el arreglo a la mitad
//     while ((pri < ult) && (X != arreglo[medio])) /// si todavía índice pri no se cruzó con ult y no encontré X
//     {
//         if (X < arreglo[medio]) /// el valor buscado es menor
//         {
//             ult = medio - 1; /// descarto la mitad derecha del arreglo
//         }
//         else /// el valor buscado es mayor
//         {
//             pri = medio + 1; /// descarto la mitad izquierda
//         }
//         medio = (pri + ult) / 2; /// vuelvo a partir a la mitad
//     }
//     if (X == arreglo[medio]) /// si lo encontré cambio enc a“verdadero” enc = 1;
//         return enc;
// }