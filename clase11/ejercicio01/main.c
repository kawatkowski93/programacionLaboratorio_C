#include <stdio.h>
#include <stdlib.h>
#include "employee.h"
#include "funcionesGet.h"
#define CANTIDAD 8

int main()
{
    int opcion,flag=0,idAux;

    eEmployee arrayEmpleados[CANTIDAD];
    eNacionalidad arrayNacionalidad[4]={{1,"Argentina"},{2,"Brasil"},{3,"Uruguay"},{4,"Peru"}};

    initEmployees(arrayEmpleados,CANTIDAD);

    hardcodearDatosEmpleados(arrayEmpleados,4);
    do
    {
        opcion= getValidIntOpcion("1-ALTAS\n2-MODIFICAR\n3-BAJA\n4-INFORMAR\n5-SALIR\n","Opcion no valida",1,5);

        switch(opcion)
        {
        case 1://ALTA
            system("cls");
            addEmployee(arrayEmpleados,CANTIDAD);
            flag=1;
            break;

        case 2://MODIFICAR
            system("cls");
            if(flag==0)
                printf("No se han cargado datos aun\n");

            else
            {
                idAux= getValidIntOpcion("Ingrese id a modificar\n","Error\nID NO VALIDO",1,CANTIDAD);
                if(modificarEmployee(arrayEmpleados,CANTIDAD,idAux)==0)
                    printf("Se han modificado los datos\n");

                flag=1;
            }
            break;

        case 3://BAJA
            system("cls");
            if(flag==0)
                printf("No se han cargado datos aun\n");

            else
            {
                idAux= getValidIntOpcion("Ingrese id a dar de baja\n","Error\nID NO VALIDO",0,CANTIDAD);
                if(removeEmployee(arrayEmpleados,CANTIDAD,idAux)==0)
                    printf("\nSe ha dado de baja\n\n");

                    flag=1;
            }
            break;

        case 4://INFORMAR
            system("cls");
            if(flag==1)
                printListEmployee(arrayEmpleados,CANTIDAD,arrayNacionalidad,4);

            else
                printf("No se han cargado datos aun\n");

            break;
        }
    }
    while(opcion!=5);

    return 0;
}
