#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <time.h>
#include "menues.h"
#include "funcionesGet.h"


 static int idAutoincrementable= 0;

/**
 * \brief Genera un id que se ira autoincrementando
 * \param void
 * \return int, id unico generado
 *
 */
int array_generarProximoIdMenues(void)
{
    idAutoincrementable ++;
    return idAutoincrementable;
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
int findMenuById(eMenu* menues,int cantidadMenues,int id)
 {
     int i,retorno=-1;


        for(i=0;i<cantidadMenues;i++)
        {
            if(menues[i].idMenu== id)
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
int menu_findIsEmpty(eMenu* menues,int cantidad)
 {
     int i,retorno=-1;


        for(i=0;i<cantidad;i++)
        {
            if(menues[i].isEmpty==ESTADO_LIBRE)
            {
                retorno= i;
                break;
            }
        }

     return retorno;
 }


  /** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
 int initMenues(eMenu* menues,int cantidadMenues)
 {
     int i,retorno=-1;

     for(i=0;i<cantidadMenues;i++)
     {
         menues[i].isEmpty= ESTADO_LIBRE;
         retorno=0;
     }
     return retorno;
 }


   /** \brief ordena los elemento de la estructura
 * \param list employee*
 * \param cantidad int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 *
 */
 void ordenarMenues(eMenu* menues,int cantidadMenues)
{
    int i,j;
    eMenu aux;

    for(i=0;i<cantidadMenues-1;i++)
    {
        for(j=i+1;j<cantidadMenues;j++)
        {
            if(menues[i].importe> menues[j].importe)
            {
                aux=menues[i];
                menues[i]=menues[j];
                menues[j]=aux;
            }
        }
    }
}


 /** \brief modifica datos en el arrey de menues
 * \param list employee*
 * \param cantidad int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 *
 */
int modificarMenu(eMenu* menues, int cantidadMenues,int idAux)
{
    int retorno=-1,opcion,posicion;

    posicion= findMenuById(menues,cantidadMenues,idAux);

    if(posicion!= -1)
    {
        do
        {
            opcion= getValidIntOpcion("Que desaa modificar:\n1-DESCRIPCION\n2-IMPORTE\n3-VOLVER\n","Error\nOpcion no valida\n",1,3);

            switch(opcion)
            {
            case 1:
                system("cls");
                getValidString("INGRESE DESCRIPCION\n","Error\nCaracter no valido\n",menues[posicion-1].descripcion);
                break;

            case 2:
                system("cls");
                menues[posicion-1].importe= getValidFloat("INGRESE IMPORTE\n","Error\nCaracter no valido\n");
                break;
            }
        }
        while(opcion!=3);
        retorno=0;
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
int removeMenu(eMenu* menues,int cantidadMenues,int id)
 {
     int i, retorno=-1;


         for(i=0;i<cantidadMenues;i++)
         {
             if(menues[i].idMenu==id)
             {
                 menues[i].isEmpty=ESTADO_LIBRE;
                 retorno=0;
                 break;
             }
         }

     return retorno;
 }


/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 *
 */
int addMenu(eMenu* menues,int cantidad)
{
    int posicionAux,retorno=-1;

    if(cantidad>=0)
    {
        posicionAux= menu_findIsEmpty(menues,cantidad);

        if(posicionAux!=-1)
        {
            getValidString("Ingrese Menu:\n","Error\nCaracter no valido",menues[posicionAux].descripcion);
            menues[posicionAux].importe= getValidFloat("Ingrese Importe:\n","Error\nCaracter no valido");
            menues[posicionAux].idMenu= array_generarProximoIdMenues();
            menues[posicionAux].isEmpty= ESTADO_OCUPADO;
            system("cls");
            retorno=0;
        }
    }
    return retorno;
}



void administrarMenues(eMenu* menues, int cantidadMenues)
{
    int i, opcion, idAux;

    do
    {
        opcion= getValidIntOpcion("1-ALTA\n2-MODIFICAR\n3-BAJA\n4-LISTAR\n5-VOLVER\n\n","Error\nOpcion no valida",1,5);

        switch(opcion)
        {
            case 1://ALTA MENU
                if(addMenu(menues,cantidadMenues)==0)
                printf("Se ha cargado menu\n");

                break;

            case 2://MODIFICAR MENUES
                idAux= getValidIntOpcion("Ingrese id a modificar\n","Error id no valido",0,cantidadMenues);
                system("cls");
                if(modificarMenu(menues,cantidadMenues,idAux)==0)
                    printf("Se ha modificado correctamente\n");

                else
                    printf("No se ha podido modificar");

                break;

            case 3:
                idAux= getValidIntOpcion("Ingrese id a dar de baja\n","Error\nCaracter no valido\n",0,cantidadMenues);
                if(removeMenu(menues,cantidadMenues,idAux)==0)
                    printf("Se ha dado de baja correctamente\n");

                else
                    printf("No se ha podido dar de baja");

                break;

            case 4://IMPRIMIR
                ordenarMenues(menues,cantidadMenues);
                system("cls");
                printf("PRECIO\t\tDESCRIPCION\n");
                for(i=0;i<cantidadMenues;i++)
                {
                    if(menues[i].isEmpty==ESTADO_OCUPADO)
                    {
                        printf("%.2f\t\t%s\n",menues[i].importe,menues[i].descripcion);
                    }
                }
                break;
        }
    }while(opcion!=5);
}
