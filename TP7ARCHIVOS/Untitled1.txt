void CargaUnAlumno(Alumno *DatoAlumno)
{
    printf("\tLEGAJO: ");
    scanf("%i", &(*DatoAlumno).Legajo);
    printf("\tNOMBRE Y APELLIDO: ");
    fflush(stdin);
    gets((*DatoAlumno).NombreApellido);
    printf("\tEDAD: ");
    scanf("%i", &(*DatoAlumno).Edad);
    printf("\tANIO: ");
    scanf("%i", &(*DatoAlumno).Anio);
}
void CargaListaAlumno(char NombreArchivo[])
{
    FILE *arch;
    Alumno DatoAlumno;
    int i = 0;
    char ctrl;
    arch = fopen(NombreArchivo, "ab");
    if (arch != NULL)
    {
        do
        {
            CargaUnAlumno(&DatoAlumno);
            fwrite(&DatoAlumno, sizeof(Alumno), 1, arch);
            printf("Desea continuar? <s/n>: ");
            fflush(stdin);
            scanf("%c", &ctrl);
        } while (ctrl == 's' && i < CANT_MAX);

        fclose(arch);
    }
}
void MostrarAlumno(Alumno DatoAlumno)
{
    puts("----------------------------------");
    printf("\tLEGAJO: %i\n", DatoAlumno.Legajo);
    printf("\tNOMBRE: %s\n", DatoAlumno.NombreApellido);
    printf("\tEDAD: %i\n", DatoAlumno.Edad);
    printf("\tANIO: %i\n", DatoAlumno.Anio);
    puts("----------------------------------");
}
void MostrarListaAlumno(char NombreArchivo[])
{
    FILE *arch;
    Alumno DatoAlumno;
    arch = fopen(NombreArchivo, "rb");
    if (arch != NULL)
    {
        while (fread(&DatoAlumno, sizeof(Alumno), 1, arch) > 0)
        {
            MostrarAlumno(DatoAlumno);
        }
        fclose(arch);
    }
}
void AgregarUnAlumnoAlFinal(Alumno ListaAlumno[], int *validos, char NombreArchivo[])
{
    FILE *arch;
    Alumno DatoAlumno;
    arch = fopen(NombreArchivo, "ab");
    if (arch != NULL)
    {
        CargaUnAlumno(&DatoAlumno);
        fwrite(&DatoAlumno, sizeof(Alumno), 1, arch);
        fclose(arch);
    }
}

void CargaUnAlumno(stAlumno *al)
{
    printf("\tLEGAJO: ");
    scanf("%i", &(*al).Legajo);
    printf("\tNOMBRE Y APELLIDO: ");
    fflush(stdin);
    gets((*al).NombreApellido);
    printf("\tEDAD: ");
    scanf("%i", &(*al).Edad);
    printf("\tANIO: ");
    scanf("%i", &(*al).Anio);
}
void CargaListaAlumno(char Nombrefpivo[])
{
    FILE *fp;
    stAlumno al;
    int i = 0;
    char ctrl;
    fp = fopen(Nombrefpivo, "ab");
    if (fp != NULL)
    {
        do
        {
            CargaUnAlumno(&al);
            fwrite(&al, sizeof(Alumno), 1, fp);
            printf("Desea continuar? <s/n>: ");
            fflush(stdin);
            scanf("%c", &ctrl);
        } while (ctrl == 's' && i < CANT_MAX);

        fclose(fp);
    }
}
void MostrarAlumno(stAlumno al)
{
    puts("----------------------------------");
    printf("\tLEGAJO: %i\n", al.Legajo);
    printf("\tNOMBRE: %s\n", al.NombreApellido);
    printf("\tEDAD: %i\n", al.Edad);
    printf("\tANIO: %i\n", al.Anio);
    puts("----------------------------------");
}
void MostrarListaAlumno(char NombreArchivo[])
{
    FILE *fp;
    stAlumnoal;
    fp = fopen(Nombrefpivo, "rb");
    if (fp != NULL)
    {
        while (fread(&al, sizeof(Alumno), 1, fp) > 0)
        {
            MostrarAlumno(al);
        }
        fclose(fp);
    }
}
void AgregarUnAlumnoAlFinal(stAlumno ListaAlumno[], int *validos, char NombreArchivo[])
{
    FILE *fp;
    stAlumnoal;
    fp = fopen(Nombrefpivo, "ab");
    if (fp != NULL)
    {
        CargaUnAlumno(&al);
        fwrite(&al, sizeof(Alumno), 1, fp);
        fclose(fp);
    }
}