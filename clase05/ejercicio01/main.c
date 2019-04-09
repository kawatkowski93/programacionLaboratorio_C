#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD 7

//REALIZAR UN ARRAY DE ENTEROS, CARGAR(SECUENCIAL) E IMPRIMIR LOS DATOS - REALIZAR UN PROMEDIO

int main()
{
    int datos[CANTIDAD],i;
    float acumulador=0;

    for(i=0; i<CANTIDAD; i++)
    {
        printf("Ingrese edad: \n");
        scanf("%d",&datos[i]);
        acumulador= acumulador+datos[i];
    }
    for(i=0; i<CANTIDAD; i++)
    {
        printf("Posicion: %d   Dato: %d\n",i,datos[i]);
    }
    printf("\nEl promedio es: %.2f",acumulador/(float)i);

    return 0;
}
