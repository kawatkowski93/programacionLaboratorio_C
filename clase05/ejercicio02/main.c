#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD 5

//REALIZAR UN ARRAY DE ENTEROS PARALELOS, CARGAR(SECUENCIAL) IMPRIMIR LOS DATOS CON TSU RESPECTIVO LEGAJO,NOTA Y PROMEDIO

int main()
{
    int nota1[CANTIDAD],nota2[CANTIDAD],nota3[CANTIDAD],i;
    float acumulador[CANTIDAD],promedio[CANTIDAD];

    for(i=0; i<CANTIDAD; i++)
        acumulador[i]=0;

    for(i=0; i<CANTIDAD; i++)
    {
        printf("Numero de legajo: %d\n\n",i);
        printf("Ingrese nota 1: \n");
        scanf("%d",&nota1[i]);
        printf("Ingrese nota 2: \n");
        scanf("%d",&nota2[i]);
        printf("Ingrese nota 3: \n");
        scanf("%d",&nota3[i]);
        system("cls");
        acumulador[i]= acumulador[i]+ nota1[i]+ nota2[i]+nota3[i];
        promedio[i]= acumulador[i]/3;
    }

    for(i=0; i<CANTIDAD; i++)
    {
        printf("Legajo: %d   nota 1: %d   nota 2: %d   nota 3: %d  promedio: %.2f   \n",i,nota1[i],nota2[i],nota3[i],promedio[i]);
    }
    return 0;
}
