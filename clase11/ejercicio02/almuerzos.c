#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <time.h>
#include "almuerzos.h"
#include "funcionesGet.h"

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initAlmuerzos(eAlmuerzo* almuerzos,int cantidadAlmuerzos)
{
    int i, retorno=-1;


        for(i=0;i<cantidadAlmuerzos;i++)
        {
            almuerzos[i].isEmpty=ESTADO_LIBRE;
        }
        retorno=0;

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
int almuerzo_findIsEmpty(eAlmuerzo* almuerzos,int cantidadAlmuerzos)
 {
     int i,retorno=-1;


        for(i=0;i<cantidadAlmuerzos;i++)
        {
            if(almuerzos[i].isEmpty==ESTADO_LIBRE)
            {
                retorno= i;
                break;
            }
        }

     return retorno;
 }


void altaAlmuerzos(eAlmuerzo* almuerzos,int cantidadAlmuerzos,eMenu* menues,eEmployee* empleados)
{
    int  posicionDisponible;

    posicionDisponible= almuerzo_findIsEmpty(almuerzos,cantidadAlmuerzos);

    if(posicionDisponible!=-1)
    {

    }
}



