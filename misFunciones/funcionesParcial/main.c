#include <stdio.h>
#include <stdlib.h>
#include "funcionesGet.h"

int main()
{
    int numero;

    numero=getValidInt("Ingrese opcion\n","\nerror",1,5);
    printf("%d",numero);

}
