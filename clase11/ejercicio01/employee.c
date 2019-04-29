#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <time.h>
#include "employee.h"
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
            empleados[posicionAux].nacionalidad= getValidIntOpcion("ELIGA SU nacionalidad\nArgentina 1\nBrasil 2\nUruguay 3\nPeru 4\n","ERROR\nOpcion no valida\n",1,4);
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
void printEmployee(eEmployee empleado,eNacionalidad* nacionalidad,int cantidad)
 {
     int i;
     char descripcion[31];

         for(i=0;i<cantidad;i++)
         {
             if(empleado.nacionalidad== nacionalidad[i].idNacionalidad)
             {
                strcpy(descripcion,nacionalidad[i].descripcion);
                break;
             }
         }
    printf("Nombre: %s \nApellido: %s\nnacionalidad: %s \nSalario:%.2f\nID: %d\n\n",empleado.name,empleado.lastName,descripcion,empleado.salary,empleado.id);
 }

  /** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
 void printListEmployee(eEmployee* empleados,int cantidadEmpleados,eNacionalidad* nacionalidades,int cantidadNacionalidades)
 {
     int i;

     for(i=0;i<cantidadEmpleados;i++)
     {
         if(empleados[i].isEmpty==ESTADO_OCUPADO)
         {
             printEmployee(empleados[i], nacionalidades,cantidadNacionalidades);
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
            opcion= getValidIntOpcion("Que desea modificar\n1-NOMBRE\n2-APELLIDO\n3-SALARIO\n4-nacionalidad\n5-SALIR\n","Opcion no valida\n",1,5);

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
                empleados[id-1].nacionalidad= getValidIntOpcion("nacionalidad\nArgentina 1\nBrasil 2\nUruguay 3\nPeru 4\n","ERROR\nOpcion no valida\n",1,4);
                break;
            }
        }
        while(opcion!=5);
        retorno=0;
    }
    return retorno;
}

void hardcodearDatosEmpleados(eEmployee* empleado, int cantidad)
{
    int i;
    char nombres[][50]= {"Carlos","Maria","Carlos","Pedro","Carlos","Mateo"};
    char apellido[][50]= {"Lopez","Dias","Suarez","Fagundez","Albornoz","Imbert"};
    float sueldosBruto[]= {22000,22000,15000,4000,21000,6000};
    int nacionalidad[]={1,2,3,1,2,2};

    for(i=0; i<cantidad; i++)
    {
        empleado[i].id=array_generarProximoId();
        strcpy(empleado[i].name,nombres[i]);
        strcpy(empleado[i].lastName,apellido[i]);
        empleado[i].salary= sueldosBruto[i];
        empleado[i].nacionalidad= nacionalidad[i];
        empleado[i].isEmpty= ESTADO_OCUPADO;
    }
}

