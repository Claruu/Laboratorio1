#include <stdio.h>
#include <stdlib.h>

int main()
{
// Suponga que un individuo desea invertir su capital en un banco y desea saber
// cuanto dinero ganara despues de un mes si el banco paga a razon de 2% mensual.
float capitalInicial=0, porcentajeMensual=0.02, capitalFinal=0,ganancia=0;

printf("Ingrese el capital a invertir: $");
scanf("%f", &capitalInicial);

ganancia = capitalInicial * porcentajeMensual;

printf("Por lo cual, su ganancia seria de: $%.2f\n",ganancia);

system("pause");
return 0;

}
