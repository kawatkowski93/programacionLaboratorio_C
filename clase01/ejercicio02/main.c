#include <stdio.h>
#include <stdlib.h>

// MOSTRAR NUMEROS DE MAYOR A MENOR E IMPRIMIRLOS

int main()
{
    int maximo,minimo, numero,i=0;

    for(i=0;i<10;i++)
    {
        printf("\n Ingrese numeros: ");
        scanf("%d",&numero);
        minimo=numero;

        if(minimo<maximo)
            minimo=minimo;

        if(maximo>minimo)
            maximo=maximo;

    }

    printf("Hello world!\n");
    return 0;
}
