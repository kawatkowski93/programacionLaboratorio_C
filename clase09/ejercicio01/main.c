#include <stdio.h>
#include <stdlib.h>
#include "persona.h"

#define CANT 2

int main()
{
    int opcion,idAux;
    char seguir;

  //  eNacion nacionalidad[]={1,"Argentina",2,"Chile",3,"Peru",4,"Brasil"};
    ePersona persona[CANT];
    inicializarEstado(persona,CANT);

    do
    {
        printf("\n1-ALTA\n2-MOSTRAR\n3-SEGUIR?\n4-ORDENAR\n5-BAJA\n");
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            system("cls");
            altaPersona(persona,CANT);
            break;

        case 2:
            system("cls");
            mostrarTodoPersona(persona,CANT);
            break;

        case 3:
            printf("\nDesea continuar?\n s/n");
            scanf("%c",&seguir);
            break;
        case 4:
            ordenar(persona,CANT);
            system("cls");
            printf("Se ha ordenado\n");
            break;

        case 5:
            system("cls");
            printf("Ingrese id a dar de baja\n");
            scanf("%d",&idAux);
            darBaja(persona,idAux,CANT);
            break;
        }
    }while(seguir!='s');

    return 0;
}
