#include <stdio.h>
#include <stdlib.h>
#define TAM_MAX 20

void CargarNotasAlumno(float notaParcial1[], float notaParcial2[], int dni[], int *validos, int rta);
void PrintNotas(float notaParcial1[], float notaParcial2[], int dni[], int validos);
void insercionDesordenado(int dni[], float nota1[], float nota2[], int validos, int DNI, float notaParcial1, float notaParcial2);
void insercionOrdenado(int dni[], float nota1[], float nota2[], int validos, int DNI, float notaParcial1, float notaParcial2);
int BusquedaDNIDesordenado(int dni[], int validos, int DNI);
int BusquedaDNIOrdenado(int dni[], int validos, int DNI);
void MostrarNotasPosicion(float nota1[], float nota2[], int validos, int posicion);
void MensajeDeAprobacionParcial(int dni[], float nota1[], float nota2[], int validos);
void PromedioDNI(int dni[], float nota1[], float nota2[], int validos);
void PromocionMateria(int dni[], float nota1[], float nota2[], int validos);
int NotaMaxima(float nota1[], int validos);

int main()
{
    float notasParcial1[TAM_MAX];
    float notasParcial2[TAM_MAX];
    int dnis[20];
    int validos = 0, rta, posicion, dni, valor;
    printf("Como quieres cargar a los alumnos:\n1 - Desordenados.\n2 - Ordenados.");
    scanf("%i", &rta);
    CargarNotasAlumno(notasParcial1, notasParcial2, dnis, &validos, rta);
    PrintNotas(notasParcial1, notasParcial2, dnis, validos);
    printf("Ingrese un DNI para verificar: ");
    scanf("%i", &dni);
    switch (rta)
    {
    case 1:
        posicion = BusquedaDNIDesordenado(dnis, validos, dni);
        if (posicion == -1)
            printf("El DNI no se encontro.");
        else
            printf("El DNI se posiciona en: %i", posicion);
        break;
    case 2:
        posicion = BusquedaDNIOrdenado(dnis, validos, dni);
        if (posicion == -1)
            printf("El DNI no se encontro.");
        else
            printf("El DNI se posiciona en: %i", posicion);
        break;
    default:
        printf("Opcion incorrecta. \n");
    }
    printf("Ingrese el dni del que desea ver sus notas.");
    scanf("%i", &valor);
    MostrarNotasPosicion(notasParcial1, notasParcial2, validos, valor);
    MensajeDeAprobacionParcial(dnis, notasParcial1, notasParcial2, validos);
    PromedioDNI(dnis, notasParcial1, notasParcial2, validos);
    PromocionMateria(dnis, notasParcial1, notasParcial2, validos);
    posicion = NotaMaxima(notasParcial1, validos);
    printf("La nota mas alta esta en la posicion %i y la nota es: %i", posicion, dnis[posicion]);
    return 0;
}
void CargarNotasAlumno(float notaParcial1[], float notaParcial2[], int dni[], int *validos, int rta)
{
    int DNI;
    float nota1;
    float nota2;
    char ctrl;
    do
    {
        printf("Ingrese dni: ");
        scanf("%i", &DNI);
        printf("Ingrese nota del primer parcial: ");
        scanf("%f", &nota1);
        printf("Ingrese nota del segundo parcial: ");
        scanf("%f", &nota2);
        if (rta == 1)
            insercionDesordenado(dni, notaParcial1, notaParcial2, *validos, DNI, nota1, nota2);
        else
            insercionOrdenado(dni, notaParcial1, notaParcial2, *validos, DNI, nota1, nota2);
        (*validos)++;
        printf("Desea seguir:");
        fflush(stdin);
        scanf("%c", &ctrl);
    } while ((ctrl == 'S' || ctrl == 's') && (*validos) < TAM_MAX);
}
void PrintNotas(float notaParcial1[], float notaParcial2[], int dni[], int validos)
{
    for (int i = 0; i < validos; i++)
    {
        printf("Notas del alumno.\n");
        printf("Nota 1: %f\n", notaParcial1[i]);
        printf("Nota 2: %f\n", notaParcial2[i]);
        printf("DNI: %i\n", dni[i]);
        printf("----------------\n");
    }
}
/*1. Crear una funci�n que los cargue de manera ordenada(por dni), hasta que el usuario
lo decida.*/
void insercionOrdenado(int dni[], float nota1[], float nota2[], int validos, int DNI, float notaParcial1, float notaParcial2)
{
    int i = validos - 1;
    while (i >= 0 && dni[i] > DNI)
    {
        dni[i + 1] = dni[i];
        nota1[i + 1] = nota1[i];
        nota2[i + 1] = nota2[i];
        i--;
    }
    dni[i + 1] = DNI;
    nota1[i + 1] = notaParcial1;
    nota2[i + 1] = notaParcial2;
}
/*2. Crear una funci�n que los cargue de manera desordenada, hasta que el usuario lo
decida.*/
void insercionDesordenado(int dni[], float nota1[], float nota2[], int validos, int DNI, float notaParcial1, float notaParcial2)
{
    int i = validos;
    dni[i] = DNI;
    nota1[i] = notaParcial1;
    nota2[i] = notaParcial2;
}
/*3. Crear una funci�n que busque dentro del arreglo de dnis un dni determinado y
retorne la posici�n ( Si no se encuentra retornar -1). (considerar que si se hizo una
inserci�n ordenada la b�squeda es con consideraci�n ORDENADA, de lo contrario
es una b�squeda en un arreglo DESORDENADO)*/
int BusquedaDNIDesordenado(int dni[], int validos, int DNI)
{
    int rta = -1;
    if (validos != 0)
    {
        printf("Iniciando Busqueda...");
        for (int i = 0; i < validos; i++)
        {
            if (dni[i] == DNI)
            {
                rta = i;
            }
        }
    }
    else
    {
        printf("El arreglo de DNI esta vacio.");
    }
    return rta;
}
int BusquedaDNIOrdenado(int dni[], int validos, int DNI)
{
    int rta = -1, i = 0;
    if (validos != 0)
    {
        printf("Iniciando Busqueda...");
        while (i < validos && dni[i] != DNI)
        {
            i++;
        }
        if (i < validos)
        {
            rta = i;
        }
    }
    else
    {
        printf("El arreglo de DNI esta vacio.");
    }
    return rta;
}
/*4. Hacer una funci�n que muestre las notas del primer y segundo parcial, recibiendo
como par�metro la posici�n.*/
void MostrarNotasPosicion(float nota1[], float nota2[], int validos, int posicion)
{
    int i = 0;
    while (i < validos)
    {
        if (i == posicion)
        {
            printf("Nota primer parcial: %.2f", nota1[i]);
            printf("Nota segunto parcial: %.2f", nota2[i]);
        }
    }
    if (i == validos)
    {
        printf("No se encontro el usuario, no esta esa posicion.\n");
    }
}
/*5. Hacer una funci�n que muestre cada dni y un mensaje �DESAPROBADO� para
aquellos que desaprobaron solo un parcial (nota menor a 6) y para aquellos que
desaprobaron ambos debe mostrar la palabra �RECURSA�.*/
void MensajeDeAprobacionParcial(int dni[], float nota1[], float nota2[], int validos)
{
    for (int i = 0; i < validos; i++)
    {
        if (nota1[i] < 6 && nota2[i] < 6)
        {
            printf("El alumno %i, RECURSA con ambos parciales desaprobados.", dni[i]);
            if (nota1[i] < 6)
            {
                printf("El alumno %i, DESAPROBO el parcial 1.", dni[i]);
            }
            else
            {
                printf("El alumno %i, APROBO el parcial 1.", dni[i]);
            }
            if (nota2[i] < 6)
            {
                printf("El alumno %i, DESAPROBO el parcial 2.", dni[i]);
            }
            else
            {
                printf("El alumno %i, APROBO el parcial 2.", dni[i]);
            }
        }
        else
        {
            printf("El alumno %i, APROBO ambos parciales.\n", dni[i]);
        }
    }
}
/*6. Hacer una funci�n que muestre la nota promedio de cada dni.*/
void PromedioDNI(int dni[], float nota1[], float nota2[], int validos)
{
    float promedio;
    for (int i = 0; i < validos; i++)
    {
        promedio = 0;
        promedio = (nota1[i] + nota2[i]) / 2;
        printf("DNI: %i", dni[i]);
        printf("Nota 1: %.2f", nota1[i]);
        printf("Nota 2: %.2f", nota2[i]);
        printf("Promedio: %.2f", promedio);
    }
}
/*7. Hacer una funci�n que muestre todos los dni que promocionaron la materia. Se promociona
con un promedio de 8.*/
void PromocionMateria(int dni[], float nota1[], float nota2[], int validos)
{
    float promedio;
    for (int i = 0; i < validos; i++)
    {
        promedio = 0;
        promedio = (nota1[i] + nota2[i]) / 2;
        if (promedio >= 8)
        {
            printf("DNI: %i", dni[i]);
            printf("Nota 1: %.2f", nota1[i]);
            printf("Nota 2: %.2f", nota2[i]);
            printf("Promedio: %.2f", promedio);
        }
    }
}
/*8. Hacer una funci�n que busque la m�xima nota obtenida en el primer parcial y
retorne la posici�n, luego en el main informar el dni que obtuvo esa m�xima nota.*/
int NotaMaxima(float nota1[], int validos)
{
    int i = 0, notamax = 0, posicion;
    while (i < validos)
    {
        notamax = nota1[i];
        if (notamax < nota1[i + 1])
        {
            notamax = nota1[i + 1];
            posicion = i + 1;
        }
    }
    return posicion;
}
/*9. Hacer una funci�n que retorne la posici�n del mejor promedio (m�ximo promedio) de
los 2 parciales. Luego en el main informar que dni obtuvo ese promedio.*/

/*10. Hacer una funci�n que muestre la nota promedio total.*/

/*11. Hacer una funci�n que pase a una pila aquellos DNIS que obtuvieron un promedio
mayor a 7.*/

/*12. Hacer una funci�n que reciba la pila de DNIS y retorne la cantidad de datos
almacenada.*/
