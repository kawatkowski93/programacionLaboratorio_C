#include <stdio.h>
#include <stdlib.h>
#include "persona.h"

#define CANT 3

int main()
{
    int opcion;
    char seguir;

    ePersona persona[CANT];
    inicializarEstado(persona,CANT);

    do
    {
        printf("\n1-ALTA\n2-MOSTRAR\n3-SEGUIR?\n");
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            altaPersona(persona,CANT);
            break;

        case 2:
            mostrarTodoPersona(persona,CANT);
            break;

        case 3:
            printf("\nDesea continuar?\n s/n");
            scanf("%c",&seguir);
        }

    }while(seguir!='s');


    return 0;
}
