#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//
int readValidateInput(int foo);

int main()
{
    int foo = 0;
    foo = readValidateInput(foo);
    if ((foo = readValidateInput(foo)) == 1)
    {
        printf("foo %d", foo);
    }

    system("pause");
    return 0;
}

int readValidateInput(int foo)
{
    int numOfTasks = 0;
    char str[10] = {'\0'};

readStdin:
    fgets(str, 10, stdin);
    // printf("fgets is returning %s\n", str);

    int numerical = 1;
    int i = 0;

    for (i = 0; i < 10; i++)
    {
        // printf("Digit at str[%d] is %c\n", i, str[i]);
        // printf("numerical = %d\n", numerical);
        if (isdigit(str[i]) == 0)
        {
            if (str[i] == '\n')
                break;
            numerical = 0;
            // printf("numerical changed= %d\n", numerical);
            break;
        }
    }
    if (!numerical)
    {
        printf("This is not a valid number of tasks, you need to enter at least 1 task\n");
        goto readStdin;
    }
    else if (str[i] == '\n')
    {
        str[i] = '\0';
        numOfTasks = atoi(str);
        // printf("Captured Number of tasks from stdin is %d\n", numOfTasks);
    }
    return foo;
}