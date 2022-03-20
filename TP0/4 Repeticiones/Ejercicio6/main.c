#include <stdio.h>
#include <stdlib.h>
// Calcular e imprimir la tabla de multiplicar de un número cualquiera.
// Imprimir el multiplicando, el multiplicador y el producto.

int main()
{
    int numero, multiplicador, producto, limite, contador;

    printf("\tTabla multiplicar\t");

    printf("\nIngrese un numero para saber su tabla de multiplicar\n");
    scanf("%d", &numero);
    printf("Hasta que numero debe de llegar la tabla:\n");
    scanf("%d", &limite);

    for (contador = 0; contador <= limite; contador++)
    {
        producto = numero * contador;
        if (contador >= 1)
        {
            printf(" %d *  %d  = %d\n", numero, contador, producto);
        }
    }

    system("pause");
    return 0;
}
