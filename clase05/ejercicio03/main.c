#include <stdio.h>
#include <stdlib.h>
#define MAXIMO 5

//REALIZAR UN ARRAY DE ENTEROS PARALELOS, CARGAR(aleatoria)

int main()
{
    int edad[MAXIMO],i,leg,contador=0;
    float sueldo[MAXIMO],suma=0,promedio;
    char seguir;

    for(i=0;i<MAXIMO;i++)
    {
        edad[i]=0;
        sueldo[i]=0;
    }
    do
    {
        printf("Ingrese legajo: \n");
        scanf("%d",&leg);
        printf("Ingrese edad: \n");
        scanf("%d",&edad[leg-1]);//los legajos jamas empiezan con 0
        printf("Ingrese sueldo: \n");
        scanf("%f",&sueldo[leg-1]);
        system("cls");
        printf("Desea ingresar otro dato?\n   S/N  \n");
        fflush(stdin);//vaciar el buffer antes de tomar cualquier dato caracter
        scanf("%c",&seguir);
        contador ++;
        suma= suma+ sueldo[leg-1];
    }while(seguir=='s');

    promedio= suma/contador;
    printf("El sueldo promedio es %.2f",promedio);
    return 0;
}
