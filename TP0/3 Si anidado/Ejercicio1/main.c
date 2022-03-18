#include <stdio.h>
#include <stdlib.h>
// Leer 2 números; si son iguales que los multiplique,
// si el primero es mayor que el segundo que los reste y si no que los sume.

int main()
{
    int numeroUno = 0, numeroDos = 0, resultado = 0;

    printf("Dame dos numeros enteros, por favor\n");
    scanf("%d", &numeroUno);
    scanf("%d", &numeroDos);

    if (numeroUno != numeroDos && numeroUno > numeroDos)
    {
        resultado = numeroUno - numeroDos;
        printf("\t %d - %d = %d \n", numeroUno, numeroDos, resultado);
    }
    else if (numeroUno == numeroDos)
    {
        resultado = numeroUno * numeroDos;
        printf("\t %d * %d = %d \n", numeroUno, numeroDos, resultado);
    }
    else
    {
        resultado = (numeroDos + numeroUno);
        printf("\t %d + %d = %d \n", numeroDos, numeroUno, resultado);
    }

    system("pause");
    return 0;
}
