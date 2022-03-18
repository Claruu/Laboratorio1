#include <stdio.h>
#include <stdlib.h>
// Calcular el promedio de un alumno que tiene 7 calificaciones en la materia de Programación 1
int main()
{
    float nota = 0, promedio = 0, indice = 0, sumaNota = 0;
    printf("Por favor ingrese calificaciones\n");
    while (indice < 3)
    {
        indice++;
        printf("Ingrese calificacion");
        scanf("%f", &nota);
        sumaNota += nota;
    }
    promedio = sumaNota / indice;
    printf("promedio: %.2f \n", promedio);

    system("pause");
    return 0;
}
