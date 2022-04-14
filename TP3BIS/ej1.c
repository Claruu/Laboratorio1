#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Devuelve un numero aleatorio de 0 a 100
int random();

int main()
{
    srand(time(NULL));
    printf("Numero random del 0 al 100: %d \n", random());

    system("pause");
    return 0;
}

int random()
{
    int numerito = rand() % 101;
    return numerito;
}
// Desarrollar una función que devuelva un valor RANDOM en el rango de 0 a 100.