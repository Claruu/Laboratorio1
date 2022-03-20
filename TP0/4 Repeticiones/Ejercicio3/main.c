#include <stdio.h>
#include <stdlib.h>
// Leer 10 números e imprimir solamente los números positivos

int main()
{
    int numero = 0, contador = 0;

    while (contador < 10)
    {
        contador++;
        printf("Ingrese el numero #%d:\n", contador);
        scanf("%d", &numero);

        if (numero > 0)
        {
            printf("\nNumero positivo!:%d \n", numero);
        }
    }

    return 0;
}
