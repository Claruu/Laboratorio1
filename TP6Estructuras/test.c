#include <stdio.h>
#include <stdlib.h> // Used for atoi() function
#include <string.h> // Used for strlen() function
#define TRUE 1
#define FALSE 0

int checkNum(int);

int main(void)
{
    int matricula = 468;
    matricula = checkNum(matricula);
    printf("Matricula: %d\n", matricula);
    system("pause");
    return 0;
}
int checkNum(int aVerificar)
{

    char n[10]; // Limits characters to the equivalent of the 32 bits integers limit (10 digits)

    printf("Ingrese # matricula: ");

    do
    {
        scanf(" %s", n);

        aVerificar = TRUE; // Sets the default for the integer test variable to TRUE

        int i = 0, l = strlen(n);
        if (n[0] == '-') // Tests for the negative sign to correctly handle negative integer values
            i++;
        while (i < l)
        {
            if (n[i] < '0' || n[i] > '9') // Tests the string characters for non-integer values
            {
                aVerificar = FALSE; // Changes intTest variable from TRUE to FALSE and breaks the loop early
                break;
            }
            i++;
        }
        if (aVerificar == TRUE)
        {
            aVerificar = atoi(n);
        } // Converts the string to an integer and prints the integer value
        else
        {
            printf("Error. Vuelva a ingresar el # matricula: "); // Prints "Retry:" if tested FALSE
            if (aVerificar == TRUE)
            {
                aVerificar = atoi(n);
            }
        }

    } while (aVerificar == FALSE); // Continues to ask the user to input a valid integer value

    return aVerificar;
}