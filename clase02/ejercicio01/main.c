#include <stdio.h>
#include <stdlib.h>

//REALIZAR UNA FUNCION QUE RECIBA 2 PARAMETROS Y REALIZE UNA SUMA

int suma(int , int );

int main()
{
    int numero1, numero2, resultado;

    printf("Ingrese Numero: \n");
    scanf("%d",&numero1);
    printf("Ingrese Numero: \n");
    scanf("%d",&numero2);
    resultado= suma(numero1,numero2);
    printf("La suma es: %d", resultado);
    return 0;
}

int suma(int op1, int op2)
{
    int resultado;

    resultado= op1+op2;
    return resultado;
}

