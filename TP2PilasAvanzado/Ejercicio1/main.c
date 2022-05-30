// #include <stdio.h>
// #include <stdlib.h>
// #include "..\Librerias\pila.c"
// // Sumar los elementos de una pila (usar variables enteras)
// int funcion1(Pila p)
// {
//     int a = 0;
//     int b;
//     while (!pilavacia(&p))
//     {
//         a = a + (tope(&p) % 2 == 0);
//         b = desapilar(&p);
//         printf("a: %i\n", a);
//     }
//     return a;
// }

// int main()
// {
//     Pila pilaUser, aux;
//     inicpila(&pilaUser);
//     inicpila(&aux);
//     apilar(&pilaUser, 4);
//     apilar(&pilaUser, 6);
//     apilar(&pilaUser, 7);
//     apilar(&pilaUser, 8);
//     apilar(&pilaUser, 9);
//     apilar(&pilaUser, 0);
//     apilar(&pilaUser, 5);
//     int user = 0, sumaUser = 0;
//     char continuar;
//     continuar = 's';

//     // do
//     // {
//     //     leer(&pilaUser);
//     //     printf("Desea seguir agregando elementos? ");
//     //     fflush(stdin);
//     //     scanf("%c", &continuar);
//     // } while (continuar == 's' || continuar == 'S');
//     user = funcion1(pilaUser);
//     printf("user: %i", user);
//     // while (!pilavacia(&pilaUser))
//     // {
//     //     sumaUser += tope(&pilaUser);
//     //     apilar(&aux, desapilar(&pilaUser));
//     // }
//     // while (!pilavacia(&aux))
//     // {
//     //     apilar(&pilaUser, desapilar(&aux));
//     // }
//     // printf("Tu pila se ve asi: ");
//     // mostrar(&pilaUser);
//     // printf("Por lo cual, la suma de tus valores seria de %d.\n", sumaUser);

//     system("pause");
//     return 0;
// }
