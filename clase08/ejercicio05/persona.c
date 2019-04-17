#include <stdio.h>
#include <stdlib.h>
#include "persona.h"


void altaPersona(ePersona persona[],int cantidad)
{
    int i,id=0;

    for(i=0; i<cantidad; i++)
    {
        printf("Ingrese Nombre:\n");
        fflush(stdin);
        gets(persona[i].nombre);

        printf("Ingrese apellido:\n");
        fflush(stdin);
        gets(persona[i].apellido);

        printf("Ingrese edad:\n");
        scanf("%d",&persona[i].edad);

        persona[i].isEmpty= 0;

        id++;

        persona[i].idUnico=id;

        system("cls");
    }
}

void mostrarTodoPersona(ePersona persona[],int cantidad)
{
    int i;
    for(i=0;i<cantidad;i++)
    {
        mostrarPersona(persona[i]);
    }
}

void mostrarPersona(ePersona persona)
{
    printf("Apellido: %s\nNombre: %s\nEdad: %d\nEstado: %d\nID: %d\n",persona.apellido,persona.nombre,persona.edad,persona.isEmpty,persona.idUnico);
}

void inicializarEstado(ePersona persona[],int cantidad)
{
    int i;

    for(i=0;i<cantidad;i++)
    {
        persona[i].isEmpty=1;
    }
}

