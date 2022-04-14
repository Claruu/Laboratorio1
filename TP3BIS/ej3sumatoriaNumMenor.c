#include <stdio.h>
#include <stdlib.h>
// Diseñe una función que reciba un número entero N y realice la suma de los números enteros positivos menores que N y lo retorne. N es un  dato ingresado por el usuario en el main.
int sumaNumerosmenores(int);

int main()
{
    int numi = 0;

    printf("Ingrese un numero para hacer la sumatoria: ");
    scanf("%d", &numi);
    printf("%d \n", sumaNumerosmenores(numi));

    system("pause");
    return 0;
}

int sumaNumerosmenores(int numero)
{
    int suma = 0, i;

    for (i = 0; i < numero; i++)
    {
        suma += i;
    }

    return suma;
}