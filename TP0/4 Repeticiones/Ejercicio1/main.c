#include <stdio.h>
#include <stdlib.h>
// Calcular el promedio de un alumno que tiene 7 calificaciones en la materia de Programación 1
int main()
{
    float nota = 0, promedio = 0, indice = 0, sumaNota = 0;
    printf("\tSistema de calculo de promedios. \n      Se promedia entre 7 calificaciones.\t");
    while (indice < 7)
    {
        indice++;
        printf("\nIngrese una calificacion, por favor: ");
        scanf("%f", &nota);
        sumaNota += nota;
    }
    promedio = sumaNota / indice;
    printf("Su promedio es de: %.2f \n", promedio);

    system("pause");
    return 0;
}
