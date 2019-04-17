#include <stdio.h>
#include <stdlib.h>
#include "persona.h"

int main()
{
    ePersona persona;//DECLARO UNA VARIABLE DEL TIPO ESTRUCTURA ePERSONA

    persona= altaPersona(persona); // AL SER UNA UNICA ESTRUCTURA SE PUEDE ASIGNAR CON "="

    system("cls");

    mostrarPersona(persona);//IMPRIME POR PANTALLA, RECIBE COMO PARAMETRO UNA ESTRUCTURA

    return 0;
}
