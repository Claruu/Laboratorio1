#include <stdio.h>
#include <stdlib.h>

int
main ()
{
  //Suponga que un individuo desea invertir su capital en un banco
  //y desea saber cuanto dinero ganarA despues de un mes, si el banco paga a razon de 2% mensual.

//Declaro e inicializo mis variables como float
  float gananciasTotales = 0;
  float porcentajeGanancias = 0.02;
  float capitalInicial = 0;

  printf ("Porcentaje de Interes = 2 \nPor favor ingrese el capital del que dispone: $");
  scanf ("%f", &capitalInicial);

//hago el c�lculo necesario, le muestro al usuario el resultado
  gananciasTotales = capitalInicial * porcentajeGanancias;

  printf ("Sus ganancias al invertir serian de: $%.2f",gananciasTotales);

  system("pause");
  return 0;

}
