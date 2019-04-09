#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD 5

int main()
{
    int vector[CANTIDAD]={2,7,6,3,8};
    int i,j,aux;

    for(i=0;i<CANTIDAD-1;i++)
    {
        for(j=i+1;j<CANTIDAD;j++)
        {
            if(vector[i]> vector[j])
            {
                aux= vector[i];
                vector[i]= vector[j];
                vector[j]= aux;
            }
        }
    }

    for(i=0;i<CANTIDAD;i++)
        printf("%d",vector[i]);

    return 0;
}
