#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <time.h>
#include "employee.h"
#include "menues.h"
#include "funcionesGet.h"


static int idAutoincrementable= 0;

/**
 * \brief Genera un id que se ira autoincrementando
 * \param void
 * \return int, id unico generado
 *
 */
int array_generarProximoId(void)
{
    idAutoincrementable ++;
    return idAutoincrementable;
}


/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(eEmployee* empleados,int cantidad)
{
    int i, retorno=-1;


        for(i=0;i<cantidad;i++)
        {
            empleados[i].isEmpty=ESTADO_LIBRE;
        }
        retorno=0;

    return retorno;
}

/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 *
 */
int addEmployee(eEmployee* empleados,int cantidad)
{
    int posicionAux,retorno=-1;

    if(cantidad>=0)
    {
        posicionAux= findIsEmpty(empleados,cantidad);

        if(posicionAux!=-1)
        {
            getValidString("Ingrese nombre:\n","Error\nCaracter no valido",empleados[posicionAux].name);
            getValidString("Ingrese apellido:\n","Error\nCaracter no valido",empleados[posicionAux].lastName);
            empleados[posicionAux].salary= getValidFloat("Ingrese sueldo:\n","Error\nCaracter no valido");
            empleados[posicionAux].id= array_generarProximoId();
            system("cls");
            empleados[posicionAux].fechaIngreso.anio= getValidIntOpcion("Ingrese año de ingreso: ","Error\nFecha no valida",1950,2019);
            empleados[posicionAux].fechaIngreso.mes= getValidIntOpcion("Ingrese mes de ingreso: ","Error\nFecha no valida",1,12);
            empleados[posicionAux].fechaIngreso.dia= getValidIntOpcion("Ingrese dia de ingreso: ","Error\nFecha no valida",1,31);
            getValidString("Ingrese sexo:\n (f)femenino\n(m)masculino\n","Caracter no valido\n",empleados[posicionAux].sexo);
            empleados[posicionAux].idSector= getValidIntOpcion("Escoga sector\n1-Comras\n2-Ventas\n3-RRHH\n","Error\nOpcion no valida",1,3);
            empleados[posicionAux].isEmpty= ESTADO_OCUPADO;
            system("cls");
            printf("SE HA CARGADO EMPLEADO\n\n");
            retorno=0;
        }
    }
    return retorno;
}


/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int findEmployeeById(eEmployee* empleados,int cantidad,int id)
 {
     int i,retorno=-1;


        for(i=0;i<cantidad;i++)
        {
            if(empleados[i].id== id)
            {
                retorno= id;
                break;
            }
        }

     return retorno;
 }



 /** \brief find an Employee by Id en returns the free place position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int findIsEmpty(eEmployee* empleados,int cantidad)
 {
     int i,retorno=-1;


        for(i=0;i<cantidad;i++)
        {
            if(empleados[i].isEmpty==ESTADO_LIBRE)
            {
                retorno= i;
                break;
            }
        }

     return retorno;
 }



 /** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
 *
 */
int removeEmployee(eEmployee* empleados,int cantidad,int id)
 {
     int i, retorno=-1;


         for(i=0;i<cantidad;i++)
         {
             if(empleados[i].id==id)
             {
                 empleados[i].isEmpty=ESTADO_LIBRE;
                 retorno=0;
                 break;
             }
         }

     return retorno;
 }

 /** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
void printEmployee(eEmployee empleado,eSector* sectores,int cantidad)
{
    int i;
    char descripcionAux[31];

    for(i=0; i<cantidad; i++)
    {
        if(empleado.idSector==sectores[i].idSector)
        {
            strcpy(descripcionAux,sectores[i].descripcionSector);
            break;
        }
    }
    printf("Nombre: %s\nApellido: %s\nSexo: %s\nID: %d\nSalario: %.2f\nFecha Ingreso: %d/%d/%d\nSector: %s\n\n",empleado.name,empleado.lastName,empleado.sexo,empleado.id,empleado.salary,empleado.fechaIngreso.dia,empleado.fechaIngreso.mes,empleado.fechaIngreso.anio,descripcionAux);
 }

  /** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
 void printListEmployee(eEmployee* empleados,int cantidadEmpleados,eSector* sectores)
 {
     int i;

     for(i=0;i<cantidadEmpleados;i++)
     {
         if(empleados[i].isEmpty==ESTADO_OCUPADO)
         {
             printEmployee(empleados[i],sectores,cantidadEmpleados);
       }
     }
 }






 /** \brief modifica datos en el arrey de empleados
 * \param list employee*
 * \param cantidad int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 *
 */
