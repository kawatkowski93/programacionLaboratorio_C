#include <stdio.h>
#include <stdlib.h>
#include "persona.h"

ePersona altaPersona(ePersona persona)
{
    printf("Ingrese Nombre:\n");
    fflush(stdin);
    gets(persona.nombre);

    printf("Ingrese apellido:\n");
    fflush(stdin);
    gets(persona.apellido);

    printf("Ingrese edad:\n");
    scanf("%d",&persona.edad);

    persona.isEmpty= 0;

    return persona;
}

void mostrarPersona(ePersona persona)
{
    printf("Apellido: %s\nNombre: %s\nEdad: %d\nEstado: %d\n\n",persona.apellido,persona.nombre,persona.edad,persona.isEmpty);
}
