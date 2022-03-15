#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Un maestro desea saber qué porcentaje de hombres y que
    // porcentaje de mujeres hay en un grupo de estudiantes.

    int hombres = 0, mujeres = 0;
    float totalAlumnos = 0, porHombres = 0, porMujeres = 0;

    printf("Ingrese cuantas mujeres hay en su clase:");
    scanf("%i", &mujeres);

    printf("Ingrese cuantos hombres hay en su clase:");
    scanf("%i", &hombres);

    totalAlumnos = mujeres + hombres;
    porHombres = (float)((hombres / totalAlumnos) * 100);
    porMujeres = (float)((mujeres / totalAlumnos) * 100);

    printf("En su clase, el porcentaje de mujeres es de: %.2f \n", porMujeres);
    printf("En su clase, el porcentaje de hombres es de: %.2f \n", porHombres);

    system("pause");
    return 0;
}
