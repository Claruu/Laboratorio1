#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Se necesita saber el promedio de las notas de un estudiante del curso formalizaci�n de algoritmos, el mismo rindi� 3 parciales.
//declaro e inicializo variables
    float parcialUno = 0, parcialDos = 0, parcialTres = 0, sumaNumero = 0, promedio = 0, cantNotas = 3;

//luego, le pido al usuario que ingrese qu� n�meros desea sumar
    printf("Ingrese los numeros a sumar\n");
    scanf ("%f",&parcialUno);
    scanf ("%f",&parcialDos);
    scanf ("%f",&parcialTres);

//declaro que suma numero es igual a la suma de los parciales
    sumaNumero = parcialUno + parcialDos + parcialTres;

    promedio = sumaNumero / cantNotas;

    printf("Tu promedio es de %f",promedio);
    
    system("pause");
    return 0;
}
