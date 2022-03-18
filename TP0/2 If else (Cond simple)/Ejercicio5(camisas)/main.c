#include <stdio.h>
#include <stdlib.h>

// hacer un algoritmo que calcule el total a pagar por la compra de camisas. sI SE COMPORAN TRES CAMISAS O
// MAS SE APLICA UN DESCUENTO DEL 20% SOBRE EL TOTAL DE LA COMPRA Y SI SON MENOS DE 3 CAMISAS UN DESCUENTO DEL 10%

int main()
{
    int camisas;
    float descuento, totalCompra = 0;
    printf("\n Por favor ingrese el total de su compra: \n");
    scanf("%f", &totalCompra);

    printf("\n Ahora, ingrese cuantas camisas ha comprado con ese dinero:\n");
    scanf("%i", &camisas);

    if (camisas >= 3)
    {
        printf("Se le realizara un descuento del 20%% \n");
        descuento = (totalCompra * 0.8);
    }
    else if (camisas < 3)

    {
        printf("\nUsted no califica para el descuento del 20%%, le haremos uno del 10%%");
        descuento = (totalCompra * 0.9);
    }

    printf("\n Con el descuento aplicado, usted pagaria: %.2f\n", descuento);
    system("pause");
    return 0;
}
