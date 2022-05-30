#include <stdio.h>
#include <stdlib.h>
#define NOM_ARCH "Miarchivo.bin"
#define CANT_MAX 20

/**
Para trabajar con archivos existe un intermediario
 FILE* fp ///intermediario
 En el se setea  toda la informacion acerca del archivo que abrimos
TIPOS DE ARCHIVOS
 CON FORMATO - TEXTO - son una ristra de caracteres
 SIN FORMATO - BINARIOS - son una ristra de 1s y 0s -> Con este vamos a trabajar nosotros
TIPOS DE ACCESO
- Secuencial -> leo dato a dato hasta llegar al buscado o a la posicion buscada
- Directo -> Accedo directamente a una posicion del archivo moviendome una secuencia de bytes
FUNCIONES DE CONTROL
    FILE* fopen(RUTA,MODO); --> nos devuelve un puntero a file si se logra abrir de lo contrario NULL
       /// si no especifico una ruta, la ruta directa es la del proyecto
       ///de lo contrario ... C://MiCarpeta/OtraCarpeta/Miarchivo.bin debo especificar la ruta completa
    MODOS DE APERTURA
        ESCRITURA
        - wb -> write binary -> Modo escritura, si no existe el archivo, lo crea. situa el puntero al inicio asi que BORRA la informacion que tengamos ya escrita,
        - ab -> append binary -> Modo escritura, si no  existe el archivo, lo crea. situa el puntero al final del archivo para luego añadir datos.
        LECTURA
        - rb -> read binary -> Modo lectura, si no existe, NO LO CREA
   int fclose(FILE* fp) -> Cierra el archivo correctamente, devuelve 0 si se cerro de manera correcta de lo contrario -1
FUNCIONES DE ESCRITURA/LECTURA
    int fwrite(ubicacion de la variable que queremos escribir, tamano del tipo de dato de mi variable, la cantidad de datos, FILE*);
    int fread(ubicacion de mi variable, tamano del tipo de dato a leer, cantidad de datos de ese tipo, FILE*); -> me devuelve cantidad de bytes leidos
**/

/// prototipado
void cargaArreglo(int[], int *);

void cargaArreglo(int arreglo[], int *validos)
{
    char continuar;
    int i = *validos; /// quiero que comience desde la posicion validos
    do
    {
        printf("Ingrese un numero entero\n");
        scanf("%i", &arreglo[i]);
        printf("Desea continuar\n");
        fflush(stdin);
        scanf("%c", &continuar);
        i++;
    } while (i < CANT_MAX && continuar == 's');

    *validos = i;
}

void muestraArreglo(int arreglo[], int validos)
{
    for (int i = 0; i < validos; i++)
    {
        printf("%i ", arreglo[i]);
    }
}

int main()
{
    /// MODO ESCRITURA
    FILE *fp; /// Manejador del archivo /// handler /// intermediario
    int numerito = 3;
    fp = fopen("Miarchivo.bin", "wb");
    if (fp != NULL) /// la apertura de archivo fue exitosa
    {
        fwrite(&numerito, sizeof(int), 1, fp);
        fclose(fp);
    }
    else
        printf("Fallo la apertura del archivo");

    /// MODO LECTURA
    FILE *fp;
    int numerito;
    fp = fopen(NOM_ARCH, "rb");
    if (fp != NULL)
    {
        fread(&numerito, sizeof(int), 1, fp);
        fclose(fp);
        printf("numerito: %i", numerito);
    }
    // 3 10 Pedro

    /// Escribir una ristra de datos
    FILE *fp;
    int numerito = 10;
    char nombre[20] = "Pedro";
    fp = fopen(NOM_ARCH, "ab"); /// añadir al final del archivo datos

    if (fp != NULL)
    {
        fwrite(&numerito, sizeof(int), 1, fp);
        fwrite(&nombre, sizeof(char), 20, fp);
        fclose(fp);
    }

    // 3 10 Pedro
    /// Lectura de una ristra de datos
    FILE *fp;
    int numerito;
    int otronumero;
    char nombre[20];
    fp = fopen(NOM_ARCH, "rb");
    if (fp != NULL)
    {
        fread(&numerito, sizeof(int), 1, fp);
        fread(&otronumero, sizeof(int), 1, fp);
        fread(&nombre, sizeof(char), 20, fp);
        fclose(fp);

        printf("numerito: %i\n", numerito);
        printf("otronumero: %i\n", otronumero);
        puts(nombre);
    }

    /// Escritura de un arreglo de enteros
    FILE *fp;
    int arreglo[20];
    int validos = 0;
    cargaArreglo(arreglo, &validos);
    fp = fopen("OtroArchivo.bin", "ab");
    if (fp != NULL)
    {
        fwrite(&arreglo, sizeof(int), validos, fp);
        fclose(fp);
    }

    /// Lectura de un arreglo de enteros
    FILE *fp;
    int arreglo[20];
    int validos;
    int i = 0;
    fp = fopen("OtroArchivo.bin", "rb");
    if (fp != NULL)
    {
        while (fread(&arreglo[i], sizeof(int), 1, fp) > 0) /// me lee dato a dato hasta no leer mas nada
        {
            i++;
        }

        fclose(fp);

        validos = i;
        muestraArreglo(arreglo, validos);
    }

    return 0;
}