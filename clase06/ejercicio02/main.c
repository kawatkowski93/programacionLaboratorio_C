#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//declarar variable de tipo cadena e imprimir cadena

int main()
{
    char nombre[20];

    printf("Ingrese nombre:");
    fflush(stdin);
    gets(nombre);
//no se usa porque solo se usa para microsoft
//tiene agujeros de seguridad
    printf("Ha ingresado: %s \n\n",nombre);

    return 0;
}
