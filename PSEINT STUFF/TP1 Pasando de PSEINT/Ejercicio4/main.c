#include <stdio.h>
#include <stdlib.h>

int main()
////Suponga que un individuo desea invertir su capital en un banco y desea saber cuanto dinero ganar� despu�s de un mes
//si el banco paga a raz�n de 2% mensual.
//Mismo que el inciso 3, pero preguntando los meses de inversi�n.

{
	 float capitalInicial,porcentajeGanancias,gananciasTotales,cantidadMeses;
    capitalInicial=0;
	porcentajeGanancias=0;
	cantidadMeses=0;
	gananciasTotales=0;

//pido al usuario ingresar los datos importantes
printf ("Ingrese cuanto desea invertir $");
scanf("%f", &capitalInicial);

printf ("Ingrese la cantidad de meses que desea invertir: ");
scanf("%f", &cantidadMeses);

printf ("Ingrese el porcentaje de ganancias, por favor: ");
scanf("%f", &porcentajeGanancias);

//calculo sus ganancias totales y se las muestro
gananciasTotales = (capitalInicial  * porcentajeGanancias) * cantidadMeses;

printf("Sus ganancias serian de $%.2f, desea continuar con la operacion?\n",gananciasTotales);

system("pause");
return 0;

}
