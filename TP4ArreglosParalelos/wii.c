#include <stdio.h>
#include <stdlib.h>
#define TAM_MAX 10
//

int main()
{
    int array[TAM_MAX];
    int indice = 0, suma = 0, validos = 0, j = 0;
    char continuar = 's';

    do
    {
        printf("Ingrese un dato al array numerico: ");
        scanf("%d", &array[indice]);
        printf("Desea continuar? s/n: ");
        fflush(stdin);
        scanf("%c", &continuar);
        indice++;
    } while ((continuar == 's' || continuar == 'S') && (indice < TAM_MAX));
    validos = indice;

    printf("\nSu arreglo: ");
    for (indice = 0; indice < validos; indice++)
    {
        printf("| %i", array[indice]);
    }
    printf("\nIngreso %d elementos validos.\n", validos);

    while (j < validos && array[j] >= 0)
    {
        suma = suma + array[j];
        j++;
    }

    printf("wii: %d", suma);

    system("pause");
    return 0;
}