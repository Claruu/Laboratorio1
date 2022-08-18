#include <stdio.h>
#include <stdlib.h>

void persistencia(int[], char[], int);
void leer(int);
int suma(int m[2][2], int f, int c);

int main()
{

    /*int A[5] = {0, 1, 2, 3, 4};
    char B[5] = {'a', 'b', 'c', 'd', 'e'};
    int validos = 5;
    persistencia(A, B, validos);

    printf("A");
    leer(validos);*/

    // FunciÃ³n que sume elementos en posiciones pares de una matriz cuadrada de 2 x 2 y lo retorne.
    int f = 2, c = 2;
    int m[2][2] = {{3, 4}, {1, 2}};
    printf("%d", suma(m, f, c));
    system("pause");
    return 0;
}

int suma(int m[2][2], int f, int c)
{
    int suma = 0;
    for (int i = 0; i < f; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (((i + j) % 2) == 0)
            {
                printf("%d", m[i][j]);
                suma = suma + m[i][j];
            }
        }
    }
    return suma;
}

void persistencia(int A[], char B[], int v)
{
    FILE *fp = fopen("test.bin", "ab");
    if (fp != NULL)
    {
        fwrite(&v, sizeof(int), 1, fp);

        for (int i = 0; i < v; i++)
        {
            fwrite(&A[i], sizeof(int), 1, fp);
        }
        for (int j = 0; j < v; j++)
        {
            fwrite(&B[j], sizeof(char), 1, fp);
        }
    }
}

void leer(int validos)
{
    FILE *fp = fopen("test.bin", "rb");
    int aux = 0;
    int aux2 = 0;
    char aux3;
    if (fp != NULL)
    {
        fread(&aux, sizeof(int), 1, fp);
        printf("%d", aux);

        for (int i = 0; i < validos; i++)
        {
            fread(&aux2, sizeof(int), 1, fp);
            printf("%d -", aux2);
        }
        for (int h = 0; h < validos; h++)
        {
            fread(&aux3, sizeof(char), 1, fp);
            printf("%c -", aux3);
        }
    }
}