#include <stdio.h>
#include <stdlib.h>
// Leer 10 números y obtener su cubo y su cuarta.

int main()
{
    int numeroOrig = 0, numero = 0, contador = 0;

    while (contador < 10)
    {
        contador++;
        printf("\nPor favor ingrese el numero #%d: ", contador);
        scanf("%d", &numeroOrig);
        if (numeroOrig == 0 || numeroOrig == 1)
        {
            printf("Che como que este ya es obvio,no? Porque no intentas con otro la prox?");
        }
        numero = numeroOrig * numeroOrig * numeroOrig;
        printf("\nCubo de tu numero: %d", numero);
        numero = numero * numeroOrig;
        printf("\nCuarta de tu numero: %d\n", numero);
    }

    system("pause");
    return 0;
}
