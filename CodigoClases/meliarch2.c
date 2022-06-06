#include <stdio.h>
#include <stdlib.h>
#define NOM_ARCH "ArchivoPersonas.bin"
#define CANT_MAX 20

typedef struct
{
    char nombre[20];
    char dni[9];
    char telefono[20];
    char o_social[20];
    int edad;
    int baja; /// 1 dado de baja, 0 caso contrario
} Persona;

/// prototipado

/// carga sin orden // a tener en cuenta
/// siempre se anade el nuevo dato al final del  archivo
void altaUnaPersona(Persona, FILE *fp);    /// escribimos una persona en el archivo
void cargaListaPersonas(Persona[], int *); /// secuencial
/// carga con orden /// a tener en cuenta
/// debemos traernos los datos del archivo al arreglo - insertar el dato en el arreglo - persistir el arreglo
void altaUnaPersonaOrdenadaEnArchivo();
void cargaListaPersonasOrdenada(Persona[], int *);
void insercionOrdenada(Persona[], int, Persona);
/// ambas
void cargaPersona(Persona *);
void persistenciaListaPersonas(Persona[], int);      /// guardar la lista en el archivo
void despersistenciaListaPersonas(Persona[], int *); /// traernos del archivo la lista
void mostrarListaPersonas(Persona[], int);
void mostrarUnaPersona(Persona);
/// MODIFICACION
void modificacionRegistro(char[]);
void modificarTelefono(Persona *);
void modificarNombre(Persona *);
/// BAJA
void bajaLogica(char dni[]); /// baja logica de un dato
void mantenimientoArchivo(); /// filtra las personas dadas de baja

/// implementacion

void altaUnaPersonaEnArchivo()
{
    FILE *fp = fopen(NOM_ARCH, "ab");
    Persona p;
    if (fp != NULL)
    {
        cargaPersona(&p);
        fwrite(&p, sizeof(Persona), 1, fp);
        fclose(fp);
    }
}

void altaUnaPersona(Persona p, FILE *fp)
{
    if (fp != NULL)
    {
        fwrite(&p, sizeof(Persona), 1, fp);
    }
}

void cargaListaPersonas(Persona listaPersonas[], int *validos)
{
    char continuar = 's';
    Persona p;
    int i = *validos;
    FILE *fp;
    fp = fopen(NOM_ARCH, "ab");
    while (i < CANT_MAX && continuar == 's')
    {
        cargaPersona(&p);
        listaPersonas[i] = p;
        altaUnaPersona(p, fp);
        i++;
        printf("Desea continuar? \n");
        fflush(stdin);
        scanf("%c", &continuar);
    }
    *validos = i;
}

/// en orden
void cargaListaPersonasOrdenada(Persona listaPersonas[], int *validos)
{
    char continuar;
    Persona p;
    int i = *validos;
    do
    {
        cargaPersona(&p);
        insercionOrdenada(listaPersonas, i, p);
        printf("Desea ingresar otra persona\n");
        fflush(stdin);
        scanf("%c", &continuar);
        i++;

    } while (i < CANT_MAX && continuar == 's');

    *validos = i;
}

void insercionOrdenada(Persona listaPersonas[], int validos, Persona p)
{
    int i = validos - 1;
    while (i >= 0 && strcmp(listaPersonas[i].nombre, p.nombre) > 0)
    {
        listaPersonas[i + 1] = listaPersonas[i];
        i--;
    }

    listaPersonas[i + 1] = p;
}

void altaUnaPersonaOrdenadaEnArchivo()
{
    Persona listaPersonas[CANT_MAX];
    Persona p;
    int validos = 0;
    despersistenciaListaPersonas(listaPersonas, &validos);
    cargaPersona(&p);
    insercionOrdenada(listaPersonas, validos, p);
    persistenciaListaPersonas(listaPersonas, validos);
}

/// ambas

void cargaPersona(Persona *p)
{
    printf("Ingrese Nombre: ");
    fflush(stdin);
    gets((*p).nombre);
    printf("Ingrese DNI: ");
    fflush(stdin);
    gets((*p).dni);
    printf("Ingrese Telefono: ");
    fflush(stdin);
    gets((*p).telefono);
    printf("Ingrese Obra Social: ");
    fflush(stdin);
    gets((*p).o_social);
    printf("Ingrese edad: ");
    scanf("%i", &((*p).edad));
    (*p).baja = 0; /// se setea baja en 0
}

