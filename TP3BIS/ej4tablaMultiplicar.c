#include <stdio.h>
#include <stdlib.h>
// Desarrollar una función que muestre la tabla de multiplicar de un número entero recibido por parámetro. void tabla(int)

// muestra la tabla de multiplicar de un numero entero
void tabla(int *, int *);

int main()
{
    int limite = 0, numero = 0; // declaro e inicializo variables

    // pido al usuario los datos necesarios
    printf("\nIngrese un numero para saber su tabla de multiplicar\n");
    scanf("%d", &numero);

    printf("Hasta que numero debe de llegar la tabla:\n");
    scanf("%d", &limite);

    tabla(&numero, &limite); // llamada a la funcion tabla para que me muestre lo que hace

    system("pause");
    return 0;
}

// contenido de la funcion previamente prototipada arriba
void tabla(int *numero, int *limite)
{
    int producto, contador; // declaro variables usadas en el entorno tabla

    for (contador = 0; contador <= *limite; contador++)
    { // inicializo el ciclo for para que funcione hasta el numero que quiera el usuario

        producto = *numero * contador; // declaro para que sirve el producto

        // si el contador es mayor o igual a 1, entra al ciclo, sino sigue iterando
        if (contador >= 1)
        {
            printf(" %d *  %d  = %d\n", *numero, contador, producto);
        }
    }
}