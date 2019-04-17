#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

        printf("Ingrese dia de nacimiento: \n");
        scanf("%d",&persona[i].fechaNac.dia);

        printf("Ingrese mes de nacimiento: \n");
        scanf("%d",&persona[i].fechaNac.mes);

        printf("Ingrese anio de nacimiento: \n");
        scanf("%d",&persona[i].fechaNac.anio);

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
    if(persona.isEmpty==0)
    printf("Apellido: %s\nNombre: %s\nEdad: %d\nisEmpty%d\nID%d\nFecha de nacimiento: %d/%d/%d\n\n",persona.apellido,persona.nombre,persona.edad,persona.isEmpty,persona.idUnico,persona.fechaNac.dia,persona.fechaNac.mes,persona.fechaNac.anio);
}

void inicializarEstado(ePersona persona[],int cantidad)
{
    int i;

    for(i=0;i<cantidad;i++)
    {
        persona[i].isEmpty=1;
    }
}

void ordenar(ePersona persona[],int cantidad)
{
    int i,j;
    ePersona aux;

    for(i=0;i<cantidad-1;i++)
    {
        for(j=i+1;j<cantidad;j++)
        {
            if(strcmp(persona[i].apellido,persona[j].apellido)>0)
            {
                aux=persona[i];
                persona[i]=persona[j];
                persona[j]=aux;
            }
        }
    }
}


void darBaja(ePersona persona[],int idBuscador,int cantidad)
{
    int i;

    for(i=0;i<cantidad;i++)
    {
        if(persona[i].idUnico== idBuscador)
        {
            persona[i].isEmpty=1;
            printf("Se ha dado de baja correctamente\n");
        }
    }
}
