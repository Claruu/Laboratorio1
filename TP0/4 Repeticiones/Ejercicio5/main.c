#include <stdio.h>
#include <stdlib.h>
#define CANT 40
/*Suponga que se tiene un conjunto de calificaciones de un grupo de 40 alumnos.
Realizar un algoritmo para calcular la calificación promedio y
la calificación más baja de todo el grupo.*/

int main()
{
    float nota = 0, notaBaja = 11, promedio = 0;

    for (int indice = 0; indice < CANT; indice++)
    {
        printf("Ingrese la nota %d: ", indice);
        scanf("%f", &nota);

        if (nota > 10 || nota < 0)
        {
            indice--;
            continue;
        }
        else
        {
            promedio += nota;
        }

        if (notaBaja > nota)
        {
            notaBaja = nota;
        }
    }

    promedio = (float)(promedio / CANT);
    printf("Promedio: %2.f\n", promedio);
    printf("Nota mas baja: %2.f\n", notaBaja);

    system("pause");
    return 0;
}
