#include <stdio.h>
#include <stdlib.h>
#define MAX 5

//REALIZAR UNA CARGA ALEATORIA E IMPRIMIR POR PANTALLA EL MINIMO Y MAXIMO

int main()
{
    int datos[MAX],i,minimo,maximo;
    char seguir;

    for(i=0;i<MAX;i++)
        datos[i]=0;

    do
    {
        printf("Ingrese legajo: \n");
        scanf("%d",&i);
        printf("Ingrese dato: \n");
        scanf("%d",&datos[i]);
        system("cls");
        printf("Desea ingresar otro dato?\n   S/N  \n");
        fflush(stdin);//vaciar el buffer antes de tomar cualquier dato caracter
        scanf("%c",&seguir);
    }while(seguir=='s');

    for(i=0;i<MAX;i++)
    {
        if(i==0 || datos[i]>maximo)
            maximo= datos[i];

        if(i==0 || datos[i]<minimo)
            minimo= datos[i];
    }

    printf("El maximo es: %d\nEl minimo es: %d",maximo,minimo);

    return 0;
}
