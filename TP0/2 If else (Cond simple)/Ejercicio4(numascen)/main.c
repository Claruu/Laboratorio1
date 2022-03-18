#include <stdio.h>
#include <stdlib.h>
// Desarrolle un algoritmo que lea dos números y los imprima en forma ascendente
int main()
{
    int numerouno, numerodos;

    printf("Por favor ingrese dos numeros diferentes: \n");
    scanf("%i", &numerouno);
    scanf("%i", &numerodos);

    if (numerouno > numerodos)
    {
        printf("Tu primer numero es mas grande, asi que va primero.");
        printf("\nNumero grande: %i\n   Numero chico: %i \n", numerouno, numerodos);
    }

    else if (numerouno < numerodos)
    {
        printf("Ya que tu segundo numero es mas grande, va primero: \n");
        printf("\n  Numero grande: %i\n     Numero chico: %i \n", numerodos, numerouno);
    }

    else
    {
        printf("\nLe pedi dos numeros distintos.\n");
        printf("\n");
    }

    system("pause");
    return 0;
}