int modificarEmployee(eEmployee* empleados, int cantidad,int id)
{
    int retorno=-1,opcion;

    id= findEmployeeById(empleados,cantidad,id);

    if(id!= -1)
    {
        do
        {
            opcion= getValidIntOpcion("Que desea modificar\n1-NOMBRE\n2-APELLIDO\n3-SALARIO\n4-SEXO\n5-FECHA DE INGRESE\n6-SECTOR\n7-VOLVER\n","Error\nOpcion no valida\n",1,7);

            switch(opcion)
            {
            case 1:
                system("cls");
                getValidString("Ingrese nombre:\n","Error\nCARACTER NO VALIDO\n",empleados[id-1].name);
                break;

            case 2:
                system("cls");
                getValidString("Ingrese apellido:\n","Error\nCARACTER NO VALIDO\n",empleados[id-1].lastName);
                break;

            case 3:
                system("cls");
                empleados[id-1].salary= getValidFloat("Ingrese sueldo: \n","Error\nCARACTER NO VALIDO");
                break;

            case 4:
                system("cls");
                getValidString("Escoga sexo\n(f) FEMENINO\n(m) MASCULINO","Error\nopcion no valida",empleados[id-1].sexo);
                break;

            case 5:
                system("cls");
                empleados[id-1].fechaIngreso.dia= getValidIntOpcion("Ingrese dia:\n","Error\nOpcion no valida",1,31);
                empleados[id-1].fechaIngreso.mes= getValidIntOpcion("Ingrese mes:\n","Error\nOpcion no valida",1,12);
                empleados[id-1].fechaIngreso.anio= getValidIntOpcion("Ingrese anio:\n","Error\nOpciono no valida",1950,2019);
                break;

            case 6:
                system("cls");
                empleados[id-1].idSector= getValidIntOpcion("Ingrese sector\n1-COMPRAS\t2-ENTAS\t3-RRHH\n","Error\nOpcion no valida",1,3);
                break;
            }
        }
        while(opcion!=7);
        retorno=0;
    }
    return retorno;
}





void administrarEmpleado(eEmployee* empleado,eSector* sectores,int cantidad)
{
    int opcion,idAux;

    do
    {
        opcion= getValidIntOpcion("1-ALTA\n2-MODIFICAR\n3-BAJA\n4-LISTAR\n5-VOLVER\n\n","Error\nOpcion no valida",1,5);

        switch(opcion)
        {
        case 1://ALTA EMPLEADO
            addEmployee(empleado,cantidad);
            break;

        case 2://MODIFICAR EMPLEADO
            idAux=getValidIntOpcion("Ingrese ID de empleado a modificar\n","Error\nID no valido\n",1,cantidad);

            if(modificarEmployee(empleado,cantidad,idAux)==0){
                printf("SE HA MODIFICADO CORRECTAMENTE\n");}

                break;

        case 3://BAJA EMPLEADO
            idAux=getValidIntOpcion("Ingrese ID de empleado a dar de baja","Error\nID no valido\n",1,cantidad);

            if(removeEmployee(empleado,cantidad,idAux)==0){
                printf("SE HA DADO DE BAJA\n");}

                break;

        case 4://IMPRIMIR LISTA EMPLEADO
            printListEmployee(empleado,cantidad,sectores);
            break;
        }

    }while(opcion!=5);
}








