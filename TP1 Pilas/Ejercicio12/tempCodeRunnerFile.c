printf("Ingrese valores para la pila DADA\n");
    do
    {
        scanf("%d", &user);
        if (user != 0)
        {
            apilar(&dada, user);
        }
    } while (user != 0);