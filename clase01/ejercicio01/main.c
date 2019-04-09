#include <stdio.h>
#include <stdlib.h>

//MOSTRAR NUMEROS DEL 1 AL 10
    // using for, do while y while

int main()
{
    int i=0;

    /*
    for(i=0; i<10; i++)                     FOR
    {
        printf("%d\n",(i+1));
    }

    do                                      DO WHILE
    {
        printf("%d\n",(i+1));
        i++;
    }while(i<10);
    */
    while(i<10)                             //WHILE
    {
        printf("%d\n",(i+1));
        i++;
    }
    return 0;
}

