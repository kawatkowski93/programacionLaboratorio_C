#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//declarar variable de tipo cadena e imprimir cadena
int main()
{
    char nombre[20];

    printf("Ingrese nombre:");
    fflush(stdin);
    scanf("%s",nombre);

    printf("Ha ingresado: %s",nombre);

    return 0;
}