void persistenciaListaPersonas(Persona listaPersonas[], int validos)
{
    FILE *fp;
    fp = fopen(NOM_ARCH, "wb");
    if (fp != NULL)
    {
        fwrite(listaPersonas, sizeof(Persona), validos, fp);
        fclose(fp);
    }
}
/// traer los datos del archivo
void despersistenciaListaPersonas(Persona listaPersonas[], int *validos)
{
    FILE *fp;
    fp = fopen(NOM_ARCH, "rb");
    int i = 0;
    if (fp != NULL)
    {
        while (fread(&listaPersonas[i], sizeof(Persona), 1, fp) > 0)
        {
            if (listaPersonas[i].baja == 0) /// si esta dada de alta
                i++;
        }
        fclose(fp);
        *validos = i;
    }
}

void mostrarUnaPersona(Persona p)
{
    printf("NOMBRE: %s\n", p.nombre);
    printf("DNI: %s\n", p.dni);
    printf("EDAD: %i\n", p.edad);
    printf("TELEFONO: %s\n", p.telefono);
    printf("Obra Social: %s\n", p.o_social);
}

void mostrarListaPersonas(Persona listaPersonas[], int validos)
{
    for (int i = 0; i < validos; i++)
    {
        mostrarUnaPersona(listaPersonas[i]);
        printf("\n");
    }
}

/// modificacion de un registro de archivo
/// modo r+b /// me permite abrir un archivo en modo lectura y escritura

int cantPersonasArchivo()
{
    FILE *fp;
    int cant = 0;
    fp = fopen(NOM_ARCH, "rb");
    if (fp != NULL)
    {
        fseek(fp, 0, SEEK_END);
        cant = ftell(fp) / sizeof(Persona);
    }

    return cant;
}

void modificarTelefono(Persona *p)
{
    printf("Ingrese el nuevo telefono\n");
    fflush(stdin);
    gets((*p).telefono);
}

void modificacionRegistro(char dni[])
{
    FILE *fp;
    fp = fopen(NOM_ARCH, "r+b");
    Persona p;
    int cantPersonas = cantPersonasArchivo();
    int i = 0;
    if (fp != NULL)
    {
        fread(&p, sizeof(Persona), 1, fp);
        while (i < cantPersonas && strcmpi(p.dni, dni) != 0)
        {
            i++;
            fread(&p, sizeof(Persona), 1, fp);
        }
        if (i < cantPersonas)
        {
            modificarTelefono(&p);
            fseek(fp, sizeof(Persona) * (-1), SEEK_CUR);
            fwrite(&p, sizeof(Persona), 1, fp);
        }
        fclose(fp);
    }
}

/// BAJA LOGICA segun un dni
void bajaLogica(char dni[])
{
    FILE *fp;
    fp = fopen(NOM_ARCH, "r+b");
    int cantPersonas = cantPersonasArchivo();
    int i = 0;
    if (fp != NULL)
    {
        fread(&p, sizeof(Persona), 1, fp);
        while (i < cantPersonas && strcmpi(p.dni, dni) != 0)
        {
            i++;
            fread(&p, sizeof(Persona), 1, fp);
        }
        if (i < cantPersonas)
        {
            p.baja = 1; /// doy de baja la persona
            fseek(fp, sizeof(Persona) * (-1), SEEK_CUR);
            fwrite(&p, sizeof(Persona), 1, fp);
        }
        fclose(fp);
    }
}

void mantenimientoArchivo()
{
    Persona listaPersonas[CANT_MAX];
    int validos;
    despersistenciaListaPersonas(listaPersonas, &validos); /// me filtra las dadas de baja
    persistenciaListaPersonas(listaPersonas, validos);     /// reescribe con las personas dadas de alta
}

int main()
{
    Persona listaPersonas[CANT_MAX];
    int validos = 0;
    char dni[9];
    // alta
    //     cargaListaPersonasOrdenada(listaPersonas,&validos);
    //     persistenciaListaPersonas(listaPersonas,validos);
    despersistenciaListaPersonas(listaPersonas, &validos);
    mostrarListaPersonas(listaPersonas, validos);
    /// modificacion
    printf("Ingrese dni de la persona a modificar\n");
    fflush(stdin);
    gets(dni);
    modificacionRegistro(dni);
    despersistenciaListaPersonas(listaPersonas, &validos);
    mostrarListaPersonas(listaPersonas, validos);
    /// baja
    bajaLogica("3452920");
    bajaLogica("3452921");
    bajaLogica("3452923");
    mantenimientoArchivo();

    return 0;
}