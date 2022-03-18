#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Determinar si un alumno aprueba a reprueba un curso, sabiendo que aprobara si
    // su promedio de tres calificaciones es mayor o igual a 7;reprueba en caso contrario.

    float promedio = 0, notaIngresada = 1, sumaNotas = 0;
    int cantNotas = 0;
    printf("Programa para calcular promedios.\n");
    printf("\nPara calcular el promedio, ingrese algun numero negativo. \n Ausente = 0 (cuenta en el promedio)\n");
    do
    {
        printf("\n Ingrese la nota %d: ", cantNotas + 1);
        scanf("\n%f", &notaIngresada);

        if (notaIngresada >= 0 && notaIngresada <= 10)
        {
            cantNotas++;
            sumaNotas += notaIngresada;
        }
        else
        {
            printf("La nota debe ser del 0 al 10 :<\n");
        }

    } while (cantNotas < 3);

    promedio = (float)(sumaNotas / cantNotas);
    printf("\nSu promedio es de: %.2f ", promedio);

    if (promedio > 8)
    {
        printf("\nUsted ha promocionado la materia \n");
    }
    else if (promedio >= 7)
    {
        printf("\nUsted aprueba la materia \n");
    }
    else
    {
        printf("\nUsted ha desaprobado la materia, que decepcion, eh! \n");
    }
    system("pause");
    return 0;
}