#include <stdio.h>
#include <stdlib.h>
#define TAM_MAX 30
// APELLIDO Y NOMBRE CLARA DOMINGUEZ
// Calcular a través de funciones e informar por pantalla:
void lecturaArchivoYmuestraMatrices(char[][TAM_MAX], int[][TAM_MAX], int *, char[]);

// Jugador más predominante en el juego, es decir, el que aparece en la mayoría de las casillas.
int contarLetrasJugadores(char[][TAM_MAX], int);

// Jugador con más puntos.
int contarPuntosJugadores(char[][TAM_MAX], int[][TAM_MAX], int);

// Cantidad de columnas en dónde aparece un sólo Jugador
int cantColumnasUnSoloJugador(char[][TAM_MAX], int[][TAM_MAX], int);

int main()
{
    FILE fp;
    char nombArch[TAM_MAX] = {"datos.bin"};
    int rango;
    int validos = 0, respuesta = -1, respuesta2 = -1, respuesta3 = -1;

    int puntaje[TAM_MAX][TAM_MAX];
    char jugadores[TAM_MAX][TAM_MAX];

    lecturaArchivoYmuestraMatrices(jugadores, puntaje, &rango, nombArch);

    respuesta = contarLetrasJugadores(jugadores, rango);

    if (respuesta != -1 || respuesta2 != -1 || respuesta3 != -1)
    {
        if (respuesta == 1)
        {
            printf("El jugador A es el mas predominante.\n");
        }
        else
        {
            printf("El jugador B es el mas predominante.\n");
        }

        respuesta2 = contarPuntosJugadores(jugadores, puntaje, rango);
        if (respuesta2 == 1)
        {
            printf("\nEl jugador A es el con mas puntos.\n");
        }
        else
        {
            printf("\nEl jugador B es el con mas puntos.\n");
        }
        respuesta3 = cantColumnasUnSoloJugador(jugadores, puntaje, rango);
        printf("\nLa cantidad de columnas iguales es %i\n", respuesta3);
    }

    system("pause");
    return 0;
}

void lecturaArchivoYmuestraMatrices(char jugadores[][TAM_MAX], int puntaje[][TAM_MAX], int *rango, char nombreArchivo[])
{
    FILE *fp;
    fp = fopen(nombreArchivo, "rb");
    if (fp != NULL)
    {
        fread(rango, sizeof(int), 1, fp); // primero leo el rango

        printf("Matriz A: \n");
        for (int i = 0; i < *rango; i++) // luego voy recorriendo ambas matrices e impriendo el valor en pantalla
        {
            for (int j = 0; j < *rango; j++)
            {
                fread(&jugadores[i][j], sizeof(char), 1, fp);
                printf("[ %c ] ", jugadores[i][j]);
            }
            printf("\n"); // para el formato matricial
        }

        printf("\nMatriz B: \n");
        for (int i = 0; i < *rango; i++)
        {
            for (int j = 0; j < *rango; j++)
            {
                fread(&puntaje[i][j], sizeof(int), 1, fp);
                printf("[ %i ] ", puntaje[i][j]);
            }
            printf("\n");
        }
        fclose(fp);
    }
    else
        printf("Error. No se ha podido abrir el archivo.");
}

// Jugador más predominante en el juego, es decir, el que aparece en la mayoría de las casillas.
int contarLetrasJugadores(char jugadores[][TAM_MAX], int rango)
{
    int numJugadorA = 0, numJugadorB = 0, respuesta = 0;

    for (int i = 0; i < rango; i++)
    {
        printf("\n");
        for (int j = 0; j < rango; j++)
        {
            printf(" [ %c ] ", jugadores[i][j]);

            if (jugadores[i][j] == 'A')
            {
                numJugadorA++;
            }
            else
            {
                numJugadorB++;
            }
        }
        printf("\n");
    }

    if (numJugadorA > numJugadorB)
    {
        respuesta = 1;
    }

    return respuesta;
}

// Jugador con más puntos.
int contarPuntosJugadores(char jugadores[][TAM_MAX], int puntajes[][TAM_MAX], int rango)
{
    int contadorA = 0, contadorB = 0, respuesta2 = 0;
    for (int i = 0; i < rango; i++)
    {
        for (int j = 0; j < rango; j++)
        {
            if (jugadores[i][j] == 'A')
            {
                contadorA += puntajes[i][j];
            }
            else
            {
                contadorB += puntajes[i][j];
            }
        }
    }

    if (contadorA > contadorB)
    {
        respuesta2 = 1;
        printf("\nPuntos del jugador A: %i\n", contadorA);
    }

    return respuesta2;
}

// Cantidad de columnas en dónde aparece un sólo Jugador
int cantColumnasUnSoloJugador(char jugadores[][TAM_MAX], int puntajes[][TAM_MAX], int rango)
{
    int columIguales = 0, j = 0;
    char letra;

    for (int i = 0; i < rango; i++)
    {
        j = 0;
        letra = jugadores[j][i];

        while ((j < rango) && (letra == jugadores[j][i]))
        {
            j++;
        }

        if (j == rango)
        {
            columIguales++;
        }
    }

    return columIguales;
}