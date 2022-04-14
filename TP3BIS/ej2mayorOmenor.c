#include <stdio.h>
#include <stdlib.h>
// Diseñe una función que reciba 3 números enteros y muestre el mayor y el menor.
void mayorOmenor(int, int, int);
void buscarMenor(int, int, int);
void buscarMayor(int, int, int);

int main()
{
    int numero1 = 0, numero2 = 0, numero3 = 0;
    printf("Ingrese 3 numeros para calcular el mayor y el menor.\n");
    scanf("%d", &numero1);
    scanf("%d", &numero2);
    scanf("%d", &numero3);
    mayorOmenor(numero1, numero2, numero3);
    system("pause");
    return 0;
}

void buscarMayor(int num1, int num2, int num3)
{
    int mayor;

    if (num1 > num2 && num1 > num3)
    {
        mayor = num1;
    }
    else if (num2 > num3)
    {
        mayor = num2;
    }
    else
    {
        mayor = num3;
    }
    printf("Tu numero mayor es: %d\n", mayor);
}
void buscarMenor(int num1, int num2, int num3)
{
    int menor = 0;
    if (num1 < num2 && num1 < num3)
    {
        menor = num1;
    }
    else if (num2 < num3)
    {
        menor = num2;
    }
    else
    {
        menor = num3;
    }
    printf("Tu numero menor es: %d \n", menor);
}

void mayorOmenor(int num1, int num2, int num3)
{
    buscarMenor(num1, num2, num3);
    buscarMayor(num1, num2, num3);
}