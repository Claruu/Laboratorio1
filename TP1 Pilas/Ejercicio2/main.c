#include <stdio.h>
#include <stdlib.h>
#include "..\Librerias\pila.c"
// 2. Cargar desde el teclado la pila ORIGEN e inicializar en vacío la pila DESTINO. Pasar todos los elementos de la pila ORIGEN a la pila DESTINO.
int main()
{
    // Defino pilas, inicializo, defino e inicializo variable user
    Pila origen, destino;
    char continuar;
    continuar = 's';
    inicpila(&origen);
    inicpila(&destino);
    int user = 0;
    

    // pido al user que me ingrese los valores necesarios
    printf("Primer valor para la pila ORIGEN: \n");
    scanf("%d", &user);
    apilar(&origen, user);
    printf("Segundo valor para la pila ORIGEN: \n");
    scanf("%d", &user);
    apilar(&origen, user);
    printf("Tercer valor para la pila ORIGEN: \n");
    scanf("%d", &user);
    apilar(&origen, user);

    // le muestro como se ve originalmente su pila
    printf("Entonces, su pila ORIGEN se ve asi originalmente");
    mostrar(&origen);

    // hago una condicion que dice que mientras origen no sea una pila vacia, deben de pasarse los datos de origen a destino
    while (!pilavacia(&origen))
    {
        apilar(&destino, desapilar(&origen));
    }

    // finalmente muestro la pila al user
    printf("Por lo cual, al pasar los datos de ORIGEN a DESTINO, se ve asi: ");
    mostrar(&destino);

    system("pause");
    return 0;
}