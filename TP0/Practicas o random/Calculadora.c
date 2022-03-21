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
    printf("5 - Cuadrado del primer numero\n");
    printf("6 - Cuadrado del segundo numero\n");
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
    case 5:
        resultado = numeroUno * numeroUno;
        break;
    case 6:
        resultado = numeroDos * numeroDos;
        break;
    default:
        printf("\t \tOpcion invalida.\t\n");
        break;
    }
    if (opcion < 7)
    {
        printf("\nEl resultado es: %d \n", resultado);
    }

    system("pause");

    return 0;
}