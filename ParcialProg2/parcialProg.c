#include <stdio.h>
#include <stdlib.h>
//
void persistencia(int A[], char B[], int validos);
int sumarPosicionesPares(int Matriz[][2], int filas, int columnas);

int main()
{
    int M[2][2];
    int fi = 0, col = 0, validos, i = 0, suma = 0;
    int A[5];
    char B[5];
    char continuar;

    do
    {
        printf("Cargue un int al array: ");
        fflush(stdin);
        scanf("%i", &A[i]);

        fflush(stdin);
        printf("Cargue un CHAR al array: ");
        scanf("%c", &B[i]);

        i++;
        fflush(stdin);
        printf("Desea continuar? s/n: ");
        scanf("%c", &continuar);
    } while (i < 5 && continuar == 's');

    validos = i;

    persistencia(A, B, validos);
    system("pause");
    return 0;
}

void persistencia(int A[], char B[], int validos)
{
    FILE *fp;

    fp = fopen("salida.bin", "ab");

    if (fp != NULL)
    {

        fwrite(&validos, sizeof(int), 1, fp);

        for (int i = 0; i < validos; i++)
        {
            fwrite(&A[i], sizeof(int), 1, fp);
        }

        for (int i = 0; i < validos; i++)
        {
            fwrite(&B[i], sizeof(char), 1, fp);
        }

        fclose(fp);
    }
}

int sumarPosicionesPares(int Matriz[][2], int filas, int columnas)

{

    int suma = 0;

    for (int i = 0; i < filas; i++)

    {

        for (int j = 0; j < columnas; j++)

        {

            if (((i + j) % 2) == 0)

            {

                suma += Matriz[i][j];
            }
        }
    }

    return suma;
}

// do
// {
// printf("FILA %i\n", i);
// for (int j = 0; j < 2; j++)
// {
// printf("matriz[%i][%i]= ", i, j);
// scanf("%i", &M[i][j]);
// }
// printf("Desea cargar otra fila?\n");
// fflush(stdin);
// scanf("%c", &continuar);
// i++;
// } while (i < 2 && continuar == 's');

// validos = i;
// fi = i;
// col = i;
// suma = sumarPosicionesPares(M, fi, col);
// printf("suma: %i", suma);