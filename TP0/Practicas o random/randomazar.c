#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{

    srand(time(0));
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", rand() % 40);
    }

    system("pause");
    return 0;
}
