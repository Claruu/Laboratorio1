#include <stdio.h>
#include <stdlib.h>
////2. Leer tres números diferentes e imprimir el número mayor de los tres.

int main()
{
    int numeroUno = 0, numeroDos = 0, numeroTres = 0;

    printf("Por favor, ingrese un numero: \n");
    scanf("%d", &numeroUno);
    scanf("%d", &numeroDos);
    scanf("%d", &numeroTres);

    if (numeroUno == numeroDos && numeroDos == numeroTres)
    {
        printf("Tus numeros son todos iguales \n");
    }
    else if (numeroUno > numeroDos && numeroUno > numeroTres)
    {
        printf("Tu primer numero es el mayor\n", numeroUno);
    }
    else if (numeroDos > numeroTres)
    {
        printf("Tu segundo numero es el mayor\n", numeroDos);
    }
    else
    {
        printf("Tu tercer numero es el mayor\n", numeroTres);
    }

    system("pause");
    return 0;
}
