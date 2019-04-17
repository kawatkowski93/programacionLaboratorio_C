#include <stdio.h>
#include <stdlib.h>
#include "persona.h"

#define CANT 3

int main()
{
    ePersona persona[CANT];//DECLARO UN ARRAY DEL TIPO ESTRUCTURA ePERSONA

    altaPersona(persona,CANT); // AL SER UNA UNICA ESTRUCTURA SE PUEDE ASIGNAR CON "="
                        // ES UNA REFERENCIA POR ESO "&" y el comienzo del vector[0]

    mostrarTodoPersona(persona,CANT);//IMPRIME POR PANTALLA, RECIBE COMO PARAMETRO UNA ESTRUCTURA

    return 0;
}
