#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//INGRESAR NOMBRE Y APELLIDO. PASAR TODO A MINUSCULA Y LAS PRIMERAS LETRAS PASARLAS A MAYUSCULA, LUEGO CONTATENAR E IMPRIMIR


int main()
{
    char nombre[64];
    char apellido[64];
    int cantidad;


    printf("Ingrese nombre: ");
    fgets(nombre,sizeof(nombre)-2,stdin);
    cantidad = strlen(nombre);

    nombre[cantidad-1] = ' ';

    printf("\nIngrese apellido: ");
    fgets(apellido,sizeof(apellido)-2,stdin);
    cantidad = strlen(apellido);

    apellido[cantidad-1] = '\0';

    strlwr(nombre);
    strlwr(apellido);

    nombre[0]= toupper(nombre[0]);
    apellido[0]= toupper(apellido[0]);

    strcat(nombre, apellido);

    printf("\n%s \n",nombre);

    return 0;
}


//apellidoNombre[0]= "\0";
//strcpy(apellidoNombre,apellido);
//strcat(apellidoNombre,apellido);
//strcat(apellidoNombre, "");
//strcat(apellidoNombre,nombre);
