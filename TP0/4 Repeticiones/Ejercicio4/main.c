#include <stdio.h>
#include <stdlib.h>
// Leer 15 números negativos y convertirlos en positivos e imprimir dichos números.

int main()
{
    int numero = 0, contador = 0;
    printf("     Programa para pasar numeros negativos a positivos\t \n");
    while (contador < 15)
    {
        contador++;
        printf("\nIngrese el numero negativo #%d:\n", contador);
        scanf("%d", &numero);
        if (numero < 0)
        {
            numero = numero * (-1);
            printf("Como positivo seria: %d\n", numero);
        }
    }

    system("pause");
    return 0;
}
