#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Una tienda ofrece un descuento del 15% sobre el total de la compra y
    // un cliente desea saber cuánto deberá pagar finalmente por su compra.

    float descuento = 0, compra = 0;

    printf("Usted originalmente iba a pagar: $");
    scanf("%f", &compra);

    descuento = compra * 0.15;
    compra -= descuento;

    printf("Aplicado el descuento, pagara: $%.2f\n", compra);

    system("pause");
    return 0;
}
