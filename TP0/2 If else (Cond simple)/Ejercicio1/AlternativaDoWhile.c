#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Determinar si un alumno aprueba a reprueba un curso, sabiendo que aprobara si
    // su promedio de tres calificaciones es mayor o igual a 7;reprueba en caso contrario.

    float promedio = 0, notaIngresada = 1, sumaNotas = 0;
    int cantNotas = 0;
    printf("Programa para calcular promedios.\n");
    system("color 0b");
    printf("\nPara calcular el promedio, ingrese algun numero negativo. \n Ausente = 0 (cuenta en el promedio)\n");
    do
    {
        printf("\n Ingrese la nota %d: ", cantNotas + 1);
        scanf("\n%f", &notaIngresada);

        do
            if (notaIngresada > 10)
            {
                printf("\n  Incorrecto. Por favor ingrese un numero del 0 al 10. \n");
                printf("\n Ingrese la nota %d: ", cantNotas + 1);
                scanf("\n %f", &notaIngresada);
            }
        while (notaIngresada > 10 || notaIngresada < 0);

        if (notaIngresada >= 0)
        {
            cantNotas++;
            sumaNotas += notaIngresada;
        }

    } while (notaIngresada >= 0 && cantNotas < 3);

    if (cantNotas <= 0)
    {
        printf("No se han ingresado notas.\n");
        return 1;
    }

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