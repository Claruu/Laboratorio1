#include <stdio.h>
#include <stdlib.h>
// Un obrero necesita calcular su salario semanal, el cual se obtiene de la sig.manera :
// Si trabaja 40 horas o menos se le paga $300 por hora Si trabaja más de 40 horas
// se le paga $300 por cada una de las primeras 40 horas y $400 por cada hora extra.int main()
int main()

{
    float salarioBase, salarioFinal, salarioExtra, horasTrabajadas, pagaBase, pagaExtra, horasExtra, limiteHoras;
    pagaBase = 300;
    pagaExtra = 400;
    horasExtra = 0;
    limiteHoras = 40;
    salarioExtra = (limiteHoras * 300);

    printf("\nPor favor, ingrese las horas que trabajo esta semana:\n");
    scanf("%f", &horasTrabajadas);

    if (horasTrabajadas <= limiteHoras)
    {
        salarioBase = (horasTrabajadas * pagaBase);
        printf("\nEsta semana, al trabajar %.2f", horasTrabajadas);
        printf(" horas, usted cobra $%.2f\n\n", salarioBase);
    }
    else
    {
        salarioBase = limiteHoras * pagaBase;
        salarioBase = (horasTrabajadas - limiteHoras) * pagaExtra;
        salarioFinal = (salarioBase + salarioExtra);
        printf("\nEsta semana, ya que trabajaste %.2f", horasTrabajadas);
        printf(" horas, cobraras $%.2f\n\n", salarioFinal);
    }
    system("pause");
    return 0;
}