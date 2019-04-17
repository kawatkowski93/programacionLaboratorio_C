#include <stdio.h>
#include <stdlib.h>
//declarar una estructura de datos e imprimirlos

struct persona{
    char apellido[31];
    char nombre[31];
    int edad;
    int isEmpty;
};

int main()
{
    struct persona persona;         //DECLARO VARIABLE TICO STRUCT PERSONA persona.


    printf("Ingrese Nombre:\n");
    gets(persona.nombre);

    printf("Ingrese apellido:\n");
    gets(persona.apellido);

    printf("Ingrese edad:\n");
    scanf("%d",&persona.edad);

    persona.isEmpty= 0;
    system("cls");

    printf("\n\nApellido: %s\nNombre: %s\nEdad: %d\n",persona.apellido,persona.nombre,persona.edad);
    if(persona.isEmpty==0)
        printf("Su estado es: OCUPADO\n");

    return 0;
}
