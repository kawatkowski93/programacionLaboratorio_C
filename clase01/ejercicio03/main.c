#include <stdio.h>
#include <stdlib.h>

// CREAR UN PROGRAMA QUE INDIQUE QUE ACTIVIDAD CORRESPONDE A CADA HORARIO
    //0 - 5 levantarse
    //6 - 9 dormir
    //10 - 00
int main()
{
    /*int hora;                           //VARIABLE ENTERA

    printf("Ingrese hora: \n");
    scanf("%d",&hora);

    switch(hora)
    {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            printf("Dormir");
            break;

        case 6:
        case 7:
        case 8:
        case 9:
            printf("Levantarse");
            break;

        case 10:
        case 11:

            printf("Comer");
            break;
    }
    */

    char hora;                           //VARIABLE CARACTER

    printf("Ingrese hora: \n");
    scanf("%c",&hora);

    switch(hora)
    {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
            printf("Dormir");
            break;

        case '6':
        case '7':
        case '8':
        case '9':
            printf("Levantarse");
            break;

        case '10':
        case '11':

            printf("Comer");
            break;
    }

    return 0;
}
