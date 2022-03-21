#include <stdio.h>
#include <stdlib.h>

int main()
{
    //1)Se necesita sumar dos n�meros le�dos desde el teclado (los ingresa el usuario) y mostrar el resultado por pantalla.

//primero, declaro las variables y las inicializo en 0
    int num1 = 0;
    int num2 = 0;
    int sumaNumero = 0;

//luego, le pido al usuario que ingrese qu� n�meros desea sumar
    printf("Ingrese los numeros a sumar\n");
    scanf ("%d",&num1);
    scanf ("%d",&num2);
//declaro que suma numero es igual a la suma de num1 y num2
    sumaNumero = num1 + num2;

//imprimo en pantalla los n�meros que me ha pasado el usuario, y le muestro el resultado en la misma l�nea
    printf("%d + %d = ", num1, num2);
    printf("%d",sumaNumero);

    system("pause");
    return 0;
}
