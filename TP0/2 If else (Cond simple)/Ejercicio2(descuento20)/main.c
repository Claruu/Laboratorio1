#include <stdio.h>
#include <stdlib.h>
// En un almacén se hace un 20% de descuento a los clientes cuya compra supere los $5000
//¿Cuál será la cantidad que pagara una persona por su compra?

int main()
{
    float compraTotal = 0, descuento20 = 20, resultadoDescuento = 0;
    // primero, a definir y dar valor o limpiar las variables.
    printf("          Bienvenido al almacen de los descuentos     ");
    // le doy la bienvenida al usuario y le digo de que se trata el programa
    printf("\nAqui, a los clientes que compren mas de $5000, se les resta el 20 porciento de descuento.\n");
    // le consulto el monto de la compra
    printf("\nDe que monto es su compra?\n$");
    scanf("%f", &compraTotal);
    // condicion fundamental, molto fundamental:
    if (compraTotal >= 5001)
    {
        resultadoDescuento = (descuento20 * compraTotal) / 100;
        compraTotal = compraTotal - resultadoDescuento;
        printf("\nSu compra aplica para el descuento :D");
    }
    // ah, no me iba a olvidar del else e-e
    else if (compraTotal <= 5000)
    {
        printf("\nSu compra no supera los $5000, debera pagar el monto sin descuento :C\n");
    }
    // le digo al cliente cuánto tiene que pagar en la caja
    printf("\n\n            En la caja, usted paga: $%.2f         \n \n", compraTotal);
    system("pause");
    return 0;
}