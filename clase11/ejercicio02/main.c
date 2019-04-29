#include <stdio.h>
#include <stdlib.h>
#include "employee.h"
#include "menues.h"
#include "funcionesGet.h"
#define CANTIDAD_EMPLEADOS 8
#define CANTIDAD_MENUES 5
#define CANTIDAD_ALMUERZOS 3

int main()
{
    int opcion;

    eEmployee arrayEmpleados[CANTIDAD_EMPLEADOS];
    eSector arraySectores[3]={{1,"COMPRAS"},{2,"VENTAS"},{3,"RRHH"}};
    eMenu arrayMenues[CANTIDAD_MENUES];

    initEmployees(arrayEmpleados,CANTIDAD_EMPLEADOS);
    initMenues(arrayMenues,CANTIDAD_MENUES);

    do
    {
        system("cls");
        opcion= getValidIntOpcion("1-ADMINISTRAR EMPLEADOS\n2-ADMINISTRAR MENUES\n3-ADMINISTRAR ALMUERZOS\n4-SALIR\n","Opcion no valida",1,4);

        switch(opcion)
        {
        case 1://administrar empleados
            system("cls");
            administrarEmpleado(arrayEmpleados,arraySectores,CANTIDAD_EMPLEADOS);
            break;

        case 2://administrar menues
            system("cls");
            administrarMenues(arrayMenues,CANTIDAD_MENUES);
            break;

        case 3://administrar almuerzos
            system("cls");

            break;

        case 4://INFORMAR
            system("cls");


            break;
        }
    }
    while(opcion!=5);

    return 0;
}
