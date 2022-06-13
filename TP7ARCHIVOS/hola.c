#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM_MAX 30
typedef struct
{
    int legajo;
    char nombreYapellido[30];
    int edad;
    int anio;

} stAlumnos;

void cargarAlumno(stAlumnos *);
void cargarListaAlumnosYsobreesc(char[TAM_MAX]);
void mostrarArchivo(stAlumnos p, int validos);

int main()
{
    stAlumnos p;
    stAlumnos arregloAlumnos[10];
    FILE *fp;
    int validos = 0;
    char arch[] = {"Archivo3.bin"};
    cargarListaAlumnosYsobreesc(arch);
    mostrarArchivo(p, validos);
    system("pause");
}

void cargarAlumno(stAlumnos *a)
{
    fflush(stdin);
    printf("Ingrese legajo del alumno: ");
    scanf("%i", &(a)->legajo);

    printf("Ingrese nombre y apellido del alumno: ");
    fflush(stdin);
    gets(a->nombreYapellido);

    printf("Ingrese edad del alumno: ");
    fflush(stdin);
    scanf("%i", &(a)->edad);
    while (a->edad <= 10 || a->edad >= 160)
    {
        printf("Ingrese nuevamente (de 10 en adelante): ");
        scanf("%i", &(a)->edad);
    }

    printf("Ingrese anio del alumno(de 1 a 6): ");
    fflush(stdin);
    scanf("%i", &(a)->anio);
    while (a->anio > 6 || a->anio <= 0)
    {
        printf("Ingrese nuevamente (de 1 a 6): ");
        scanf("%i", &(a)->anio);
    }
}

// carga una lista de alumnos y sobreescribe
void cargarListaAlumnosYsobreesc(char archStruct[TAM_MAX])
{
    FILE *fp;
    char continuar;
    int validos = 0;
    stAlumnos alumnoNuevo;
    fp = fopen(archStruct, "wb");
    if (fp != NULL)
    {

        do
        {
            fflush(stdin);
            printf("- - - - - - - - - - - - Alumno #%i- - - - - - - - - - - - - -\n ", validos + 1);
            cargarAlumno(&alumnoNuevo);
            fwrite(&alumnoNuevo, sizeof(stAlumnos), 1, fp);
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

void mostrarUnAlumno(stAlumnos p)
{
    printf("LEGAJO: %i \n", p.legajo);
    printf("NOMBRE Y APELLIDO: %s \n", p.nombreYapellido);
    printf("EDAD: %i \n", p.edad);
    printf("ANIO: %i \n\n", p.anio);
}

void mostrarArchivo(stAlumnos p, int validos)
{
    FILE *fp;
    int i = 0;
    fp = fopen("Archivo3.bin", "rb");
    if (fp != NULL)
    {

        while ((fread(&p, sizeof(stAlumnos), 1, fp)) > 0)
        {

            mostrarUnAlumno(p);
        }
        fclose(fp);
    }
    else
    {
        printf("No se pudo abrir el archivo. \n");
    }
}