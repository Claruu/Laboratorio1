#include <stdio.h>
#include <stdlib.h>

int main()
{
    int alumnes = 0, alumnasM = 0;
    float porcentaje = 0;

    printf("Por favor, ingrese la cantidad de alumnos: ");
    scanf("%d", &alumnes);

    printf("\nCantidad de alumnos mujeres: ");
    scanf("%d", &alumnasM);

    porcentaje = (float)(alumnasM * 100) / alumnes; // totalAlumnos * alumh/100

    printf("\nPorcentaje de mujeres: %.2f%% \n ", porcentaje);
    printf("\nPorcentaje de hombres: %.2f%%\n", 100 - porcentaje);

    system("pause");
    return 0;
}
