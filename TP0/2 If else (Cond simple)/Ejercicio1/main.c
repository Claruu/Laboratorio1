#include <stdio.h>
#include <stdlib.h>
// Determinar si un alumno aprueba a reprueba un curso, sabiendo que aprobara si
//  su promedio de tres calificaciones es mayor o igual a 7;reprueba en caso contrario.

int main()
{
    // primero que nada, declaro e inicializo las variables
    float parcialUno = 0, parcialDos = 0, parcialTres = 0, sumaNumero = 0, promedio = 0;

    // luego, le pido al usuario que ingrese qu� n�meros desea sumar
    printf("Ingrese los numeros a sumar:\n");
    scanf("%f", &parcialUno);
    scanf("%f", &parcialDos);
    scanf("%f", &parcialTres);

    // declaro que suma numero es igual a la suma de los parciales
    sumaNumero = parcialUno + parcialDos + parcialTres;

    promedio = sumaNumero / 3;

    if (promedio >= 7)
    {
        printf("\nAlumno, ya que su promedio es de %.2f:", promedio);
        printf("\nUsted aprueba la materia :D \n");
    }
    else
    {
        printf("\nAlumno, ya que su promedio es de %.2f:", promedio);
        printf("\nUsted reprueba la materia :c \n");
    }

    system("pause");
    return 0;
}