#include <stdio.h>
#include <stdlib.h>
// Realice una pequeña calculadora, utilizando funciones (una función de suma, una de multiplicación, una de resta, una de división…)

void tabla(int, int);
void suma(int, int);
void resta(int, int);
void division(int, int);
void menu();

int main()
{
    menu();
    system("pause");
    return 0;
}

void menu()
{
    int opcion = 0;
    int numeroUno, numeroDos;
    char continuar = 's';

    do
    {
        printf("\tCalculadora:\nIngrese un numero: ");
        scanf("%d", &numeroUno);
        printf("Segundo numero: ");
        scanf("%d", &numeroDos);

        printf("\n1-Suma.\n2-Resta.\n3-Multiplicacion.\n4-Division:\n");
        printf("Ingrese la opcion a elegir (entre 1 y 4): \n");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            suma(numeroUno, numeroDos);
            break;
        case 2:
            resta(numeroUno, numeroDos);
            break;
        case 3:
            tabla(numeroUno, numeroDos);
            break;
        case 4:
            division(numeroUno, numeroDos);
            break;
        default:
            printf("Usted no ha ingresado una opcion valida.");
            break;
        }
        fflush(stdin);
        printf("\nDesea continuar utilizando la calculadora?\nIngrese s para continuar: ");
        scanf("%c", &continuar);
    } while (opcion > 0 && opcion < 5 && continuar == 's' || continuar == 'S');
}

void tabla(int numeroUno, int numeroDos)
{
    int producto;
    producto = numeroUno * numeroDos;
    printf("%d * %d = %d \n", numeroUno, numeroDos, producto);
}
void suma(int numeroUno, int numeroDos)
{
    int producto = numeroUno + numeroDos;
    printf("El resultado de su suma es de %d \n", producto);
}

void resta(int numeroUno, int numeroDos)
{
    int producto = numeroUno - numeroDos;
    printf("El resultado de su resta es de %d \n", producto);
}

void division(int numeroUno, int numeroDos)
{
    if (numeroDos == 0)
    {
        printf("Error, no se puede dividir por cero");
        return;
    }
    int producto = numeroUno / numeroDos;

    printf("El resultado de su division es de %d \n", producto);
}