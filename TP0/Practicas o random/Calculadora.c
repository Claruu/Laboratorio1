#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numeroUno, numeroDos, opcion, resultado;

    printf("Dame dos numeros enteros, por favor\n");
    scanf("%d", &numeroUno);
    scanf("%d", &numeroDos);
    printf("\tMenu de opciones\t");
    printf("\n1 - Suma");
    printf("\n2 - Resta");
    printf("\n3 - Multiplicacion");
    printf("\n4 - Division\n");
    printf("\nPor favor seleccione que operacion desea realizar: ");
    scanf("%d", &opcion);

    switch (opcion)
    {
    case 1:
        resultado = numeroUno + numeroDos;
        break;
    case 2:
        resultado = numeroUno - numeroDos;
        break;
    case 3:
        resultado = numeroUno * numeroDos;
        break;
    case 4:
        resultado = numeroUno / numeroDos;
        break;
    default:
        printf("\t \tOpcion invalida.\t\n");
        break;
    }
    while (opcion < 5)
    {
        printf("\nEl resultado es: %d \n", resultado);
    }

    system("pause");

    return 0;
}
//

//     if (numeroUno != numeroDos && numeroUno > numeroDos)
//     {
//         resultado = numeroUno - numeroDos;
//         printf("\t %d - %d = %d \n", numeroUno, numeroDos, resultado);
//     }
//     else if (numeroUno == numeroDos)
//     {
//         resultado = numeroUno * numeroDos;
//         printf("\t %d * %d = %d \n", numeroUno, numeroDos, resultado);
//     }
//     else
//     {
//         resultado = (numeroDos + numeroUno);
//         printf("\t %d + %d = %d \n", numeroDos, numeroUno, resultado);
//     }
